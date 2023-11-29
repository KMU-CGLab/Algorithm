// 42883, 큰 수 만들기
// Greedy

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";

    long long index = 0;
    while(k > 0)
    {
        int value0 = stoi(number.substr(index, 1));
        int value1 = stoi(number.substr(index + 1, 1));

        // 뒤의 숫자가 더 가치가 높으면 앞의 숫자 제거
        if(value0 < value1)
        {
            //cout << number[index] << " vs " << number[index + 1] << endl;
            number.replace(index, 1, "");
            k--;
            index--;
        }
        else
            index++;
        
        // 같은 수 대응 (21111111111, 10 의 경우)
        if(index == number.length() - 1)
        {
            number.replace(index, 1, "");
            k--;
            index--;
        }
        
        // index-- 하면서 -1로 가는 경우
        if(index < 0)
        {
            index = 0;
        }
    }

    answer = number;

    return answer;
}