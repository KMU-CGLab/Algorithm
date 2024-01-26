// 142085 : 디펜스 게임 LV.2

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) 
{
    int answer = 1;
    int FinalRound = enemy.size();
    int Round = 0;
    int Sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;  // 오른차순
    
    while(Round < FinalRound)
    {
        int EnemyCount = enemy[Round];
        
        pq.push(EnemyCount);
        
        // 무적권을 쓸 수 있는 라운드 중에 가장 안아프게 맞음
        if(pq.size() > k)
        {
            //cout << pq.top() << endl;
            Sum += pq.top();
            pq.pop();
        }
        
        // 잃은 병력의 수가 내 병력수를 넘어서면 게임 종료 (0은 통과임)
        if(Sum > n)
        {
            break;
        }
            
        // 다음 라운드로
        Round++;
    }
    
    answer = Round;
    return answer;
}