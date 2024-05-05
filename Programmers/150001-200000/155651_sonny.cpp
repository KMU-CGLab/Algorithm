// 155651 : 호텔 대실 Lv 2

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 1;
    vector<pair<int, int>> convert_times;
    multiset<int> exit_times;  // 같은 시간 퇴실 고려
    
    // int 값으로 전부 변환
    for(vector<string> Times : book_time)
    {
        Times[0].erase(2, 1);
        Times[1].erase(2, 1);
        
        pair<int, int> times = {stoi(Times[0]), stoi(Times[1]) + 10};
        
        // 시간값이니까, 60분 지나면 1시간++
        if(times.second % 100 >= 60)
        {
            times.second += 40;
        }
        
        convert_times.push_back(times);
    }
    
    sort(convert_times.begin(), convert_times.end(), Compare);
    
    exit_times.emplace(convert_times[0].second);
    for(int i = 1; i < convert_times.size(); i++)
    {   
        int newEnter = convert_times[i].first;
        int newExit = convert_times[i].second;
        bool newBook = true;
        
        for(int oldExit : exit_times)
        {
            // 빈방이 있다.
            if(oldExit <= newEnter)
            {
                exit_times.extract(oldExit);  // 퇴실
                exit_times.emplace(newExit);   // 입실
                newBook = false;
                break;
            }
        }
        
        // 빈방 없으면 방 추가
        if(newBook)
        {
            answer++;
            exit_times.emplace(newExit); 
        }
    }
    
    return exit_times.size();
}