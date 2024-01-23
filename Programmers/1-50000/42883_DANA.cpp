#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//테스트케이스 10번 (2934.04ms,5.6MB) 가 나옴으로 추후 알고리즘 수정 필요
string solution(string number, int k) {
    string answer = number;

    int idx=0,count=0;
    char max=answer[0];
    bool isRemove=false;
    
    if(number.length()-k>1){
        while(count<k){
            for(int j=0;j<answer.length()-1;j++){
                isRemove=false;
                if(answer[j]=='9'){
                    continue;
                }
                else if(answer[j]<answer[j+1]){
                    answer.erase(answer.begin()+j,answer.begin()+j+1);
                    isRemove=true;
                    count++;
                    break;
                }
            }
            
            if(!isRemove){
                answer.pop_back();
                count++;
            }
        }
    }
    else{
        for(int i=0;i<answer.length();i++){
            if(answer[i]=='9'){
                max=answer[i];
                break;
            }
            if(max<answer[i]){
                max=answer[i];
            }
        }
        answer = max;
    }

    return answer;
}