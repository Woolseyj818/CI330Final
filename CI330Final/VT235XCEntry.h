#pragma once
#include"SensorID.h"

class VT235XCEntry
{
	//dataWriter << "Sensor ID,Sensor IP Address, Pipe Route, Flow Level, Flow Speed, Viscosity, Temperature, GPS Position, Battery Level, Free Space on Hard Drive, WiFi Signal";
	
public:
	SensorID sid;
	int ID;
	int IP;
	int route;
	int flowLevel;
	int viscosity;
	int temperature;
	int gpsPos;
	int batterPct;
	int freeSpace;
	int wifiSignal;
	VT235XCEntry(int id = 0, int ip = 0, int route = 0, int flowLevel = 0, int viscosity = 0, int temperature = 0, int gpsPos = 0, int batteryPct = 0, int freeSpace = 0, int wifiSignal = 0);
	VT235XCEntry(SensorID sid, int route = 0, int flowLevel = 0, int viscosity = 0, int temperature = 0, int gpsPos = 0, int batteryPct = 0, int freeSpace = 0, int wifiSignal = 0);
	~VT235XCEntry();
};

