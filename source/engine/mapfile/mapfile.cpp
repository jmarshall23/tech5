#include "mapfile/mapfile.h"

#include "decls/declentitydef.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/file_permanent.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"
#include "idlib/text/lexer.h"
#include "idlib/typeinfo/typeinfotree.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <memory>

namespace {

mapMaterialToolsFlagsResolver_t materialToolsFlagsResolver = nullptr;
mapEntityFilter_t productionEntityFilter = nullptr;

const char* const groupStateTokens[] = {
    "normal", "hidden", "frozen", nullptr
};

template<class type>
void DeletePointerList(idList<type*, TAG_IDLIB>& values) {
    for (int index = 0; index < values.Num(); ++index) {
        delete values[index];
    }
    values.Clear();
}

template<class type>
void AppendList(idList<type, TAG_IDLIB>& destination,
        const idList<type, TAG_IDLIB>& source) {
    for (int index = 0; index < source.Num(); ++index) {
        destination.Append(source[index]);
    }
}

unsigned int FloatBits(const float value) {
    unsigned int bits = 0;
    static_assert(sizeof(bits) == sizeof(value), "float size changed");
    std::memcpy(&bits, &value, sizeof(bits));
    return bits;
}

unsigned int MapStringHash(const char* text) {
    unsigned int hash = 0;
    if (text == nullptr) {
        return hash;
    }
    for (unsigned int index = 0; text[index] != '\0'; ++index) {
        hash ^= static_cast<unsigned int>(
            static_cast<unsigned char>(text[index])) << (index & 3u);
    }
    return hash;
}

idVec3 TransformVector(const idVec3& vector, const idMat3& axis) {
    // The recovered PPC code multiplies column-wise (axis transpose in the
    // row-major PC facade), so do not use idMat3::operator* here.
    return idVec3(
        axis[0].x * vector.x + axis[1].x * vector.y
            + axis[2].x * vector.z,
        axis[0].y * vector.x + axis[1].y * vector.y
            + axis[2].y * vector.z,
        axis[0].z * vector.x + axis[1].z * vector.y
            + axis[2].z * vector.z);
}

idPlane PlaneFromPoints(const idVec3& first, const idVec3& second,
        const idVec3& third) {
    idVec3 normal = (first - second).Cross(third - second);
    normal.NormalizeFast();
    return idPlane(normal.x, normal.y, normal.z, -normal.Dot(second));
}

bool StartsWithNoCase(const char* text, const char* prefix) {
    if (text == nullptr || prefix == nullptr) {
        return false;
    }
    while (*prefix != '\0') {
        if (*text == '\0'
            || std::tolower(static_cast<unsigned char>(*text))
                != std::tolower(static_cast<unsigned char>(*prefix))) {
            return false;
        }
        ++text;
        ++prefix;
    }
    return true;
}

bool ContainsNoCase(const char* text, const char* needle) {
    if (text == nullptr || needle == nullptr || *needle == '\0') {
        return false;
    }
    const int needleLength = static_cast<int>(std::strlen(needle));
    for (const char* cursor = text; *cursor != '\0'; ++cursor) {
        int index = 0;
        while (index < needleLength && cursor[index] != '\0'
            && std::tolower(static_cast<unsigned char>(cursor[index]))
                == std::tolower(static_cast<unsigned char>(needle[index]))) {
            ++index;
        }
        if (index == needleLength) {
            return true;
        }
    }
    return false;
}

bool EndsWithNoCase(const char* text, const char* suffix) {
    if (text == nullptr || suffix == nullptr) {
        return false;
    }
    const std::size_t textLength = std::strlen(text);
    const std::size_t suffixLength = std::strlen(suffix);
    return suffixLength <= textLength
        && idStr::Icmp(text + textLength - suffixLength, suffix) == 0;
}

idStr Quote(const char* text) {
    idStr result("\"");
    result.Append(text == nullptr ? "" : text);
    result.Append('"');
    return result;
}

idStr Unquote(const char* text) {
    if (text == nullptr) {
        return idStr();
    }
    const std::size_t length = std::strlen(text);
    if (length >= 2 && ((text[0] == '"' && text[length - 1] == '"')
            || (text[0] == '\'' && text[length - 1] == '\''))) {
        idStr result;
        for (std::size_t index = 1; index + 1 < length; ++index) {
            result.Append(text[index]);
        }
        return result;
    }
    return idStr(text);
}

idStr FileBase(const char* path) {
    const char* start = path == nullptr ? "" : path;
    for (const char* cursor = start; *cursor != '\0'; ++cursor) {
        if (*cursor == '/' || *cursor == '\\') {
            start = cursor + 1;
        }
    }
    idStr result(start);
    result.StripFileExtension();
    return result;
}

bool HasFileExtension(const char* path) {
    if (path == nullptr) {
        return false;
    }
    for (const char* cursor = path + std::strlen(path); cursor != path;) {
        --cursor;
        if (*cursor == '.') return true;
        if (*cursor == '/' || *cursor == '\\') return false;
    }
    return false;
}

void LowerCase(idStr& text) {
    idStr lowered;
    for (const char* cursor = text.c_str(); *cursor != '\0'; ++cursor) {
        lowered.Append(static_cast<char>(
            std::tolower(static_cast<unsigned char>(*cursor))));
    }
    text = lowered;
}

void EnsureExtension(idStr& path, const char* extension) {
    if (!HasFileExtension(path.c_str())) {
        path.SetFileExtension(extension);
    }
}

unsigned int PackEditorColor(float red, float green, float blue) {
    const auto byte = [](float value) -> unsigned int {
        value = (std::max)(0.0f, (std::min)(1.0f, value));
        return static_cast<unsigned int>(value * 255.0f + 0.5f);
    };
    return byte(red) | (byte(green) << 8) | (byte(blue) << 16);
}

const char* StateToken(unsigned int state) {
    return state < 3 ? groupStateTokens[state] : groupStateTokens[0];
}

bool ParseStateToken(const char* token, unsigned int& state) {
    for (unsigned int index = 0; groupStateTokens[index] != nullptr;
         ++index) {
        if (idStr::Icmp(token, groupStateTokens[index]) == 0) {
            state = index;
            return true;
        }
    }
    return false;
}

void ClearMapEntities(idMapFile& mapFile) {
    if (!mapFile.entitiesAreReference) {
        DeletePointerList(mapFile.entities);
    } else {
        mapFile.entities.Clear();
    }
    mapFile.entitiesAreReference = false;
}

idFile* OpenMapWriteFile(const char* path, bool osPath) {
    if (osPath) {
        idFile_Permanent* file = new idFile_Permanent(path, path,
            FS_WRITE, true);
        if (file->IsOpen()) {
            return file;
        }
        delete file;
        return nullptr;
    }
    return fileSystem == nullptr ? nullptr
        : fileSystem->OpenFileWrite(path, FSPATH_BASE);
}

} // namespace

idMapGroups::~idMapGroups() = default;

void idMapGroups::WriteGroups(idFile* const file,
        const char* const tabs) const {
    if (file == nullptr || groupList.IsEmpty()) {
        return;
    }
    const char* const indentation = tabs == nullptr ? "" : tabs;
    file->WriteFloatString("%sgroups {\n", indentation);
    for (int index = 0; index < groupList.Num(); ++index) {
        file->WriteFloatString("%s\t\"%s\"\n", indentation,
            groupList[index].c_str());
    }
    file->WriteFloatString("%s}\n", indentation);
}

