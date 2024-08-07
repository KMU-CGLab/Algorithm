// 12899 : 124 나라의 숫자 Lv2
// 아이디어 문제

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) 
{
    string answer = "";
    vector<char> remains;
    
    int R = 0;
    while(n > 0)
    {
        R = n % 3;
        
        if(R == 0)
        {
            R = 4;
            n--;
        }
        
        char c124 = (char)(R + 48);
        answer = c124 + answer;  // 뒤에 달지말고 앞에 달기
        
        n /= 3;
    }
    
    return answer;
}