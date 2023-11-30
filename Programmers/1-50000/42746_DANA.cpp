#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string i,string j){
    if(i+j>j+i) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strNums;
    for(int i=0;i<numbers.size();i++){
        strNums.push_back(to_string(numbers[i]));
    }
    
    //sort를 이용하여 모든 정렬의 수 중 제일 높은 경우가 되는 것으로 정렬
    sort(strNums.begin(),strNums.end(),compare);
    
    bool isZero=true;
    for(int i=0;i<strNums.size();i++){
        if(strNums[i]!="0") isZero=false;
        answer+=strNums[i];  
    }
    
    //모든 입력이 0인 경우를 예외처리
    if(isZero) answer="0";
    
    return answer;
}