#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> appliers;
vector<string> place;
int pCount,oCount;

//만약 원하는 comp가 j,z에 있는 경우 카운트
void getCount(int j,int z,string comp,string origin){
    if(j>=0&&j<5&&z>=0&&z<5){
        string tmp;
        tmp = place[j].substr(z,1);
        if(tmp==comp&&origin=="P") pCount++;
        else if(tmp==comp&&origin=="O") oCount++;
    }
}

//방마다 체크를 함
// O의 경우 위아래 양옆으로 P의 갯수를 체크 -> 2개 이상이면 P가 대각선으로 존재하면서 O(테이블)이 있는 경우이기에 거리두기가 안됨
// P의 경우 위아래 양옆으로 P의 갯수 체크 -> 거리를 지키지 않음으로 1개 이상이면 거리두기가 안됨
bool checkAround(){
    for(int j=0;j<5;j++){
        for(int z=0;z<5;z++){   //room row
            pCount=0;oCount=0;
            string val = place[j].substr(z,1);
            if(val=="P"){
                //up
                getCount(j-1,z,"P","P");
                //down
                getCount(j+1,z,"P","P");
                //right
                getCount(j,z+1,"P","P");
                //left
                getCount(j,z-1,"P","P");
            }
            else if(val=="O"){
                //up
                getCount(j-1,z,"P","O");
                //down
                getCount(j+1,z,"P","O");
                //right
                getCount(j,z+1,"P","O");
                //left
                getCount(j,z-1,"P","O");
            }
            
            //if pCount>=1 oCount>=2
            if(pCount>=1||oCount>=2)
                return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    
    for(int i=0;i<5;i++){       //room
        place = places[i];
        pCount=0;
        oCount=0;
        
        if(!checkAround()) answer.push_back(0);
        else answer.push_back(1);
        
    }
    
    return answer;
}