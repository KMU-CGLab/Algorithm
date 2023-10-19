#include<vector>
using namespace std;

struct space
{
    int row;
    int col;
    int wall;
    bool visited;
    vector<int, int> neighbors;
    int arrive_cost;

    space(int in_row, int in_col, int in_wall, bool in_visited) :
    row(in_row), col(in_col), wall(in_wall), visited(in_visited) 
    { arrive_cost = 0; }
};

// 위 아래 오른쪽 왼쪽
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int max_row = maps.size();
    int max_col = maps[0].size();
    vector<space> game_map;

    // 되돌아 가는 것이 없다 -> 도달한 카운트가 곧 최단거리 경로이다.
    // 방문 하면서, 여기에 도달 할 수 잇는 최솟값과, 어디서 왔는지 체크 해야함

    for(int row = 0; row < max_row; ++row)
    {
        for(int col = 0; col < max_col; ++col)
        {
            space s = space(row, col, maps[row][col], false);
            
            for(int dir = 0; dir < 4; ++dir)
            {
                int nx = col + dx[dir];
                int ny = row + dy[dir];

                if(nx < 0 || nx >= max_col)
                    continue;
                if(ny < 0 || ny >= max_row)
                    continue;

                // 접근 가능한 이웃 찾기
                if(maps[ny][nx] == 1)
                {
                    int neighbor_index = ny * max_col + nx;
                    s.neighbors.push_back(neighbor_index);
                }
            }
            game_map.push_back(s);
        }
    }

    return answer;
}