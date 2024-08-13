// 12978 : 배달 Lv2
// 플로이드와샬
// DFS로도 가능
// 함수로 2차원 배열 반환하는 방법

// typedef 쓰는 법
// typedef 타입 원하는이름
// typedef int 4바이트
// typedef int(*td)[51] : int배열 * 51줄 -> 2차원 배열의 이름은 td

// 2차원 배열을 특정값으로 채우기
// fill(&town[0][0], &town[50][50], INF);

#include <iostream>
#include <vector>
using namespace std;

#define INF 500001

// 1차원 배열 50개짜리 -> 2차원 배열 을 td라고 부르겠다 (two-dimension)
typedef int(*td)[51];

td GetTown(int N, const vector<vector<int>>& road);

int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 0;
    int (*town)[51] = GetTown(N, road);
    
    // 플로이드 와샬
    for(int mid = 1; mid <= N; mid++)
    {
        for(int start = 1; start <= N; start++)
        {
            for(int end = 1; end <= N; end++)
            {
                if(town[start][end] > town[start][mid] + town[mid][end])
                {
                    town[start][end] = town[start][mid] + town[mid][end];
                }
            }
        }
    }
    
    for(int end = 1; end <= N; end++)
    {
        if(town[1][end] <= K)
        {
            answer++;
        }   
    }
    
    // for(int start = 1; start <= N; start++)
    // {
    //     for(int end = 1; end <= N; end++)
    //     {
    //         cout << town[start][end] << " ";
    //     }
    //     cout << endl;
    // }
    
    return answer;
}

td GetTown(int N, const vector<vector<int>>& road)
{
    int town[51][51];
    fill(&town[0][0], &town[50][50], INF);
    
    for(int i = 0; i <= N; i++)
    {
        town[i][i] = 0;
    }
    
    for(int i = 0; i < road.size(); i++)
    {
        int s = road[i][0];
        int e = road[i][1];
        int c = road[i][2];
        
        town[s][e] = min(town[s][e], c);
        town[e][s] = min(town[e][s], c);
    }
    
    
    return town;
}