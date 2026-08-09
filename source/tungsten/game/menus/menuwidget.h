#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\menus\menuwidget.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1436; PDB kind: enum.
enum idMenuWidget::widgetState_t : __int32
{
  WIDGET_STATE_HIDDEN = 0x0,
  WIDGET_STATE_NORMAL = 0x1,
  WIDGET_STATE_SELECTING = 0x2,
  WIDGET_STATE_SELECTED = 0x3,
  WIDGET_STATE_DISABLED = 0x4,
  WIDGET_STATE_MAX = 0x5,
};

// IDA Local Type ordinal 1437; PDB kind: enum.
enum idMenuWidget_Button::animState_t : __int32
{
  ANIM_STATE_UP = 0x0,
  ANIM_STATE_DOWN = 0x1,
  ANIM_STATE_OVER = 0x2,
  ANIM_STATE_MAX = 0x3,
};

// IDA Local Type ordinal 2363; PDB kind: enum.
enum widget_t::actionResult_t : __int32
{
  ACTION_IGNORED = 0x0,
  ACTION_HANDLED = 0x1,
  ACTION_HANDLED_STATECHANGED = 0x2,
};

// IDA Local Type ordinal 14932; PDB kind: struct.
struct __declspec(align(4)) widget_t
{
  // Recovered virtual interface; IDA vtable ordinal 14939.
  virtual ~widget_t();
  virtual float CalcWidth(idDeviceContext *);
  virtual float CalcHeight(idDeviceContext *);
  virtual void Render(idDeviceContext *, float, float, float, float);
  virtual widget_t::actionResult_t DoEvent(const sysEvent_t *, int);


  widget_t::actionResult_t actionResult;
  bool selectedRow;
  bool selectedColumn;
};

// IDA Local Type ordinal 16041; PDB kind: class.
class idMenuWidget
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16044.
  virtual ~idMenuWidget();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);

  idSWFSpriteInstance *boundSprite;
  idMenuWidget *parent;
  idList<idStr,5> spritePath;
  idList<idMenuWidget *,5> children;
  idList<idMenuWidget *,5> observers;
  idList<idList<idWidgetAction,5>,5> eventActions;
  idStaticList<int,18> eventActionLookup;
  idMenuDataSource *dataSource;
  int dataSourceFieldIndex;
  int focusIndex;
  idMenuWidget::widgetState_t widgetState;
};

// IDA Local Type ordinal 18320; PDB kind: class.
class __declspec(align(4)) idMenuWidget_List : public idMenuWidget
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18321.
  virtual ~idMenuWidget_List();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void Scroll(const int);
  virtual void ScrollOffset(const int);
  virtual int GetTotalNumberOfOptions();
  virtual bool PrepareListElement(idMenuWidget *, const int);

  int numVisibleOptions;
  int viewOffset;
  int viewIndex;
  bool allowWrapping;
};

// IDA Local Type ordinal 18322; PDB kind: struct.
struct idMenuWidget_DevList::indexInfo_t
{
  const char *name;
  int focusIndex;
  int viewIndex;
  int viewOffset;
};

// IDA Local Type ordinal 18324; PDB kind: class.
class idMenuWidget_DevList : public idMenuWidget_List
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18325.
  virtual ~idMenuWidget_DevList();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void Scroll(const int);
  virtual void ScrollOffset(const int);
  virtual int GetTotalNumberOfOptions();
  virtual bool PrepareListElement(idMenuWidget *, const int);

  const idDeclDevMenuList *devMenuList;
  idList<idMenuWidget_DevList::indexInfo_t,5> devMapListInfos;
};

// IDA Local Type ordinal 18326; PDB kind: class.
class idMenuWidget_Help : public idMenuWidget
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18327.
  virtual ~idMenuWidget_Help();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);

  idStr lastFocusedMessage;
  idStr lastHoveredMessage;
};

// IDA Local Type ordinal 18338; PDB kind: class.
class idMenuWidget_Button : public idMenuWidget
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18339.
  virtual ~idMenuWidget_Button();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);

  idStr label;
  idStr description;
  menuOption_t optionType;
  idMenuWidget_Button::animState_t animState;
};

// IDA Local Type ordinal 18341; PDB kind: class.
class idMenuWidget::HandleAction::__l31::DeclineQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18342.
  virtual ~DeclineQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18343; PDB kind: class.
class idMenuWidget::HandleAction::__l30::AcceptQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18344.
  virtual ~AcceptQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18360; PDB kind: class.
class idMenuWidget::WrapWidgetSWFEvent : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18361.
  virtual ~WrapWidgetSWFEvent();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMenuWidget *targetWidget;
  widgetEvent_t targetEvent;
  int targetEventArg;
};
