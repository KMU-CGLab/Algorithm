// 12981 : 영어 끝말잇기 LV2

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> wordSet;
    
    // 단어 탐색
    // previous의 마지막 글자와, 현재 첫 글자가 다르면 리턴
    // i % n + 1
    int err = 0;
    wordSet.emplace(words[0]);
    for(int i = 1; i < words.size(); i++)
    {
        char previous = words[i - 1].back();
        char current = words[i].front();
        
        // 잘못 말함
        if(previous != current || wordSet.find(words[i]) != wordSet.end())
        {
            err = i;
            break;
        }
        
        wordSet.emplace(words[i]);
    }
    
    if(err == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back((err % n) + 1);  // err man
        answer.push_back((err / n) + 1);  // order
    }
    
    return answer;
}