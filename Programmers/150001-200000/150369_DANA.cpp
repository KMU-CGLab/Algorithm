#include <string>
#include <vector>
#include<iostream>

using namespace std;

/*
Return
- minimum of distance

Rule
- n : home
- nth home : distance n
- cap : maximum of box

*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliver=0;
    int pickup=0;
    
    int count=0;
    for(int i=n-1;i>=0;i--){
        count=0;
        
        deliver-=deliveries[i];
        pickup-=pickups[i];
        while(deliver<0||pickup<0){     //한번에 들고 갈수 있는 경우 deliver와 pickup은 0이상임
            deliver+=cap;
            pickup+=cap;
            count+=1;       //다시 이 칸을 올 반복 횟수
        }
        
        answer+=(i+1)*2*count;
        
    }
    
    return answer;
}