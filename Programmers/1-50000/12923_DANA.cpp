#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int getValue(long long value){
    if(value==1) return 0;
    else{
        int idx=0;
        for (long long i = 2; i <= sqrt(value); i++) {  //빠른 소수 찾기
            if (value%i == 0&&value/i<=10000000) {  //블록이 10000000까지기 때문에
                cout<<value/i;
                return value/i;
            }
            else if(value%i == 0){
                idx=i;
            }
        }
        if(idx>0)
            return idx;
        return 1;
    }
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i=begin;i<=end;i++)
        answer.push_back(getValue(i));
    
    return answer;
}