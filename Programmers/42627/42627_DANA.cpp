#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int currentTime;

//시작시간 기준으로
bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0])
        return a[1]>b[1];
    else
        return a[0]>b[0];
}

//실행시간 위주로
bool cmp2(vector<int> a, vector<int> b){
    if(currentTime>a[0]&&currentTime>b[0]){
            return a[1]>b[1];
    }
    else if(currentTime<a[0]&&currentTime<b[0]){
        if(a[0]+a[1]==b[0]+b[1])
            return a[1]>b[1];
        else
            return a[0]+a[1]>b[0]+b[1];
    }
    else if(currentTime>=a[0]){
        if(a[0]+a[1]==b[0]+b[1])
            return a[1]>b[1];
        else{
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]>b[0];
        }
    }
    else if(currentTime>=b[0]){
        if(a[0]+a[1]==b[0]+b[1])
            return a[1]>b[1];
        else
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]>b[0];
    }
    else{
        if(a[0]==b[0])
            return a[1]>b[1];
        else if(a[0]==0){
            if(a[0]+a[1]>b[0]+b[1])
                return false;
            else
                return true;
        }
        else if(b[0]==0){
             if(a[0]+a[1]<b[0]+b[1])
                return false;
            else
                return true;
        }
        else{
            if(a[0]+a[1]==b[0]+b[1])
                return a[0]>b[0];
            else
                return a[0]+a[1]>b[0]+b[1];
        }
    }
    
}

int solution(vector<vector<int>> jobs) {
    int answer = 0,costTime=0;
    currentTime=0;
    int size=jobs.size();
   
    while(jobs.size()>0){
         make_heap(jobs.begin(),jobs.end(),cmp);        //시작시간 기준으로 정렬
        
        //0번이 대기중이면 (뒤에도 대기가 있을 수 있음)
        if(jobs[0][0]<=currentTime){
            //작은 경우 [0]+[1]이 제일 빠른 순서대로 해야함, 경우에 따라 달라지기 때문에 다시 정렬
            make_heap(jobs.begin(),jobs.end(),cmp2);
            //정렬된 것중 제일 먼저 처리해야할 jobs[0]의 시작 시간이 현재 시간보다 작다면
            currentTime+=jobs[0][1];
            costTime = currentTime-jobs[0][0];
        }
        else{       //jobs[0]의 시작 시간이 현재 시간보다 크다면
            currentTime = jobs[0][0]+jobs[0][1];
            costTime = jobs[0][1];
        }

        jobs.erase (jobs.begin(),jobs.begin()+1);       //처리한 job은 지워줌

        answer+=costTime;
    }
    answer/=size;
    return answer;
}