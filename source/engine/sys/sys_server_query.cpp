/*
===========================================================================

Licensed idTech 5 source recovery.
Behavior and constants in this file are reconstructed from the Tungsten
retail Hex-Rays dump and PDB type information.

===========================================================================
*/

#pragma hdrstop
#include "sys_precompiled.h"
#include "sys_server_query.h"

idServerQuery::serverQueryInfo_t::serverQueryInfo_t() :
	lastAttemptTime( -1 ),
	attempts( 0 ),
	acked( false ) {
}

void idServerQuery::HandleServerQueryRequest( idLobby & partyLobby,
	idLobby & gameLobby, lobbyAddress_t & remoteAddr, idBitMsg & msg,
	idLobby::lobbyType_t lobbyType, int msgType, unsigned int checksum ) {
	(void)msgType;
	NET_VERBOSE_PRINT( "HandleServerQueryRequest from %s\n", remoteAddr.ToString() );

	bool canJoin = static_cast< unsigned int >( msg.ReadLong() ) == checksum;
	if ( !canJoin ) {
		NET_VERBOSE_PRINT( "idServerQuery::HandleServerQueryRequest: Invalid version from %s\n", remoteAddr.ToString() );
	}

	idLobby & targetLobby = lobbyType == idLobby::TYPE_GAME ? gameLobby : partyLobby;
	if ( !targetLobby.IsHost() ) {
		NET_VERBOSE_PRINT( "idServerQuery::HandleServerQueryRequest: Not host of target lobby\n" );
		canJoin = false;
	}
	if ( targetLobby.NumFreeSlots() == 0 || gameLobby.NumFreeSlots() == 0 ) {
		NET_VERBOSE_PRINT( "idServerQuery::HandleServerQueryRequest: No free slots.\n" );
		canJoin = false;
	}

	idLocalUser * masterUser = session != NULL && session->HasSignInManager()
		? session->GetSignInManager().GetMasterLocalUser() : NULL;
	if ( masterUser == NULL ) {
		canJoin = false;
	}

	idLobby & activeLobby = gameLobby.IsRunningAsHostOrPeer() ? gameLobby : partyLobby;
	byte buffer[ idPacketProcessor::MAX_PACKET_SIZE - 2 ];
	idBitMsg reply( buffer, sizeof( buffer ) );
	reply.WriteBool( canJoin );

	if ( canJoin ) {
		serverInfo_t serverInfo;
		serverInfo.joinable = session->GetState() >= idSession::LOADING;
		serverInfo.serverName = masterUser->GetGamerTag();
		if ( gameLobby.IsRunningAsHostOrPeer() ) {
			serverInfo.gameMap = gameLobby.GetMatchParms().gameMap;
			serverInfo.gameMode = gameLobby.GetMatchParms().gameMode;
		} else {
			serverInfo.gameMap = -1;
			serverInfo.gameMode = -1;
		}
		serverInfo.numPlayers = activeLobby.GetNumActiveLobbyUsers();
		serverInfo.maxPlayers = activeLobby.GetMatchParms().numSlots;
		serverInfo.Write( reply );
	}

	partyLobby.SendConnectionLess( remoteAddr, idLobby::OOB_MATCH_QUERY_ACK,
		reply.GetReadData(), reply.GetSize() );
}

bool idServerQuery::Pump( idLobby & partyLobby, unsigned int checksum ) {
	int ackCount = 0;
	for ( int index = 0; index < servers.Num(); ++index ) {
		serverQueryInfo_t & query = servers[ index ];
		if ( query.acked ) {
			++ackCount;
			continue;
		}

		const int now = Sys_Milliseconds();
		if ( query.lastAttemptTime != -1 && now - query.lastAttemptTime <= 2000 ) {
			continue;
		}
		if ( query.attempts >= 5 ) {
			servers.RemoveIndex( index-- );
			continue;
		}

		byte buffer[ idPacketProcessor::MAX_PACKET_SIZE - 2 ];
		idBitMsg request( buffer, sizeof( buffer ) );
		NET_VERBOSE_PRINT( "UpdateQueryServers: Hash version: %i, sending to: %s\n",
			checksum, query.addr.ToString() );
		request.WriteLong( checksum );
		partyLobby.SendConnectionLess( query.addr, idLobby::OOB_MATCH_QUERY,
			request.GetReadData(), request.GetSize() );
		query.lastAttemptTime = now;
		++query.attempts;
	}

	if ( servers.Num() != ackCount ) {
		return false;
	}
	NET_VERBOSE_PRINT( "idServerQuery::Pump: DONE (%i acks)\n", ackCount );
	return true;
}

void idServerQuery::HandleQueryAck( lobbyAddress_t & addr, idBitMsg & msg ) {
	NET_VERBOSE_PRINT( "HandleQueryAck: Response from %s\n", addr.ToString() );
	for ( int index = 0; index < servers.Num(); ++index ) {
		serverQueryInfo_t & query = servers[ index ];
		if ( query.acked || !query.addr.Compare( addr, false ) ) {
			continue;
		}

		NET_VERBOSE_PRINT( "HandleQueryAck: Response from %s ACKED\n", addr.ToString() );
		if ( msg.ReadBool() ) {
			query.acked = true;
			query.serverInfo.Read( msg );
			return;
		}
		servers.RemoveIndex( index );
		return;
	}
}

void idServerQuery::AddServerToQuery( const lobbyConnectInfo_t & connectInfo,
	const lobbyAddress_t & addr ) {
	for ( int index = 0; index < servers.Num(); ++index ) {
		if ( servers[ index ].addr.Compare( addr, false ) ) {
			return;
		}
	}

	serverQueryInfo_t query;
	query.connectInfo = connectInfo;
	query.addr = addr;
	servers.Append( query );
}
