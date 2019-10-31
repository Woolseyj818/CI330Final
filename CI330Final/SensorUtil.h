#pragma once
#include"SensorID.h"
#include"VT235XCEntry.h"
#include<chrono>

namespace SensorUtil {
	SensorID* generateID(int numIDs, int seed = 0);
	VT235XCEntry genSensorData(SensorID sid, int seed = 0);
}