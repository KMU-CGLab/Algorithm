#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 벽은 0, 빈 공간은 1
enum SPACE
{
    Wall = 0,
    Empty = 1
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int>> Path;

    int MaxRow = maps.size();
    int MaxCol = maps[0].size(); 
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};

    int PathLength = 1;
    int X = 0;
    int Y = 0;
    // 둘중에 하나라도 도달하지 못했다면
    while (X != MaxCol - 1 || Y != MaxRow - 1)
    {
        PathLength++;
        for (int d = 0; d < 4; d++)
        {
            int Dx = X + dirX[d];
            int Dy = Y + dirY[d];

            // 범위 초과 -> 넘어가기
            if (Dx < 0 || Dy < 0 || Dx >= MaxCol || Dy >= MaxRow)
            {
                continue;
            }

            // 마킹, 갔던 길은 가지 않음
            if (maps[Dy][Dx] == SPACE::Empty)
            {
                maps[Dy][Dx] = PathLength;
                Path.push(pair<int, int>(Dy, Dx));
            }
        }

        if(Path.size() > 0)
        {
            X = Path.front().second;
            Y = Path.front().first;
            Path.pop();
            PathLength = maps[Y][X];
            //cout << X << "," << Y << endl;
        }
        else
        {
            return -1;
        }
    }

    answer = maps[MaxRow-1][MaxCol-1];

    return answer;
}