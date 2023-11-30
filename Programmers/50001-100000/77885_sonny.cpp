// 77885 : 2개 이하로 다른 비트
// #규칙 찾기 #2진수 변환 #bitset

#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <cmath>

// 0000
// 0001

// 0010
// 0011 3 -> 안됨

// 0100 4 -> 됨
// 0101 5 -> 됨  // 2
// 0110 6 -> 됨
// 0111 7 -> 안됨

// 1000 8 -> 됨
// 1001 9 -> 됨
// 1010 10 -> 됨
// 1011 11 -> 안됨 -> 13
// 1100 12
// 1101 13
// 1110 14

// 01111 15  // 4
// 10001 16
// 10010 17
// 10011 18
// 10100 19
// 10101 20
// 10110 21
// 10111 22  // 16 + 4 + 2 + 1 -> 8
// 11000 23
// 11001 24
// 11010 25
// 11011 26

// 011111 31
// 100000
// 101111 (32 + 8 + 4+ 2 + 1) 47 -> 16

// 00
// 01
// 10
// 11 -> 문제 발생 -> pow(2, 1);
// 연속 1 카운트 -> pow(2, n-1);

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    
    for(const auto number : numbers)
    {
        const uint8_t bit_size = sizeof(number) * 8;
        unsigned long long casted_number = (unsigned long long)number;
        bitset<bit_size> binary_number = {casted_number};

        int continuous = -1;
        for(int i = 0; i < bit_size; ++i)
        {
            if((casted_number >> i) & 1)
                continuous++;
            else
                break;
        }
        
        if(continuous < 0)
            continuous = 0;
        
        unsigned long long next_number = casted_number + pow(2, continuous);
        
        answer.push_back(next_number);
    }
    
    return answer;
}