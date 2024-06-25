// 17680 : [1차] 캐시 Lv2

#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

bool IsContain(deque<string>& dq, const string target)
{
    for(auto iter = dq.begin(); iter != dq.end(); iter++)
    {
        string item = *iter;
        
        if(item == target)
        {
            dq.erase(iter);
            return true;
        }
    }
    
    return false;
}

void Capital(string& city)
{
    for(char& c : city)
    {
        if(c >= 'a')
            c -= 32;
    }
}

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    
    // 캐시 없으면 불가능
    if(cacheSize == 0)
    {
        return cities.size() * 5;
    }
    
    deque<string> cacheDeque;
    
    for(int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        
        //.. 모두 대문자로 저장
        Capital(city);
        
        //.. 캐시를 탐색한다. -> 캐시에서 발견되면 -> answer++, break;
        bool isFind = IsContain(cacheDeque, city);
        
        answer += isFind ? 1 : 5;
        
        cacheDeque.push_back(city);
        if(cacheDeque.size() > cacheSize)
        {
            cacheDeque.pop_front();
        }
    }
    
    return answer;
}