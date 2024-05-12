// 131127 : 할인 행사 Lv2
// 브루트포스

#include <string>
#include <vector>
#include <map>

using namespace std;

bool Check(const map<string, int>& a, map<string, int>& b)
{
    for(auto pair : a)
    {
        string key = pair.first;
        int value = pair.second;
        
        if(b.count(key) > 0)
        {
            if(value != b[key])
            {
                return false;
            }
        }
        else
            return false;
    }
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    map<string, int> buyList;
    map<string, int> sellList;
    
    for(int i = 0; i < want.size(); i++)
    {
        buyList.emplace(want[i], number[i]);
    }
    
    for(int i = 0; i < 10; i++)
    {
        string product = discount[i];
        
        if(sellList.count(product) > 0)
        {
            sellList[product]++;
        }
        else
        {
            sellList.emplace(product, 1);
        }
    }
    
    for(int i = 10; i < discount.size(); i++)
    {
        if(Check(buyList, sellList))
        {
            answer++;   
        }
        
        string previous = discount[i - 10];
        string current = discount[i];
        
        // 열흘 전 품목 제거
        sellList[previous]--;
        
        if(sellList.count(current) > 0)
        {
            sellList[current]++;
        }
        else
        {
            sellList.emplace(current, 1);
        }
    }
    
    // last day
    if(Check(buyList, sellList))
    {
        answer++;   
    }
    
    return answer;
}