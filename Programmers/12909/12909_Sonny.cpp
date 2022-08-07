#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    // container에 하나씩 담기 시작
    // (을 발견하면 + 1, )를 발견하면 -1 해서, 마지막에 0이 안되면 false
    // 중간에 음수가 돼버리면 종료
    
    bool answer = true;
    int pos = 0;
    std::vector<char> word = std::vector<char>();

    for(int i = 0; i < s.length(); i++)
    {
        word.push_back(s[i]);
    }

    for(auto unit : word)
    {

        if(unit == '(')
        {
            pos++;
        }
        else if(unit == ')')
        {
            pos--;
        }

        if(pos < 0)
        {
            break;
        }
    }

    if(pos != 0)
        answer = false;
    
    return answer;
}