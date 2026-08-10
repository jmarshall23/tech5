#include "jxr_compat.h"

void jxr_set_user_data( jxr_image * image, void * data ) { if ( image != nullptr ) image->userData = data; }
void * jxr_get_user_data( jxr_image * image ) { return image == nullptr ? nullptr : image->userData; }
