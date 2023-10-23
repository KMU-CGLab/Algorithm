#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 초급
string solution(string X, string Y) 
{
    string answer = "";

    // 큰 수로 정렬
    sort(X.begin(), X.end(), std::greater<char>());
    sort(Y.begin(), Y.end(), std::greater<char>());

    // 1 ~ 9까지 숫자가, 각 문자열마다 몇 개씩인지 체크
    // 적은 갯수만큼 answer에 붙이기
    for (int i = 9; i >= 0; --i)
    {
        int count = 0;
        for (auto x : X)
        {
            int ix = x - '0';

            if(ix == i)
            {
                count++;
            }
        }

        int count2 = 0;
        for (auto y : Y)
        {
            int iy = y - '0';
            
            if(iy == i)
            {
                count2++;
            }
        }

        count = count < count2 ? count : count2;

        for(int j = 0; j < count; j++)
        {
            answer += (char)(i + 48);  // 숫자 0은 아스키 48
        }
    }

    // 아무것도 발견 x
    if(answer == "")
        answer = "-1";

    // 0 중복일 때,
    if(atoi(answer.c_str()) == 0)
        answer = "0";

    return answer;
}