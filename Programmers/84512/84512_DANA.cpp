#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> nums;
string aeiou[5]={"A","E","I","O","U"};

void repeatPermutation(string s, int maxLength)
{
    if(maxLength==s.size()) //문자열의 크기 == 채울 문자열 크기
    {
        nums.push_back(s);
        return; //재귀함수 종료
    }
    
    for(int i=0;i<5;i++)
    {
        repeatPermutation(s+aeiou[i],maxLength); //재귀함수 호출
    }
}

int solution(string word) {
    int answer = 0;
    
    for(int i=1;i<=5;i++){
        repeatPermutation("",i);
    }
    
    sort(nums.begin(), nums.end());  

    for(int i=0;i<nums.size();i++)
    {
        if(word==nums[i]){
            answer=i;
            break;
        }
    }
       
    return answer+1;
}