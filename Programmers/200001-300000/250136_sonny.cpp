// 250136 : 석유 시추
// 자기 자신부터 검증 : dx dy를 5로
// OilMemory를 이용해서, 이미 시추한 경험이 있는 곳은 저장해두기 (효율성)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int RowSize;
int ColSize;
int DX[5] = {0, 0, -1, 0, 1};
int DY[5] = {0, -1, 0, 1, 0};
vector<int> OilMemory;

int GetID(int x, int y)
{
    return y * ColSize + x;
}

// 석유가 연결된 하나의 공간을 Key로 삼아서, 얼마나 석유가 있는지 체크
bool ContainsKey(const vector<int> &v, int key)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == key)
            return true;
    }
    
    return false;
}

// DFS로 석유 체크
int SearchOil(vector<vector<int>> &land, int i, int j)
{
    vector<int> Visit;  // 방문 (push, pop이 있음)
    vector<int> Memory;  // 들어갔던 모든 공간을 기억해두었다가, 마지막에 Key를 한꺼번에 저장
    int Oil = 0;

    do
    {
        for (int k = 0; k < 5; k++)
        {
            int x = j + DX[k];
            int y = i + DY[k];

            if (x < 0 || y < 0)
                continue;
            if (x >= ColSize || y >= RowSize)
                continue;

            // 석유라면 push (시추된 적이 없는 공간이라면, 1을 보장)
            if (land[y][x] == 1)
            {
                land[y][x] = 0;
                Visit.push_back(GetID(x, y));
                Memory.push_back(GetID(x, y));
                Oil++;
            }
        }

        if (Visit.size() > 0)
        {
            int ID = Visit.back();
            Visit.pop_back();
            i = ID / ColSize;
            j = ID % ColSize;
        }
    } while (Visit.size() > 0);

    // 공간에 Key값 저장 (Key값은 0, 1을 제외하고, 시추된 순서)
    int MemoryKey = OilMemory.size();
    for (int i = 0; i < Memory.size(); i++)
    {
        int x = Memory[i] % ColSize;
        int y = Memory[i] / ColSize;

        land[y][x] = MemoryKey; // Key 삽입
    }

    OilMemory.push_back(Oil);

    return Oil;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    RowSize = land.size();
    ColSize = land[0].size();
    OilMemory.push_back(0);  // 0은 없음, 1은 오일 처음 시추, 2부터 OilMemory 사용
    OilMemory.push_back(0);

    for (int j = 0; j < ColSize; j++)
    {
        int TotalOil = 0;
        vector<int> searched;

        for (int i = 0; i < RowSize; i++)
        {
            int key = land[i][j];
            
            // 오일 없음
            if (key == 0)
                continue;
            
            // 이미 시추해본 경험이 있는 공간 가져오기
            if (key > 1)
            {
                if (ContainsKey(searched, key))
                {
                    // 이번 드릴에 벌써 시추 했음
                    continue;
                }
                
                TotalOil += OilMemory[key];
            }
            else
            {
                // 처음 시추
                TotalOil += SearchOil(land, i, j);
                key = land[i][j];  // 시추 후 갱신된 키
            }
            searched.push_back(key);
        }

        answer = max(answer, TotalOil);
    }

    return answer;
}