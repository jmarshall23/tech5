
// ========================================================================
// png_read_data
// EA  : 0x8321B868
// RVA : 0x0121B868
// PDB : w:\tech5\libs\png\pngrio.c
// ========================================================================

void __fastcall png_read_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  void (*read_data_fn)(void); // r11

  read_data_fn = (void (*)(void))png_ptr->read_data_fn;
  if ( read_data_fn != nullptr )
    read_data_fn();
  else
    png_error(png_ptr, error_message: "Call to NULL read function");
}


// ========================================================================
// png_default_read_data
// EA  : 0x8321B888
// RVA : 0x0121B888
// PDB : w:\tech5\libs\png\pngrio.c
// ========================================================================

void __fastcall png_default_read_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  if ( png_ptr != nullptr
    && fread(buffer: data, elementSize: 1u, count: length, stream: (_iobuf *)png_ptr->io_ptr) != length )
  {
    png_error(png_ptr, error_message: "Read Error");
  }
}


// ========================================================================
// png_set_read_fn
// EA  : 0x8321B8F0
// RVA : 0x0121B8F0
// PDB : w:\tech5\libs\png\pngrio.c
// ========================================================================

void __fastcall png_set_read_fn(
        png_struct_def *png_ptr,
        void *io_ptr,
        void (__fastcall *read_data_fn)(png_struct_def *, unsigned __int8 *, unsigned int))
{
  if ( png_ptr != nullptr )
  {
    png_ptr->io_ptr = io_ptr;
    if ( read_data_fn != nullptr )
      png_ptr->read_data_fn = read_data_fn;
    else
      png_ptr->read_data_fn = png_default_read_data;
    if ( png_ptr->write_data_fn != nullptr )
    {
      png_ptr->write_data_fn = nullptr;
      png_warning(png_ptr, warning_message: "It's an error to set both read_data_fn and write_data_fn in the ");
      png_warning(png_ptr, warning_message: "same structure.  Resetting write_data_fn to NULL.");
    }
    png_ptr->output_flush_fn = nullptr;
  }
}

