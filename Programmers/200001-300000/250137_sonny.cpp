// 250137 : 붕대 감기
// 시키는데로 하면 됨
// 변수명 짓기에 좀 신경썼음

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int Time = bandage[0];  // 붕대 정보
    int HealAmount = bandage[1];
    int HealAccumAmount = bandage[2];
    
    int MaxHealth = health;  // 최대 체력

    auto AttackIter = attacks.begin();  // 공격 정보
    int AccumCounter = Time;
    int t = 0;
    while(AttackIter < attacks.end())
    {
        t++;
        //cout << "t : " << t << endl;
        int AttackTime = (*AttackIter)[0];
        int AttackAmount = (*AttackIter)[1];
        
        // 공격 당하면 heal x
        if(t == AttackTime)
        {
            health -= AttackAmount;
            AccumCounter = Time;
            AttackIter++;
            
            //cout << "Attack -> cur health : " << health << endl;
            
            // 캐릭터 사망
            if(health <= 0)
            {
                health = -1;
                break;
            }
            
            continue;
        }
        
        health = min(health + HealAmount, MaxHealth);
        AccumCounter--;
        //cout << "Heal -> cur health : " << health << endl;
        
        if(AccumCounter == 0)
        {
            health = min(health + HealAccumAmount, MaxHealth);
            AccumCounter = Time;
            //cout << "AccumHeal -> cur health : " << health << endl;
        }
    }
    
    answer = health;
    
    return answer;
}