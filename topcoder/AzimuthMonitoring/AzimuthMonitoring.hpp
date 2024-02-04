#include <string>
#include <vector>
#include <iostream>
using namespace std;
class AzimuthMonitoring {
    public:

    /* "LEFT" - turn left 90 degrees

    "RIGHT" - turn right 90 degrees

    "TURN AROUND" - turn around (a 180 degree turn)

    "LEFT X" - turn left X degrees, where X is a positive integer

    "RIGHT X" - turn right X degrees, where X is a positive integer

    "HALT" - stop executing instructions; further instructions are not executed */
    int getAzimuth(vector<string> instructions) {
        int azimuth = 0;
        for (int i = 0; i < instructions.size(); i++) {
        string instruction = instructions[i];
            // cout << instruction << " " << instruction.substr(0,4) << endl;
            // correct azimuth
            if(instruction == "LEFT") {
                azimuth -= 90;
            }
            else if (instruction == "RIGHT") {
                azimuth += 90;
            }
            // LEFT X
            else if (instruction.length() >= 6 && instruction.substr(0,4) == "LEFT") {
                int X = stoi(instruction.substr(4,instruction.length()));
                azimuth -= X;
            }
            // RIGHT X
            else if (instruction.length() >= 6 && instruction.substr(0,5) == "RIGHT") {
                
                int X = stoi(instruction.substr(5,instruction.length()));
                azimuth += X;
            }    
            if (instruction == "TURN AROUND") {
                azimuth += 180;

            }
            if (instruction == "HALT") {
                return azimuth;
            }

            azimuth %= 360;
            if (azimuth <= 0) {
                azimuth += 360;
            }
            if (azimuth >= 360) {
                azimuth -= 360;
            }
        }
        return azimuth;
    }
};