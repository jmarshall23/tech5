#include "sound_local.h"

idTypedResourceList< idSoundSample > idSoundSample::resourceList( "sample" );
idDeclInfoTemplate< idSoundShader > idSoundShader::resourceList( "sound", "idSoundShader", "sndshd" );
idDeclInfoTemplate< idDeclDuck > idDeclDuck::resourceList( "duck", "idDeclDuck", "sndshd" );

namespace {
void ClearShaderParms( soundShaderParms_t & parms ) {
	memset( &parms, 0, sizeof( parms ) );
	parms.minDistance = 128.0f;
	parms.maxDistance = 1024.0f;
	parms.distanceFactor = 1.0f;
	parms.volume.min = parms.volume.max = 0.0f;
	parms.pitch.min = parms.pitch.max = 1.0f;
	parms.lfeVolume = -6.0f;
	parms.priority = SPRIORITY_MEDIUM;
	parms.maxPlay.playbackType = SMAX_IGNORE;
}

int DuckGroupIndex( const char * name ) {
	static const char * names[ 25 ] = {
		"ui", "music_menu", "music_ingame", "sfx_general", "amb_core",
		"amb_spot", "explosions", "key_events", "impacts", "rico_bys",
		"movement_ai", "movement_pl", "veh_ai", "veh_pl", "veh_collisions_ai",
		"veh_collisions_pl", "weapons_ai", "weapons_pl", "special_enemy_movement",
		"special_enemy_voice", "vo_player", "vo_event", "vo_ingame", "vo_radio",
		"vo_battle"
	};
	for ( int i = 0; i < 25; ++i ) if ( idStr::Icmp( name, names[ i ] ) == 0 ) return i;
	return -1;
}
}

idSoundShader::idSoundShader() : preSound( NULL ), postSound( NULL ), remoteSound( NULL ),
	nextSample( NULL ), playingChannels() {
	ClearShaderParms( parms );
}

idSoundShader::~idSoundShader() { FreeData(); }

void idSoundShader::FreeData() {
	ClearShaderParms( parms );
	soundFiles.Clear();
	entries.Clear();
	preSound = postSound = remoteSound = NULL;
	nextSample = NULL;
}

bool idSoundShader::SetImplicitText() {
	idStr sampleName( GetName() );
	const char * slash = strrchr( sampleName.c_str(), '.' );
	if ( slash == NULL ) sampleName.Append( ".wav" );
	idStr text;
	text.Format( "{ // IMPLICITLY GENERATED\n\tedit = {\n\t\tsoundFiles = {\n"
		"\t\t\tnum = 1;\n\t\t\titem[0] = \"%s\";\n\t\t}\n\t}\n}\n",
		sampleName.c_str() );
	SetText( text.c_str() );
	return true;
}

void idSoundShader::Parse( idParser * parser ) {
	idDeclTypeInfo::Parse( parser );
	entries.Clear();
	for ( int i = 0; i < soundFiles.Num(); ++i ) {
		const char * fileName = soundFiles[ i ].c_str();
		if ( fileName == NULL || fileName[ 0 ] == '\0' ) continue;
		idResource * resource = idSoundSample::resourceList.Load( fileName, true );
		if ( resource != NULL ) entries.Append( static_cast< idSoundSample * >( resource ) );
	}
}

void idSoundShader::List() {
	unsigned int bytes = 0;
	for ( int i = 0; i < entries.Num(); ++i ) if ( entries[ i ] != NULL ) bytes += entries[ i ]->staticBufferSize;
	idLib::Printf( "%5.1fKB %s\n", bytes / 1024.0f, GetName() );
	for ( int i = 0; i < entries.Num(); ++i ) if ( entries[ i ] != NULL ) entries[ i ]->List();
}

unsigned int idSoundShader::Size() const {
	return static_cast< unsigned int >( sizeof( *this ) + soundFiles.MemoryUsed() + entries.MemoryUsed() );
}

