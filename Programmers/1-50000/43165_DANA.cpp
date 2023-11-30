#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> num;
int count;

void bfs(int idx, int level,int target){
    if(idx==num.size()){
        if(level==target){
            count+=1;
        }
        return;
    }
    else{
        //그다음의 수를 더하는 경우
        bfs(idx+1,level+num[idx],target);
        //그다음의 수를 빼는 경우
        bfs(idx+1,level-num[idx],target);
    }
}

//bfs
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    num = numbers;
    count=0;
    bfs(0,0,target);
    answer= count;
    
    return answer;
}