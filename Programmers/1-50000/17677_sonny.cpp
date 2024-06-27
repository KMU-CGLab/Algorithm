// 17677 : 뉴스 클러스터링 Lv2

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> GetItems(string str)
{
    vector<string> items;
    int index = 0;
    while(index < str.length() - 1)
    {
        string item = str.substr(index, 2);
        index++;
        
        if(item[0] < 'A' || item[0] > 'Z')
            continue;
        
        if(item[1] < 'A' || item[1] > 'Z')
            continue;
        
        items.push_back(item);
    }
    
    return items;
}

void SetCapital(string& str)
{
    for(char& c : str)
    {
        if(c >= 'a' && c <= 'z')
            c -= 32;
    }
}

int solution(string str1, string str2) 
{
    int answer = 0;
    const int weight = 65536;
    
    // 모두 대문자로
    SetCapital(str1);
    SetCapital(str2);
    
    // 2개씩 끊어서 아이템 만들기. 특수문자는 제외
    vector<string> derStr1 = GetItems(str1);
    vector<string> derStr2 = GetItems(str2);
    
    // 합집합과 교집합
    vector<string> cup;
    vector<string> con;
    
    // 합집합은 일단 다 합친 후, 교집합을 뺀만큼임
    cup = derStr1;
    cup.insert(cup.end(), derStr2.begin(), derStr2.end());
    
    for(int i = 0; i < derStr1.size(); i++)
    {
        string item = derStr1[i];
        for(int j = 0; j < derStr2.size(); j++)
        {
            string compare = derStr2[j];
        
            if(item == compare)
            {
                con.push_back(item);
                derStr2[j] = "";
                break;
            }
        }
    }
    
    // 아이템이 하나도 안만들어져있으면, 1
    if(cup.size() == 0)
        return weight;
    
    // cup에 중복 요소들 빼주기
    int lower = cup.size() - con.size();
    int upper = con.size() * weight;
    
    answer = upper / lower;
    
    return answer;
}