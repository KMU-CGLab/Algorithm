#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insert(vector<int>& v, int number)
{
    // vector에 아무것도 없으면 push back
    if (v.size() == 0)
    {
        v.push_back(number);
        return;
    }

    // vector는 오름차순으로 정렬할 것이며, begin은 min, end는 가장 큰 값
    auto i = v.begin();
    for (; i != v.end(); i++)
    {
        if ((*i) > number)
        {
            v.insert(i, number);
            break;
        }
    }

    // break를 걸어뒀기 때문에, vector를 끝까지 순회할 동안 number보다 큰 값이 없으면 number가 제일 큰 값
    if(i == v.end())
        v.push_back(number);
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    for (auto unit : operations)
    {
        // operation과 number 분리
        string operation = unit.substr(0, 1);
        int number = std::stoi(unit.substr(1, unit.size() - 1)); // string -> int

        // input
        if (operation == "I")
        {
            //std::cout << "insert : " << number << std::endl;
            insert(answer, number);
        }
        // delete
        else if (operation == "D")
        {
            // vector에 아무것도 없으면 무시
            if (answer.size() > 0)
            {
                switch (number)
                {
                case 1:
                    //std::cout << "max delete : " << *--answer.end() << std::endl;
                    // MAX 삭제
                    answer.erase(--answer.end());
                    break;
                case -1:
                    //std::cout << "min delete : " << *answer.begin() << std::endl;
                    // min 삭제
                    answer.erase(answer.begin());
                    break;
                }
            }
        }
    }

    // max & min 만 남기고 모두 제거 + 없으면 0, 0
    if (answer.size() > 0)
    {
        int Max = *(--answer.end());
        int min = *(answer.begin());
        answer.clear();
        answer.push_back(Max);
        answer.push_back(min);
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}