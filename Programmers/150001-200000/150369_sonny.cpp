// 150369 : 택배 배달과 수거하기 LV.2
// 그리디 문제
// 택배차의 cap이 하나지만, delivery의 cap과  pickup의 cap을 따로 생각해도 됨
// 예시 1번때문에 헷갈리면 안됨 (택배를 가지고 갔다가 아무집이나 주면 되니까, 굳이 처음에 3개를 가져갈 이유가 없음)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;
    
    int d = 0;
    int p = 0;
    int count = 0;
    
    for(int i = n - 1; i >= 0; i--)
    {
        // 배달 할 집 설정
        d += deliveries[i];
        p += pickups[i];
        
        while(1)
        {
            if(d <= 0 && p <= 0)
                break;
            
            d -= cap;
            p -= cap;
            
            count++;
        }
        
        answer += (i + 1) * 2 * count;
        count = 0;
    }
    
    
    return answer;
}