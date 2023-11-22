#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[60001];
//가로길이 1 세로 길이 2
//2 * n 바닥을 채우기 방법 갯수
//점화식 dp[i] = dp[i-1] + dp[i-2]
int solution(int n) {
    int answer = 0;
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=1000000007;
    }  
    
    answer = dp[n-1];
    
    return answer;
}