// n^2 배열 자르기, 2차원 배열 직렬화

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;

    for(long long i = left; i <= right; i++)
    {
        int X = i % n;
        int Y = i / n;

        // 값은 1부터 시작
        long long Value = X + 1;

        if(Y > X)
            Value = Y + 1;

        answer.push_back(Value);
    }

    return answer;
}