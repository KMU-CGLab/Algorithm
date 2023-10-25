#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //완전 탐색
    int sum = brown+yellow;
    for(int i=2;i<sum;i++){
        if(sum%i!=0) continue;
        else
        {
            if((i-2)*(sum/i-2)==yellow)
            {
                answer.push_back(sum/i);
                answer.push_back(i);
                break;
            }
            else continue;
        }
    }
    
    return answer;
}