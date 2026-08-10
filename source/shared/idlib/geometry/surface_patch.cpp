#include "idlib/geometry/surface_patch.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>

namespace {

float QuadraticWeight0(const float value) {
    const float inverse = 1.0f - value;
    return inverse * inverse;
}

float QuadraticWeight1(const float value) {
    return 2.0f * value * (1.0f - value);
}

float QuadraticWeight2(const float value) {
    return value * value;
}

idDrawVert SampleControlPatch(const idList<idDrawVert, TAG_IDLIB>& source,
        const int sourceWidth, const int baseColumn, const int baseRow,
        const float u, const float v) {
    const float columnWeights[3] = {
        QuadraticWeight0(u), QuadraticWeight1(u), QuadraticWeight2(u)
    };
    const float rowWeights[3] = {
        QuadraticWeight0(v), QuadraticWeight1(v), QuadraticWeight2(v)
    };
    idDrawVert result{};
    result.xyz.Zero();
    result.st.Zero();
    float colors[4] = {};
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            const float weight = rowWeights[row] * columnWeights[column];
            const idDrawVert& control = source[
                (baseRow + row) * sourceWidth + baseColumn + column];
            result.xyz = result.xyz + control.xyz * weight;
            result.st.x += control.st.x * weight;
            result.st.y += control.st.y * weight;
            for (int component = 0; component < 4; ++component) {
                colors[component] += control.color[component] * weight;
            }
        }
    }
    for (int component = 0; component < 4; ++component) {
        result.color[component] = static_cast<unsigned char>(
            (std::max)(0.0f, (std::min)(255.0f,
                colors[component] + 0.5f)));
    }
    return result;
}

float PointLineDistance(const idVec3& point, const idVec3& start,
        const idVec3& end) {
    const idVec3 segment = end - start;
    const float lengthSqr = segment.LengthSqr();
    if (lengthSqr <= 1.0e-20f) {
        return (point - start).Length();
    }
    const float fraction = (point - start).Dot(segment) / lengthSqr;
    return (point - (start + segment * fraction)).Length();
}

int RequiredSubdivisions(const idList<idDrawVert, TAG_IDLIB>& controls,
        const int controlWidth, const int baseColumn, const int baseRow,
        const bool horizontal, const float error, const float maxLength) {
    int subdivisions = 1;
    for (int cross = 0; cross < 3; ++cross) {
        const int firstIndex = horizontal
            ? (baseRow + cross) * controlWidth + baseColumn
            : baseRow * controlWidth + baseColumn + cross;
        const int middleIndex = horizontal ? firstIndex + 1
            : firstIndex + controlWidth;
        const int lastIndex = horizontal ? firstIndex + 2
            : firstIndex + controlWidth * 2;
        const idVec3& first = controls[firstIndex].xyz;
        const idVec3& middle = controls[middleIndex].xyz;
        const idVec3& last = controls[lastIndex].xyz;
        float remainingError = PointLineDistance(middle, first, last);
        const float length = (last - first).Length();
        int needed = 1;
        while (needed < 64
            && ((error > 0.0f && remainingError > error)
                || (maxLength > 0.0f && length / needed > maxLength))) {
            needed *= 2;
            remainingError *= 0.25f;
        }
        subdivisions = (std::max)(subdivisions, needed);
    }
    return subdivisions;
}

} // namespace

idSurface_Patch::idSurface_Patch()
    : width(0), height(0), maxWidth(0), maxHeight(0), expanded(false) {
}

idSurface_Patch::idSurface_Patch(const idSurface_Patch& other)
    : idSurface(other), width(other.width), height(other.height),
      maxWidth(other.maxWidth), maxHeight(other.maxHeight),
      expanded(other.expanded) {
}

idSurface_Patch::~idSurface_Patch() = default;

void idSurface_Patch::SetSize(const int patchWidth,
        const int patchHeight) {
    if (patchWidth < 1 || patchWidth > maxWidth) {
        idLibPrint::FatalError(
            "idSurface_Patch::SetSize: invalid patchWidth");
    }
    if (patchHeight < 1 || patchHeight > maxHeight) {
        idLibPrint::FatalError(
            "idSurface_Patch::SetSize: invalid patchHeight");
    }
    width = patchWidth;
    height = patchHeight;
    verts.SetNum(width * height);
}

void idSurface_Patch::ProjectPointOntoVector(const idVec3& point,
        const idVec3& start, const idVec3& end, idVec3& projected) {
    const idVec3 direction = end - start;
    const float lengthSqr = direction.LengthSqr();
    projected = lengthSqr <= 0.0f ? start
        : start + direction * ((point - start).Dot(direction) / lengthSqr);
}

