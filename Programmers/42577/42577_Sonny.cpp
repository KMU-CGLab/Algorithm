#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    std::map len_book = std::map<string, int>();

    for (auto i : phone_book)
    {
        len_book.insert({ i, i.length() });
    }

    bool is_find = false;

    for (std::map<std::string, int>::iterator iter = len_book.begin();
        iter != len_book.end(); iter++)
    {
        auto next = std::next(iter);

        // 마지막까지 왔을 땐, next가 없음
        if (next == len_book.end())
            break;

        // 자기 뒤의 것이랑만 비교
        if ((*iter).second > (*next).second)
        {
            continue;
        }

        string slice = (*next).first.substr(0, (*iter).second);

        if (slice == (*iter).first)
        {
            std::cout << slice << " : " << (*iter).first << std::endl;
            answer = false;
            is_find = true;
            break;
        }
    }

    return answer;
}