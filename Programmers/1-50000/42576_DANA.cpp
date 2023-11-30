#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//완주하지 못한 선수

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //참가자와 완주자 vector를 정렬
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    //idx를 통해 비교할 참가자의 번호를 설정
    int idx=0;
    //완주자의 수만큼 for문
    for(int i=0;i<completion.size();i++){
        //만약 비교할 참가자와 완주자의 배열 위치의 값이 다르다면 break
        if(participant[idx]!=completion[i])
            break;
        //그렇지 않다면 뒤의 참가자로 넘어감
        idx++;
    }

    //결과 값으로 idx의 값을 출력 
    //(마지막 한명이 남는 경우 그 이전에 idx++이 실행되었기 때문에 마지막 인원이 출력됨)
    answer = participant[idx];
    
    return answer;
}