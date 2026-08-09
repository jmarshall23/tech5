/*
===========================================================================

  Snapshot serializer diagnostics recovered from the idTech 5 executable.

  The Xbox decompilation loses several aggregate argument types in the GUI
  calls.  The reporting decisions, cvars, commands, field comparisons and
  emitted text below follow the recovered code; drawing is expressed through
  the platform-neutral idRenderModelGui facade used by the Windows sys layer.

===========================================================================
*/

#include "network_precompiled.h"
#include "snapshot.h"
#include "snapshotmetrics.h"

#include "../../shared/idlib/color.h"

#include <cstdio>

idCVar net_snapshot_metrics( "net_snapshot_metrics", "1", CVAR_BOOL,
	"Enables snapshot metrics" );
idCVar net_snapshot_metrics_report_mode( "net_snapshot_metrics_report_mode", "3", CVAR_INTEGER,
	"What to do when we report metrics: 0=Nothing, 1=Print to console log, 2=Log to network metrics server, 3=both" );
idCVar net_snapshot_metrics_report_netrole( "net_snapshot_metrics_report_netrole", "3", CVAR_INTEGER,
	"Who should do the reporting. 0=No one, 1=Server only, 2=Clients only, 3=Both" );
idCVar net_snapshot_metrics_report_seq( "net_snapshot_metrics_report_seq", "100", CVAR_INTEGER,
	"Minimum snap sequence to report. Used to not report initial snapshots" );
idCVar net_snapshot_metrics_report_size( "net_snapshot_metrics_report_size", "2000", CVAR_INTEGER,
	"Report snapshot metrics snapshot delta is greater than this size" );
idCVar net_snapshot_metrics_report_fragment( "net_snapshot_metrics_report_fragment", "1", CVAR_BOOL,
	"Report snapshot metrics when delta fragments" );
idCVar net_snapshot_metrics_report_wait( "net_snapshot_metrics_report_wait", "30000", CVAR_INTEGER,
	"Minimum time to wait between generating snapshot reports" );
idCVar net_snapshot_metrics_report_once_per_deltaseq(
	"net_snapshot_metrics_report_once_per_deltaseq", "1", CVAR_BOOL,
	"If true, only generate reports one time per base sequence per peer. Prevents spam if base states arent being ACKd" );
idCVar net_snapshot_metrics_skipZero( "net_snapshot_metrics_skipZero", "1", CVAR_BOOL,
	"Skips objects that didnt change in metric report" );
idCVar net_snapshot_gui_scale( "net_snapshot_gui_scale", "0.75", CVAR_FLOAT, "GUI scale" );

idSnapshotMetrics snapshotMetrics;

namespace {

bool SnapshotStringContains( const char * text, const char * search ) {
	if ( text == NULL || search == NULL ) {
		return false;
	}
	if ( search[ 0 ] == '\0' ) {
		return true;
	}
	const int searchLength = static_cast< int >( std::strlen( search ) );
	for ( const char * cursor = text; *cursor != '\0'; ++cursor ) {
		if ( _strnicmp( cursor, search, searchLength ) == 0 ) {
			return true;
		}
	}
	return false;
}

int CompressionSizeForObject( const idSerializerLog & log, int objectID ) {
	for ( int index = 0; index < log.compressionEntries.Num(); ++index ) {
		if ( log.compressionEntries[ index ].objID == objectID ) {
			return log.compressionEntries[ index ].csize;
		}
	}
	return 0;
}

idVec4 SnapshotColorVector( const idColor & color ) {
	return idVec4( color.r, color.g, color.b, color.a );
}

void MetricWriteMessage( idMetricFile * metricFile, idBitMsg & message ) {
	if ( metricFile == NULL || metricFile->fileHandle == NULL ) {
		return;
	}
	std::fwrite( message.GetWriteData(), 1, message.GetSize(),
		static_cast< FILE * >( metricFile->fileHandle ) );
}

} // namespace

