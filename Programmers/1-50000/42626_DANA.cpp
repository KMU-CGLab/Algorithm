#include <string>
#include <vector>
#include<queue>
#include<functional>
#include<iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 1;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        
        int first=pq.top();     //가장 맵지 않은 음식의 스코빌 지수
        if(!pq.empty())
            pq.pop();
        int second=pq.top()*2;  //(두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
        if(!pq.empty())
            pq.pop();
        //스코빌 지수
        int scoville = first+second;
        pq.push(scoville);
        int top = pq.top();
        //만약 스코빌 지수가 크지 않거나 사이즈가 2이하일때
        if(top>=K||pq.size()<2){
            break;
        }
        else{
            answer++;
        }
    }
    //사이즈가 2 이하일때, 가장 작은 스코빌 지수가 K를 넘지 않는다면 더이상 K이상으로 만들수 없음
    if(pq.size()<2&&pq.top()<K){ 
        answer=-1;
    }
    
    return answer;
}