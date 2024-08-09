// 49189 : 가장 먼 노드 Lv3
// DFS로 하면 실패
// 그래프 하나씩 탐색하면서 distance update

#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    int maxDistance = 1;
    int depart = 1;
    
    map<int, set<int>> graph;
    map<int, int> distanceMap;
    
    // 그래프 만들기
    for(int i = 0; i < edge.size(); i++)
    {
        vector<int> node = edge[i];
        
        if(graph.count(node[0]) > 0)
        {
            graph[node[0]].emplace(node[1]);
        }
        else
        {
            set<int> link;
            link.emplace(node[1]);
            graph.emplace(node[0], link);
        }
        
        if(graph.count(node[1]) > 0)
        {
            graph[node[1]].emplace(node[0]);
        }
        else
        {
            set<int> link;
            link.emplace(node[0]);
            graph.emplace(node[1], link);
        }
    }
    
    queue<pair<int, int>> BFS;
    for(int dest : graph[1])
    {
        BFS.push( {dest, 1} );
        distanceMap.emplace(dest, 1);
    }
    
    while(BFS.size() > 0)
    {
        int start = BFS.front().first;
        int distance = BFS.front().second;
        BFS.pop();
        
        distance++;
        for(int dest : graph[start])
        {
            if(dest == start || dest == depart)
                continue;
            
            if(distanceMap.count(dest) > 0)
            {
                if(distanceMap[dest] > distance)
                {
                    distanceMap[dest] = distance;
                    
                    BFS.push( {dest, distance} );
                }
            }
            else
            {
                distanceMap.emplace(dest, distance);
                BFS.push( {dest, distance} );
            }
            cout << distance << endl;
        }
        
    }
    
    for(auto dm : distanceMap)
    {
        maxDistance = max(maxDistance, dm.second);
    }
    for(auto dm : distanceMap)
    {
        if(maxDistance == dm.second)
            answer++;
    }
    
    
    return answer;
}