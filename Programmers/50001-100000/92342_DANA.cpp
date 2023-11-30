#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxDiff=0;
vector<int> answer;

bool compare(vector<int> ryan) {
    
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

void calculateScore(vector<int> ryan, vector<int> apeach){
    int rScore=0;
    int aScore=0;
    
    for(int i=0;i<11;i++){
        if(ryan[i]>apeach[i]) rScore+=10-i;     //만약 라이언의 화살 갯수가 어피치보다 크다면
        else if(apeach[i]>0) aScore+=10-i;      //작다면
    }
    
    int diff = rScore-aScore;       // 점수 차이
    if(diff>0&&maxDiff<=diff){      //첨수차이가 0보다 크고 가장 큰 점수차이보다 클때
        if(maxDiff==diff&&!compare(ryan))return;        //만약 가장 낮은 점수를 더 많이 맞힌 경우라면 maxDiff 유지
        maxDiff=diff;
        answer=ryan;
    }
    
}

//dfs
void solve(int idx, int arrows, vector<int> ryan, vector<int> apeach) {
    if(idx==11 || arrows == 0) { //모든 화살 분배 종료
        ryan[10] += arrows;     //idx는 끝났으나 화살이 남은 경우 맨 마지막 화살에 모두 더해줌
        calculateScore(ryan, apeach);
        return;
    }
    //어피치가 맞힌 화살 갯수가 현재 가지고 있는 화살보다 작을 때
    if(apeach[idx] < arrows) {
        ryan[idx] += apeach[idx] +1;        //라이언의 화살은 어피치가 맞힌 것보다 +1 만큼 더해줌
        solve(idx+1, arrows-apeach[idx]-1, ryan,apeach); //화살을 뺀 나머지 경우를 계산
        ryan[idx] -= apeach[idx] +1;    //화살을 빼지 않은 경우도 계산해야하기 때문에 다시 되돌려줌
    }
    solve(idx+1, arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
 
    vector<int> ryan(11,0);
    
    solve(0,n, ryan, info);
    
    //만약 점수가 더 높은 경우가 없으면
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}