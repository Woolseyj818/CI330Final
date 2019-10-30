#include<iostream>
#include<fstream>
#include <time.h>

using namespace std;

#define NUMENTRIES 5000
#define COMMA ","

int getTrafficFlow(char lightStatus);
int getredLightFlow(char lightStatus,int time);
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
	string sensorNames[] = { "NS1" ,"NS2","EW1","EW2" };
	dataWriter << "Sensor,Traffic Flow,Red Light Flow,Battery Power Level%,Light Status,Bulb Status,Accident Status,Gunshot \n";
	int timeSinceChange = 0;
	int batterypct = 90;
	char lightColor = 'G';
	for (int sensor = 0; sensor < 4; sensor++) {
		if (sensor > 1)
			lightColor = 'R';
		for (int i = 0; i < NUMENTRIES; i++) {
			dataWriter << sensorNames[sensor].c_str() << COMMA;
			//Write to first field, traffic flow
			int trafficFlow = getTrafficFlow(lightColor);
			dataWriter << trafficFlow << COMMA;
			//Write to second field, red light flow
			int redLightFlow = getredLightFlow(lightColor, timeSinceChange);
			dataWriter << redLightFlow << COMMA;
			//write Battery Power level%
			batterypct = getBatteryPowerLevel(batterypct);
			dataWriter << batterypct << COMMA;
			//write Light Status
			dataWriter << lightColor << COMMA;
			//write Bulb Status
			char bulbOut = getBulbStatus();
			if (bulbOut != ' ')
				dataWriter << bulbOut << COMMA;
			else
				dataWriter << "N/A" << COMMA;
			//write Accident Status
			bool accidentStatus = (rand() % 1000) == 0;
			dataWriter << accidentStatus << COMMA;
			//write gunshot status
			int gunShotStatus = (rand() % 100) > 90;
			dataWriter << gunShotStatus << COMMA;
			//check to change the light
			if (timeSinceChange >= 90) {
				if (lightColor == 'A' || lightColor == 'G') {
					lightColor = 'R';
				}
				else if (lightColor == 'R') {
					lightColor = 'G';
				}
				timeSinceChange = 0;
			}
			else if (timeSinceChange >= 75) {
				if (lightColor == 'G') {
					lightColor = 'A';
				}
			}
			//end row, increment "time"
			dataWriter << endl;
			timeSinceChange += 3;
		}
	}
}

int getTrafficFlow(char lightStatus)
{
	if (lightStatus == 'G' || lightStatus == 'A')
		return rand() % 25;
	return 0;
}

int getredLightFlow(char lightStatus,int time)
{
	if (lightStatus == 'R') {
		if (rand() % (time * time) < 20)
			return rand() % 3 + 1;
	}
	return 0;
}

int getBatteryPowerLevel(int batterpct)
{
	return (rand() % 50 + 5) + (batterpct / 2);
}

char getBulbStatus()
{
	bool bulbIsOut = (rand() % 1000) == 0;
	char bulbType = ' ';
	if (bulbIsOut) {
		int bulbOut = rand() % 3;
		switch (bulbOut) {
		case 0:
			bulbType = 'G';
			break;
		case 1:
			bulbType = 'A';
			break;
		default:
			bulbType = 'R';
			break;
		}
	}
	return bulbType;
}
