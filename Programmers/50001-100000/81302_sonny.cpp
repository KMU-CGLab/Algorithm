// 81302 : 거리두기 확인하기 Lv2
// 현재 방법 : 인접지역을 확인하는 방법
// false Table을 이용한 방법으로도 다시 풀어보기

#include <string>
#include <vector>

using namespace std;
int dx[8] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int ex[4] = {0, -2, 0, 2};
int ey[4] = {-2, 0, 2, 0};

// 9칸 비교 -> 사람이 있다면, 그 사람과 나 사이에 파티션이 있는가?
bool IsSafty(int id, const vector<string>& room)
{
    // 3. neighbor 체크 -> 사람 있으면 false
    int x = id % 5;
    int y = id / 5;
    for(int i = 0; i < 4; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        
        if(u < 0 || u >= 5)
            continue;
        if(v < 0 || v >= 5)
            continue;
        
        if(room[v][u] == 'P')
        {
            return false;
        }
        else if(room[v][u] == 'O')
        {
            int s = x + ex[i];
            int t = y + ey[i];
            
            if(s < 0 || s >= 5)
                continue;
            if(t < 0 || t >= 5)
                continue;
            
            if(room[t][s] == 'P')
            {
                return false;
            }
        }
    }
    
    // 4. adjacence 체크 -> 파티션 확인 [y + 1][x + 1] -> [y + 1][x], [y][x + 1] 확인
    for(int i = 4; i < 8; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        
        if(u < 0 || u >= 5)
            continue;
        if(v < 0 || v >= 5)
            continue;
        
        if(room[v][u] == 'P')
        {
            // 파티션 확인
            if(room[v][x] == 'O' || room[y][u] == 'O')
            {
                return false;
            }
        }
    }
    
    return true;
}

int Serialize(int x, int y)
{
    return y * 5 + x;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    
    for(int room = 0; room < places.size(); room++)
    {
        vector<string> place = places[room];
        
        int safty = 1;
        for(int y = 0; y < 5; y++)
        {
            for(int x = 0; x < 5; x++)
            {
                int id = Serialize(x, y);

                if(place[y][x] == 'P')
                {
                    if(!IsSafty(id, places[room]))
                    {
                        safty = 0;
                        break;
                    }
                }
            }
            if(safty == 0)
                break;
        }

        answer.push_back(safty);
    }
    
    return answer;
}