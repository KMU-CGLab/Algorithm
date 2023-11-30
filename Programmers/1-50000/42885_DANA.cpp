#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //정렬
    sort(people.begin(),people.end());
    
    int maxIdx=people.size()-1;
    
    //투포인터 이용
    int i;
    for(i=0;i<maxIdx;i++){
        while(maxIdx>i){
            if(people[i]+people[maxIdx]<=limit){
                maxIdx--;
                break;
            }
            else{
                answer++;
            }
            maxIdx--;
        }
        answer++;
    }
    
    //마지막 남은 한개 더해주기 사이즈가 홀수인 경우
    if(i==maxIdx) answer++;
    
    return answer;
}