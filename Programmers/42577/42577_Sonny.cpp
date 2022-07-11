#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    std::map len_book = std::map<string, int>();
    
    for(auto i : phone_book)
    {
        len_book.insert( {i, i.length()} );
    }

    bool is_find = false;
    for(auto i : phone_book)
    {
        for(auto j : len_book)
        {
            // 자기 자신 체크
            if(i == j.first)
                    continue;
            
            // 접두어의 길이가 더 긴지 체크
            if(i.length() > j.second)
            {
                continue;
            }
            
                string slice = j.first.substr(0, i.length());
                
                if(slice == i)
                {
                    answer = false;
                    is_find = true;
                    break;
                }
            
        }
        
        if(is_find)
            break;
    }
    
    
    return answer;
}