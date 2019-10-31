#include<iostream>
#include<fstream>
#include <time.h>

using namespace std;

#define NUMENTRIES 50
#define COMMA ","

int getTrafficFlow(char lightStatus);
int getredLightFlow(char lightStatus, int time);
int getBatteryPowerLevel(int batterpct);
char getBulbStatus();

int main() {
	//seed is taken as time to make each run different
	srand(time(NULL));
	//initialize ofstream, exit if file cannot open
	ofstream dataWriter("Random.csv");
	if (!dataWriter.good()) {
		cout << "Could Not create file";
		return -1;
	}
	//first line for csv
	string pipelineRoute[] = { "Spokane" , "Great Falls" };
	dataWriter << "Sensor ID, Sensor IP Address, Pipe Route, Flow Level, Viscosity, Temperature, GPS Position, Battery Level, Free Space on Hard Drive, WiFi Signal";
	for (int i = 0; i < NUMENTRIES; i++) {

	}

}

