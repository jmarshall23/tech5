#include "network_precompiled.h"
#include "hansoftreport.h"

#if defined( TECH5_HAS_AMQP_REPORTING )
#include "../../shared/idlib/networking/amqp/mqcommon.h"
#include "../../shared/idlib/networking/amqp/mqmessaging.h"
#endif

idHansoftReport hansoftReport;

void idHansoftReport::SendReport( char * report, unsigned int byteSize, const char * targetPlatform ) {
#if defined( TECH5_HAS_AMQP_REPORTING )
	amqpEndpoint_t endpoint;
	endpoint.host = cvarSystem != NULL ? cvarSystem->GetCVarString( "mq_host", "localhost" ) : "localhost";
	endpoint.port = static_cast< unsigned short >( cvarSystem != NULL ? cvarSystem->GetCVarInteger( "mq_port", 5672 ) : 5672 );
	endpoint.username = cvarSystem != NULL ? cvarSystem->GetCVarString( "mq_user", "guest" ) : "guest";
	endpoint.password = cvarSystem != NULL ? cvarSystem->GetCVarString( "mq_pw", "guest" ) : "guest";
	endpoint.vhost = cvarSystem != NULL ? cvarSystem->GetCVarString( "mq_vhost", "/" ) : "/";

	idMQConnection connection;
	connection.Init( endpoint );
	if ( connection.Connect() ) {
		idMQChannel * channel = connection.GetChannel();
		if ( channel != NULL ) {
			const idStr exchange( "idtech5" );
			const idStr exchangeType( "topic" );
			channel->ExchangeDeclare( exchange, exchangeType, true );
			idStr routingKey;
			routingKey.Format( "idtech5.crash_reports.Tungsten.%s",
				targetPlatform != NULL ? targetPlatform : "unknown" );
			channel->BasicPublish( exchange, routingKey, false, false, report, byteSize );
		}
	}
	connection.Close();
#else
	(void)report;
	(void)byteSize;
	(void)targetPlatform;
	idLib::Warning( "Hansoft AMQP reporting is not linked into this Windows target" );
#endif
}

idStr idHansoftReport::CombineLines( idStr & source ) {
	idStr result;
	const char * cursor = source.c_str();
	while ( cursor != NULL && *cursor != '\0' ) {
		const char * end = strchr( cursor, '\n' );
		const int length = end != NULL ? static_cast< int >( end - cursor ) : static_cast< int >( strlen( cursor ) );
		idStr line;
		for ( int i = 0; i < length; ++i ) line.Append( cursor[i] );
		line.TrimWhitespaceRecovered();
		if ( line.Length() != 0 ) {
			result.Append( line );
			const unsigned char last = static_cast< unsigned char >( line.c_str()[ line.Length() - 1 ] );
			if ( ( last >= 'a' && last <= 'z' ) || ( last >= 'A' && last <= 'Z' ) || ( last >= '0' && last <= '9' ) ) {
				result.Append( '.' );
			}
			result.Append( ' ' );
		}
		if ( end == NULL ) break;
		cursor = end + 1;
	}
	return result;
}

void idHansoftReport::Write360Report( void * exceptionPointers ) {
	(void)exceptionPointers;
#if !defined( _XBOX )
	// The recovered body serializes Xbox kernel/debug-monitor structures into
	// idreports::Xbox360CrashReport.  Those types have no Windows ABI; keeping
	// this entry point inert is the retail platform split, not a PC substitute.
	idLib::Warning( "Write360Report is unavailable on the Windows target" );
#endif
}
