#include <string>
#include <vector>
#include <map>

using namespace std;
//Map�� Ű�� �̸����� �ް� ���� �ش� Ű�� ������ ���� ����� ���� ����� ����� �̸��� �� ��ŭ�� ���� ����.
//Map���� 0���� ū ���� ������ �� Ű�� ���̴�.
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> list;
    int count = participant.size();

    for (int i = 0; i < count; i++)
    {
        if (list.find(participant[i]) == list.end())
        {
            list.emplace(make_pair(participant[i], 0));
        }
        else
            list[participant[i]]++;
    }
    int count1 = completion.size(); 
    
    for (int i = 0; i < count1; i++)
    {
        if (list.find(completion[i]) != list.end())
        {
            list[completion[i]]--;
        }
        
    }
    string answer = "";

    for (auto i = list.begin(); i != list.end(); i++)
    {
        if (i->second >= 0)
        {
            return answer = i->first;
        }
    }
    return answer;
}