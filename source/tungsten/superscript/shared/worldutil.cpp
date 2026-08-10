#include "superscript/shared/worldutil.h"

#include "superscript/lib/sys.h"

// ?Init@ssWorldUtil@@UAAXXZ (0x82EECD50)
void ssWorldUtil::Init() {
    if (self.spawnId == ssEntity("world").spawnId) {
        world = ssEntity("world");
        player1 = ssEntity("player1");
        player2 = ssEntity("player2");
        player3 = ssEntity("player3");
        player4 = ssEntity("player4");
        player5 = ssEntity("player5");
        player6 = ssEntity("player6");
        player7 = ssEntity("player7");
        player8 = ssEntity("player8");
        return;
    }

    Error(ssString(
        "ssWorldUtil should only be placed on the world entity (worldspawn)."));
}
