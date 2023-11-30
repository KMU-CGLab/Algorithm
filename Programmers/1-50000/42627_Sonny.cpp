#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
}

bool cmp_0(vector<int> a, vector<int> b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int size = jobs.size();
    int counter = 0;

    std::vector<std::vector<int>> new_jobs = std::vector<std::vector<int>>();

    // 요청시간으로 소팅
    std::sort(jobs.begin(), jobs.end(), cmp_0);

    // 현재 처리 할 task
    auto task = jobs.back(); jobs.pop_back();
    
    // task list에 처리할 것이 있으면
    while (jobs.size() > 0 || new_jobs.size() > 0)
    {
        // 제일 빠른 요청시간에 counter가 도달하지 않았을 때 jump
        if (task[0] > counter)
            counter = task[0];

        // 작업 처리 완료 시간 까지 jump
        counter += task[1];

        // jobs list에 처리할 것이 남아 있으면
        if (jobs.size() > 0)
        {
            // counter보다 이전에 있는 작업들
            for (int i = counter - task[1]; i <= counter; i++)
            {
                // 요청시간이 가장 빠른 작업 꺼내기
                auto next = jobs.back();

                if (counter >= next[0])
                {
                    new_jobs.push_back(next);
                    jobs.pop_back();
                }

                // 꺼낼 작업이 없다면 break
                if (jobs.size() <= 0)
                    break;
            }

            // task들 중 가장 짧은 처리 task를 선택 -> 현재 counter - task[0] 가 가장 짧은것들로 sort
            std::sort(new_jobs.begin(), new_jobs.end(), cmp);
        }

        answer += (counter - task[0]);

        if (new_jobs.size() > 0)
        {
            task = new_jobs.back();
            new_jobs.pop_back();
        }
        else
        {
            task = jobs.back();
            jobs.pop_back();
        }
    }

    if (task[0] > counter)
        counter = task[0];

    // 마지막으로 지정된 작업 처리
    counter += task[1];
    answer += (counter - task[0]);

    answer /= size;

    return answer;
}