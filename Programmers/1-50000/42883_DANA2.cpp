#include <string>
#include <vector>

using namespace std;

//테스트 케이스 10 번 통과 (4209.84ms, 5.6MB)
string solution(string number, int k) {
    string answer = "";
    
    int originSize=number.size();
    for(int i=0;i<k;i++){
        for(int j=0;j<number.size()-1;j++){
            if(number[j]<number[j+1]){
                number.erase(j,1);
                break;
            }
        }
    }
    
    int erasedNum = originSize-number.size();
    if(erasedNum<k){
        int newK = k-erasedNum;
        number.erase(number.size()-newK,newK);
    }
    
    answer = number;
    
    return answer;
}