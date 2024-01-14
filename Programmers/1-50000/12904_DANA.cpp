#include <iostream>
#include <string>
using namespace std;

/*

Return
- 문자열 s의 부문문자열 중 가장 긴 팰린드룸의 길이

Rule
- 앞뒤를 뒤집어도 똑같은 문자열 : 팰린드롬

*/

//팰린드롬 판별
//반으로 자른 후 앞뒤 문자 비교
bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
            if(s.at(start++) != s.at(end--)) return false;
    }
    return true;
}


int solution(string s)
{
    //제일 큰 사이즈부터 내려가면서 탐색
    for(int i=s.size(); i>0; i--) {
        for(int j = 0; j+i<=s.size(); j++) {
            if(isPalindrome(s,j, j+i-1)){
                return i;
            }
        }
    }
    
    return 0;
}