/*
===========================================================================

  Recovered SMTP client implementation.

  Function signatures, protocol text, cvars and command data are taken from
  the idTech 5 Xbox 360 Hex-Rays dump.  Socket and time calls use the recovered
  Windows shared-idlib interfaces.

===========================================================================
*/

#include "network_precompiled.h"
#include "smtp.h"

#include <ctime>

idCVar smtp_debug( "smtp_debug", "0", CVAR_BOOL, "Show SMTP messages." );
idCVar smtp_sendAttachments( "smtp_sendAttachments", "1", CVAR_BOOL,
	"sends attachments on emails, for viewnotes" );
idCVar smtp_domain( "smtp_domain", "machinegames.com", 0,
	"Email domain for smtp server" );

namespace {

static const char SMTP_BOUNDARY[] = "KkK170891tpbkKk__FV_KKKkkkjjwq";

const char * SMTP_FileName( const char * path ) {
	const char * name = path != NULL ? path : "";
	for ( const char * cursor = name; *cursor != '\0'; ++cursor ) {
		if ( *cursor == '/' || *cursor == '\\' ) {
			name = cursor + 1;
		}
	}
	return name;
}

bool SMTP_IsTextAttachment( const char * path ) {
	const char * name = SMTP_FileName( path );
	const char * extension = NULL;
	for ( const char * cursor = name; *cursor != '\0'; ++cursor ) {
		if ( *cursor == '.' ) {
			extension = cursor + 1;
		}
	}
	if ( extension == NULL ) {
		return false;
	}
	return ( extension[ 0 ] == 't' || extension[ 0 ] == 'T' ) &&
		( extension[ 1 ] == 'x' || extension[ 1 ] == 'X' ) &&
		( extension[ 2 ] == 't' || extension[ 2 ] == 'T' ) &&
		extension[ 3 ] == '\0';
}

} // namespace

