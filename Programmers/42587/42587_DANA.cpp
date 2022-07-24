#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int index=0;

    deque<pair<int,int>> print;
    //우선순위 큐 사용 (자기 자신보다 큰 값이 있는지 체크용)
    priority_queue <int> prioPrint;

    for(int i=0;i<priorities.size();i++){
        print.push_back(make_pair(priorities[i],i));
        prioPrint.push(priorities[i]);
    }
    
    while(print.size()>0){
        pair<int,int> temp = print[0];
        print.pop_front();
        if(prioPrint.top()==temp.first){        //자기 자신보다 큰게 있다면
            prioPrint.pop();
            index++;
            if(temp.second==location)
                break;
        }
        else{
            print.push_back(temp);
        }
    }

    answer=index;
    
    return answer;
}