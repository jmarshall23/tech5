#pragma once

// Recovered from w:\tech5\engine\network\smtp.h PDB records and the
// matching Xbox 360 SMTP implementation.  idStr/idList/idTCP are supplied by
// network_precompiled.h, as in the original engine build.

struct emailData_t {
	idStr			server;
	idStr			subject;
	idStr			senderName;
	idStr			senderEmail;
	idList< idStr >	recipientEmail;
	idStr			body;
	idStr			attachment;
};

class idSMTP {
public:
	void		SendEmail( emailData_t & data );

private:
	int			EncodeBase64( byte * source, int sourceLength, byte ** encoded );
	bool		RecvFromServer( const char * expected );
	bool		SendToServer( const char * text );

	idTCP		tcp;
};

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( emailData_t ) == 208, "Recovered emailData_t ABI changed" );
static_assert( sizeof( idSMTP ) == 20, "Recovered idSMTP ABI changed" );
#endif
