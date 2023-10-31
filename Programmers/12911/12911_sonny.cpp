#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    uint32_t max_n = 1000000;
    int BitCount = 0;
    int tmp_n = n;
    int BinaryCount = 0;

    // 주어진 수의 비트 갯수 구하기
    while (tmp_n / 2 > 0)
    {
        tmp_n /= 2;
        BitCount++;
    }

    // Shift 연산을 통해, 10진수를 2진수로 표현하고, 
    // 2진수 중 1인 비트 수 체크
    for (int i = BitCount; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            BinaryCount++;
        }
    }

    // 1인 비트 수가 같은 다음 수 구하기
    int counter = 1;
    while (true)
    {
        int tmp_n = n + counter;
        int BinaryCount2 = 0;

        // 2진수 중 1인 비트 수 체크
        for (int i = BitCount + 1; i >= 0; i--)
        {
            if ((tmp_n >> i) & 1)
            {
                BinaryCount2++;
            }
        }

        // Find out next number!
        if (BinaryCount == BinaryCount2)
        {
            answer = n + counter;
            break;
        }
        
        counter++;
    }

    return answer;
}