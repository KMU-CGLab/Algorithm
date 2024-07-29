// 17679 : [1차] 프렌즈4블록 Lv2
// 전체 탐색, 구현 문제

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 4칸이 일치하는지
bool CheckGrid(const vector<string>& board, int inX, int inY)
{   
    char criteria = board[inY][inX];
    
    if(criteria == ' ')
        return false;
    
    if(board[inY][inX + 1] != criteria) 
    { 
        return false;
    }
    
    if(board[inY + 1][inX] != criteria)
    {
        return false;
    }
    
    if(board[inY + 1][inX + 1] != criteria)
    {
        return false;
    }
    
    return true;
}

// 격자 삭제
int DeleteGrid(vector<string>& board, int inX, int inY)
{   
    int delCount = 0;
    
    delCount += board[inY][inX] != ' ' ? 1 : 0;
    delCount += board[inY][inX + 1] != ' ' ? 1 : 0;
    delCount += board[inY + 1][inX] != ' ' ? 1 : 0;
    delCount += board[inY + 1][inX + 1] != ' ' ? 1 : 0;
    
    board[inY][inX] = ' ';
    board[inY][inX + 1] = ' ';
    board[inY + 1][inX] = ' ';   
    board[inY + 1][inX + 1] = ' ';
    
    return delCount;
}

// 빈 곳이 있다면 하강 (바닥부터 검사)
void PullDown(vector<string>& board, int inX, int inY, const int& bottom)
{
    char criteria = board[inY][inX];
    
    if(criteria == ' ')
        return;
    
    int y = inY + 1;
    int delCount = 0;
    while(y < bottom)
    {
        if(board[y][inX] == ' ')
        {
            y++;
            delCount++;
        }
        else
            break;
    }
    
    if(delCount > 0)
    {
        board[y - 1][inX] = criteria;
        board[inY][inX] = ' ';
    }
}

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;
    
    vector<pair<int, int>> deleteTarget;

    // 처음에는 deleteTarget이 없기 때문에 do-while
    do
    {
        // 삭제
        while(deleteTarget.size() > 0)
        {
            int x = deleteTarget.back().first;
            int y = deleteTarget.back().second;
            deleteTarget.pop_back();
            answer += DeleteGrid(board, x, y);
        }
        
        // 하강
        for(int y = m - 1; y >= 0; y--)
        {
            for(int x = 0; x < n; x++)
            {
                PullDown(board, x, y, m);
            }    
        }

        // 탐색
        for(int y = 0; y < m - 1; y++)
        {
            for(int x = 0; x < n - 1; x++)
            {
                if(CheckGrid(board, x, y))
                {
                    deleteTarget.push_back({x, y});
                }
            }
        }
    } while(deleteTarget.size() > 0);
    
    return answer;
}