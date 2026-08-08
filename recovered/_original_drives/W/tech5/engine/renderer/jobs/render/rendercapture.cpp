
// ========================================================================
// ?RenderCapture@@YAXPBUcaptureParms_t@@@Z
// EA  : 0x828D9F48
// RVA : 0x008D9F48
// PDB : w:\tech5\engine\renderer\jobs\render\rendercapture.cpp
// ========================================================================

void __fastcall RenderCapture(const captureParms_t *parms)
{
  renderCapture_t capture; // r11

  capture = parms->capture;
  if ( parms->capture <= (unsigned int)CAPTURE_GUI_IMAGE )
  {
    switch ( capture )
    {
      case CAPTURE_VIEW_DEPTH:
        CaptureViewDepth(parms);
        break;
      case CAPTURE_FEEDBACK:
        CaptureFeedback(parms);
        break;
      case CAPTURE_GLARE_MAP:
        CaptureGlareMap(parms);
        break;
      default:
        if ( capture != CAPTURE_VIEW_COLOR )
          CaptureGuiImage(parms);
        else
          CaptureViewColor(parms);
        break;
    }
  }
}

