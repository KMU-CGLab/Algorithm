// 12951 : JadenCase 문자열 만들기 LV.2
// 8번 케이스 반례 : "  for the what 1what  " >> "  For The What 1what  "
// 중점사항 : 아스키코드

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// 65 ~ 90
// 97 ~ 122


string solution(string s)
{
    string answer = "";
    istringstream ss(s);
    char delim = ' ';
    string token;
    
    while(getline(ss, token, delim))
    {
        // 소문자라면 대문자로
        if(token[0] >= 97)
            token[0] -= 32;
        
        for(int i = 1; i < token.length(); i++)
        {
            char& c = token[i];
            int ctoi = (int)c;
            
            // 소문자는 넘어가기
            if(ctoi >= 97)
            {
                continue;
            }
            
            // 대문자는 소문자로
            token[i] += 32;
        }
        
        answer += token;
        answer += delim;
    }
    
    int popCount = answer.length() - s.length();
    for(int i = 0; i < popCount; i++)
    {
        answer.pop_back();
    }
        
    return answer;
}