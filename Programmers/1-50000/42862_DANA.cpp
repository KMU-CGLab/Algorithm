#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//n : 전체 학생의 수
//lost : 체육복을 도난당한 학생들의 번호 배열
//reserve : 여벌의 체육복을 가져온 학생들의 번호 배열
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //앞 뒤 수를 비교할 것이기 때문에 정렬 과정이 꼭 필요함
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    //두가지 배열을 통해 벡터의 삽입,삭제를 진행하지 않고
    //체크를 했는지 표시해줌
    bool isChecked[31]={false};
    bool isCheckedReserve[31]={false};
    int coverNum=0;
    
    //먼저 같은 값들은 모두 true로 변경하고 빌려줌으로써 메꿀수 있는 사람수를 증가
    for(int i=0;i<reserve.size();i++)
    {
        for(int j=0;j<lost.size();j++){
            if(reserve[i]==lost[j]){
                isChecked[j]=true;
                isCheckedReserve[i]=true;
                coverNum++;
            }
        }
    }
    //그 후 남은 것들을 이용하여 앞뒤의 경우의 수를 통해 메꿀수 있는 학생 수 계산
    for(int i=0;i<reserve.size();i++){
        if(coverNum==lost.size())break;
        for(int j=0;j<lost.size();j++){
            if(isChecked[j]||isCheckedReserve[i]) continue;
            else if(lost[j]-1==reserve[i]||lost[j]+1==reserve[i]||lost[j]==reserve[i])
            {
                coverNum++;
                isChecked[j]=true;
                isCheckedReserve[i]=true;
            }
        }
    }
    
    //정답 = 총학생수 - 잃어버린 체육복 수 + 메꾼 학생 수
    answer = n-lost.size()+coverNum;
    
    return answer;
}