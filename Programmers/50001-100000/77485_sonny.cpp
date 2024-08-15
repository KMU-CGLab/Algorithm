// 77485 : 행렬 테두리 회전하기 Lv2
// 그저 시키는 데로

#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int SetRotate(vector<vector<int>>& table, int x1, int x2, int y1, int y2)
{   
    int start = table[y1][x1];
    int rotateMin = start;
    
    for(int i = y1; i < y2; i++)
    {
        table[i][x1] = table[i + 1][x1];
        rotateMin = min(rotateMin, table[i][x1]);
    }
    for(int i = x1; i < x2; i++)
    {
        table[y2][i] = table[y2][i + 1];
        rotateMin = min(rotateMin, table[y2][i]);
    }
    for(int i = y2; i > y1; i--)
    {
        table[i][x2] = table[i - 1][x2];
        rotateMin = min(rotateMin, table[i][x2]);
    }
    for(int i = x2; i > x1; i--)
    {
        table[y1][i] = table[y1][i - 1];
        rotateMin = min(rotateMin, table[y1][i]);
    }
    
    table[y1][x1 + 1] = start;
    
    return rotateMin;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    vector<vector<int>> table = vector<vector<int>>(rows + 1, vector<int>(columns + 1, 0));
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            table[i][j] = (i - 1) * columns + j;
        }
    }

    for(int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][1];
        int x2 = queries[i][3];
        int y1 = queries[i][0];
        int y2 = queries[i][2];
        
        answer.push_back( SetRotate(table, x1, x2, y1, y2) );
    }
        
    // for(int i = 1; i <= rows; i++)
    // {
    //     for(int j = 1; j <= columns; j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return answer;
}