#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*

Return
- 모든 공격이 끝난 직후 남은 체력
- 만약 체력이 0 이하가 되어 죽으면 -1

Rule
- 추가 회복량 : bandage
- 최대 체력 : health
- 몬스터의 공격 시간과 피해량 : attacks
- t 초 동안 1초마다 x 만큼의 체력 회복
- t 초 연속으로 성공하면 y만큼 체력을 추가로 회복

*/

void heal(int& healStat,int healValue,int healthMax){
    healStat+=healValue;
    if(healStat>healthMax) healStat = healthMax;    
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int endTime = attacks[attacks.size()-1][0];
    int combo=0,attackIdx=0;
    for(int i=0;i<=endTime;i++){
        if(attacks[attackIdx][0]==i){
            answer-=attacks[attackIdx][1];
            combo=0;
            attackIdx++;
        }
        else{
            combo++;
            heal(answer,bandage[1],health);
            if(combo==bandage[0]){
                //active combo
                heal(answer,bandage[2],health);
                combo=0;
            }
        }
        
        if(answer<=0){
            answer=-1;
            break;
        }
    }
    
    return answer;
}