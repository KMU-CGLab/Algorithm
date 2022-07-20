#include <string>
#include <vector>
#include<queue>
#include<cmath>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    
    //필요한 날짜 저장
    for(int i=0;i<progresses.size();i++){
        day.push(ceil((100-progresses[i])/(float)speeds[i]));
        cout<<ceil((100-progresses[i])/(float)speeds[i])<<endl;
    }
    
    //비교할 day 설정
    int dayNum=day.front();
    int taskNum=0;          //누적된 일의 갯수
    while(day.size()>0){
        if(dayNum<day.front()){
            dayNum=day.front();
            answer.push_back(taskNum);      //누적된 일 처리
            taskNum=1;                      //day 갱신하면서 처리되는 일
        }
        else{
            taskNum++;                      //앞의 일이 더 오래 걸리면 쌓이는 처리될 일
        }
        day.pop();
    }
    
    answer.push_back(taskNum);
    
    return answer;
}