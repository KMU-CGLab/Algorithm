// 60058, 괄호 변환, 2020 카카오 블라인드 리크루트
// 문제에서 시키는대로 하면 통과

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsCorrectStr(string str)
{
    int counter = 0;

    for (auto c : str)
    {
        if (c == '(')
        {
            counter++;
        }
        else
        {
            counter--;
        }

        if (counter < 0)
            return false;
    }

    return true;
}

int DeviedStr(string p)
{
    int counter = 0;
    for (int i = 0; i < p.length(); ++i)
    {
        if (p[i] == ')')
            counter--;
        else
            counter++;

        if (counter == 0)
            return i;
    }

    return 0;
}

string ModifyStr(string p)
{
    string u = "";
    string v = "";
    int devide_index = DeviedStr(p);

    if (IsCorrectStr(p))
        return p;

    u = p.substr(0, devide_index + 1);
    v = p.substr(devide_index + 1, p.length());

    // cout << "u : " << u << endl;
    // cout << "v : " << v << endl;

    if (IsCorrectStr(u))
        v = ModifyStr(v);
    else
    {
        string dummy_str = "(";
        v = ModifyStr(v);
        dummy_str += v;
        dummy_str += ")";
        u.erase(0, 1);
        u.erase(u.length() - 1, 1);

        string reverse_u;
        for (auto c : u)
        {
            if (c == '(')
                reverse_u += ")";
            else
                reverse_u += "(";
        }
        dummy_str += reverse_u;

        return dummy_str;
    }

    return u + v;
}

string solution(string p)
{
    string answer = "";

    if (p == "")
        return p;

    answer = ModifyStr(p);

    return answer;
}