#pragma once

// PDB-authoritative declarations for w:\tech5\engine\network\snapshotmetrics.h.
// The implementation is recovered from the matching idTech 5 executable.

class idSnapshotMetrics {
public:
	class idSnapshotMetricRecord : public idMetricRecord {
	public:
		idSnapshotMetricRecord();
		~idSnapshotMetricRecord() override = default;
		void WriteHeader( idMetricFile * metricFile ) override;
		void SerializeEntry( idMetricFile * metricFile ) override;

		idStr text;
	};

	idSnapshotMetrics();

	void ProcessEvent( const sysEvent_t * event );
	void GenerateReport( idSnapShot & snapshot, const idSnapShot * oldSnapshot,
		int sequence, int baseSequence, int peer, idRenderModelGui * gui,
		bool reportMetrics, bool printConsole );
	void LogSnapshotDelta( idSnapShot & snapshot, const idSnapShot * oldSnapshot,
		int sequence, int baseSequence, int peer, int size, bool fullSnapshot );

	idStaticList< idStr, 16 > ignoreList;
	idStaticList< idStr, 16 > watchList;
	bool printNextReport;
	float SNAPSHOTS_DRAW_SCALE;
	float SNAPSHOTS_Y_OFFSET;
	float SNAPSHOTS_X_OFFSET;
	float SNAPSHOTS_Y_SPACING;
	float curY;
	int width;
	int height;
	int nameLen;
	int lastReportMS;
	int guiOffset;
	int nextKeyEvent;
	idArray< int, 6 > peerSeq;

private:
	bool ShouldShowEntry( idSerializerLog * log,
		const idSerializerLog::logEntry_t & entry );
	void NewLine( bool print, idRenderModelGui * gui, idStr * output );
	int OutputLine( const char * text, bool print, idColor color,
		idRenderModelGui * gui, idStr * output );
};

extern idSnapshotMetrics snapshotMetrics;
extern idCVar net_snapshot_metrics;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idSnapshotMetrics::idSnapshotMetricRecord ) == 100,
	"Recovered snapshot metric record ABI changed" );
static_assert( sizeof( idSnapshotMetrics ) == 1128,
	"Recovered idSnapshotMetrics ABI changed" );
#endif
