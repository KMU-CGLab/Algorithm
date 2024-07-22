// 72411 : 메뉴 리뉴얼 Lv2
// 경우의 수 문제
// combination, next_permutation
// 오름차순 정렬 돼있어야함!!!! (bool은 false, false, true, true 순서)

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    
    vector<int> realCourse;
    for(int i : course)
    {
        int count = 0;
        for(string order : orders)
        {
            if(order.length() >= i)
            {
                count++;
            }
        }
        
        if(count >= 2)
        {
            realCourse.push_back(i);
        }
    }
    
    map<string, int> courseMap;
    for(int c : realCourse)
    {
        // 2개짜리 코스 -> 3개짜리 코스 -> ...
        for(string order : orders)
        {
            if(order.length() < c)
                continue;
            
            // 현재 주문 중, 2개만 선택하기
            vector<bool> combination = vector<bool>(order.length(), true);
            for(int i = 0; i < combination.size() - c; i++)
            {
                combination[i] = false;
            }

            // 현재 오더의 가짓수
            do 
            {
                string newCourse;
                for(int i = 0; i < combination.size(); i++)
                {
                    if(combination[i])
                        newCourse += order[i];
                }
                
                sort(newCourse.begin(), newCourse.end());
                
                if(courseMap.count(newCourse) > 0)
                    courseMap[newCourse]++;
                else
                    courseMap.emplace(newCourse, 1);
                
            } while(std::next_permutation(combination.begin(), combination.end()));
        }
    }
    
    vector<int> select;
    for(int c : realCourse)
    {
        int curMax = 0;
        for(auto newCourse : courseMap)
        {
            if(newCourse.first.length() == c && newCourse.second >= 2)
            {
                curMax = max(curMax, newCourse.second);
            }
        }
        
        for(auto newCourse : courseMap)
        {
            if(newCourse.first.length() == c && curMax == newCourse.second)
                answer.push_back(newCourse.first);
        }    
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}