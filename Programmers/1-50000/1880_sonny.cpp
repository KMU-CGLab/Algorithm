// 1880 : 땅따먹기 Lv2
// DP
// DP[y][x]는 DP[y-1][i] + land[y][x], 여기서 i =! x
// 현재층 기준, 자신 + 이전 층 중에 max 값 (단, 이전층과 같은 열은 제외)

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int bottom = land.size();
    int DP[bottom][4];
    
    DP[0][0] = land[0][0];
    DP[0][1] = land[0][1];
    DP[0][2] = land[0][2];
    DP[0][3] = land[0][3];
    
    int y = 1;
    int x = 0;
    while(y < bottom)
    {
        DP[y][x] = 0;
        
        for(int i = 0; i < 4; i++)
        {
            if(x == i)
                continue;
            
            int candidate = land[y][x] + DP[y - 1][i];
            DP[y][x] = max(DP[y][x], candidate);
        }
        
        x++;
        
        if(x == 4)
        {
            y++;
            x = 0;
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        answer = max(answer, DP[bottom - 1][i]);
    }
    
    return answer;
}