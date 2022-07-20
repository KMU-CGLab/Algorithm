#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> s;
    s.push(arr[0]);
    answer.push_back(arr[0]);
    int count = arr.size();
    for (int i = 1; i < count; i++)
    {
        if (s.top() != arr[i])
        {
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }

    return answer;
}