/*
========================
idSMTP::EncodeBase64

The recovered encoder wraps complete 76-character lines with CRLF and returns
the allocation length including the terminating NUL.
========================
*/
int idSMTP::EncodeBase64( byte * source, int sourceLength, byte ** encoded ) {
	static const char alphabet[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	if ( encoded == NULL ) {
		return 0;
	}
	*encoded = NULL;
	if ( source == NULL || sourceLength < 0 ) {
		return 0;
	}

	const int characterCount = 4 * ( ( sourceLength + 2 ) / 3 );
	const int allocationLength = characterCount + 2 * ( characterCount / 76 ) + 1;
	byte * output = static_cast< byte * >( Sys_Alloc( allocationLength, TAG_NETWORKING ) );
	if ( output == NULL ) {
		return 0;
	}

	*encoded = output;
	int lineLength = 0;
	int offset = 0;
	while ( sourceLength >= 3 ) {
		output[ offset++ ] = alphabet[ source[ 0 ] >> 2 ];
		output[ offset++ ] = alphabet[ ( ( source[ 0 ] << 4 ) & 0x30 ) | ( source[ 1 ] >> 4 ) ];
		output[ offset++ ] = alphabet[ ( ( source[ 1 ] << 2 ) & 0x3C ) | ( source[ 2 ] >> 6 ) ];
		output[ offset++ ] = alphabet[ source[ 2 ] & 0x3F ];
		source += 3;
		sourceLength -= 3;
		lineLength += 4;
		if ( lineLength >= 76 ) {
			output[ offset++ ] = '\r';
			output[ offset++ ] = '\n';
			lineLength = 0;
		}
	}

	if ( sourceLength != 0 ) {
		output[ offset++ ] = alphabet[ source[ 0 ] >> 2 ];
		output[ offset++ ] = alphabet[ ( source[ 0 ] << 4 ) & 0x30 |
			( sourceLength == 2 ? source[ 1 ] >> 4 : 0 ) ];
		output[ offset++ ] = sourceLength == 2 ? alphabet[ ( source[ 1 ] << 2 ) & 0x3C ] : '=';
		output[ offset++ ] = '=';
	}
	output[ offset++ ] = '\0';
	return offset;
}

/*
========================
idSMTP::RecvFromServer
========================
*/
bool idSMTP::RecvFromServer( const char * expected ) {
	if ( !tcp.Select( 32000 ) ) {
		idLib::Warning( "SMTP Timeout while waiting for reply to %s", expected );
		return false;
	}

	if ( smtp_debug.GetBool() ) {
		idLib::Printf( "SMTP Recv: " );
	}

	int firstCharacter = -1;
	char buffer[ 4096 ];
	for ( ;; ) {
		const int length = tcp.Read( buffer, sizeof( buffer ) - 1 );
		if ( length <= 0 ) {
			if ( smtp_debug.GetBool() ) {
				idLib::Printf( "...\n" );
			}
			idLib::Warning( "SMTP Error while waiting for a reply to %s", expected );
			return false;
		}

		buffer[ length ] = '\0';
		if ( firstCharacter < 0 ) {
			firstCharacter = static_cast< unsigned char >( buffer[ 0 ] );
		}
		if ( smtp_debug.GetBool() ) {
			idLib::Printf( "%s", buffer );
		}
		if ( buffer[ length - 1 ] == '\n' ) {
			if ( firstCharacter != '5' ) {
				return true;
			}
			idLib::Warning( "SMTP Error in reply to %s", expected );
			return false;
		}

		if ( !tcp.Select( 32000 ) ) {
			if ( smtp_debug.GetBool() ) {
				idLib::Printf( "...\n" );
			}
			idLib::Warning( "SMTP Timeout while waiting for reply to %s", expected );
			return false;
		}
	}
}

/*
========================
idSMTP::SendToServer
========================
*/
bool idSMTP::SendToServer( const char * text ) {
	if ( text == NULL ) {
		return false;
	}
	if ( smtp_debug.GetBool() ) {
		idStr display( text );
		display.ReplaceRecovered( "\r\n", "\n" );
		display.ReplaceRecovered( "\n", "<nl>" );
		idLib::Printf( display.Length() <= 50 ? "SMTP Send: %s\n" : "SMTP Send: %.50s...\n",
			display.c_str() );
	}
	return tcp.Write( text, static_cast< int >( std::strlen( text ) ) ) >= 0;
}

/*
========================
idSMTP::SendEmail
========================
*/
void idSMTP::SendEmail( emailData_t & data ) {
	if ( !tcp.Connect( data.server.c_str(), 25, true, false, false ) ) {
		idLib::Warning( "SMTP: Could not connect to server %s", data.server.c_str() );
		return;
	}

	if ( !RecvFromServer( "hello from server" ) ||
		!SendToServer( va( "HELO %s\r\n", smtp_domain.GetString() ) ) ||
		!RecvFromServer( "reply to HELO" ) ||
		!SendToServer( va( "MAIL FROM: <%s>\r\n", data.senderEmail.c_str() ) ) ||
		!RecvFromServer( "reply to MAIL FROM" ) ) {
		tcp.Close();
		return;
	}

	for ( int index = 0; index < data.recipientEmail.Num(); ++index ) {
		if ( !SendToServer( va( "RCPT TO: <%s>\r\n", data.recipientEmail[ index ].c_str() ) ) ||
			!RecvFromServer( "reply to RCPT TO" ) ) {
			tcp.Close();
			return;
		}
	}

	if ( !SendToServer( "DATA\r\n" ) || !RecvFromServer( "reply to DATA" ) ) {
		tcp.Close();
		return;
	}

	static const char * monthNames[] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	const __time64_t now = _time64( NULL );
	tm utcTime;
	_gmtime64_s( &utcTime, &now );

	idStr headers;
	headers.Format( "Date: %d %s %d %02d:%02d:%02d GMT\r\n",
		utcTime.tm_mday, monthNames[ utcTime.tm_mon ], utcTime.tm_year + 1900,
		utcTime.tm_hour, utcTime.tm_min, utcTime.tm_sec );
	headers.Append( "From: " );
	headers.Append( data.senderName );
	headers.Append( " <" );
	headers.Append( data.senderEmail );
	headers.Append( ">\r\nTo: " );
	for ( int index = 0; index < data.recipientEmail.Num(); ++index ) {
		headers.Append( data.recipientEmail[ index ] );
		if ( index + 1 < data.recipientEmail.Num() ) {
			headers.Append( "," );
		}
	}
	headers.Append( "\r\nSubject: " );
	headers.Append( data.subject );
	headers.Append( "\r\nMIME-Version: 1.0\r\nContent-Type: multipart/mixed; \r\n"
		" boundary=\"KkK170891tpbkKk__FV_KKKkkkjjwq\" \r\n" );

	if ( !SendToServer( headers.c_str() ) ||
		!SendToServer( "--KkK170891tpbkKk__FV_KKKkkkjjwq\r\n"
			"Content-Type: text/plain; charset=US-ASCII\r\n\r\n" ) ||
		!SendToServer( data.body.c_str() ) ) {
		tcp.Close();
		return;
	}

	if ( smtp_sendAttachments.GetBool() && data.attachment.Length() > 0 ) {
		void * fileBuffer = NULL;
		const int fileLength = fileSystem->ReadFile( data.attachment.c_str(), &fileBuffer, NULL );
		if ( fileBuffer != NULL && fileLength >= 0 ) {
			byte * base64Buffer = NULL;
			EncodeBase64( static_cast< byte * >( fileBuffer ), fileLength, &base64Buffer );
			if ( base64Buffer != NULL ) {
				idStr attachmentHeader( "\r\n\r\n--KkK170891tpbkKk__FV_KKKkkkjjwq\r\n" );
				attachmentHeader.Append( SMTP_IsTextAttachment( data.attachment.c_str() ) ?
					"Content-Type: text/plain\r\n" : "Content-Type: image/jpeg\r\n" );
				attachmentHeader.Append( "Content-Transfer-Encoding: base64\r\n"
					"Content-Disposition: attachment;\r\n filename= \"" );
				attachmentHeader.Append( SMTP_FileName( data.attachment.c_str() ) );
				attachmentHeader.Append( "\"\r\n\r\n" );

				const bool sent = SendToServer( attachmentHeader.c_str() ) &&
					SendToServer( reinterpret_cast< const char * >( base64Buffer ) );
				if ( sent ) {
					Sys_Sleep( 500 );
				}
				const bool terminated = sent && SendToServer( "\r\n\r\n" );
				Sys_Free( base64Buffer );
				fileSystem->FreeFile( fileBuffer );
				if ( !terminated ) {
					tcp.Close();
					return;
				}
			} else {
				fileSystem->FreeFile( fileBuffer );
			}
		}
	}

	if ( SendToServer( "\r\n\r\n--KkK170891tpbkKk__FV_KKKkkkjjwq--\r\n" ) &&
		SendToServer( "\r\n.\r\n" ) && RecvFromServer( "reply to DATA body" ) &&
		SendToServer( "QUIT\r\n" ) ) {
		RecvFromServer( "reply to QUIT" );
	}
	tcp.Close();
}

CONSOLE_COMMAND_COMPILE( TestEmail, "Tests the SMTP code", NULL ) {
	if ( args.Argc() < 2 ) {
		idLib::Printf( "Syntax: %s <recepient>\n", args.Argv( 0 ) );
		return;
	}

	emailData_t data;
	data.subject = "TestEmail_f";
	data.senderName = "Brian Harris";
	data.senderEmail = "brian@idsoftware.com";
	data.recipientEmail.Append( idStr( args.Argv( 1 ) ) );
	data.body = "Hi, this is a test of the SMTP code.\n\nIt looks like it worked.\r\n\r\nYay!";
	idSMTP smtp;
	smtp.SendEmail( data );
}
