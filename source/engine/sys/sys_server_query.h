#pragma once

#include "sys_lobby.h"

// Server-query state recovered from the retail PDB.  The packet behavior is
// implemented in sys_server_query.cpp from the matching Hex-Rays functions.
class idServerQuery {
public:
	struct serverQueryInfo_t {
		serverQueryInfo_t();

		lobbyConnectInfo_t connectInfo;
		lobbyAddress_t addr;
		int lastAttemptTime;
		int attempts;
		bool acked;
		serverInfo_t serverInfo;
	};

	static void HandleServerQueryRequest( idLobby & partyLobby, idLobby & gameLobby,
		lobbyAddress_t & remoteAddr, idBitMsg & msg, idLobby::lobbyType_t lobbyType,
		int msgType, unsigned int checksum );

	bool Pump( idLobby & partyLobby, unsigned int checksum );
	void HandleQueryAck( lobbyAddress_t & addr, idBitMsg & msg );
	void AddServerToQuery( const lobbyConnectInfo_t & connectInfo,
		const lobbyAddress_t & addr );

	idStaticList< serverQueryInfo_t, 32 > servers;
};
