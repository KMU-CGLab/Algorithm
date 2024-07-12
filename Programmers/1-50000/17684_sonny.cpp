// 17684 : [3차] 압축 Lv2
// 시키는대로 하면 됨

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    map<string, int> dic;
    
    // 1. 알파벳 초기화
    for(int i = 0; i < 26; i++)
    {
        string s;
        s += 'A' + i;
        dic.emplace(s, i + 1);
    }
    
    auto i = msg.begin();
    int index = 27;
    while(i != msg.end())
    {
        // K
        string s;
        s += *i;
        
        // w 찾으면서, wc가 되면 break
        while(dic.count(s) > 0)
        {
            s += *(++i);
        }
        
        // wc 추가
        dic.emplace(s, index++);
        
        // w의 index 찾기
        string key = s.substr(0, s.length() - 1);
        
        // index 추가
        answer.push_back(dic[key]);
    }
    
    return answer;
}