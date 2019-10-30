#pragma once
class VT235XCEntry
{
	//dataWriter << "Sensor ID,Sensor IP Address, Pipe Route, Flow Level, Flow Speed, Viscosity, Temperature, GPS Position, Battery Level, Free Space on Hard Drive, WiFi Signal";
	
public:
	int ID;
	int IP;
	int route;
	int flowLevel;
	int Viscosity;
	int Temperature;
	int GPSPos;
	int BatterPct;
	int FreeSpace;
	int WifiSignal;
	VT235XCEntry();
	~VT235XCEntry();
};

