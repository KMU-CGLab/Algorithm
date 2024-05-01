// 12946 : 하노이의 탑

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;

// 이 함수는 n개의 판때기를 목적지로 옮길 것임
void Process(int n, int start, int mid, int end)
{
    if(n == 1)
    {
        answer.push_back({ start, end });
        return;
    }
    
    n--;
    Process(n, start, end, mid);  // 제일 큰 판 제외한 것들을 전부 mid로 (많은 재귀 호출)
    Process(1, start, mid, end);  // 제일 큰 판을 end로 (1개만 이동)
    Process(n, mid, start, end);  // 제일 큰 판 위에 합치기 (많은 재귀 호출))
}

vector<vector<int>> solution(int n) 
{
    int start = 1;
    int mid = 2;
    int end = 3;
    
    Process(n, start, mid, end);
    
    return answer;
}