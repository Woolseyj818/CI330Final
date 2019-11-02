#pragma once
#include"SensorID.h"
#include"VT235XCEntry.h"
#include"PSX25Entry.h"
#include<chrono>

namespace SensorUtil {
	SensorID* generateID(int numIDs, int seed = 0);
	VT235XCEntry genVTEntry(SensorID sid, int seed = 0);
	PSX25Entry genPSXEntry(SensorID sid, VT235XCEntry* downline, int numDownlineSensors, int seed = 0);
}