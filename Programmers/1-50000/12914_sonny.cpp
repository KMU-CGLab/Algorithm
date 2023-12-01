// 12914, 멀리 뛰기
// dp
// 규칙 찾아보면, 점화식이 피보나치의 형태를 띄고잇음
// mod 1234567 타이밍이 모호함

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long GetFibonacci(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    int k1 = 1;
    int k2 = 2;
    int kn = k1 + k2;
    for(int i = 3; i < n; i++)
    {
        k1 = k2;
        k2 = kn;
        kn = (k1 + k2) % 1234567;
    }
    
    return kn;
}

long long solution(int n) 
{
    long long answer = 0;
    
    answer = GetFibonacci(n);
    
    return answer;
}