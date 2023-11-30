#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int size = 0;
    
    priority_queue<int,vector<int>,less<int>> pq;
    priority_queue<int,vector<int>,greater<int>> pqG;
    
    
    for(int i=0;i<operations.size();i++){
        stringstream ss(operations[i]);
        string first,second;
        ss>>first>>second;
        if(first=="I"){
            pq.push(stoi(second));
            pqG.push(stoi(second));
            size++;
        }
        else{           //D
            if(size>0){
                if(second=="1"){
                    //최솟값 삭제
                    if(pq.size()>0){
                        pq.pop();
                        size--;
                    }
                }
                else{
                    //최댓값 삭제
                    if(pqG.size()>0){
                        pqG.pop();
                        size--;
                    }
                }
                
            }
        }
        //size==0 인 경우 순서가 헷갈릴수 있기 때문에 clear해줘야함
        if(size==0){
            pq= priority_queue<int,vector<int>,less<int>>();
            pqG = priority_queue<int,vector<int>,greater<int>>();
        }
    }
    
    if(size==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else if(size==1){
        if(pq.size()==0){
            answer.push_back(pqG.top());
            answer.push_back(pqG.top());
        }
        else if(pqG.size()==0){
            answer.push_back(pq.top());
            answer.push_back(pq.top());
        }
    }
    else{
        answer.push_back(pq.top());
        answer.push_back(pqG.top());
    }
    
    return answer;
}