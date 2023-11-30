#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> left_bracket;
    stack<char> right_bracket;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('){
            left_bracket.push('(');
        }
        else if(s[i]==')'){
            if(left_bracket.size()>0){
                left_bracket.pop();
            }
            else{
                right_bracket.push(')');
            }
                
        }
    }
    
    (left_bracket.size()==0&&right_bracket.size()==0)?answer=true:answer=false;

    return answer;
}