idSoundSample * idSoundShader::GetNextEntry( bool preTouchData ) {
	const int count = entries.Num();
	if ( count <= 0 ) return NULL;
	if ( parms.soundShaderFlags & SSF_RANDOM_LOOPING ) {
		idSoundSample * selected = entries[ soundSystemLocal.random.RandomInt( count ) ];
		if ( preTouchData && selected != NULL ) selected->PreCacheStreamData( true );
		return selected;
	}
	if ( nextSample == NULL ) {
		nextSample = entries[ ( parms.soundShaderFlags & SSF_SEQUENTIAL ) ? 0 :
			soundSystemLocal.random.RandomInt( count ) ];
	}
	int oldIndex = entries.FindIndex( nextSample );
	int newIndex = 0;
	if ( count == 2 ) {
		newIndex = oldIndex == 0 ? 1 : 0;
	} else if ( count > 2 && ( parms.soundShaderFlags & SSF_SEQUENTIAL ) ) {
		newIndex = ( oldIndex + 1 ) % count;
	} else if ( count > 1 ) {
		newIndex = soundSystemLocal.random.RandomInt( count - 1 );
		if ( oldIndex >= 0 && newIndex >= oldIndex ) ++newIndex;
	}
	idSoundSample * result = nextSample;
	nextSample = entries[ newIndex ];
	if ( preTouchData ) {
		if ( result != NULL ) result->PreCacheStreamData( true );
		if ( nextSample != NULL ) nextSample->PreCacheStreamData( false );
	}
	return result;
}

int idSoundShader::GetMaxLength() const {
	if ( parms.soundShaderFlags & ( SSF_LOOPING | SSF_RANDOM_LOOPING ) ) return 0;
	int maximum = 0;
	for ( int i = 0; i < entries.Num(); ++i ) {
		if ( entries[ i ] != NULL ) maximum = ( std::max )( maximum, entries[ i ]->LengthInMsec() );
	}
	return maximum;
}

idDeclDuck::idDeclDuck() : layer( 0 ) { memset( groupVolume, 0, sizeof( groupVolume ) ); }

void idDeclDuck::Parse( idParser * parser ) {
	memset( groupVolume, 0, sizeof( groupVolume ) );
	idToken token;
	while ( parser != NULL && parser->ReadToken( token ) ) {
		if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) break;
		if ( idStr::Icmp( token.c_str(), "layer" ) == 0 ) {
			parser->ExpectTokenString( "=" ); layer = parser->ParseInt(); parser->CheckTokenString( ";" );
			continue;
		}
		const int index = DuckGroupIndex( token.c_str() );
		parser->ExpectTokenString( "=" );
		const float value = parser->ParseFloat();
		parser->CheckTokenString( ";" );
		if ( index >= 0 ) groupVolume[ index ] = value;
		else parser->Warning( "Unknown sound duck group '%s'", token.c_str() );
	}
}

bool idDeclDuck::RebuildTextSource() {
	static const char * names[ 25 ] = {
		"ui", "music_menu", "music_ingame", "sfx_general", "amb_core", "amb_spot",
		"explosions", "key_events", "impacts", "rico_bys", "movement_ai", "movement_pl",
		"veh_ai", "veh_pl", "veh_collisions_ai", "veh_collisions_pl", "weapons_ai",
		"weapons_pl", "special_enemy_movement", "special_enemy_voice", "vo_player",
		"vo_event", "vo_ingame", "vo_radio", "vo_battle"
	};
	idStr text; text.Format( "{\nlayer = %d\n", layer );
	for ( int i = 0; i < 25; ++i ) if ( groupVolume[ i ] != 0.0f ) {
		char line[ 128 ]; _snprintf_s( line, sizeof( line ), _TRUNCATE, "%s = %f\n", names[ i ], groupVolume[ i ] );
		text.Append( line );
	}
	text.Append( "}" ); SetText( text.c_str() ); return true;
}

idDeclInfo * idDeclDuck::GetDeclInfo() const { return &resourceList; }

