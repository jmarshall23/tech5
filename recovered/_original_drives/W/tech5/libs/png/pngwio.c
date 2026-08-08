
// ========================================================================
// png_write_data
// EA  : 0x8321E698
// RVA : 0x0121E698
// PDB : w:\tech5\libs\png\pngwio.c
// ========================================================================

void __fastcall png_write_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  void (*write_data_fn)(void); // r11

  write_data_fn = (void (*)(void))png_ptr->write_data_fn;
  if ( write_data_fn != nullptr )
    write_data_fn();
  else
    png_error(png_ptr, error_message: "Call to NULL write function");
}


// ========================================================================
// png_default_write_data
// EA  : 0x8321E6B8
// RVA : 0x0121E6B8
// PDB : w:\tech5\libs\png\pngwio.c
// ========================================================================

void __fastcall png_default_write_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  if ( png_ptr != nullptr && fwrite(buffer: data, size: 1u, count: length, stream: (_iobuf *)png_ptr->io_ptr) != length )
    png_error(png_ptr, error_message: "Write Error");
}


// ========================================================================
// png_flush
// EA  : 0x8321E720
// RVA : 0x0121E720
// PDB : w:\tech5\libs\png\pngwio.c
// ========================================================================

void __fastcall png_flush(png_struct_def *png_ptr)
{
  void (*output_flush_fn)(void); // r11

  output_flush_fn = (void (*)(void))png_ptr->output_flush_fn;
  if ( output_flush_fn != nullptr )
    output_flush_fn();
}


// ========================================================================
// png_default_flush
// EA  : 0x8321E738
// RVA : 0x0121E738
// PDB : w:\tech5\libs\png\pngwio.c
// ========================================================================

void __fastcall png_default_flush(png_struct_def *png_ptr)
{
  _iobuf *io_ptr; // r3

  if ( png_ptr != nullptr )
  {
    io_ptr = (_iobuf *)png_ptr->io_ptr;
    if ( io_ptr != nullptr )
      fflush(stream: io_ptr);
  }
}


// ========================================================================
// png_set_write_fn
// EA  : 0x8321E758
// RVA : 0x0121E758
// PDB : w:\tech5\libs\png\pngwio.c
// ========================================================================

void __fastcall png_set_write_fn(
        png_struct_def *png_ptr,
        void *io_ptr,
        void (__fastcall *write_data_fn)(png_struct_def *, unsigned __int8 *, unsigned int),
        void (__fastcall *output_flush_fn)(png_struct_def *))
{
  if ( png_ptr != nullptr )
  {
    png_ptr->io_ptr = io_ptr;
    if ( write_data_fn != nullptr )
      png_ptr->write_data_fn = write_data_fn;
    else
      png_ptr->write_data_fn = png_default_write_data;
    if ( output_flush_fn != nullptr )
      png_ptr->output_flush_fn = output_flush_fn;
    else
      png_ptr->output_flush_fn = png_default_flush;
    if ( png_ptr->read_data_fn != nullptr )
    {
      png_ptr->read_data_fn = nullptr;
      png_warning(png_ptr, warning_message: "Attempted to set both read_data_fn and write_data_fn in");
      png_warning(png_ptr, warning_message: "the same structure.  Resetting read_data_fn to NULL.");
    }
  }
}