void idMapGroups::RenameReferenceGroups(const char* const referenceName) {
    for (int index = 0; index < groupList.Num(); ++index) {
        idStr renamed;
        renamed.Format("$%s/%s", referenceName == nullptr ? "" : referenceName,
            groupList[index].c_str());
        groupList[index] = renamed;
    }
}

idStr idMapGroups::RemoveLeadingReferencePaths() {
    idStr referenceName;
    for (int index = 0; index < groupList.Num(); ++index) {
        const char* const group = groupList[index].c_str();
        if (std::strstr(group, "$func_reference") != group) {
            continue;
        }
        const char* const slash = std::strchr(group, '/');
        if (slash == nullptr || slash == group) {
            continue;
        }
        if (referenceName.Length() == 0) {
            for (const char* cursor = group + 1; cursor != slash; ++cursor) {
                referenceName.Append(*cursor);
            }
        }
        groupList[index] = slash + 1;
    }
    return referenceName;
}

void idMapGroups::ParseGroups(idLexer& lexer,
        idList<idStr, TAG_IDLIB>& groups) {
    if (!lexer.CheckTokenString("groups")) {
        return;
    }
    if (!lexer.ExpectTokenString("{")) {
        return;
    }
    idToken token;
    while (lexer.ReadToken(token) && idStr::Cmp(token.c_str(), "}") != 0) {
        if (token.type == TT_STRING && groups.FindIndex(token) < 0) {
            groups.Append(token);
        }
    }
}

idMapPrimitive::idMapPrimitive()
    : type(MAP_PRIMITIVE_REFERENCE) {
}

idMapPrimitive::~idMapPrimitive() = default;

unsigned int idMapPrimitive::GetGeometryCRC() const {
    return 0;
}

void idMapPrimitive::Transform(const idVec3&, const idMat3&) {
}

bool idMapPrimitive::Write(idFile*, int) const {
    return false;
}

idMapModel::idMapModel() = default;

idMapModel::~idMapModel() {
    DeletePointerList(primitives);
}

void idMapModel::TransformPrimitives(const idVec3& origin,
        const idMat3& axis) {
    for (int index = 0; index < primitives.Num(); ++index) {
        if (primitives[index] != nullptr) {
            primitives[index]->Transform(origin, axis);
        }
    }
}

idMapBrushSide::idMapBrushSide()
    : plane(0.0f, 0.0f, 0.0f, 0.0f),
      texMat{idVec3(0.0f, 0.0f, 0.0f), idVec3(0.0f, 0.0f, 0.0f)},
      origin(0.0f, 0.0f, 0.0f) {
}

const idPlane& idMapBrushSide::GetPlane() const {
    return plane;
}

idMapBrush::idMapBrush() {
    type = MAP_PRIMITIVE_BRUSH;
    sides.PreAllocate(8);
}

idMapBrush::~idMapBrush() {
    DeletePointerList(sides);
}

unsigned int idMapBrush::GetGeometryCRC() const {
    unsigned int result = 0;
    for (int index = 0; index < sides.Num(); ++index) {
        const idMapBrushSide* const side = sides[index];
        if (side == nullptr) {
            continue;
        }
        result ^= FloatBits(side->plane.a) ^ FloatBits(side->plane.b)
            ^ FloatBits(side->plane.c) ^ FloatBits(side->plane.d)
            ^ MapStringHash(side->material.c_str());
    }
    return result;
}

void idMapBrush::Transform(const idVec3& origin, const idMat3& axis) {
    for (int index = 0; index < sides.Num(); ++index) {
        idMapBrushSide* const side = sides[index];
        if (side == nullptr) {
            continue;
        }
        const idVec3 normal = TransformVector(side->plane.Normal(), axis);
        side->plane.a = normal.x;
        side->plane.b = normal.y;
        side->plane.c = normal.z;
        side->plane.d -= origin.Dot(normal);
    }
}

bool idMapBrush::Write(idFile* const file, const int primitiveNumber) const {
    if (file == nullptr) {
        return false;
    }
    file->WriteFloatString("\t// primitive %d\n\t{\n", primitiveNumber);
    WriteGroups(file, "\t\t");
    file->WriteFloatString("\t\tbrushDef3 {\n");
    for (int index = 0; index < sides.Num(); ++index) {
        const idMapBrushSide* const side = sides[index];
        if (side == nullptr) {
            continue;
        }
        file->WriteFloatString(
            "\t\t\t( %.9g %.9g %.9g %.9g ) ",
            side->plane.a, side->plane.b, side->plane.c, side->plane.d);
        file->WriteFloatString(
            "( ( %.9g %.9g %.9g ) ( %.9g %.9g %.9g ) ) \"%s\" 0 0 0\n",
            side->texMat[0].x, side->texMat[0].y, side->texMat[0].z,
            side->texMat[1].x, side->texMat[1].y, side->texMat[1].z,
            side->material.c_str());
    }
    file->WriteFloatString("\t\t}\n\t}\n");
    return true;
}

idMapPatch::idMapPatch(const int maxPatchWidth, const int maxPatchHeight)
    : origin(0.0f, 0.0f, 0.0f), horzSubdivisions(0),
      vertSubdivisions(0), explicitSubdivisions(false) {
    type = MAP_PRIMITIVE_PATCH;
    maxWidth = (std::max)(0, maxPatchWidth);
    maxHeight = (std::max)(0, maxPatchHeight);
    width = 0;
    height = 0;
    expanded = false;
    if (maxWidth > 0 && maxHeight > 0) {
        verts.PreAllocate(maxWidth * maxHeight);
    }
}

idMapPatch::~idMapPatch() = default;

int idMapPatch::GetHorzSubdivisions() const {
    return horzSubdivisions;
}

bool idMapPatch::GetExplicitlySubdivided() const {
    return explicitSubdivisions;
}

unsigned int idMapPatch::GetGeometryCRC() const {
    unsigned int result = static_cast<unsigned int>(horzSubdivisions)
        ^ static_cast<unsigned int>(vertSubdivisions);
    for (int column = 0; column < width; ++column) {
        for (int row = 0; row < height; ++row) {
            const idDrawVert& vertex = verts[row * width + column];
            result ^= FloatBits(vertex.xyz.x) ^ FloatBits(vertex.xyz.y)
                ^ FloatBits(vertex.xyz.z);
        }
    }
    return result ^ MapStringHash(material.c_str());
}

void idMapPatch::Transform(const idVec3& transformOrigin,
        const idMat3& axis) {
    RotateSelf(axis);
    TranslateSelf(transformOrigin);
}

bool idMapPatch::Write(idFile* const file,
        const int primitiveNumber) const {
    if (file == nullptr) {
        return false;
    }
    file->WriteFloatString("\t// primitive %d\n\t{\n", primitiveNumber);
    WriteGroups(file, "\t\t");
    file->WriteFloatString(explicitSubdivisions
        ? "\t\tpatchDef3 {\n" : "\t\tpatchDef2 {\n");
    file->WriteFloatString("\t\t\t\"%s\"\n", material.c_str());
    if (explicitSubdivisions) {
        file->WriteFloatString("\t\t\t( %d %d %d %d 0 0 0 )\n",
            width, height, horzSubdivisions, vertSubdivisions);
    } else {
        file->WriteFloatString("\t\t\t( %d %d 0 0 0 )\n", width, height);
    }
    file->WriteFloatString("\t\t\t(\n");
    for (int column = 0; column < width; ++column) {
        file->WriteFloatString("\t\t\t\t(");
        for (int row = 0; row < height; ++row) {
            const idDrawVert& vertex = verts[row * width + column];
            file->WriteFloatString(" ( %.9g %.9g %.9g %.9g %.9g )",
                vertex.xyz.x, vertex.xyz.y, vertex.xyz.z,
                vertex.st.x, vertex.st.y);
        }
        file->WriteFloatString(" )\n");
    }
    file->WriteFloatString("\t\t\t)\n\t\t}\n\t}\n");
    return true;
}

