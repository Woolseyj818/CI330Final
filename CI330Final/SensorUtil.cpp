#include "SensorUtil.h"

enum Route {SPOKAN, GREATFALLS};

//Creates an array of IDS
SensorID* SensorUtil::generateID(int numIDs, int seed)
{
	if (numIDs <= 0) {
		return nullptr;
	}
	if (seed = 0) {
		seed = time(NULL);
	}
	srand(seed);
	SensorID* ids;
	ids = new SensorID[numIDs];
	for (int i = 0; i < numIDs; i++) {
		ids[i].ID = i;
		ids[i].IP = rand() % 254 + 1;
		for (int j = i; j > 0; j--) {
			if (ids[i].IP == ids[j - 1].IP) {
				ids[i].IP++;
			}
		}
	}
	return ids;
}

VT235XCEntry SensorUtil::genVTEntry(SensorID sid, int seed = 0)
{
	if (seed = 0) {
		seed = time(NULL);
	}
	srand(seed);
	VT235XCEntry v;

	return v;
}

PSX25Entry SensorUtil::genPSXEntry(SensorID sid, VT235XCEntry * downline, int numDownlineSensors, int seed) {
	PSX25Entry px;
	
	return px;
}
