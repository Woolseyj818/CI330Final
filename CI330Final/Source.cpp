#include<iostream>
#include<fstream>
#include <time.h>
#include"SensorID.h"
#include"SensorUtil.h"
#include"Argp.h"
#include"Args.h"

using namespace std;

#define NUMENTRIES 50
#define COMMA ","
#define NUMVT 3
#define NUMPSX 2
#define BIFLAGS "oi"
#define UFLAGS "ac"

int main(int argc, char** argv) {
	Args* args;
	if (argc < 2) {
		return 0;
	}
	else {
		args = parseArgs(argc, argv, UFLAGS, 2 ,BIFLAGS , 2);
	}
	//seed is taken as time to make each run different
	srand(time(NULL));
	//initialize ofstream, exit if file cannot open
	ofstream dataWriter("Random.csv");
	if (!dataWriter.good()) {
		cout << "Could Not create file";
		return -1;
	}
	string pipelineRoute[] = { "Spokane" , "Great Falls" };
	//first line for csv
	dataWriter << "Sensor ID, Sensor IP Address, Pipe Route, Flow Level, Viscosity, Temperature, GPS Position, Battery Level, Free Space on Hard Drive, WiFi Signal";
	SensorID* sids = SensorUtil::generateID(NUMVT);
	for (int i = 0; i < NUMENTRIES; i++) {
		
		for (int sensornum = 0; sensornum < NUMVT; sensornum++) {
			SensorUtil::genVTEntry(sids[0], 4);
			
		}

	}

	delete[] sids;
}

