#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0;i<prices.size();i++){
        answer.push_back(0);
    }
    
    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
            if(prices[j]<prices[i]){
                answer[i]=j-i;
                break;
            }
        }
        if(answer[i]==0){
            answer[i]=prices.size()-i-1;
        }
    }
    
    return answer;
}