#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> map_participant = map<string, int>();
    
    for(auto i : participant)
    {
        // participant 리스트 삽입하되, 이미 존재한다면 ++
        if(map_participant.find(i) != map_participant.end())
        {
            map_participant[i]++;
        }
        else
        {
            map_participant.insert({i, 1});
        }
    }
    
    for(auto i : completion)
    {
        map_participant[i]++;
    }
    
    for(auto i : map_participant)
    {
        if(i.second % 2 != 0)
        {
            answer = i.first;
            break;
        }
    }
    
    return answer;
}