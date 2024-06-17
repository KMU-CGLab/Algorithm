// 12973 : 짝지어 제거하기 Lv2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> stack;
    
    stack.push_back(s[0]);
    for(int i = 1; i < s.length(); i++)
    {
        char c = s[i];
        
        // 없으면 넣기
        if(stack.size() == 0)
        {
            stack.push_back(c);
            continue;
        }
        
        // 하나라도 있다면
        if(stack.back() == c)
        {
            stack.pop_back();
        }
        else
        {
            stack.push_back(c);
        }
    }
    
    return stack.size() == 0;
}