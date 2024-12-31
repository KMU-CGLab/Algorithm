#include <string>
#include <vector>

using namespace std;

//최적의 사용 돌 갯수 구해서 answer에 더해주는 함수
void GetOptimalStoneCount(int& storey,int& answer){
    int count = storey%10;
    
    if(count<5) answer+=count;
    else{
        if(count==5&&storey%100<50){
            answer+=count;
        }
        else{
            answer+=10-count;
            storey=storey+10-count;
        }
    }
    storey/=10;
    //printf("%d, %d\n",storey,answer);
}

int solution(int storey) {
    int answer = 0;

    while(storey>1){
        GetOptimalStoneCount(storey,answer);
    }
    
    return answer+storey;
}