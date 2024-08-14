// 12907 : 거스름돈 Lv3
// 중복조합은 안됨
// DP를 잘 이해해야함

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>

#define SORT(x) x.begin(), x.end()

using namespace std;

void combination(const vector<int>& arr, int r, int index, long& count)
{
    if (r == 0)
    {
        count++;
        return;
    }
    else if (index == arr.size())
    {
        return;
    }
    else
    {
        if (r - arr[index] < 0) return;

        // 뽑고 다음에 똑같은거 또 뽑을 것
        combination(arr, r - arr[index], index, count);
        
        // 안뽑고 다음
        combination(arr, r, index + 1, count);
    }
}

int solution(int n, vector<int> money) {
    
    long count = 0;
    int size = money.size();
    int dp[n + 1];
    
    sort(SORT(money), less<int>());
    
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    
    for(int i = 0; i < size; i++)
    {
        int coin = money[i];
        
        for(int j = coin; j < n + 1; j++)
        {
            // 2원 차례에서,
            // 3원 : 2원 쓰고, 1원 쓰는 방법
            // 4원 : 2원 쓰고, 2원 쓰는 방법
            dp[j] += dp[j - coin];
        }
    }
    
    count = dp[n];
    
    return count % 1000000007;
}