#include <iostream>
using namespace std;

class RockStar {
    public: 
    int getNumSongs(int ff, int fs, int sf, int ss) { 
        if(fs > sf)	return ff + 2*sf + ss + 1; // ff -> fs -> ss -> sf -> fs 
        else if(fs == 0) return ff > 0 ? ff : ss + min(sf, 1);
        // sf >= fs
        else return ff + 2*fs + ss; // ff -> fs -> ss -> sf
    } 
};