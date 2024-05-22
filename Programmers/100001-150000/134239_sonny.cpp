// 134239 : 우박수열 정적분 Lv2
// 시키는대로 풀면 됨

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) 
{
    vector<double> answer;
    vector<double> areas;
    
    int y = k;
    while(k > 1)
    {
        if(k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k *= 3;
            k += 1;
        }
        
        double area;
        area = ((y + k) / 2.0f);
        areas.push_back(area);
        
        y = k;
    }
    
    for(int i = 0; i < ranges.size(); i++)
    {
        int begin = ranges[i][0];
        int end = ranges[i][1] + areas.size();
        double area = 0;
        
        for(int j = begin; j < end; j++)
        {
            area += areas[j];
        }
        
        if(begin > end)
        {
            area = -1.0f;
        }
        
        answer.push_back(area);
    }
    
    
    return answer;
}