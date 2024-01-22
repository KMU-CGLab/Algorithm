// 43105 : 정수 삼각형 LV.3
// 중복되는 곳은 큰 값으로 초기화 하는 것이 포인트

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int MaxLevel;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    MaxLevel = triangle.size();

    vector<int> first;
    first.push_back(triangle[0][0]);
    vector<vector<int>> dp;
    dp.push_back(first);
        
    // 현재 레벨에서 출발
    for(int Lv = 0; Lv < MaxLevel - 1; Lv++)
    {
        int MaxDegree = triangle[Lv].size();
        dp.push_back(vector<int>(MaxDegree + 1));

        // 현재 위치에서
        for(int deg = 0; deg < MaxDegree; deg++)
        {
            // 아래 층으로, 왼쪽 오른쪽으로 분기
            for(int i = 0; i < 2; i++)
            {
                int origin = dp[Lv + 1][deg + i];
                int compare = dp[Lv][deg] + triangle[Lv + 1][deg + i];
                
                // 중복되는 곳은 큰 값으로 선택
                dp[Lv + 1][deg + i] = max(origin, compare);

                answer = max(answer, compare);
            }
        }
    }
    
    // for(int i = 0; i < dp.size(); i++)
    // {
    //     for(int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return answer;
}