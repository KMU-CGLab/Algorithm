// 연속한 자연수의 합
// Brute Force

#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    
    int Total = 0;
    int Start = 1;
    while(Start <= n)
    {
        for(int i = Start; i <= n; ++i)
        {
            Total += i;

            if(Total >= n)
                break;
        }

        if(Total == n)
            answer++;

        Start++;
        Total = 0;
    }

    return answer;
}