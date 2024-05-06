// 159993 : 미로 탈출 Lv2, BFS

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> maps) 
{
    int answer = 0;
    int x, y;
    int endX = maps[0].size();
    int endY = maps.size();
    int deltaX[4] = {0, -1, 0, 1};
    int deltaY[4] = {-1, 0, 1, 0};
    vector<vector<int>> visitedMap = vector<vector<int>>(endY, vector<int>(endX, -1));
    vector<vector<int>> visitedMap2 = vector<vector<int>>(endY, vector<int>(endX, -1));
    queue<pair<int, int>> q;
    
    // init
    for(int i = 0; i < endY; i++)
    {
        for(int j = 0; j < endX; j++)
        {
            if(maps[i][j] == 'S')
            {
                x = j;
                y = i;
            }
            
            if(maps[i][j] != 'X')
            {
                visitedMap[i][j] = 0;
                visitedMap2[i][j] = 0;
            }
        }
    }
    
    // 레버 찾기 (visitMap 1사용)
    q.push({x, y});
    visitedMap[y][x] = answer;
    bool isFindL = false;
    while(q.size() > 0)
    {
        // 방문
        x = q.front().first;
        y = q.front().second;
        q.pop();
        answer = visitedMap[y][x];
        
        if(maps[y][x] == 'L')
        {
            isFindL = true;
            break;
        }
        
        answer++;
        
        for(int i = 0; i < 4; i++)
        {
            int dx = x + deltaX[i];
            int dy = y + deltaY[i];
            
            if(dx < 0 || dx >= endX)
                continue;
            if(dy < 0 || dy >= endY)
                continue;
            
            if(visitedMap[dy][dx] != 0)
                continue;
            
            visitedMap[dy][dx] = answer;
            q.push({dx, dy});
        }
    }
    
    // q 초기화
    q = queue<pair<int, int>>();


    // 출구 찾기 (visitedMap2 사용, 출발지점 비용은 레버까지 도달한 거리부터 시작)
    q.push({x, y});
    visitedMap2[y][x] = answer;
    bool isFindE = false;
    while(q.size() > 0 && isFindL)
    {
        // 방문
        x = q.front().first;
        y = q.front().second;
        q.pop();
        answer = visitedMap2[y][x];
        
        if(maps[y][x] == 'E')
        {
            isFindE = true;
            break;
        }
        
        answer++;
        
        for(int i = 0; i < 4; i++)
        {
            int dx = x + deltaX[i];
            int dy = y + deltaY[i];
            
            if(dx < 0 || dx >= endX)
                continue;
            if(dy < 0 || dy >= endY)
                continue;
            
            if(visitedMap2[dy][dx] != 0)
                continue;
            
            visitedMap2[dy][dx] = answer;
            q.push({dx, dy});
        }
    }
    
    answer = visitedMap2[y][x];
    
    if(isFindL == false || isFindE == false)
        answer = -1;
    
    return answer;
}