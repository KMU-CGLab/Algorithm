#include <string>
#include<map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,string> kind;
    map<string,int> num;
    
    for(int i=0;i<clothes.size();i++){
        
        //만약 존재한다면
        if(num.count(clothes[i][1])>0){
            num[clothes[i][1]]++;
        }
        //존재하지 않는다면
        if(kind.count(clothes[i][0])==0){
            kind.insert({clothes[i][0],clothes[i][1]});
            num.insert({clothes[i][1],1});
        }
    }

    int sum=1;
    //(n+1)*(m+1) : 모든 경우의 수
    for(auto iter:num)
        sum*=iter.second+1;
    
    if(num.size()==1) answer = kind.size();
    else answer = sum-1;        //아무것도 입지 않은 경우를 빼줌
    
    return answer;
}