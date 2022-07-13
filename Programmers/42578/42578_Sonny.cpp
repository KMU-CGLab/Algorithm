// self -> hint -> sol
// sol 사용

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> map_cloth = map<string, int>();
    
    for(auto i : clothes)
    {
        int k = 0;
        for(auto j : i)
        {
            // 홀 수 번째 string이 옷의 종류를 의미
            // 옷의 이름은 의미가 없음
            if(k % 2 == 1)
            {
                if(map_cloth.count(j) == 0)
                {
                    // 아무것도 잆지 않은 경우의 수 + 이 옷 종류를 등록
                    map_cloth.insert({j, 2});
                }
                else
                {
                    // 이미 옷 종류가 들어가있다면 갯수만 ++
                    map_cloth[j]++;
                }
            }
            
            k++;
        }
    }
    
    int multi = 1;
    for(auto k : map_cloth)
    {
        // 각 옷 종류를 골라 잆는 경우의 수
        multi *= k.second; 
    }
    
    answer = multi;
    
    // 아무것도 잆지 않는 경우의 수
    answer--;
    
    return answer;
}