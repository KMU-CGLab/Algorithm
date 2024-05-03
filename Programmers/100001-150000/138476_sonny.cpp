// 138476 : 귤 고르기 LV 2

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    //map<int, int> countMap;
    vector<pair<int, int>> countMap;
    
    sort(tangerine.begin(), tangerine.end(), less<int>());
    
    int previous = tangerine[0];
    int count = 1;
    for(int i = 1; i < tangerine.size(); i++)
    {
        if(previous != tangerine[i])
        {
            //countMap.emplace({previous, count});
            countMap.push_back({previous, count});
            //cout << previous << " : " << count << endl;
            previous = tangerine[i];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    countMap.push_back({previous, count});
    
    sort(countMap.begin(), countMap.end(), compare);
    
    int sum = 0;
    for(auto pair : countMap)
    {
        sum += pair.second;
        answer++;
        
        //cout << pair.second << " ";
        
        if(sum >= k)
            break;
    }
    
    return answer;
}