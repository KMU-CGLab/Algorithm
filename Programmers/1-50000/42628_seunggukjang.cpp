#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

bool smaller(int a, int b)
{
    return a > b;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> dq;
    int count = operations.size();
    for (int i = 0; i < count; i++)
    {
        int number;
        int stringSize = operations[i].size();
        if (operations[i][0] == 'I')
        {
            std::string str = operations[i].substr(2, stringSize - 1);
            std::stringstream ssInt(str);
            ssInt >> number;
            dq.push_back(number);
            sort(dq.begin(), dq.end(), smaller);
        }
        else if (!dq.empty())
        {
            if (operations[i] == "D -1")
            {
                dq.erase(dq.end()-1);
            }
            else if (operations[i] == "D 1")
            {
                dq.erase(dq.begin());
            }
        }
    }
    
    if (!dq.empty())
    {
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}