void idSurface_Patch::SubdivideExplicit(
        const int horizontalSubdivisions,
        const int verticalSubdivisions, const bool generateNormals,
        const bool removeLinearColumnsRows) {
    if (width < 3 || height < 3) {
        GenerateIndexes();
        if (generateNormals) {
            GenerateNormals();
        }
        return;
    }

    const int horizontal = (std::max)(1, horizontalSubdivisions);
    const int vertical = (std::max)(1, verticalSubdivisions);
    const int patchColumns = (width - 1) / 2;
    const int patchRows = (height - 1) / 2;
    const int newWidth = patchColumns * horizontal + 1;
    const int newHeight = patchRows * vertical + 1;
    const int sourceWidth = width;
    const idList<idDrawVert, TAG_IDLIB> source(verts);
    idList<idDrawVert, TAG_IDLIB> sampled;
    sampled.SetNum(newWidth * newHeight);

    for (int row = 0; row < newHeight; ++row) {
        const int patchRow = (std::min)(row / vertical, patchRows - 1);
        const float v = row == newHeight - 1 ? 1.0f
            : static_cast<float>(row % vertical)
                / static_cast<float>(vertical);
        for (int column = 0; column < newWidth; ++column) {
            const int patchColumn = (std::min)(column / horizontal,
                patchColumns - 1);
            const float u = column == newWidth - 1 ? 1.0f
                : static_cast<float>(column % horizontal)
                    / static_cast<float>(horizontal);
            sampled[row * newWidth + column] = SampleControlPatch(source,
                sourceWidth, patchColumn * 2, patchRow * 2, u, v);
        }
    }

    verts = sampled;
    width = newWidth;
    height = newHeight;
    maxWidth = newWidth;
    maxHeight = newHeight;
    expanded = false;
    if (removeLinearColumnsRows) {
        RemoveLinearColumnsRows();
    }
    GenerateIndexes();
    if (generateNormals) {
        GenerateNormals();
    }
}

void idSurface_Patch::Subdivide(const float horizontalError,
        const float verticalError, const float maxLength,
        const bool generateNormals) {
    if (width < 3 || height < 3) {
        GenerateIndexes();
        if (generateNormals) {
            GenerateNormals();
        }
        return;
    }
    int horizontal = 1;
    int vertical = 1;
    for (int patchRow = 0; patchRow + 2 < height; patchRow += 2) {
        for (int patchColumn = 0; patchColumn + 2 < width;
             patchColumn += 2) {
            horizontal = (std::max)(horizontal, RequiredSubdivisions(verts,
                width, patchColumn, patchRow, true, horizontalError,
                maxLength));
            vertical = (std::max)(vertical, RequiredSubdivisions(verts,
                width, patchColumn, patchRow, false, verticalError,
                maxLength));
        }
    }
    SubdivideExplicit(horizontal, vertical, generateNormals, true);
}

void idSurface_Patch::GenerateNormals() {
    if (width < 1 || height < 1) {
        return;
    }
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            const int left = (std::max)(0, column - 1);
            const int right = (std::min)(width - 1, column + 1);
            const int top = (std::max)(0, row - 1);
            const int bottom = (std::min)(height - 1, row + 1);
            idVec3 tangent = verts[row * width + right].xyz
                - verts[row * width + left].xyz;
            idVec3 bitangent = verts[bottom * width + column].xyz
                - verts[top * width + column].xyz;
            tangent.NormalizeFast();
            bitangent.NormalizeFast();
            idVec3 normal = bitangent.Cross(tangent);
            normal.NormalizeFast();
            idDrawVert& vertex = verts[row * width + column];
            vertex.SetNormal(normal);
            vertex.SetTangent(tangent);
            vertex.SetBiTangent(bitangent);
        }
    }
}

void idSurface_Patch::GenerateIndexes() {
    indexes.Clear();
    if (width < 2 || height < 2) {
        return;
    }
    indexes.PreAllocate((width - 1) * (height - 1) * 6);
    for (int row = 0; row + 1 < height; ++row) {
        for (int column = 0; column + 1 < width; ++column) {
            const int topLeft = row * width + column;
            const int topRight = topLeft + 1;
            const int bottomLeft = topLeft + width;
            const int bottomRight = bottomLeft + 1;
            indexes.Append(topLeft);
            indexes.Append(bottomLeft);
            indexes.Append(topRight);
            indexes.Append(topRight);
            indexes.Append(bottomLeft);
            indexes.Append(bottomRight);
        }
    }
    GenerateEdgeIndexes();
}

