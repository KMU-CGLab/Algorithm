#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const pair<int,int>& lValue,const pair<int,int>& rValue){
    return lValue.second>rValue.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<pair<int,int>> tangerinePair;
    
    sort(tangerine.begin(),tangerine.end());

    int prev = tangerine[0];
    tangerinePair.push_back(make_pair(tangerine[0],0));
    for(int i=0;i<tangerine.size();i++){
        if(prev==tangerine[i]){
            tangerinePair[tangerinePair.size()-1].second++;
        }
        else{
            tangerinePair.push_back(make_pair(tangerine[i],1));
            prev=tangerine[i];
        }
    }
    
    sort(tangerinePair.begin(),tangerinePair.end(),cmp);
    
    int count=0;
    for(int i=0;i<tangerinePair.size();i++){
        if(count>=k) break;
        count+=tangerinePair[i].second;
        answer++;
    }
    
    
    return answer;
}