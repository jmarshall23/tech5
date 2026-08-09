#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

// This PDB type was associated with detaildata.h even though its symbol name
// is generic.  Keep the recovered layout available without relying on a PCH.
struct emailData_t {
    idStr server;
    idStr subject;
    idStr senderName;
    idStr senderEmail;
    idList<idStr, 5> recipientEmail;
    idStr body;
    idStr attachment;
};
