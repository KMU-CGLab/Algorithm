// 87946 : 피로도 Lv2
// 완전 탐색
// dfs + 재귀로 구현

// next_purmutation으로 더 간단하게 구현 가능

#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int answer = 0; 

void Reculsive(int k, const vector<vector<int>>& dungeons, int go, bitset<8> visited)
{
    int require = dungeons[go][0];
    
    // 여기는 안감
    if(k < require)
    {
        return;
    }
    
    // 다음 갈 곳 선택하기
    int cost = dungeons[go][1];
    k -= cost;
    visited[go] = 1;
    
    // 갔던 곳 합산
    int count = 0;
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i])
        {
            count++;
        }
    }
    answer = max(answer, count);

    // 다음 갈 곳 선정
    for(int i = 0; i < dungeons.size(); i++)
    {   
        if(visited[i])
            continue;
        
        Reculsive(k, dungeons, i, visited);
    }   
}

int solution(int k, vector<vector<int>> dungeons) 
{
    bitset<8> visited = 0;

    for(int i = 0; i < dungeons.size(); i++)
    {
        Reculsive(k, dungeons, i, visited);
    }
    
    return answer;
}