idMapBrush* idMapBrush::Parse(idLexer& lexer, const idVec3& origin,
        const bool newFormat, const int version) {
    if (!lexer.ExpectTokenString("{")) {
        return nullptr;
    }

    idList<idMapBrushSide*, TAG_IDLIB> parsedSides;
    idToken token;
    if (!lexer.ReadToken(token)) {
        lexer.Error("idMapBrush::Parse: unexpected EOF");
        return nullptr;
    }

    while (idStr::Cmp(token.c_str(), "}") != 0) {
        // Older tools could place quoted epairs before the first plane. They
        // are not brush geometry, but the recovered parser accepts them.
        while (idStr::Cmp(token.c_str(), "(") != 0) {
            if (token.type != TT_STRING) {
                lexer.Error("idMapBrush::Parse: unexpected %s, expected ( or epair key string",
                    token.c_str());
                DeletePointerList(parsedSides);
                return nullptr;
            }
            idToken value;
            if (!lexer.ReadTokenOnLine(value) || value.type != TT_STRING
                || !lexer.ReadToken(token)) {
                lexer.Error("idMapBrush::Parse: expected epair value string not found");
                DeletePointerList(parsedSides);
                return nullptr;
            }
        }

        lexer.UnreadToken();
        std::unique_ptr<idMapBrushSide> side(new idMapBrushSide());
        if (newFormat) {
            if (!lexer.Parse1DMatrix(4, side->plane.ToFloatPtr())) {
                lexer.Error("idMapBrush::Parse: unable to read brush side plane definition");
                DeletePointerList(parsedSides);
                return nullptr;
            }
        } else {
            idVec3 points[3];
            if (!lexer.Parse1DMatrix(3, &points[0].x)
                || !lexer.Parse1DMatrix(3, &points[1].x)
                || !lexer.Parse1DMatrix(3, &points[2].x)) {
                lexer.Error("idMapBrush::Parse: unable to read brush side plane definition");
                DeletePointerList(parsedSides);
                return nullptr;
            }
            for (idVec3& point : points) {
                point = point - origin;
            }
            side->plane = PlaneFromPoints(points[0], points[1], points[2]);
        }

        if (!lexer.Parse2DMatrix(2, 3, &side->texMat[0].x)) {
            lexer.Error("idMapBrush::Parse: unable to read brush side texture matrix");
            DeletePointerList(parsedSides);
            return nullptr;
        }
        side->origin = origin;
        if (!lexer.ReadTokenOnLine(token)) {
            lexer.Error("idMapBrush::Parse: unable to read brush side material");
            DeletePointerList(parsedSides);
            return nullptr;
        }
        if (version >= 2) {
            side->material = token.c_str();
        } else {
            side->material = "textures/";
            side->material.Append(token.c_str());
        }
        // The recovered format carries three obsolete integer flags after
        // each material. Consume them when present without crossing lines.
        for (int ignored = 0; ignored < 3; ++ignored) {
            idToken unused;
            if (!lexer.ReadTokenOnLine(unused)) {
                break;
            }
        }
        parsedSides.Append(side.release());

        if (!lexer.ReadToken(token)) {
            lexer.Error("idMapBrush::Parse: unexpected EOF");
            DeletePointerList(parsedSides);
            return nullptr;
        }
    }

    if (!lexer.ExpectTokenString("}")) {
        DeletePointerList(parsedSides);
        return nullptr;
    }
    std::unique_ptr<idMapBrush> brush(new idMapBrush());
    for (int index = 0; index < parsedSides.Num(); ++index) {
        brush->sides.Append(parsedSides[index]);
    }
    parsedSides.Clear();
    return brush.release();
}

idMapBrush* idMapBrush::ParseQ3(idLexer& lexer, const idVec3& origin) {
    std::unique_ptr<idMapBrush> brush(new idMapBrush());
    while (!lexer.CheckTokenString("}")) {
        std::unique_ptr<idMapBrushSide> side(new idMapBrushSide());
        idVec3 points[3];
        if (!lexer.Parse1DMatrix(3, &points[0].x)
            || !lexer.Parse1DMatrix(3, &points[1].x)
            || !lexer.Parse1DMatrix(3, &points[2].x)) {
            lexer.Error("idMapBrush::ParseQ3: unable to read brush side plane definition");
            return nullptr;
        }
        for (idVec3& point : points) {
            point = point - origin;
        }
        side->plane = PlaneFromPoints(points[0], points[1], points[2]);

        idToken materialToken;
        if (!lexer.ReadTokenOnLine(materialToken)) {
            lexer.Error("idMapBrush::ParseQ3: unable to read brush side material");
            return nullptr;
        }
        side->material = "textures/";
        side->material.Append(materialToken.c_str());
        side->texMat[0].Set(0.03125f, 0.0f, 0.0f);
        side->texMat[1].Set(0.0f, 0.03125f, 0.0f);
        side->origin = origin;
        lexer.SkipRestOfLine();
        brush->sides.Append(side.release());
    }
    return brush.release();
}

idMapPatch* idMapPatch::Parse(idLexer& lexer, const idVec3& origin,
        const bool patchDef3, const int version) {
    if (!lexer.ExpectTokenString("{")) {
        return nullptr;
    }

    idToken materialToken;
    if (!lexer.ReadToken(materialToken)) {
        lexer.Error("idMapPatch::Parse: unexpected EOF");
        return nullptr;
    }

    float patchInfo[7] = {};
    const int infoCount = patchDef3 ? 7 : 5;
    if (!lexer.Parse1DMatrix(infoCount, patchInfo)) {
        lexer.Error("idMapPatch::Parse: unable to parse patch definition info");
        return nullptr;
    }

    const int patchWidth = static_cast<int>(patchInfo[0]);
    const int patchHeight = static_cast<int>(patchInfo[1]);
    if (patchWidth < 1 || patchHeight < 1) {
        lexer.Error("idMapPatch::Parse: bad size");
        return nullptr;
    }

    std::unique_ptr<idMapPatch> patch(
        new idMapPatch(patchWidth, patchHeight));
    patch->SetSize(patchWidth, patchHeight);
    patch->origin = origin;
    if (version >= 2) {
        patch->material = materialToken.c_str();
    } else {
        patch->material = "textures/";
        patch->material.Append(materialToken.c_str());
    }
    if (patchDef3) {
        patch->horzSubdivisions = static_cast<int>(patchInfo[2]);
        patch->vertSubdivisions = static_cast<int>(patchInfo[3]);
        patch->explicitSubdivisions = true;
    }

    if (!lexer.ExpectTokenString("(")) {
        lexer.Error("idMapPatch::Parse: bad patch vertex data");
        return nullptr;
    }
    float vertexData[5];
    for (int column = 0; column < patchWidth; ++column) {
        if (!lexer.ExpectTokenString("(")) {
            lexer.Error("idMapPatch::Parse: bad vertex row data");
            return nullptr;
        }
        for (int row = 0; row < patchHeight; ++row) {
            if (!lexer.Parse1DMatrix(5, vertexData)) {
                lexer.Error("idMapPatch::Parse: bad vertex column data");
                return nullptr;
            }
            idDrawVert& vertex = patch->verts[row * patchWidth + column];
            vertex.xyz.Set(vertexData[0] - origin.x,
                vertexData[1] - origin.y, vertexData[2] - origin.z);
            vertex.st.Set(vertexData[3], vertexData[4]);
        }
        if (!lexer.ExpectTokenString(")")) {
            lexer.Error("idMapPatch::Parse: unable to parse patch control points");
            return nullptr;
        }
    }
    if (!lexer.ExpectTokenString(")")) {
        lexer.Error("idMapPatch::Parse: patch control points have no closure");
        return nullptr;
    }

    idToken token;
    while (lexer.ReadToken(token) && idStr::Cmp(token.c_str(), "}") != 0) {
        if (token.type == TT_STRING) {
            idToken value;
            lexer.ExpectTokenType(TT_STRING, 0, value);
        }
    }
    if (!lexer.ExpectTokenString("}")) {
        return nullptr;
    }
    return patch.release();
}

