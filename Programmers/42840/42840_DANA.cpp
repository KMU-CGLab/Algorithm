#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> i,pair<int,int> j){
    return i.second>j.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int student1[5]={1,2,3,4,5};
    int student2[8]={2,1,2,3,2,4,2,5};
    int student3[10]={3,3,1,1,2,2,4,4,5,5};
    
    vector<pair<int,int>> Count;
    Count.push_back(make_pair(1,0));
    Count.push_back(make_pair(2,0));
    Count.push_back(make_pair(3,0));
    //맞은 갯수 카운팅
    for(int i=0;i<answers.size();i++){
        if(answers[i]==student1[i%5]) Count[0].second++;
        if(answers[i]==student2[i%8]) Count[1].second++;
        if(answers[i]==student3[i%10]) Count[2].second++;
    }

    //맞은 갯수가 큰 것 별로 정렬
    sort(Count.begin(),Count.end(),compare);

    int max=Count[0].second;        //max 값 = 맞은 갯수가 가장 큰 수
    for(int i=0;i<Count.size();i++){
        if(max==Count[i].second) {
            answer.push_back(Count[i].first);   //만약 맞은 갯수가 같다면 해당 값도 넣기
        }
        else break;     //그렇지 않다면 더이상 계산할 필요가 없음
    }
    
    //오름차순으로 정렬
    sort(answer.begin(),answer.end());
    
    return answer;
}