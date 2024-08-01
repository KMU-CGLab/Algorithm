// 147354 : 테이블 해시 함수 Lv2
// 구현문제
// xor 오퍼레이터 사용

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

int compareIdx;
bool CustomSortFunc(const vector<int>& a, const vector<int>& b)
{
    if(a[compareIdx] == b[compareIdx])
    {
        return a[0] > b[0];
    }
    else
        return a[compareIdx] < b[compareIdx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    int answer = 0;
    int length = data[0].size();
    compareIdx = col - 1;
    
    // 2번
    sort(data.begin(), data.end(), CustomSortFunc);
    
    // 3번
    vector<int> siVec;
    for(int y = row_begin - 1; y <= row_end - 1; y++)
    {
        int si = 0;
        for(int x = 0; x < length; x++)
        {
            si += data[y][x] % (y + 1);
        }
        siVec.push_back(si);
    }
    
    answer = siVec[0];
    for(int i = 1; i < siVec.size(); i++)
    {   
        answer = answer xor siVec[i];
    }
    
    return answer;
}