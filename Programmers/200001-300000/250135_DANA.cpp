#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//시계 한칸에 30도
int getCount(int h,int m,int s){
    int ret=0;      //만나는 횟수
    
    //각도
    float hDegree = fmodf(h*30+m/2+s/120,360);
    float mDegree = fmodf(m*6+s*0.1,360);
    float sDegree = s*6;

    //만약 초침과 분침이 만나거나 초침이 앞섰다면
    if(sDegree>=mDegree) ret +=1;
    //만약 초침과 시침이 만나거나 초침이 앞섰다면
    if(sDegree>=hDegree) ret +=1;
    
    ret += (h*60+m)*2; //분당 2번씩 만난다고 계산
    ret -= h; //59분 -> 0분일때는 분침과 만나지 않음
    if(h>=12) ret -= 2;
    
    return ret;

}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;                                                       
    answer = getCount(h2,m2,s2)-getCount(h1,m1,s1);
    //시작 시간이 0시0분0초인 경우 한번 더 세야함
    if((h1==0||h1==12)&&m1==0&&s1==0) answer +=1;

    return answer;
}