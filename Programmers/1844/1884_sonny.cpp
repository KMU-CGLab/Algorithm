#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    const int dx[4] = {1, 0, -1, 0};  // 오른쪽 아래 왼쪽 위
    const int dy[4] = {0, -1, 0, 1};
    const int max_row = maps.size();
    const int max_col = maps[0].size();
    const int last_idx = max_row * max_col - 1;

    int row = 0;
    int col = 0;
    int cost = 1;
    bool finish_tag = true;
        
    // 마지막 지점이 한 곳이라도 연결 돼 있는가
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = max_col - 1 + dx[dir];
        int ny = max_row - 1 + dy[dir];

        if (nx < 0 || nx >= max_col)
            continue;
        if (ny < 0 || ny >= max_row)
            continue;

        // 접근 가능한 이웃 찾기
        if (maps[ny][nx] == 1)
        {
            finish_tag = false;
        }
    }

    queue<int> q;
    q.push(0);
    maps[0][0] = cost;
    while (!q.empty() && !finish_tag)
    {
        int space_idx = q.front(); 
        q.pop();
        row = space_idx / max_col;
        col = space_idx % max_col;
        cost = maps[row][col] + 1;
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = col + dx[dir];
            int ny = row + dy[dir];

            if (nx < 0 || nx >= max_col)
                continue;
            if (ny < 0 || ny >= max_row)
                continue;

            // 접근 가능한 이웃 찾기
            if (maps[ny][nx] == 1)
            {
                int neighbor_index = ny * max_col + nx;

                if (neighbor_index == last_idx)
                {
                    finish_tag = true;
                    answer = cost;
                    break;
                }

                maps[ny][nx] = cost; 
                q.push(neighbor_index);
            }
        }
    }

    return answer;
}