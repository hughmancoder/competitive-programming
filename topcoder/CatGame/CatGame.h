#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CatGame
{
    public:
        int getNumber(vector<int> coordinates, int X);
};

int CatGame::getNumber(vector<int> coordinates, int X){
    vector<vector<int>> cats;
    if(coordinates.size() == 1){return 0;}
    int min = 200000000;
    for (int i = 0; i < coordinates.size(); i++){
        vector<int> temp;
        temp.push_back(coordinates[i]+X);
        temp.push_back(coordinates[i]-X);
        cats.push_back(temp);
    }

    

    for (int i = 0; i < coordinates.size(); i++){
        for (int k = 0; k < coordinates.size(); k++){
            if(k == i){continue;}
            for (int j = 0; j < 2; j++){
                for(int l = 0; l < 2; l++){
                    int bottom = cats[i][j];
                    int top = cats[k][l];
                    if(top < bottom){continue;}
                    int total = 0;
                    for(int m = 0; m < coordinates.size(); m++){
                        
                        if((cats[m][0] >= bottom && cats[m][0] <= top) || (cats[m][1] >= bottom && cats[m][1] <= top)){
                            //cout << "here" << endl;
                        }else{
                            //cout << top << "   " << bottom << "    "<< cats[m][0] << cats[m][1] << endl;
                            total +=1;
                            break;
                        }
                    }
                    //cout << total << endl;
                    if(total == 0){
                        if(min > (top - bottom)){min = top - bottom;}
                    }
                    
                }
            }
        }
    }
    
    return min;
    
}
