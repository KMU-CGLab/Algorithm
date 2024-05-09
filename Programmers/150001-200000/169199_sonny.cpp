// 169199 : 리코쳇 로봇 Lv2, BFS

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int deltaX[4] = {0, -1, 0, 1};
int deltaY[4] = {-1, 0, 1, 0};

int solution(vector<string> board) 
{
    int answer = -1;
    int endX = board[0].length();
    int endY = board.size();
    vector<vector<int>> costMap = vector<vector<int>>(endY, vector<int>(endX, 0));
    queue<pair<int, int>> q;
    bool isAble = false;
    
    int x,y;
    for(int i = 0; i < endY; i++)
    {
        for(int j = 0; j < endX; j++)
        {
            char c = board[i][j];

            if(c == 'R')
            {
                x = j;
                y = i;
            }
            
            if(c == 'R' || c == 'G')
            {
                // G, R이 벽에 가로막혀있다.
                int wallCount = 0;
                for(int k = 0; k < 4; k++)
                {
                    int dx = j + deltaX[k];
                    int dy = i + deltaY[k];

                    if(dx < 0 || dx >= endX ||
                       dy < 0 || dy >= endY ||
                       board[dy][dx] == 'D')
                    {
                        wallCount++;
                        continue;
                    }
                }
                
                if(wallCount == 4)
                    return -1;
            }
            
            if(c == 'G')
            {
                // G 주변에 벽이 없다.
                for(int k = 0; k < 4; k++)
                {
                    int dx = j + deltaX[k];
                    int dy = i + deltaY[k];

                    if(dx < 0 || dx >= endX ||
                       dy < 0 || dy >= endY ||
                       board[dy][dx] == 'D')
                    {
                        isAble = true;
                        break;
                    }
                }
                if(!isAble)
                    return -1;
            }
            
            
        }
    }
    
    q.push({x, y});
    int value = 0;
    while(q.size() > 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(board[y][x] == 'G')
        {
            answer = costMap[y][x];
            break;
        }
        
        value = costMap[y][x];
        value++;
        
        for(int i = 0; i < 4; i++)
        {
            // 방향 결정
            int multi = 1;
            int dx = x + deltaX[i] * multi;
            int dy = y + deltaY[i] * multi;
            
            // 한 방향으로 쭉 가기
            while(1)
            {
                dx = x + deltaX[i] * multi;
                dy = y + deltaY[i] * multi;
                
                // 벽 또는 장애물이면 탈출
                if(dx < 0 || dx >= endX ||
                   dy < 0 || dy >= endY ||
                   board[dy][dx] == 'D')
                {
                    dx -= deltaX[i];
                    dy -= deltaY[i];
                    if(costMap[dy][dx] == 0)
                    {
                        costMap[dy][dx] = value;
                        q.push({dx, dy});
                    }

                    break;
                }
                
                multi++;
            }
        }
    }
    
    // for(int i = 0; i < endY; i++)
    // {
    //     for(int j = 0; j < endX; j++)
    //     {
    //         cout << costMap[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return answer;
}