void idSurface_Patch::RemoveLinearColumnsRows() {
    constexpr float linearEpsilon = 0.1f;
    for (int column = 1; column + 1 < width;) {
        bool linear = true;
        for (int row = 0; row < height && linear; ++row) {
            linear = PointLineDistance(verts[row * width + column].xyz,
                verts[row * width + column - 1].xyz,
                verts[row * width + column + 1].xyz) <= linearEpsilon;
        }
        if (!linear) {
            ++column;
            continue;
        }
        idList<idDrawVert, TAG_IDLIB> reduced;
        reduced.SetNum((width - 1) * height);
        for (int row = 0; row < height; ++row) {
            int outputColumn = 0;
            for (int sourceColumn = 0; sourceColumn < width;
                 ++sourceColumn) {
                if (sourceColumn != column) {
                    reduced[row * (width - 1) + outputColumn++] =
                        verts[row * width + sourceColumn];
                }
            }
        }
        verts = reduced;
        --width;
        maxWidth = width;
    }

    for (int row = 1; row + 1 < height;) {
        bool linear = true;
        for (int column = 0; column < width && linear; ++column) {
            linear = PointLineDistance(verts[row * width + column].xyz,
                verts[(row - 1) * width + column].xyz,
                verts[(row + 1) * width + column].xyz) <= linearEpsilon;
        }
        if (!linear) {
            ++row;
            continue;
        }
        idList<idDrawVert, TAG_IDLIB> reduced;
        reduced.SetNum(width * (height - 1));
        int outputRow = 0;
        for (int sourceRow = 0; sourceRow < height; ++sourceRow) {
            if (sourceRow == row) {
                continue;
            }
            for (int column = 0; column < width; ++column) {
                reduced[outputRow * width + column] =
                    verts[sourceRow * width + column];
            }
            ++outputRow;
        }
        verts = reduced;
        --height;
        maxHeight = height;
    }
}

void idSurface_Patch::PutOnCurve() {
    if (width < 3 || height < 3) {
        return;
    }
    idList<idDrawVert, TAG_IDLIB> curved(verts);
    for (int row = 0; row < height; ++row) {
        for (int column = 1; column + 1 < width; ++column) {
            curved[row * width + column].xyz =
                (verts[row * width + column - 1].xyz
                    + verts[row * width + column].xyz * 2.0f
                    + verts[row * width + column + 1].xyz) * 0.25f;
        }
    }
    verts = curved;
    curved = verts;
    for (int row = 1; row + 1 < height; ++row) {
        for (int column = 0; column < width; ++column) {
            curved[row * width + column].xyz =
                (verts[(row - 1) * width + column].xyz
                    + verts[row * width + column].xyz * 2.0f
                    + verts[(row + 1) * width + column].xyz) * 0.25f;
        }
    }
    verts = curved;
}

void idSurface_Patch::ResizeExpanded(const int newHeight,
        const int newWidth) {
    if (newHeight < 1 || newWidth < 1) {
        return;
    }
    idList<idDrawVert, TAG_IDLIB> resized;
    resized.SetNum(newHeight * newWidth);
    const int copyHeight = (std::min)(height, newHeight);
    const int copyWidth = (std::min)(width, newWidth);
    for (int row = 0; row < copyHeight; ++row) {
        for (int column = 0; column < copyWidth; ++column) {
            resized[row * newWidth + column] = verts[row * width + column];
        }
    }
    verts = resized;
    width = newWidth;
    height = newHeight;
    maxWidth = newWidth;
    maxHeight = newHeight;
}

void idSurface_Patch::Collapse() {
    if (!expanded) {
        idLibPrint::FatalError("idSurface_Patch::Collapse: patch not expanded");
    }
    maxWidth = width;
    maxHeight = height;
    verts.SetNum(width * height);
    expanded = false;
}

void idSurface_Patch::Expand() {
    if (expanded) {
        idLibPrint::FatalError("idSurface_Patch::Expand: patch already expanded");
    }
    maxWidth = width + 4;
    maxHeight = height + 4;
    verts.PreAllocate(maxWidth * maxHeight);
    expanded = true;
}

void idSurface_Patch::SampleSinglePatchPoint(
        const idDrawVert (*controlPoints)[3], const float u,
        const float v, idDrawVert* const output) const {
    if (controlPoints == nullptr || output == nullptr) {
        return;
    }
    const float columnWeights[3] = {
        QuadraticWeight0(u), QuadraticWeight1(u), QuadraticWeight2(u)
    };
    const float rowWeights[3] = {
        QuadraticWeight0(v), QuadraticWeight1(v), QuadraticWeight2(v)
    };
    *output = idDrawVert{};
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            const float weight = rowWeights[row] * columnWeights[column];
            output->xyz = output->xyz
                + controlPoints[row][column].xyz * weight;
            output->st.x += controlPoints[row][column].st.x * weight;
            output->st.y += controlPoints[row][column].st.y * weight;
        }
    }
}

void idSurface_Patch::SampleSinglePatch(
        const idDrawVert (*controlPoints)[3], const int baseColumn,
        const int baseRow, const int outputWidth, const int outputHeight,
        const int horizontalSubdivisions, idDrawVert* const output) const {
    if (controlPoints == nullptr || output == nullptr || outputWidth < 1
        || outputHeight < 1) {
        return;
    }
    const int horizontal = (std::max)(1, horizontalSubdivisions);
    for (int row = 0; row < outputHeight; ++row) {
        const float v = outputHeight == 1 ? 0.0f
            : static_cast<float>(row) / static_cast<float>(outputHeight - 1);
        for (int column = 0; column < horizontal + 1
             && baseColumn + column < outputWidth; ++column) {
            const float u = static_cast<float>(column)
                / static_cast<float>(horizontal);
            SampleSinglePatchPoint(controlPoints, u, v,
                &output[(baseRow + row) * outputWidth
                    + baseColumn + column]);
        }
    }
}
