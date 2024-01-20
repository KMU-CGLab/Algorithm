#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <stack>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str); // [istringstream 에 데이터를 담음]
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer); // [특정 문자 기준 분리된 문자열을 vector 에 저장]
    }

    // [리턴 반환 실시]
    return result;
}

struct taskNode{
    string taskName;
    int startTime,costTime;
    taskNode(string name,int sT,int cT):taskName(name),startTime(sT),costTime(cT){}
    
    bool operator<(const taskNode s) const{
        return this->startTime > s.startTime;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<taskNode> task;
    stack<taskNode> stopTask;

    int length = plans.size();
    for(int i=0;i<length;i++){
        vector<string> result;
        result = split(plans[i][1].c_str(),':');
        printf("%s ",plans[i][1].c_str());
        int startT = stoi(result[0])*60+stoi(result[1]);
        task.push(taskNode(plans[i][0],startT,stoi(plans[i][2])));
    }
    
    taskNode tn = task.top();
    int currentTime=tn.startTime;
    
    while(!task.empty()){
        tn = task.top();
        if(!stopTask.empty()){
            taskNode sn = stopTask.top();
            stopTask.pop();
            if(tn.startTime>currentTime){
                task.push(taskNode(sn.taskName,currentTime,sn.costTime));
                continue;
            }
            else{
                stopTask.push(taskNode(sn.taskName,currentTime,sn.costTime));
            }
        }
        task.pop();
        
        taskNode NextNode = task.top();    
        currentTime = tn.startTime + tn.costTime;

        if(currentTime <= NextNode.startTime)
            answer.push_back(tn.taskName);           
        else
        {
            currentTime = NextNode.startTime;
            stopTask.push(taskNode(tn.taskName, tn.startTime, tn.costTime - (NextNode.startTime - tn.startTime)));
        }
        
    }
    
    while(!stopTask.empty()){
        taskNode tskNode = stopTask.top();
        stopTask.pop();
        answer.push_back(tskNode.taskName);
    }
    
    return answer;
}