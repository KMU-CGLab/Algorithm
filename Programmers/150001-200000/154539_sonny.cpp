// 154538 : 뒤에 있는 큰 수 찾기 Lv2
// 사고력 문제
// 뒤에서 서칭
// stack 구조 사용

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer = vector<int>(numbers.size(), -1);
    vector<int> stack;
    
    for(int i = numbers.size() - 1; i >= 0; i--)
    {
        int number = numbers[i];
        
        while(true)
        {
            if(stack.empty())
            {
                break;
            }
            else if(stack.back() > number)
            {
                answer[i] = stack.back();
                break;
            }
            
            stack.pop_back();
        }
        stack.push_back(number);
    }
    
    return answer;
}