bool idGroupState::operator==(const idGroupState& other) const {
    return idStr::Icmp(groupName.c_str(), other.groupName.c_str()) == 0;
}

idMapEditorStates::idMapEditorStates() = default;

idMapEditorStates::~idMapEditorStates() = default;

void idMapEditorStates::Parse(idLexer& lexer) {
    const auto parseStates = [&lexer](const char* sectionName,
            idList<idGroupState, TAG_IDLIB>& destination) {
        if (!lexer.CheckTokenString(sectionName)
            || !lexer.ExpectTokenString("{")) {
            return;
        }
        idToken nameToken;
        idToken stateToken;
        while (lexer.ReadToken(nameToken)
            && idStr::Cmp(nameToken.c_str(), "}") != 0) {
            if (nameToken.type != TT_STRING
                || !lexer.ExpectTokenType(TT_STRING, 0, stateToken)) {
                break;
            }
            idGroupState state;
            state.groupName = nameToken.c_str();
            if (ParseStateToken(stateToken.c_str(), state.state)) {
                destination.AddUnique(state);
            }
        }
    };

    if (lexer.PeekTokenString("groupstates")) {
        parseStates("groupstates", groupStates);
    }
    if (lexer.PeekTokenString("layerstates")) {
        parseStates("layerstates", layerStates);
    }
    if (lexer.PeekTokenString("groupcolors")
        && lexer.CheckTokenString("groupcolors")
        && lexer.ExpectTokenString("{")) {
        idToken nameToken;
        while (lexer.ReadToken(nameToken)
            && idStr::Cmp(nameToken.c_str(), "}") != 0) {
            if (nameToken.type != TT_STRING) {
                break;
            }
            const float red = lexer.ParseFloat();
            const float green = lexer.ParseFloat();
            const float blue = lexer.ParseFloat();
            lexer.ParseFloat(); // Alpha is always written as one.
            idGroupState color;
            color.groupName = nameToken.c_str();
            color.state = PackEditorColor(red, green, blue);
            groupColors.AddUnique(color);
        }
    }
}

void idMapEditorStates::Write(idFile* const file) const {
    if (file == nullptr) {
        return;
    }
    if (!groupStates.IsEmpty()) {
        file->WriteFloatString("groupstates {\n");
        for (int index = 0; index < groupStates.Num(); ++index) {
            file->WriteFloatString("\t\"%s\" \"%s\"\n",
                groupStates[index].groupName.c_str(),
                StateToken(groupStates[index].state));
        }
        file->WriteFloatString("}\n");
    }
    // The authoritative Write routine intentionally does not serialize
    // layerStates, although Parse accepts them.
    if (!groupColors.IsEmpty()) {
        file->WriteFloatString("groupcolors {\n");
        for (int index = 0; index < groupColors.Num(); ++index) {
            const unsigned int color = groupColors[index].state;
            file->WriteFloatString("\t\"%s\" %.3f %.3f %.3f %.3f\n",
                groupColors[index].groupName.c_str(),
                static_cast<float>(color & 0xFFu) / 255.0f,
                static_cast<float>((color >> 8) & 0xFFu) / 255.0f,
                static_cast<float>((color >> 16) & 0xFFu) / 255.0f,
                1.0f);
        }
        file->WriteFloatString("}\n");
    }
}

idRefMapDef::idRefMapDef(const char* const name,
        const char* const entityText)
    : mapName(name), worldSpawnText(entityText) {
}

bool idRefMapDef::operator==(const idRefMapDef& other) const {
    return idStr::Icmp(mapName.c_str(), other.mapName.c_str()) == 0;
}

idMapEntity::idMapEntity()
    : entityDef(nullptr), parentReference(nullptr) {
}

idMapEntity::~idMapEntity() {
    delete entityDef;
}

void idMapEntity::SetEntityDef(idDeclEntityDef* const definition) {
    if (entityDef == definition) {
        return;
    }
    delete entityDef;
    entityDef = definition;
}

void idMapEntity::ClearLayerList() {
    layerList.ClearFree();
}

void idMapEntity::Transform(const idVec3& origin, const idMat3& axis) {
    if (entityDef == nullptr) {
        return;
    }
    if (idStr::Icmp(entityDef->GetClass(), "idWorldSpawn") == 0) {
        model.TransformPrimitives(origin, axis);
        return;
    }

    const char* const stateText = entityDef->GetEntityStateWithInheritance();
    idTypeInfoTree tree(stateText,
        entityDef->GetEntityStateWithInheritanceLength());
    idVec3 spawnPosition(0.0f, 0.0f, 0.0f);
    idMat3 spawnOrientation(1.0f);
    tree.GetVec3("spawnPosition", spawnPosition);
    tree.GetMat3("spawnOrientation", spawnOrientation);
    spawnPosition = origin + TransformVector(spawnPosition, axis);
    spawnOrientation *= axis;
    tree.SetVec3("spawnPosition", spawnPosition);
    tree.SetMat3("spawnOrientation", spawnOrientation);
    entityDef->SetEntityState(tree, true, false);
}

void idMapEntity::FixMapModelNames(const char* const mapName,
        const char* const entityName) {
    if (entityDef == nullptr) {
        return;
    }
    idTypeInfoTree tree(entityDef->GetEntityStateWithInheritance(),
        entityDef->GetEntityStateWithInheritanceLength());
    idStr modelName;
    if (!tree.GetStrType("renderModelInfo.model", modelName)
        || modelName.Length() == 0
        || !(StartsWithNoCase(modelName.c_str(), "maps/")
            || StartsWithNoCase(modelName.c_str(), "prefabs/"))
        || HasFileExtension(modelName.c_str())) {
        return;
    }

    const idStr base = FileBase(modelName.c_str());
    if (!EndsWithNoCase(entityName, base.c_str())) {
        return;
    }
    bool changed = false;
    const idStr recoveredName = idMapFile::GetMapModelName(mapName,
        entityName);
    if (idStr::Cmp(modelName.c_str(), recoveredName.c_str()) != 0) {
        tree.SetStrType("renderModelInfo.model", recoveredName.c_str());
        changed = true;
    }

    idStr clipType;
    if (tree.GetStrType("clipModelInfo.type", clipType)
        && idStr::Cmp(clipType.c_str(), "CLIPMODEL_CUSTOM") != 0
        && idStr::Cmp(clipType.c_str(), "CLIPMODEL_NONE") != 0) {
        idStr oldClipName;
        tree.GetStrType("clipModelInfo.clipModelName", oldClipName);
        if (idStr::Cmp(oldClipName.c_str(), recoveredName.c_str()) != 0) {
            tree.SetStrType("clipModelInfo.clipModelName",
                recoveredName.c_str());
            changed = true;
        }
    }
    if (changed) {
        entityDef->SetEntityState(tree, true, false);
    }
}

