// 150368 : 이모티콘 할인행사 Lv2

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

 int maxSubscribe = 0;
 int maxBenefit = 0;

void Recursive(const vector<vector<int>>& users, const vector<vector<int>>& discounts, int value)
{
    int length = discounts[0].size();
    
    if(value >= pow(4, length))
    {
        return;
    }
       
    vector<int> select = vector<int>(length, 0);
    int index = length - 1;
    
    int copy = value;
    while(copy > 0)
    {
        int R = copy % 4;
        
        select[index--] = R;
        copy = copy / 4;
    }
    
    vector<int> emoticons = vector<int>(length, 0);
    for(int i = 0; i < length; i++)
    {
        emoticons[i] = discounts[select[i]][i];
    }
    
    int subscribe = 0;
    int benefit = 0;
    for(auto user : users)
    {
        int rate = user[0];
        int money = user[1];
        
        int total = 0;
        for(int i = 0; i < length; i++)
        {
            if(rate <= (select[i] + 1) * 10)
            {
                int emoticon = emoticons[i];
                total += emoticon;
                money -= emoticon;
            }
        }
        
        if(money <= 0)
            subscribe++;
        else
            benefit += total;
    }
    
    if(subscribe > maxSubscribe)
    {
        maxSubscribe = subscribe;
        maxBenefit = benefit;
    }
    else if(subscribe == maxSubscribe)
    {
        maxBenefit = max(benefit, maxBenefit);
    }
    
    Recursive(users, discounts, ++value);
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    vector<int> answer;
    vector<vector<int>> discounts;
    
    for(int i = 10; i <= 40; i += 10)
    {
        vector<int> discount;
        for(int j = 0; j < emoticons.size(); j++)
        {
            int sub = (emoticons[j] * 0.01f) * i;
            discount.push_back(emoticons[j] - sub);
        }
        discounts.push_back(discount);
    }
    
    Recursive(users, discounts, 0);
    
    answer.push_back(maxSubscribe);
    answer.push_back(maxBenefit);
    
    return answer;
}