idSnapshotMetrics::idSnapshotMetricRecord::idSnapshotMetricRecord()
	: idMetricRecord( idStr( "SnapshotReport" ) ) {
}

void idSnapshotMetrics::idSnapshotMetricRecord::SerializeEntry( idMetricFile * metricFile ) {
	if ( metricFile == NULL || metricFile->fileHandle == NULL ) {
		return;
	}
	idMetricRecord::SerializeEntry( metricFile );
	byte buffer[ 5120 ];
	idBitMsg message( buffer, sizeof( buffer ) );
	message.BeginWriting();
	message.WriteString( text.c_str(), -1, true );
	MetricWriteMessage( metricFile, message );
}

void idSnapshotMetrics::idSnapshotMetricRecord::WriteHeader( idMetricFile * metricFile ) {
	if ( metricFile == NULL || metricFile->fileHandle == NULL ) {
		return;
	}
	idMetricRecord::WriteHeader( metricFile );
	byte buffer[ 128 ];
	idBitMsg message( buffer, sizeof( buffer ) );
	message.BeginWriting();
	message.WriteBits( 1, 32 );
	message.WriteString( "SnapshotReport", -1, true );
	message.WriteBits( 6, 32 );
	MetricWriteMessage( metricFile, message );
}

idSnapshotMetrics::idSnapshotMetrics()
	: printNextReport( false ),
	  SNAPSHOTS_DRAW_SCALE( net_snapshot_gui_scale.GetFloat() ),
	  SNAPSHOTS_Y_OFFSET( 25.0f ), SNAPSHOTS_X_OFFSET( 20.0f ),
	  SNAPSHOTS_Y_SPACING( net_snapshot_gui_scale.GetFloat() * 15.0f ),
	  curY( 25.0f ), width( 400 ), height( 50 ), nameLen( 30 ),
	  lastReportMS( 0 ), guiOffset( 0 ), nextKeyEvent( 0 ) {
	for ( int index = 0; index < peerSeq.Num(); ++index ) {
		peerSeq[ index ] = 0;
	}
}

void idSnapshotMetrics::ProcessEvent( const sysEvent_t * event ) {
	if ( event == NULL || event->evType != SE_KEY || event->evValue2 == 0 ||
		nextKeyEvent >= Sys_Milliseconds() ) {
		return;
	}
	if ( event->evValue == K_MWHEELUP ) {
		--guiOffset;
	} else if ( event->evValue == K_MWHEELDOWN ) {
		++guiOffset;
	} else {
		return;
	}
	nextKeyEvent = Sys_Milliseconds() + 100;
}

bool idSnapshotMetrics::ShouldShowEntry( idSerializerLog * log,
		const idSerializerLog::logEntry_t & entry ) {
	bool filtered = false;
	if ( watchList.Num() > 0 ) {
		bool matched = false;
		for ( int index = 0; index < watchList.Num(); ++index ) {
			matched = matched || SnapshotStringContains( entry.typeName.c_str(), watchList[ index ].c_str() ) ||
				SnapshotStringContains( entry.instanceName.c_str(), watchList[ index ].c_str() );
		}
		filtered = !matched;
	}
	for ( int index = 0; index < ignoreList.Num(); ++index ) {
		if ( SnapshotStringContains( entry.typeName.c_str(), ignoreList[ index ].c_str() ) ||
			SnapshotStringContains( entry.instanceName.c_str(), ignoreList[ index ].c_str() ) ) {
			filtered = true;
		}
	}

	// A filtered parent is retained when any descendant survives.  This is the
	// recursive behavior visible in the recovered routine and preserves the
	// hierarchy needed to understand watched leaf entries.
	if ( filtered && log != NULL ) {
		for ( int index = 0; index < log->logEntries.Num(); ++index ) {
			const idSerializerLog::logEntry_t & child = log->logEntries[ index ];
			if ( child.parentObjID == entry.objID && ShouldShowEntry( log, child ) ) {
				return true;
			}
		}
		return false;
	}
	return true;
}

