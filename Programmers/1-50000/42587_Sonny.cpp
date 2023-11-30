#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;

    deque<pair<int, int>> q_pair = deque<pair<int, int>>();
    deque<pair<int, int>> q_pair_print = deque<pair<int, int>>();

    for(int i = 0; i < priorities.size(); i++)
    {
        q_pair.push_back({i, priorities[i]});
    }

    while(q_pair.size() > 0)
    {
        pair<int, int> p_pair = q_pair.front();
        q_pair.pop_front();
        
        int prior = p_pair.second;
        bool is_find = false;

        for(auto j = q_pair.begin(); j != q_pair.end(); j++)
        {
            int cmp = (*j).second;

            if(cmp > prior)
            {
                is_find = true;
                q_pair.push_back(p_pair);
                break;
            }
        }

        if(!is_find)
        {
            q_pair_print.push_back(p_pair);
        }
    }

    int number = 1;  // 순서는 1번부터 시작
    for(auto i = q_pair_print.begin(); i != q_pair_print.end(); i++)
    {
        int id = (*i).first;

        if(id == location)
            answer = number;
        number++;
    }

    return answer;
}