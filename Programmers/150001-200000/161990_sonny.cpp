// 161990 : 바탕화면 정리
// 드래그 첫 지점 ~ 끝지점까지 계산
// x, y 값이 스위칭된 결과

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer;
    int RowSize = wallpaper.size();
    int ColSize = wallpaper[0].length();
    
    int MinX = RowSize;
    int MinY = ColSize;
    int MaxX = 0;
    int MaxY = 0;
    
    for(int y = 0; y < RowSize; ++y)
    {
        string row = wallpaper[y];
        
        for(int x = 0; x < ColSize; ++x)
        {
            if(row[x] == '#')
            {
                MinX = min(MinX, y);
                MinY = min(MinY, x);
                MaxX = max(MaxX, y + 1);
                MaxY = max(MaxY, x + 1);
            }
        }
    }
    
    answer.push_back(MinX);
    answer.push_back(MinY);
    answer.push_back(MaxX);
    answer.push_back(MaxY);
    
    return answer;
}