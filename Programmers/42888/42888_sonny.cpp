// 오픈채팅방
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    map<string, string> UserMap;
    vector<pair<string, string>> orders;

    for(int i = 0; i < record.size(); i++)
    {
        string rec = record[i];

        int start_pos = 0;
        int end_pos = rec.find(" ", start_pos);
        string order = rec.substr(start_pos, end_pos);
        
        start_pos = end_pos + 1;
        end_pos = rec.find(" ", start_pos);
        string id = rec.substr(start_pos, end_pos - start_pos);
        orders.push_back(pair<string, string>(order, id));

        if(end_pos == rec.npos)
        {
            continue;
        }

        start_pos = end_pos + 1;
        end_pos = rec.size();
        string name = rec.substr(start_pos, end_pos - start_pos);

        if(order == "Change")
        {
            UserMap[id] = name;
        }

        if(UserMap.find(id) != UserMap.end())
        {
            UserMap[id] = name;
        }
        // id가 중복이면 안들어감
        UserMap.emplace(pair<string, string>(id, name));
    }

    // map에 id + name 넣기
    // record 순회하면서, id에 매칭해서 record 바꿔서 출력하기
    for(int i = 0; i < orders.size(); i++)
    {
        string& order = orders[i].first;
        string& id = orders[i].second;
        string sentence = "";

        if(order == "Enter")
        {
            sentence = UserMap[id] + "님이 들어왔습니다.";
        }
        else if(order == "Leave")
        {
            sentence = UserMap[id] + "님이 나갔습니다.";
        }
        else
            continue;
        
        answer.push_back(sentence);
    }
    
    return answer;
}