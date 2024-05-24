// 250136 : 석유 시추 Lv2
// 기존 코드를 간략화 (아이디어는 동일함)
// OilMemory를 이용해서, 이미 시추한 경험이 있는 곳은 저장해두기 (효율성)

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<vector<int>> copyLand;

int limitX, limitY;
int DX[4] = {0, -1, 0, 1};
int DY[4] = {-1, 0, 1, 0};
map<int, int> oilMemories;
int currentKey;

void Extract(int x, int y)
{
    vector<pair<int, int>> visited;
    int result = 0;

    copyLand[y][x] = currentKey;
    visited.push_back({x, y});
    result++;

    while(visited.size() > 0)
    {
        int cx = visited.back().first;
        int cy = visited.back().second;
        visited.pop_back();

        for(int i = 0; i < 4; i++)
        {
            int dx = DX[i] + cx;
            int dy = DY[i] + cy;

            if(dx < 0 || dx >= limitX)
                continue;
            if(dy < 0 || dy >= limitY)
                continue;

            // 추출하고, key심어두기
            if(copyLand[dy][dx] == 1)
            {
                copyLand[dy][dx] = currentKey;
                visited.push_back({dx, dy});
                result++;
            }
        }
    }

    oilMemories.emplace(currentKey, result);
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    limitY = land.size();
    limitX = land[0].size();
    copyLand = land;

    // .. 시추한 후, 해당 블록에 key를 부여한다.
    // .. 해당 key를 이용하면, 연결된 석유가 총 몇개가 있는지 알 수 있게 map에 저장한다.

    currentKey = 2;

    for(int x = 0; x < limitX; x++)
    {
        set<int> visited;
        int total = 0;
        
        for(int y = 0; y < limitY; y++)
        {
            int block = copyLand[y][x];

            if(block == 0)
            {
                // 석유 없다
                continue;
            }    
            else if(block == 1)
            {
                Extract(x, y);
                block = copyLand[y][x];  // 갱신
                currentKey++;
            }

            visited.emplace(block);
        }
        
        for(int oil : visited)
        {
            total += oilMemories[oil];
        }
        
        answer = max(answer, total);
    }

    return answer;
}