void idMapEntity::FixTargetNames(const char* const baseName) {
    if (entityDef == nullptr) {
        return;
    }
    idTypeInfoTree tree(entityDef->GetEntityStateWithInheritance(),
        entityDef->GetEntityStateWithInheritanceLength());
    idTypeInfoNodeList<idTypeInfoNode*> nodes;
    tree.GetTypes("idEntity", "*", nodes);
    tree.GetTypes("idEntityPtr", "*", nodes);
    for (int index = 0; index < nodes.Num(); ++index) {
        idTypeInfoNode* const node = nodes[index];
        if (node == nullptr) {
            continue;
        }
        const idStr target = Unquote(node->value.c_str());
        if (target.Length() == 0) {
            continue;
        }
        idStr renamed;
        renamed.Format("%s_%s", baseName == nullptr ? "" : baseName,
            target.c_str());
        node->value = Quote(renamed.c_str());
    }
    entityDef->SetEntityState(tree, true, false);
}

bool idMapEntity::Write(idFile* const file, idGame* const writeGame,
        const int entityNumber,
        const mapPrimitiveFilter_t shouldWritePrimitive,
        const bool entitiesFile) const {
    (void)entityNumber;
    if (file == nullptr || entityDef == nullptr) {
        return false;
    }
    file->WriteFloatString("entity {\n");
    if (!entitiesFile) {
        WriteGroups(file, "\t");
    }
    if (!layerList.IsEmpty()) {
        file->WriteFloatString("\tlayers {\n");
        for (int index = 0; index < layerList.Num(); ++index) {
            file->WriteFloatString("\t\t\"%s\"\n",
                layerList[index].c_str());
        }
        file->WriteFloatString("\t}\n");
    }

    entityDef->SetInheritedClass(false);
    const char* const text = entityDef->GetText();
    file->Printf("\tentityDef %s ", entityDef->GetName());
    if (text != nullptr) {
        file->Write(text, static_cast<unsigned int>(std::strlen(text)));
    }
    file->Write("\n", 1);
    for (int index = 0; index < model.primitives.Num(); ++index) {
        idMapPrimitive* const primitive = model.primitives[index];
        if (primitive != nullptr
            && (shouldWritePrimitive == nullptr
                || shouldWritePrimitive(primitive, writeGame))) {
            primitive->Write(file, index);
        }
    }
    file->WriteFloatString("}\n");
    return true;
}

idMapReference::idMapReference()
    : map(nullptr) {
    type = MAP_PRIMITIVE_REFERENCE;
}

idMapReference::~idMapReference() {
    delete map;
}

unsigned int idMapReference::GetGeometryCRC() const {
    return MapStringHash(mapName.c_str());
}

bool idMapReference::Write(idFile* const file,
        const int referenceNumber) const {
    if (file == nullptr) {
        return false;
    }
    file->WriteFloatString("\t// reference %d\n\t{\n", referenceNumber);
    WriteGroups(file, "\t\t");
    file->WriteFloatString("\t\treference {\n");
    file->WriteFloatString("\t\t\t\"%s\"\n", mapName.c_str());
    file->WriteFloatString("\t\t}\n\t}\n");
    return true;
}

idMapReference* idMapReference::Parse(idLexer& lexer, const int version,
        const bool expandReferences, idMapEntity* const parent) {
    (void)version;
    if (!lexer.ExpectTokenString("{")) {
        return nullptr;
    }
    idToken fileNameToken;
    if (!lexer.ExpectTokenType(TT_STRING, 0, fileNameToken)) {
        lexer.Error("idMapReference::Parse: expected map file name not found");
        return nullptr;
    }

    std::unique_ptr<idMapReference> reference(new idMapReference());
    reference->mapName = fileNameToken.c_str();
    if (expandReferences) {
        reference->map = new idMapFile();
        if (!reference->map->Parse(reference->mapName.c_str(), false,
                parent)) {
            return nullptr;
        }
    }
    if (!lexer.ExpectTokenString("}")
        || !lexer.ExpectTokenString("}")) {
        return nullptr;
    }
    return reference.release();
}

void idMapReference::ExpandReference(idMapFile* const destination,
        idMapEntity* const mapEntity) {
    if (map == nullptr || destination == nullptr || mapEntity == nullptr
        || mapEntity->entityDef == nullptr || destination->entities.IsEmpty()) {
        return;
    }

    const idStr referenceName(mapEntity->entityDef->GetName());
    bool zeroTransform = false;
    idVec3 spawnPosition(0.0f, 0.0f, 0.0f);
    idMat3 spawnOrientation(1.0f);
    idTypeInfoTree referenceState(
        mapEntity->entityDef->GetEntityStateWithInheritance(),
        mapEntity->entityDef->GetEntityStateWithInheritanceLength());
    referenceState.GetBool("zeroTransform", zeroTransform);
    const bool renameEntities = !zeroTransform;
    if (!zeroTransform) {
        referenceState.GetVec3("spawnPosition", spawnPosition);
        referenceState.GetMat3("spawnOrientation", spawnOrientation);
    }

    idMapEntity* const destinationWorld = destination->entities[0];
    int index = 0;
    while (index < map->entities.Num()) {
        idMapEntity* const entity = map->entities[index];
        if (entity == nullptr || entity->entityDef == nullptr) {
            ++index;
            continue;
        }
        if (entity->refId.Length() == 0) {
            entity->refId = map->name;
        }
        if (!zeroTransform) {
            entity->Transform(spawnPosition, spawnOrientation);
        }

        if (renameEntities) {
            idStr renamed;
            renamed.Format("%s_%s", referenceName.c_str(),
                entity->entityDef->GetName());
            entity->entityDef->SetName(renamed.c_str());
            entity->FixMapModelNames(map->name.c_str(), renamed.c_str());
            entity->FixTargetNames(referenceName.c_str());
        }
        entity->RenameReferenceGroups(referenceName.c_str());
        for (int primitiveIndex = 0;
             primitiveIndex < entity->model.primitives.Num();
             ++primitiveIndex) {
            if (entity->model.primitives[primitiveIndex] != nullptr) {
                entity->model.primitives[primitiveIndex]
                    ->RenameReferenceGroups(referenceName.c_str());
            }
        }

        if (idStr::Icmp(entity->entityDef->GetClass(), "idWorldSpawn") != 0) {
            destination->entities.Append(entity);
            map->entities.RemoveIndex(index);
            continue;
        }

        if (destinationWorld != nullptr) {
            for (int primitiveIndex = 0;
                 primitiveIndex < entity->model.primitives.Num();
                 ++primitiveIndex) {
                destinationWorld->model.primitives.Append(
                    entity->model.primitives[primitiveIndex]);
            }
            entity->model.primitives.Clear();
        }
        const char* const text = entity->entityDef->GetText();
        worldSpawnText = text == nullptr ? "" : text;
        ++index;
    }

    AppendList(destination->referenceMaps, map->referenceMaps);
}

