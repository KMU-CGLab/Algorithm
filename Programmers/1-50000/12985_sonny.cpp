// 12985 : 예상대진표 Lv2

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    if(a > b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }

    while(b - a > 1 || b % 2 != 0)
    {
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
    }

    return answer;
}