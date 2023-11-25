// [줄 서는 방법]
// 1 2 3 사람이 있다면 다음과 같이 줄 서는 바업 6가지
// 123, 132, 213, 231, 312, 321 
// 숫자를 나열해서 작은 숫자대로 차례대로
// k번째 경우의 수 구하기 (4번째라면 231이 정답)

// 숫자를 전부 나열하고 k번째로 큰 숫자를 구해야함 (k는 인덱스니까 -1 함)
// k / (n-1)! : 제일 앞에 줄 설 사람 고정 (줄 안 선 사람들이 남음)
// ex) 4 / 2 = 2 -> [2] 번째 사람 : 3 선택
// k % (n-1)! = q : 남은 사람중에 몇 번째
// q / (n-2)! 줄 안 선 사람 중, 2번째로 줄 설 사람
// ...

#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 제발 부등호 똑바로 확인! (1시간 넘게[ 잡아먹음)
// 제발 타입을 잘 살피자 (long long) -> 효율성 체크에서 걸림
long long Factorial(int Number)
{
    if(Number == 0)
        return 0;
    
    long long result = 1;

    for(int i = 1; i <= Number; ++i)
    {
        result *= i;
    }

    return result;
}

vector<int> solution(int n, long long k) 
{
    vector<int> answer;
    vector<int> NumberPool;
    
    // 혹시 모르는 제한사항
    long long FactorialNumber = Factorial(n);
    n = n > 20 ? 20 : n;
    k = k > FactorialNumber ? FactorialNumber : k;

    int Decender = n;
    long long DivideNumber = FactorialNumber / Decender;
    
    // 인덱스니까 1번째를 찾으려면 0번째
    long long ModifiedK = k - 1;

    for(int i = 1; i <= n; ++i)
    {
        NumberPool.push_back(i);
    }

    while(NumberPool.size() > 0)
    {   
        int InsertIndex = ModifiedK / DivideNumber;
        int InsertNumber = NumberPool[InsertIndex];

        answer.push_back(InsertNumber);
        NumberPool.erase(NumberPool.begin() + InsertIndex);

        ModifiedK = ModifiedK % DivideNumber;
        Decender--;

        if(Decender == 0)
            break;

        DivideNumber /= Decender;
    }

    return answer;
}