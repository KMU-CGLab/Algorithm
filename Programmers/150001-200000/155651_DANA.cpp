#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소 후 다음 손님 사용 가능

return 코니에게 필요한 최소 객실의 수

*/

bool cmp(vector<string> lValue, vector<string> rValue){
    return lValue<rValue;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int,int>> endTime;
    
    sort(book_time.begin(),book_time.end(),cmp);

    //만약 룸의 끝나는 시간이 시작 시간보다 빠르다면 그 방을 이어서 사용
    //그렇지 않다면 새로운 방을 생성
    for(int i=0;i<book_time.size();i++){
        string startStr = book_time[i][0];
        int sHour = stoi(startStr.substr(0,2));
        int sMinute = stoi(startStr.substr(3,2));
        
        string str = book_time[i][1];
        int hour = stoi(str.substr(0,2));
        int minute = stoi(str.substr(3,2));
        
        int cleanHour=hour;
        int cleanMinute=minute;
        if(minute+10>=60){
            cleanHour+=1;
            cleanMinute-=50;
        }
        else{
            cleanMinute+=10;
        }


        bool isCheckIn=false;
        for(int j=0;j<endTime.size();j++){
            if((endTime[j].first==sHour&&endTime[j].second<=sMinute)||endTime[j].first<sHour){
                //기존 방에 체크인
                isCheckIn=true;
                endTime[j].first = cleanHour;
                endTime[j].second = cleanMinute;
                break;
            }
        }
        if(!isCheckIn){
            //새로운 방 생성
            endTime.push_back(make_pair(cleanHour,cleanMinute));
        }
    }
    
    return endTime.size();
}