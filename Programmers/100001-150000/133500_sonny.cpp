// 등대, DFS, DP
// 그냥 DFS로 풀면 안되고, Leaf에서 출발해야 생각하기 쉬움

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<int, vector<int>> GetLighthouseMaps(vector<vector<int>> InLighthouses)
{
    map<int, vector<int>> LighthouseMaps;
    
    for(auto light : InLighthouses)
    {   
        int key = light[0];
        int value = light[1];
        
        if(LighthouseMaps.count(key) > 0)
        {
            auto& LighthouseValue = LighthouseMaps[key];
            LighthouseValue.push_back(value);
        }
        else
        {   
            vector<int> LighthouseValue;
            LighthouseValue.push_back(value);
            LighthouseMaps.emplace(make_pair(key, LighthouseValue));
        }
    }
    
    for(auto light : InLighthouses)
    {
        int key = light[1];
        int value = light[0];
        
        if(LighthouseMaps.count(key) > 0)
        {
            auto& LighthouseValue = LighthouseMaps[key];
            LighthouseValue.push_back(value);
        }
        else
        {   
            vector<int> LighthouseValue;
            LighthouseValue.push_back(value);
            LighthouseMaps.emplace(make_pair(key, LighthouseValue));
        }
    }
    
    return LighthouseMaps;
}

map<int, bool> GetOnLightMap(int n)
{
    map<int, bool> OnLightMap;
    
    for(int i = 1; i <= n; ++i)
    {
        OnLightMap.emplace(make_pair(i, false));
    }
    
    return OnLightMap;
}

map<int, bool> GetVisitMap(int n)
{
    map<int, bool> VisitMap;
    
    for(int i = 1; i <= n; ++i)
    {
        VisitMap.emplace(make_pair(i, false));
    }
    
    return VisitMap;
}

int solution(int n, vector<vector<int>> lighthouse) 
{
    int answer = 0;
    
    map<int, vector<int>> LighthouseMaps = GetLighthouseMaps(lighthouse);
    map<int, bool> OnLightMap = GetOnLightMap(n);  // 불 다 끄기
    map<int, bool> VisitedMap = GetVisitMap(n);  // 모두 방문 안했음
    vector<int> ReservedVisit;
    vector<int> OrderedVisit;
    
    int HouseKey = 1;
    ReservedVisit.push_back(HouseKey);
    while(ReservedVisit.size() > 0)
    {
        HouseKey = ReservedVisit.back(); ReservedVisit.pop_back();
        
        // 방문 했던 곳은 안함
        if(VisitedMap[HouseKey])
            continue;
        
        VisitedMap[HouseKey] = true;  // 방문
        OrderedVisit.push_back(HouseKey);  // 방문 순서 저장
        vector<int> NextHouses = LighthouseMaps[HouseKey];
        
        for(auto NextHouseKey : NextHouses)
        {   
            ReservedVisit.push_back(NextHouseKey);  // 다음 방문할 등대 저장
        }
    }
    
    // 부모부터 방문했으니까, 역순으로 방문 시작
    reverse(OrderedVisit.begin(), OrderedVisit.end());
    for(auto HouseKey : OrderedVisit)
    {
        vector<int> NextHouses = LighthouseMaps[HouseKey];

        for(auto NextHouseKey : NextHouses)
        {
            // Leaf를 기준 -> 연결노드는 부모 -> 부모 등대 켜기
            if(!OnLightMap[HouseKey] && !OnLightMap[NextHouseKey])
            {
                OnLightMap[NextHouseKey] = true;
            }
        }
    }

    for(auto OnLight : OnLightMap)
    {
        if(OnLight.second)
        {
            //cout << "On : " << OnLight.first << endl;
            answer++;
        }
    }
    
    return answer;
}