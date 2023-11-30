#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    int day = 0;
    int jobNumber = 0;
    int endCount = 0;
    int count = progresses.size();
    for (int i = 0; i < count; i++)
    {
        q.push(progresses[i]);
    }
    int total = 0;
    while (total < count)
    {
        if ((!q.empty()) && q.front() + day * speeds[jobNumber] >= 100)
        {
            q.pop();
            endCount++;
            jobNumber++;
        }
        else if (endCount > 0)
        {
            total += endCount;
            answer.push_back(endCount);
            endCount = 0;
            day++;
        }
        else
        {
            day++;
        }
    }


    return answer;
}