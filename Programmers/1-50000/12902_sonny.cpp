// 3 x n 타일링, Dynamic Programming

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<long long> DP;
    
    if(n % 2 != 0)
    {
        answer = 0;
    }
    else
    {   
        DP.push_back(3);  // 2
        
        int Loop = n / 2;
        for(int i = 1; i < Loop; ++i)  // 4부터 케이스 발생
        {
            long long dp = DP[i - 1] * 3;
            for(int j = 2; j <= i; ++j)  // 6부터 케이스 발생
            {
                dp += DP[i - j] * 2;
            }
            dp += 2;
            dp = dp % 1000000007;
            DP.push_back(dp);
        }
    }
    
    int index = (n / 2) - 1;
    answer = DP[index];
    
    return answer;
}