idMapEntity* idMapEntity::Parse(idMapFile* const mapFile,
        idLexer& lexer, const int version, idMapEntity* const parent) {
    idToken token;
    if (!lexer.ReadToken(token)
        || idStr::Cmp(token.c_str(), "{") != 0) {
        lexer.Error("idMapEntity::Parse: { not found");
        return nullptr;
    }

    std::unique_ptr<idMapEntity> entity(new idMapEntity());
    entity->parentReference = parent;
    idVec3 oldOrigin(0.0f, 0.0f, 0.0f);
    idVec3 spawnPosition(0.0f, 0.0f, 0.0f);
    bool oldWorldSpawn = false;
    bool useSpawnPositionForBrushes = false;

    if (!lexer.ReadToken(token)) {
        lexer.Error("idMapEntity::Parse: EOF without closing brace");
        return nullptr;
    }
    while (idStr::Cmp(token.c_str(), "}") != 0) {
        idList<idStr, TAG_IDLIB> primitiveGroups;

        if (idStr::Cmp(token.c_str(), "groups") == 0) {
            lexer.UnreadToken();
            ParseGroups(lexer, primitiveGroups);
            if (!lexer.ReadToken(token)) {
                lexer.Error("idMapEntity::Parse: unexpected EOF");
                return nullptr;
            }
        }

        if (idStr::Cmp(token.c_str(), "layers") == 0) {
            if (!lexer.ExpectTokenString("{")) {
                return nullptr;
            }
            while (lexer.ReadToken(token)
                && idStr::Cmp(token.c_str(), "}") != 0) {
                if (token.type == TT_STRING
                    && entity->layerList.FindIndex(token) < 0) {
                    entity->layerList.Append(token);
                }
            }
            if (!lexer.ReadToken(token)) {
                lexer.Error("idMapEntity::Parse: unexpected EOF");
                return nullptr;
            }
        }

        if (idStr::Cmp(token.c_str(), "entityDef") == 0
            && entity->entityDef == nullptr) {
            idToken nameToken;
            idStr definitionText;
            if (!lexer.ReadToken(nameToken)
                || !lexer.ParseBracedSectionExact(definitionText, true)) {
                lexer.Error("idMapEntity::Parse: invalid entityDef");
                return nullptr;
            }
            AppendList(entity->groupList, primitiveGroups);
            std::unique_ptr<idDeclEntityDef> definition(
                new idDeclEntityDef());
            definition->SetName(nameToken.c_str());
            definition->SetText(definitionText.c_str());
            definition->ReParse(false);

            const char* const inheritName = definition->GetInherit();
            useSpawnPositionForBrushes =
                idStr::Icmp(inheritName, "func/static") == 0
                || ContainsNoCase(inheritName, "prop/moveable")
                || ContainsNoCase(inheritName, "func/mover")
                || ContainsNoCase(inheritName, "func/gui");
            idTypeInfoTree state(
                definition->GetEntityStateWithInheritance(),
                definition->GetEntityStateWithInheritanceLength());
            state.GetVec3("spawnPosition", spawnPosition);
            entity->entityDef = definition.release();
        } else if (idStr::Cmp(token.c_str(), "{") != 0) {
            // Version-one map epairs are retained only for origin/worldspawn
            // handling, exactly as in the recovered parser.
            const idStr key(token.c_str());
            idToken valueToken;
            if (!lexer.ReadTokenOnLine(valueToken)) {
                lexer.Error("idMapEntity::Parse: epair value not found");
                return nullptr;
            }
            if (idStr::Icmp(key.c_str(), "origin") == 0) {
                std::sscanf(valueToken.c_str(), "%f %f %f", &oldOrigin.x,
                    &oldOrigin.y, &oldOrigin.z);
            } else if (idStr::Icmp(key.c_str(), "classname") == 0
                && idStr::Icmp(valueToken.c_str(), "worldspawn") == 0) {
                oldWorldSpawn = true;
            }
        } else {
            ParseGroups(lexer, primitiveGroups);
            if (!lexer.ReadToken(token)) {
                lexer.Error("idMapEntity::Parse: unexpected EOF");
                return nullptr;
            }

            if (oldWorldSpawn || entity->entityDef != nullptr) {
                oldOrigin.Zero();
            }

            idMapPrimitive* primitive = nullptr;
            bool primitiveGroupsApplied = false;
            bool allowNullPrimitive = false;
            if (StartsWithNoCase(token.c_str(), "brush")) {
                const bool newFormat = idStr::Icmp(token.c_str(),
                    "brushDef2") == 0
                    || idStr::Icmp(token.c_str(), "brushDef3") == 0;
                const idVec3& brushOrigin = useSpawnPositionForBrushes
                    ? spawnPosition : oldOrigin;
                primitive = idMapBrush::Parse(lexer, brushOrigin,
                    newFormat, version);
            } else if (StartsWithNoCase(token.c_str(), "patch")) {
                primitive = idMapPatch::Parse(lexer, oldOrigin,
                    idStr::Icmp(token.c_str(), "patchDef3") == 0,
                    version);
            } else if (idStr::Icmp(token.c_str(), "reference") == 0) {
                idMapReference* const reference = idMapReference::Parse(
                    lexer, version, mapFile != nullptr
                        && mapFile->expandReferences, entity.get());
                if (reference != nullptr && mapFile != nullptr) {
                    AppendList(reference->groupList, primitiveGroups);
                    primitiveGroupsApplied = true;
                    if (mapFile->expandReferences) {
                        reference->ExpandReference(mapFile, entity.get());
                    }
                    mapFile->AddReferenceMap(reference->mapName.c_str(),
                        reference->worldSpawnText.c_str());
                    primitive = reference;
                } else if (reference == nullptr) {
                    allowNullPrimitive = true;
                    idLibPrint::Warning("Invalid map reference in entity '%s'",
                        entity->entityDef == nullptr ? "<unknown>"
                            : entity->entityDef->GetName());
                }
            } else if (StartsWithNoCase(token.c_str(), "splinemesh")
                || StartsWithNoCase(token.c_str(), "spline")) {
                allowNullPrimitive = true;
                lexer.SkipBracedSection(true);
                lexer.ExpectTokenString("}");
            } else {
                lexer.UnreadToken();
                primitive = idMapBrush::ParseQ3(lexer, oldOrigin);
            }

            if (primitive != nullptr) {
                if (!primitiveGroupsApplied) {
                    AppendList(primitive->groupList, primitiveGroups);
                }
                entity->model.primitives.Append(primitive);
            } else if (!allowNullPrimitive) {
                return nullptr;
            }
        }

        if (!lexer.ReadToken(token)) {
            lexer.Error("idMapEntity::Parse: EOF without closing brace");
            return nullptr;
        }
    }

    if (entity->entityDef == nullptr) {
        return nullptr;
    }
    entity->entityDef->SetInheritedClass(false);
    return entity.release();
}

idMapFile::idMapFile()
    : version(3), fileTime(0), geometryCRC(0), hasPrimitiveData(false),
      parentReference(nullptr), expandReferences(true), game(nullptr),
      entitiesAreReference(false), ignoreGroupInfo(false) {
    entities.PreAllocate(1024);
}

idMapFile::~idMapFile() {
    ClearMapEntities(*this);
}

idStr idMapFile::GetMapModelName(const char* const mapName,
        const char* const entityName) {
    idStr result;
    result.Format("%s/%s", mapName == nullptr ? "" : mapName,
        entityName == nullptr ? "" : entityName);
    return result;
}

idMapEntity* idMapFile::GetEntity(const int index) const {
    return index >= 0 && index < entities.Num() ? entities[index] : nullptr;
}

