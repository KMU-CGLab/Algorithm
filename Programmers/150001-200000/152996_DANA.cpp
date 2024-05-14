#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

/*
중심에서 2,3,4 거리의 지점에 좌석이 하나씩
return 시소 짝꿍이 몇 쌍 존재하는지
*/

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

long long solution(vector<int> weights) {
    map<int, int> m;
    long long answer = 0;
    for(int i:weights)
        m[i]++;
    for(auto i:m){
        for(int f=0; f<i.second-1; f++)
            for(int s=f+1; s<i.second; s++)
                answer++;//same weight pair
        for(auto j:m){
            if(i.first != j.first){
                int LCM = lcm(i.first, j.first);
                if(LCM == j.first){
                    LCM *= 2; //when seat is 1m
                }
                //seat of least num (2,3,4m)
                if(LCM/min(i.first, j.first)<5){
                    //number of cases
                    answer+=i.second*j.second; //second : num of same weight
                }
            }
        }
        m.erase(i.first);
    }

    return answer;
}