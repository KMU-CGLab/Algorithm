#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/*

자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 큰 뒷수라고 함

return 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열

solution 효율성을 위해 stack 사용

*/

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    stack<pair<int,int>> waitForNum;

    for(int i=0;i<numbers.size();i++){        
        answer.push_back(-1);

        while(!waitForNum.empty()){
            if(waitForNum.top().first<numbers[i]){
                answer[waitForNum.top().second]=numbers[i];
                waitForNum.pop();
            }
            else{
                break;
            }
        }
        
        waitForNum.push(make_pair(numbers[i],i));
    }
    
    return answer;
}