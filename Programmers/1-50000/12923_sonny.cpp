// 12923 : 숫자 블록 Lv2

#include <vector>
#include <cmath>

using namespace std;

const int blockEnd = 10000000;

int GetCommonDivisor(int num)
{
    int limit = sqrt(num);
    int Q = 1;
    int R = 1;
        
    // a의 약수 중 천만 이하, 그리고 자신을 제외한 가장 큰 약수
    for(int i = 2; i <= limit; i++)
    {   
        if( (num % i == 0) )
        {
            // 약수 중에 큰 수
            Q = max(i, num / i);
            R = min(i, num / i);
            
            // 큰 수가 10 000 000 보다 작다면 ㅇㅋ
            if(Q <= blockEnd)
            {
                break;
            }
        }
    }
    
    // Q에 10000000보다 큰 수가 담겨 있으면 반대 값
    return Q > blockEnd ? R : Q;
}

vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;
    
    if(begin == 1)
    {
        answer.push_back(0);
        begin++;
    }
    
    for(long long i = begin; i <= end; i++)
    {   
        int block = GetCommonDivisor(i);
        
        answer.push_back(block);
    }

    return answer;
}