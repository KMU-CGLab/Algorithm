// 118666 : 성격 유형 검사하기 Lv1

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    
    // choice를 4로 나눈 나머지가 점수
    // 몫이 선택 항목 (1 or 0)
    // map으로 각 항목에 대한 점수 저장 map<char, int>
    // char[2]짜리 배열 -> R T or T R -> 검사 진행
    
    const string checkArray = "RTCFJMAN";
    map<char, int> checkMap;
    
    // 항목 별 점수
    for(int i = 0; i < 8; i++)
    {
        checkMap.emplace(checkArray[i], 0);
    }
    
    for(int i = 0; i < survey.size(); i++)
    {
        string s = survey[i];
        int choice = choices[i];
        
        int Q = choice / 4;  // key
        int R = choice % 4;  // value
        
        if(R == 0)
            continue;
        
        if(Q == 0)
        {
            R = 4 - R;
        }
        
        checkMap[s[Q]] += R;
        
        // cout << s[Q] << " + " << R << " = " << checkMap[s[Q]] << endl; 
    }
    
    for(int i = 0; i < 8; i+=2)
    {
        char Key1 = checkArray[i];
        char Key2 = checkArray[i + 1];
        
        answer += checkMap[Key1] < checkMap[Key2] ? Key2 : Key1;
    }
    
    return answer;
}