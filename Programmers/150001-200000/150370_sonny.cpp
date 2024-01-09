// 150370 : 개인정보 수집 유효기간
// string 변환하는데 시간을 많이 씀
// 로직 자체는 크게 어려운게 없음

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char, int> TermsMap;

int GetYear(string day)
{
    return stoi(day.substr(0, 4));
}

int GetMonth(string day)
{
    return stoi(day.substr(5, 7));
}

int GetDay(string day)
{
    return stoi(day.substr(8, 10));
}

char GetKey(string privacy)
{
    return privacy[privacy.length() - 1];
}

bool func(const string today, const string privacy)
{
    int year, t_year;
    int month, t_month;
    int day, t_day;
    char key = GetKey(privacy);
    int term = TermsMap[key];

    year = GetYear(privacy); t_year = GetYear(today);
    month = GetMonth(privacy); t_month = GetMonth(today);
    day = GetDay(privacy); t_day = GetDay(today);
    
    month += term;
    
    // month가 12이하가 될 때까지 계속 year를 증가
    while(month > 12)
    {
        month -= 12;
        year++;
    }
    
    // cout << year << " " << month << " " << day << endl;
    // cout << t_year << " " << t_month << " " << t_day << endl;
    
    if(year < t_year)
    {
        return true;
    }
    else if(year == t_year)  // 같은 해 보장
    {
        if(month < t_month)
        {
            return true;
        }
        else if(month == t_month) // 같은 달 보장
        {
            if(day <= t_day)
            {
                return true;
            }
        }
    }
    
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(string term : terms)
    {
        char key = term[0];
        int value = stoi(term.substr(1, term.length()));
        
        TermsMap.emplace(make_pair(key, value));
    }

    int index = 1;  // 답이 1부터 시작
    for(string privacy : privacies)
    {
        if(func(today, privacy))
        {
            answer.push_back(index);
        }
        index++;
    }

    return answer;
}