#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> pri;
    //큐에 넣고 prices 만큼 answer 초기화
    for(int i=0;i<prices.size();i++){
        answer.push_back(0);
        pri.push(prices[i]);
    }
    int idx=1;
    //큐가 다 비고 idx가 벡터의 크기를 넘지 않을 경우에만 while
    while(!pri.empty()&&idx<prices.size()){
        //체크는 큐의 범위 반큼만 체크 하도록(queue는 []로 접근 불가능하기 때문에 vector 이용)
        for(int i=idx;i<prices.size();i++){
            //만약 큐의 front부분이 내가 체크 하고 있는 것보다 작은 경우
            //&& 이전의 것보다 작은 경우(내려가는 중을 체크) == 여기까지만 시간을 더하고 멈춤
            if(prices[i]<pri.front()&&prices[i-1]>prices[i]){
                answer[idx-1]++;
                break;
            }
            else{
                //그 이외에는 끝까지 시간을 더해줌
                answer[idx-1]++;
            }
        }
        pri.pop();      //체크한 부분은 제거
        idx++;          //위치 idx 계산
    }
    
    //마지막 부분은 무조건 0
    answer[prices.size()-1]=0;
    
    return answer;
}