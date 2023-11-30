#include <string>
#include <vector>
#include <map>

using namespace std;
//Map의 키를 이름으로 받고 값을 해당 키를 가지는 수로 사용한 다음 통과한 명단의 이름의 수 만큼을 값을 뺀다.
//Map에서 0보다 큰 수가 있으면 그 키가 답이다.
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