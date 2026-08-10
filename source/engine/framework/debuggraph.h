#pragma once

#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idMaterial;
class idRenderModelGui;


// IDA Local Type ordinal 1355; PDB kind: enum.
class idDebugGraph {
public:
  enum fillMode_t : int {
    GRAPH_LINE = 0,
    GRAPH_FILL = 1,
    GRAPH_FILL_REVERSE = 2
  };
  enum captionPos_t : int {
    CAP_NONE = 0,
    CAP_LEFT = 1,
    CAP_RIGHT = 2,
    CAP_TOP = 3,
    CAP_BOTTOM = 4
  };
  struct graphPlot_t {
    float value;
    idColor color;
  };

  explicit idDebugGraph(int numBars = 0);
  void Init(int numBars);
  void Render(idRenderModelGui* gui);
  void SetLabel(int index, const char* text);
  void AddGridLine(float value, const idColor& color);
  void SetValue(int index, float value, const idColor& color);

  const idMaterial *white;
  idColor bgColor;
  idColor fontColor;
  fillMode_t mode;
  bool sideways;
  float border;
  idVec4 position;
  bool enable;
  bool clamp;
  idStr caption;
  captionPos_t capPos;
  idList<graphPlot_t,3> bars;
  idList<graphPlot_t,3> grid;
  idList<idStr,3> labels;
};
