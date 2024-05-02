// 17687 : n진수 게임 LV.2

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string result = "";

string solution(int n, int t, int m, int p) 
{
    string answer = "";
    string charMap = "0123456789ABCDEF";
    
    // 모두가 t번 말한다.
    int resultLength = t * m;  
    
    // 말하는 수를 전부 구하고,
    int count = 0;
    result += '0';
    while(result.length() < resultLength)
    {
        string number;
        int Q = count;
        int R;
        
        while(Q > 1)
        {
            R = Q % n;
            Q = Q / n;
            
            number += charMap[R];
        }
        
        if(Q > 0)
            number += charMap[Q];
        
        reverse(number.begin(), number.end());
        result += number;
        
        count++;
    }
    
    cout << result << endl;
    
    // 튜브의 순서(p)에 해당하는 index에 것만 가지고나오기
    for(int i = 0; i < resultLength; i++)
    {
        if(i % m == (p - 1))
        {
            answer += result[i];
        }
    }
    
    return answer;
}