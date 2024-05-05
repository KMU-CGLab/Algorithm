// 68936 : 쿼드압축 후 개수 세기 Lv2

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> counts;

void RectSearch(const vector<vector<int>>& arr, int x, int y, int n)
{
    int standard = arr[y][x];
    
    for(int i = y; i < y + n; i++)
    {   
        for(int j = x; j < x + n; j++)
        {
            if(standard != arr[i][j])
            {
                int range = n / 2;
                RectSearch(arr, x, y, range);
                RectSearch(arr, x + range, y, range);
                RectSearch(arr, x, y + range, range);
                RectSearch(arr, x + range, y + range, range);
                return;
            }
        }
    }
    
    counts[standard]++;
}

vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer;
    counts.push_back(0);
    counts.push_back(0);
    
    int range = arr.size();
    
    RectSearch(arr, 0, 0, range);
    
    answer = counts;
    
    return answer;
}   