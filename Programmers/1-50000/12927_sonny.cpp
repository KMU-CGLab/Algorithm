// 12927 : 야근 지수 Lv3
// 우선순위 큐
// 그냥 n-- 하는게 답임

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) 
{
    long long answer = 0;
    int size = works.size();
    priority_queue<int> pq;
    
    for(int i = 0; i < size; i++)
    {
        pq.push(works[i]);
    }
    
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += works[i];
    }
    
    if(sum < n)
        return 0;
    else if(sum < size)
        return sum;
    
    while(n > 0)
    {
        int value = pq.top();
        pq.pop();
        value--;
        n--;
        pq.push(value);
    }

    while(pq.size() > 0)
    {
        int power = pq.top() * pq.top();
        pq.pop();
        answer += power;
    }
    
    return answer;
}