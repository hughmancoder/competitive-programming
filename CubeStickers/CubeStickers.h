#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>
using namespace std;

class CubeStickers{
    public:
        string isPossible(vector<string> sticker);

};

string CubeStickers::isPossible(vector<string> sticker){

    int total = 0;
    int temp = 0;
    while(total < 6 && sticker.size()>0){
        temp = 1;
        total++;
        for (int i = 1; i < sticker.size(); i++){
            if(sticker[i] == sticker[0] && temp < 2){
                total++;
                temp++;
                sticker.erase(sticker.begin()+i);
                i--;
            }else if(sticker[i] == sticker[0] && temp == 2){
                sticker.erase(sticker.begin()+i);
                i--;
            }
        }



        sticker.erase(sticker.begin());


        
        
        
    }

    if(total >= 6){
        return "YES";
    }

    return "NO";

}