void idMapFile::SetGeometryCRC() {
    geometryCRC = 0;
    for (int entityIndex = 0; entityIndex < entities.Num(); ++entityIndex) {
        const idMapEntity* const entity = entities[entityIndex];
        if (entity == nullptr) {
            continue;
        }
        unsigned int entityCRC = 0;
        for (int primitiveIndex = 0;
             primitiveIndex < entity->model.primitives.Num();
             ++primitiveIndex) {
            const idMapPrimitive* const primitive =
                entity->model.primitives[primitiveIndex];
            if (primitive != nullptr) {
                entityCRC ^= primitive->GetGeometryCRC();
            }
        }
        geometryCRC ^= entityCRC;
    }
}

idMapEntity* idMapFile::FindEntity(const char* const entityName,
        int* const foundIndex) const {
    for (int index = 0; index < entities.Num(); ++index) {
        idMapEntity* const entity = entities[index];
        if (entity == nullptr || entity->entityDef == nullptr) {
            idLibPrint::Warning(
                "idMapFile::FindEntity - invalid entity at index %d", index);
            continue;
        }
        if (idStr::Icmp(entity->entityDef->GetName(), entityName) == 0) {
            if (foundIndex != nullptr) {
                *foundIndex = index;
            }
            return entity;
        }
    }
    return nullptr;
}

int idMapFile::FindReferenceMap(const char* const mapNameToFind) const {
    for (int index = 0; index < referenceMaps.Num(); ++index) {
        if (idStr::Icmp(referenceMaps[index].mapName.c_str(),
                mapNameToFind) == 0) {
            return index;
        }
    }
    return -1;
}

int idMapFile::AddEntity(idMapEntity* const mapEntity) {
    return entities.Append(mapEntity);
}

void idMapFile::RemoveEntity(idMapEntity* const mapEntity) {
    const int index = entities.FindIndex(mapEntity);
    if (index >= 0) {
        entities.RemoveIndex(index);
    }
    delete mapEntity;
}

void idMapFile::AddReferenceMap(const char* const referenceName,
        const char* const worldSpawnText) {
    referenceMaps.AddUnique(idRefMapDef(referenceName, worldSpawnText));
}

idStr idMapFile::CopyMapEntities(const idMapFile* const source,
        const char* const referenceId) {
    idStr leadingReference;
    if (source == nullptr) {
        return leadingReference;
    }
    for (int index = 0; index < source->entities.Num(); ++index) {
        idMapEntity* const entity = source->entities[index];
        if (entity == nullptr) {
            continue;
        }
        if (referenceId != nullptr
            && idStr::Icmp(entity->refId.c_str(), referenceId) != 0) {
            continue;
        }
        const idStr removed = entity->RemoveLeadingReferencePaths();
        if (leadingReference.Length() == 0) {
            leadingReference = removed;
        }
        entities.Append(entity);
    }
    entitiesAreReference = true;
    return leadingReference;
}

void idMapFile::ClearCopiedEntities(const idStr& referenceName) {
    if (referenceName.Length() != 0) {
        for (int index = 0; index < entities.Num(); ++index) {
            if (entities[index] != nullptr) {
                entities[index]->RenameReferenceGroups(
                    referenceName.c_str());
            }
        }
    }
    entities.ClearFree();
    entitiesAreReference = false;
}

void idMapFile::ConvertMapModelNames() {
    for (int index = 0; index < entities.Num(); ++index) {
        idMapEntity* const entity = entities[index];
        if (entity == nullptr || entity->entityDef == nullptr) {
            continue;
        }
        idDeclEntityDef* const definition = entity->entityDef;
        idTypeInfoTree tree(definition->GetEntityState(),
            definition->GetEntityStateLength());
        idStr modelName;
        if (tree.GetStrType("renderModelInfo.model", modelName)
            && idStr::Icmp(modelName.c_str(), definition->GetName()) == 0) {
            const idStr converted = GetMapModelName(name.c_str(),
                definition->GetName());
            tree.SetStrType("renderModelInfo.model", converted.c_str());
            definition->SetEntityState(tree, false, false);
        }
    }
}

void idMapFile::WriteInternal(idFile* const file,
        const bool entitiesFile,
        const mapEntityFilter_t shouldWriteEntity,
        const mapPrimitiveFilter_t shouldWritePrimitive) const {
    if (file == nullptr) {
        return;
    }
    file->WriteFloatString("Version %d\n", 3);
    for (int index = 0; index < entities.Num(); ++index) {
        idMapEntity* const entity = entities[index];
        if (entity != nullptr
            && (shouldWriteEntity == nullptr
                || shouldWriteEntity(this, entity, game))) {
            entity->Write(file, game, index, shouldWritePrimitive,
                entitiesFile);
        }
    }
    if (!entitiesFile) {
        groupStates.Write(file);
    }
}

bool idMapFile::WriteInternal(const char* const path, const bool osPath,
        const bool entitiesFile,
        const mapEntityFilter_t shouldWriteEntity,
        const mapPrimitiveFilter_t shouldWritePrimitive) const {
    idLibPrint::Printf("writing %s...\n", path == nullptr ? "" : path);
    std::unique_ptr<idFile> file(OpenMapWriteFile(path, osPath));
    if (!file) {
        idLibPrint::Warning("Couldn't open %s", path == nullptr ? "" : path);
        return false;
    }
    WriteInternal(file.get(), entitiesFile, shouldWriteEntity,
        shouldWritePrimitive);
    return true;
}

bool idMapFile::ParseSingle(idLexer& lexer) {
    version = 1;
    fileTime = lexer.fileTime;
    ClearMapEntities(*this);
    groupStates.groupStates.Clear();
    groupStates.layerStates.Clear();
    groupStates.groupColors.Clear();

    idToken token;
    if (lexer.CheckTokenString("Version")) {
        if (!lexer.ReadTokenOnLine(token)) {
            return false;
        }
        version = static_cast<int>(std::strtoul(token.c_str(), nullptr, 0));
    }

    while (lexer.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "entity") == 0
            || idStr::Cmp(token.c_str(), "{") == 0) {
            if (idStr::Cmp(token.c_str(), "{") == 0) {
                lexer.UnreadToken();
            } else {
                idToken optionalNumber;
                lexer.CheckTokenType(TT_NUMBER, 0, optionalNumber);
            }
            idMapEntity* const entity = idMapEntity::Parse(this, lexer,
                version, parentReference);
            if (entity == nullptr) {
                idLibPrint::Warning("Failed to parse entity!");
                return false;
            }
            entities.Append(entity);
        } else if (idStr::Cmp(token.c_str(), "groupstates") == 0
            || idStr::Cmp(token.c_str(), "groupcolors") == 0) {
            lexer.UnreadToken();
            groupStates.Parse(lexer);
        } else {
            break;
        }
    }

    SetGeometryCRC();
    for (int index = 0; index < entities.Num(); ++index) {
        idMapEntity* const entity = entities[index];
        if (entity == nullptr || entity->entityDef == nullptr) {
            continue;
        }
        entity->model.name = GetMapModelName(name.c_str(),
            entity->entityDef->GetName());
        if (expandReferences) {
            entity->FixMapModelNames(name.c_str(),
                entity->entityDef->GetName());
        }
    }
    if (version <= 2) {
        ConvertMapModelNames();
    }
    hasPrimitiveData = true;
    return true;
}

