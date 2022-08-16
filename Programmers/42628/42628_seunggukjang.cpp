#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;
bool lessF(int a, int b)
{
    return a > b;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //deque<int> D_Q;
    vector<int> sol;
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
            sol.push_back(number);
            sort(sol.begin(), sol.end(), lessF);
        }
        else if (!sol.empty())
        {
            if (operations[i] == "D -1")
            {
                if (sol.begin() == sol.end())
                    sol.erase(sol.begin());
                else
                    sol.erase(sol.end() - 1);
            }
            else if (operations[i] == "D 1")
            {
                sol.erase(sol.begin());
            }
        }
    }
    answer.push_back(sol.front());
    answer.push_back(sol.back());
    return answer;
}