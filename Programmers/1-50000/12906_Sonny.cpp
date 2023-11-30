#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int before = -1;  // 파라미터에 들어있는 모든 수는 자연수이기 대문에, -1로 초기화

    for(int i = 0; i < arr.size(); i++)
    {
        // 이전 수와 같지만 않으면 됨
        if(before != arr[i])
        {
            answer.push_back(arr[i]);
            before = arr[i];
        }
    }

    return answer;
}