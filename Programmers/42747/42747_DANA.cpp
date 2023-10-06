#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    //인용 숫자별로 sorting하기
    sort(citations.begin(),citations.end());
    
    int num=citations.size();
    int i;
    for(i=0;i<citations.size();i++){
        if(citations[i]==0) continue; //0 인덱스의 경우 계산 x
        else if(citations[i]<=num-i-1)
        {
            //(인용 수)<=(i를 제외한 남은 계산해야할 인용된 논문)
            // h의 최댓값이기 때문에
            answer=num-i-1;         
        }
        else break;
    }
    
    //만약 0번 자리에서 끝나고 citations[0]가 0 이상일 때
    //모든 경우가 h번 이상 인용된 경우
    if(i==0&&citations[0]!=0){answer=num;}
    
    return answer;
}