void idSnapshotMetrics::NewLine( bool print, idRenderModelGui * gui, idStr * output ) {
	if ( gui != NULL ) {
		curY += SNAPSHOTS_Y_SPACING;
		++height;
	}
	if ( print ) {
		idLib::Printf( "\n" );
	}
	if ( output != NULL ) {
		output->Append( "\n" );
	}
}

int idSnapshotMetrics::OutputLine( const char * text, bool print, idColor color,
		idRenderModelGui * gui, idStr * output ) {
	const char * safeText = text != NULL ? text : "";
	int stringWidth = 0;
	if ( gui != NULL ) {
		// The retail renderer computes this from the active debug font.  Its
		// Windows-facing GUI facade exposes drawing only, so retain the retail
		// scale and use the font's eight-pixel cell for panel sizing.
		stringWidth = static_cast< int >( std::strlen( safeText ) * 8.0f * SNAPSHOTS_DRAW_SCALE );
		gui->DrawString( SNAPSHOTS_X_OFFSET, curY, safeText,
			SnapshotColorVector( color ), true, SNAPSHOTS_DRAW_SCALE );
	}
	if ( output != NULL ) {
		output->Append( safeText );
	}
	if ( print ) {
		idLib::Printf( "%s", safeText );
	}
	NewLine( print, gui, output );
	return stringWidth;
}

