#pragma once

#include "../framework/resource.h"
#include "../framework/resourcelist.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/text/str.h"

class idStaticModel;

// Compact render-facing payload embedded by the retail IES resource.  The
// project map is generated in memory on PC; it retains the recovered name so
// material expressions and tools see the same resource identity.
struct iesRenderInfo_t {
	iesRenderInfo_t();

	float maxCandela;
	idVec3 lightArea;
	float cutoffCosine;
	char projectMap[256];
};

class idIESfile : public idResource {
public:
	idIESfile();
	~idIESfile() override;

	void LoadResource() override;
	bool ReloadIfStale() override;
	void WriteResourceFile() override;
	idResourceList * GetResourceList() override;
	void Print() override;
	void List() override;

	float CandelaAtAngle( float horizontalAngle, float verticalAngle ) const;
	void BuildCandelaImage();
	void BuildEditorModel();

	int formatYear;
	int lampToLuminaireGeometry;
	int numAngleFactors;
	idList< float, 5 > factorAngles;
	idList< float, 5 > factorScales;
	int numLamps;
	float lumensPerLamp;
	float candelaMultiplier;
	int numVerticalAngles;
	int numHorizontalAngles;
	int photoMetricType;
	int unitsType;
	float width;
	float length;
	float height;
	float ballastFactor;
	int futureUse;
	float inputWats;
	idList< float, 5 > verticalAngles;
	idList< float, 5 > horizontalAngles;
	idList< float, 5 > candela;
	iesRenderInfo_t renderInfo;
	idStr editorModelName;
	idStaticModel * editorModel;

	static idTypedResourceList< idIESfile > resourceList;

private:
	void ClearPhotometricData();
};