bool idMapFile::Parse(const char* const fileName, const bool osPath,
        idMapEntity* const parent) {
    if (fileName == nullptr || *fileName == '\0') {
        return false;
    }
    char relativePath[256] = {};
    const char* parseName = fileName;
    if (osPath && fileSystem != nullptr
        && fileSystem->OSPathToRelativePath(fileName, relativePath,
            sizeof(relativePath))) {
        parseName = relativePath;
    }
    name = parseName;
    name.MakeNameCanonical();
    name.StripFileExtension();
    parentReference = parent;
    hasPrimitiveData = false;

    idStr path(fileName);
    LowerCase(path);
    EnsureExtension(path, "map");
    idLexer lexer(LEXFL_NOSTRINGCONCAT | LEXFL_NOSTRINGESCAPECHARS
        | LEXFL_ALLOWPATHNAMES);
    if (!lexer.LoadFile(path.c_str(), osPath) || !ParseSingle(lexer)) {
        return false;
    }

    if (!EndsWithNoCase(path.c_str(), "entities")) {
        path.SetFileExtension("sound");
        idLexer soundLexer(LEXFL_NOSTRINGCONCAT
            | LEXFL_NOSTRINGESCAPECHARS | LEXFL_ALLOWPATHNAMES);
        if (soundLexer.LoadFile(path.c_str(), osPath)) {
            idMapFile soundMap;
            soundMap.name = name;
            soundMap.expandReferences = expandReferences;
            if (soundMap.ParseSingle(soundLexer)) {
                if (!soundMap.entities.IsEmpty() && !entities.IsEmpty()) {
                    idMapEntity* const soundWorld = soundMap.entities[0];
                    idMapEntity* const world = entities[0];
                    if (soundWorld != nullptr && world != nullptr) {
                        for (int primitiveIndex = 0;
                             primitiveIndex < soundWorld->model.primitives.Num();
                             ++primitiveIndex) {
                            world->model.primitives.Append(
                                soundWorld->model.primitives[primitiveIndex]);
                        }
                        soundWorld->model.primitives.Clear();
                    }
                }
                for (int index = 1; index < soundMap.entities.Num(); ++index) {
                    entities.Append(soundMap.entities[index]);
                    soundMap.entities[index] = nullptr;
                }
                if (!soundMap.entities.IsEmpty()) {
                    delete soundMap.entities[0];
                    soundMap.entities[0] = nullptr;
                }
                soundMap.entities.Clear();
            }
        }
    }
    return true;
}

bool idMapFile::Reload() {
    const idStr reloadName(name);
    ClearMapEntities(*this);
    hasPrimitiveData = false;
    if (!Parse(reloadName.c_str(), false, nullptr)) {
        fileTime = 0;
        return false;
    }
    return true;
}

bool idMapFile::Write(const char* const fileName, const bool osPath) {
    if (fileName == nullptr || *fileName == '\0') {
        return false;
    }
    if (name.Length() == 0) {
        char relativePath[256] = {};
        if (fileSystem != nullptr && fileSystem->OSPathToRelativePath(
                fileName, relativePath, sizeof(relativePath))) {
            name = relativePath;
        } else {
            name = fileName;
        }
        name.MakeNameCanonical();
        name.StripFileExtension();
    }

    idStr path(fileName);
    EnsureExtension(path, "map");
    if (!WriteInternal(path.c_str(), osPath, false, IsNotSoundEntity,
            IsNotSoundPrimitive)) {
        return false;
    }
    if (fileTime == 0 && fileSystem != nullptr && !osPath) {
        fileTime = fileSystem->GetTimestamp(path.c_str(), false);
    }
    path.SetFileExtension("sound");
    return WriteInternal(path.c_str(), osPath, false, IsSoundEntity,
        IsSoundPrimitive);
}

bool idMapFile::WriteSounds(const char* const fileName,
        const bool osPath) {
    if (fileName == nullptr || *fileName == '\0') {
        return false;
    }
    if (name.Length() == 0) {
        char relativePath[256] = {};
        if (fileSystem != nullptr && fileSystem->OSPathToRelativePath(
                fileName, relativePath, sizeof(relativePath))) {
            name = relativePath;
        } else {
            name = fileName;
        }
        name.MakeNameCanonical();
        name.StripFileExtension();
    }
    idStr path(fileName);
    path.SetFileExtension("sound");
    return WriteInternal(path.c_str(), osPath, false, IsSoundEntity,
        IsSoundPrimitive);
}

bool idMapFile::WriteEntities(const char* const fileName,
        const bool osPath) {
    if (fileName == nullptr || *fileName == '\0') {
        return false;
    }
    if (name.Length() == 0) {
        char relativePath[256] = {};
        if (fileSystem != nullptr && fileSystem->OSPathToRelativePath(
                fileName, relativePath, sizeof(relativePath))) {
            name = relativePath;
        } else {
            name = fileName;
        }
        name.MakeNameCanonical();
        name.StripFileExtension();
    }
    idStr path(fileName);
    EnsureExtension(path, "entities");
    ignoreGroupInfo = true;
    const bool written = WriteInternal(path.c_str(), osPath, true,
        IsProductionEntity, WriteAllMapPrimitives);
    ignoreGroupInfo = false;
    if (written && fileTime == 0 && fileSystem != nullptr && !osPath) {
        fileTime = fileSystem->GetTimestamp(path.c_str(), false);
    }
    return written;
}

bool IsSoundEntity(const idMapFile*, idMapEntity* const entity, idGame*) {
    if (entity == nullptr || entity->entityDef == nullptr) {
        return false;
    }
    const char* const className = entity->entityDef->GetClass();
    return idStr::Icmp(className, "idWorldspawn") == 0
        || StartsWithNoCase(className, "idSound");
}

bool IsNotSoundEntity(const idMapFile* const mapFile,
        idMapEntity* const entity, idGame* const filterGame) {
    if (entity == nullptr || entity->entityDef == nullptr) {
        return false;
    }
    return idStr::Icmp(entity->entityDef->GetClass(), "idWorldspawn") == 0
        || !IsSoundEntity(mapFile, entity, filterGame);
}

bool IsSoundPrimitive(idMapPrimitive* const primitive, idGame*) {
    if (primitive == nullptr || primitive->type != MAP_PRIMITIVE_BRUSH
        || materialToolsFlagsResolver == nullptr) {
        return false;
    }
    const idMapBrush* const brush = static_cast<const idMapBrush*>(primitive);
    unsigned int toolsFlags = 0;
    for (int index = 0; index < brush->sides.Num(); ++index) {
        if (brush->sides[index] != nullptr) {
            toolsFlags |= materialToolsFlagsResolver(
                brush->sides[index]->material.c_str());
        }
    }
    return (toolsFlags & 0x7Eu) != 0;
}

bool IsNotSoundPrimitive(idMapPrimitive* const primitive,
        idGame* const filterGame) {
    return !IsSoundPrimitive(primitive, filterGame);
}

bool IsProductionEntity(const idMapFile* const mapFile,
        idMapEntity* const entity, idGame* const filterGame) {
    if (entity == nullptr || entity->entityDef == nullptr) {
        return false;
    }
    for (int index = 0; index < entity->layerList.Num(); ++index) {
        if (idStr::Icmp(entity->layerList[index].c_str(),
                "spawn_target_layer") == 0) {
            return false;
        }
    }
    return productionEntityFilter == nullptr
        || productionEntityFilter(mapFile, entity, filterGame);
}

bool WriteAllMapPrimitives(idMapPrimitive* const primitive, idGame*) {
    return primitive != nullptr;
}

void SetMapMaterialToolsFlagsResolver(
        const mapMaterialToolsFlagsResolver_t resolver) {
    materialToolsFlagsResolver = resolver;
}

void SetMapProductionEntityFilter(const mapEntityFilter_t filter) {
    productionEntityFilter = filter;
}