void idSnapshotMetrics::GenerateReport( idSnapShot & snapshot,
		const idSnapShot * oldSnapshot, int sequence, int baseSequence, int peer,
		idRenderModelGui * gui, bool reportMetrics, bool printConsole ) {
	if ( oldSnapshot == NULL ) {
		return;
	}
	idSerializerLog * log = snapshot.GetSerializerLog();
	idSerializerLog * oldLog = oldSnapshot->GetSerializerLog();
	if ( log == NULL || oldLog == NULL ) {
		return;
	}

	lastReportMS = Sys_Milliseconds();
	const bool print = printConsole || printNextReport;
	printNextReport = false;
	idSnapshotMetricRecord metricRecord;
	idStr * metricText = reportMetrics ? &metricRecord.text : NULL;

	SNAPSHOTS_DRAW_SCALE = net_snapshot_gui_scale.GetFloat();
	SNAPSHOTS_Y_SPACING = SNAPSHOTS_DRAW_SCALE * 15.0f;
	curY = SNAPSHOTS_Y_OFFSET;
	if ( gui != NULL ) {
		gui->DrawFilled( idVec4( 0.0f, 0.0f, 0.0f, 0.85f ),
			SNAPSHOTS_X_OFFSET - 10.0f, SNAPSHOTS_Y_OFFSET - 10.0f,
			static_cast< float >( width + 20 ),
			static_cast< float >( height + 6 ) * SNAPSHOTS_Y_SPACING );
		width = 0;
		height = 0;
	}

	idStr line;
	line.Format( "%-*s | obj sz| delta | compr | ", nameLen, "Object" );
	width = (std::max)( width, OutputLine( line.c_str(), print,
		idColor::colorWhite, gui, metricText ) );
	OutputLine( "---------------------------------------------------------------------------", print,
		idColor::colorMdGrey, gui, metricText );

	log->finalUncompressedSize = 0;
	int longestName = 0;
	const int lastEntry = (std::max)( 1, log->logEntries.Num() - 1 );
	guiOffset = idMath::ClampInt( 1, lastEntry, guiOffset );
	bool outputRoot = false;

	for ( int index = 1; index < log->logEntries.Num(); ++index ) {
		const idSerializerLog::logEntry_t & entry = log->logEntries[ index ];
		if ( entry.objID < 0 && entry.parentObjID < 0 ) {
			continue;
		}

		int depth = 0;
		int parent = entry.parent;
		for ( int guard = 0; parent > 0 && parent < log->logEntries.Num() && guard < 64; ++guard ) {
			++depth;
			parent = log->logEntries[ parent ].parent;
		}
		if ( depth == 0 && outputRoot ) {
			NewLine( print, index >= guiOffset ? gui : NULL, metricText );
		}

		idStr objectName;
		for ( int indent = 0; indent < depth; ++indent ) {
			objectName.Append( "   " );
		}
		objectName.Append( entry.typeName );
		objectName.Append( ": " );
		objectName.Append( entry.instanceName );
		longestName = (std::max)( longestName, objectName.Length() );

		const int objectSize = entry.end - entry.start;
		int deltaSize = 0;
		int compressedSize = 0;
		idStr annotation;
		idColor color = idColor::colorGreen;

		if ( entry.objID >= 0 ) {
			log->finalUncompressedSize += objectSize;
			compressedSize = CompressionSizeForObject( *log, entry.objID );
			if ( oldSnapshot->FindObjectIndexByID( entry.objID ) < 0 ) {
				deltaSize = objectSize;
				annotation = "NEW";
				color = idColor::colorYellow;
			} else {
				deltaSize = snapshot.CompareObject( oldSnapshot, entry.objID );
			}
		} else {
			const int oldIndex = oldLog->Find( entry.parentObjID,
				entry.typeName.c_str(), entry.instanceName.c_str() );
			if ( oldIndex < 0 ) {
				deltaSize = objectSize;
				annotation = "NEW";
				color = idColor::colorYellow;
			} else {
				const idSerializerLog::logEntry_t & oldEntry = oldLog->logEntries[ oldIndex ];
				deltaSize = snapshot.CompareObject( oldSnapshot, entry.parentObjID,
					entry.start, entry.end, oldEntry.start );
				if ( oldEntry.start != entry.start ) {
					annotation.Append( va( "START OFF (%d != %d) ", oldEntry.start, entry.start ) );
					color = idColor::colorCyan;
				}
				if ( oldEntry.startWriteBit != entry.startWriteBit ) {
					annotation.Append( va( "START WRITEBIT (%d != %d) ",
						oldEntry.startWriteBit, entry.startWriteBit ) );
					color = idColor::colorOrange;
				}
				if ( oldEntry.endWriteBit != entry.endWriteBit ) {
					annotation.Append( va( "END WRITEBIT (%d != %d) ",
						oldEntry.endWriteBit, entry.endWriteBit ) );
					color = idColor::colorOrange;
				}
				if ( oldEntry.end - oldEntry.start != objectSize ) {
					annotation.Append( va( "SIZE CHANGE (%d != %d) ",
						oldEntry.end - oldEntry.start, objectSize ) );
					color = idColor::colorRed;
				}
			}
		}

		if ( ( net_snapshot_metrics_skipZero.GetBool() && deltaSize == 0 ) ||
			!ShouldShowEntry( log, entry ) ) {
			continue;
		}

		line.Format( "%-*s | %5d | %5d | %5d | %s", nameLen,
			objectName.c_str(), objectSize, deltaSize, compressedSize,
			annotation.c_str() );
		idRenderModelGui * lineGui = index >= guiOffset ? gui : NULL;
		width = (std::max)( width, OutputLine( line.c_str(), print, color,
			lineGui, metricText ) );
		outputRoot = true;
	}
	nameLen = (std::max)( 1, longestName );

	if ( log->finalCompressedSize > 0 && log->finalUncompressedSize > 0 ) {
		int rleCompressedSize = 0;
		for ( int index = 0; index < log->compressionEntries.Num(); ++index ) {
			rleCompressedSize += log->compressionEntries[ index ].csize;
		}
		OutputLine( "---------------------------------------------------------------------------", print,
			idColor::colorMdGrey, gui, metricText );
		NewLine( print, gui, metricText );
		if ( log->fragmented ) {
			OutputLine( "FRAGMENTED", print, idColor::colorRed, gui, metricText );
			NewLine( print, gui, metricText );
		}

		line.Format( "Total Size:       %6d", log->finalUncompressedSize );
		OutputLine( line.c_str(), print, idColor::colorGreen, gui, metricText );
		line.Format( "RLE Compressed:   %6d", rleCompressedSize );
		OutputLine( line.c_str(), print, idColor::colorGreen, gui, metricText );
		line.Format( "Final Compressed: %6d", log->finalCompressedSize );
		OutputLine( line.c_str(), print, idColor::colorGreen, gui, metricText );
		NewLine( print, gui, metricText );
		line.Format( "Time: %6d  Delta: %4d", snapshot.GetTime(),
			snapshot.GetTime() - oldSnapshot->GetTime() );
		OutputLine( line.c_str(), print, idColor::colorWhite, gui, metricText );
		line.Format( "Seq:  %6d  Delta: %4d", sequence, sequence - baseSequence );
		OutputLine( line.c_str(), print, idColor::colorWhite, gui, metricText );
		line.Format( "Objs: %6d  Compr: %4d", snapshot.NumObjects(),
			log->compressionEntries.Num() );
		OutputLine( line.c_str(), print, idColor::colorWhite, gui, metricText );
		line.Format( "Peer[%d]    Time: %d", peer, Sys_Milliseconds() - lastReportMS );
		OutputLine( line.c_str(), print, idColor::colorWhite, gui, metricText );
	}

	if ( reportMetrics ) {
		metricRecord.Serialize();
	}
}

