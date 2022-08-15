#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs);
int main() {
    vector<vector<int>> j;
    j.push_back({ 0, 3 });
    j.push_back({ 1, 8 });
    j.push_back({ 1, 9 });
    j.push_back({ 1, 10 });
    j.push_back({ 1, 3 });
    j.push_back({ 2, 3 });
    j.push_back({ 3, 3 });
    std::cout << solution(j);
};
    

bool compare(vector<int>a, vector<int>b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int count = jobs.size();
    //sort(jobs.begin(), jobs.end(), compare);
    int totalTime = 0;
    int v = 0;
    vector<bool> check(count, false);
    while (v < count)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < count; i++)
        {
            if (check[i] != true && jobs[i][0] <= totalTime)
            {
                pq.push(pair<int, int>(jobs[i][1] + totalTime - jobs[i][0], i));
            }
        }
        if (pq.empty())
        {
            int min = 999999;
            int index = 0;
            int init = 999999;
            for (int i = 0; i < count; i++)
            {
                if (check[i] != true && min >= jobs[i][0])
                {
                    if (min == jobs[i][0] && init >= jobs[i][1])
                    {
                        index = i;
                        min = jobs[i][0];
                        init = jobs[i][1];
                    }
                    else if (min > jobs[i][0])
                    {
                        index = i;
                        min = jobs[i][0];
                        init = jobs[i][1];
                    }
                }
            }
            answer += jobs[index][1];
            totalTime = jobs[index][1] + jobs[index][0];
            check[index] = true;
        }
        else
        {
            answer += pq.top().first;
            totalTime += jobs[pq.top().second][1];
            check[pq.top().second] = true;
        }
        v++;
    }
    answer /= count;
    return answer;
}