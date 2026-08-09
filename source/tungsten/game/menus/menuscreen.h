#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\menus\menuscreen.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1438; PDB kind: enum.
enum mainMenuScreens_t : __int32
{
  MENU_AREA_INVALID = 0xFFFFFFFF,
  MENU_START = 0x0,
  MENU_ROOT = 0x1,
  MENU_DEV = 0x2,
  MENU_CAMPAIGN = 0x3,
  MENU_MULTIPLAYER = 0x4,
  MENU_SETTINGS = 0x5,
  MENU_AUDIO = 0x6,
  MENU_NUM_SCREENS = 0x7,
};

// IDA Local Type ordinal 16052; PDB kind: class.
class idMenuScreen : public idMenuWidget
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16053.
  virtual ~idMenuScreen();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void HandleMenu(const mainMenuTransition_t);
  virtual void ShowScreen(const mainMenuTransition_t);
  virtual void HideScreen(const mainMenuTransition_t);

};

// IDA Local Type ordinal 18346; PDB kind: class.
class idMenuScreen_Start : public idMenuScreen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18347.
  virtual ~idMenuScreen_Start();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void HandleMenu(const mainMenuTransition_t);
  virtual void ShowScreen(const mainMenuTransition_t);
  virtual void HideScreen(const mainMenuTransition_t);

};

// IDA Local Type ordinal 18348; PDB kind: class.
class idMenuScreen_Settings : public idMenuScreen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18349.
  virtual ~idMenuScreen_Settings();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void HandleMenu(const mainMenuTransition_t);
  virtual void ShowScreen(const mainMenuTransition_t);
  virtual void HideScreen(const mainMenuTransition_t);

};

// IDA Local Type ordinal 18350; PDB kind: class.
class idMenuScreen_Root : public idMenuScreen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18351.
  virtual ~idMenuScreen_Root();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void HandleMenu(const mainMenuTransition_t);
  virtual void ShowScreen(const mainMenuTransition_t);
  virtual void HideScreen(const mainMenuTransition_t);

};

// IDA Local Type ordinal 18353; PDB kind: class.
class idMenuScreen_Dev : public idMenuScreen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18354.
  virtual ~idMenuScreen_Dev();
  virtual void Initialize();
  virtual void Update();
  virtual void ObserveEvent(const idMenuWidget *, const idWidgetEvent *);
  virtual bool ExecuteEvent(const idWidgetEvent *);
  virtual bool HandleAction(idWidgetAction *, const idWidgetEvent *);
  virtual void HandleMenu(const mainMenuTransition_t);
  virtual void ShowScreen(const mainMenuTransition_t);
  virtual void HideScreen(const mainMenuTransition_t);

  idMenuWidget_DevList *listWidget;
};
