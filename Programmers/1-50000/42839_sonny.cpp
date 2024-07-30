// 42839 : 소수 찾기 Lv2
// next_permutation 할 때, 꼭 오름차순 정렬!

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool IsPrimeNum(int num)
{
    if(num <= 1)
        return false;
    
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    const int numLength = numbers.length();
    set<int> dictionary = set<int>();
    
    int digitNum = 1;
    while(digitNum <= numLength)
    {
        vector<bool> combination = vector<bool>(numLength, false);

        // 자릿수 정하기, 정렬
        int startIndex = numLength - digitNum;
        for(int i = startIndex; i < numLength; i++)
        {
            combination[i] = true;
        }
        
        // 1자릿수, 2자릿수, ...
        do
        {
            // 자릿수 대로 숫자 만들기
            string number;
            for(int i = 0; i < numLength; i++)
            {
                if(combination[i])
                {
                    number += numbers[i];
                }
            }
            sort(number.begin(), number.end());

            // 만들어진 숫자를 가지고 순열
            do
            {
                int realNumber = stoi(number);
                
                // 이미 한 숫자
                if(dictionary.count(realNumber) > 0)
                    continue;
                
                // 소수 체크
                if( IsPrimeNum(realNumber) )
                {
                    answer++;
                    dictionary.emplace(realNumber);
                }
    
            } while(next_permutation( number.begin(), number.end() ));
        }
        while ( next_permutation( combination.begin(), combination.end() ) );
        
        digitNum++;
    }
    
    return answer;
}