#include <iostream>
#include<string>
#include <stack>
using namespace std;

//Stack을 사용하여서 같은 2가지 문자가 있을 경우 삭제
int solution(string s)
{
    int answer=0;
    
    stack<char> coupleRemove;
    coupleRemove.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(coupleRemove.size()==0||coupleRemove.top()!=s[i]){
            coupleRemove.push(s[i]);
        }
        else{
            coupleRemove.pop();
        }
    }
    
    if(coupleRemove.size()==0) answer=1;
    
    return answer;
}