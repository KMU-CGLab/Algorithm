// 76502 : 괄호 회전하기 Lv2
// 아이디어가 어렵진 않음
// 더 쾌적한 알고리즘을 구현하려다가 실패
// Queue와 Stack은 iteration이 없음! -> 순회가 불가능함

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) 
{
    int answer = 0;;
    
    int start = 0;
    const int length = s.length();
    const string ss = s + s;
    
    map<char, char> matchMap;
    matchMap.emplace(')', '(');
    matchMap.emplace('}', '{');
    matchMap.emplace(']', '[');
    
    stack<char> bracketStack;
    
    // 짝이 맞지 않아서 불가능한 케이스
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        char sign = s[i];
        
        sum += matchMap.count(sign) ? 1 : -1;
    }
    if(sum != 0)
    {
        return 0;
    }
        
    do
    {
        for(int i = start; i < start + length; i++)
        {
            char sign = ss[i];
            bool isOpen = matchMap.count(sign) == 0;
            
            // 아무것도 없거나, 여는 괄호라면 무조건 push
            if(bracketStack.size() == 0 || isOpen)
            {
                bracketStack.push(sign);
                continue;
            }
        
            // 닫는 괄호는 무조건 매칭돼서 사라져야함
            if(bracketStack.top() != matchMap[sign])
            {
                break;
            }

            // 모든 조건이 통과되면 올바른 pop 가능
            bracketStack.pop();
        }

        if(bracketStack.size() == 0)
        {
            answer++;
        }
        
        start++;
        bracketStack = stack<char>();  // clear
        
    } while(start < length);
    
    return answer;
}