void idSnapshotMetrics::LogSnapshotDelta( idSnapShot & snapshot,
		const idSnapShot * oldSnapshot, int sequence, int baseSequence, int peer,
		int size, bool fullSnapshot ) {
	bool shouldReport = false;
	if ( sequence > net_snapshot_metrics_report_seq.GetInteger() ) {
		if ( std::abs( size ) > net_snapshot_metrics_report_size.GetInteger() ) {
			idLib::Printf( "\n^2Snapshot delta for peer %d exceeded warn size. Delta Size: %d\n",
				peer, size );
			shouldReport = true;
		} else if ( !fullSnapshot && net_snapshot_metrics_report_fragment.GetBool() ) {
			idLib::Printf( "\n^2Snapshot delta for peer %d fragmented. Delta Size: %d\n",
				peer, size );
			shouldReport = true;
		}
	}

	if ( !shouldReport || lastReportMS + net_snapshot_metrics_report_wait.GetInteger() > Sys_Milliseconds() ) {
		return;
	}
	if ( peer < 0 || peer >= peerSeq.Num() ) {
		return;
	}
	if ( net_snapshot_metrics_report_once_per_deltaseq.GetBool() && peerSeq[ peer ] >= baseSequence ) {
		return;
	}
	const int role = net_snapshot_metrics_report_netrole.GetInteger();
	if ( ( common->IsServer() && ( role & 1 ) == 0 ) ||
		( common->IsClient() && ( role & 2 ) == 0 ) ) {
		return;
	}

	peerSeq[ peer ] = baseSequence;
	const int mode = net_snapshot_metrics_report_mode.GetInteger();
	GenerateReport( snapshot, oldSnapshot, sequence, baseSequence, peer, NULL,
		( mode & 2 ) != 0, ( mode & 1 ) != 0 );
}

CONSOLE_COMMAND_COMPILE( net_snapshot_metrics_watch,
	"Only show snapshot metrics containg this", NULL ) {
	snapshotMetrics.watchList.Append( idStr( args.Argv( 1 ) ) );
}

CONSOLE_COMMAND_COMPILE( net_snapshot_metrics_ignore,
	"Ignore snapshot metrics containing this name", NULL ) {
	snapshotMetrics.ignoreList.Append( idStr( args.Argv( 1 ) ) );
}

CONSOLE_COMMAND_COMPILE( net_snapshot_metrics_clear,
	"Clear named watch/ignore", NULL ) {
	snapshotMetrics.ignoreList.Clear();
	snapshotMetrics.watchList.Clear();
}

CONSOLE_COMMAND_COMPILE( net_snapshot_metrics_print,
	"Prints next snapshot report to console log", NULL ) {
	snapshotMetrics.printNextReport = true;
}
