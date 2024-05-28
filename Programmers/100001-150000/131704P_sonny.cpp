// 131704 : 택배상자 Lv2
// 문제가 길지만, 시키는데로

#include <string>
#include <vector>
#include <queue>
#include <iostream>

// .. main에서 빼기전에 확인
// .. 아니라면 보조를 확인해보기, 
// .. 보조도 아니라면, 보조 안에 들어있는지 확인
// .. 그것도 아니면 넣기
// .. main에서 맞으면 쓰기

using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;
    queue<int> q;
    vector<int> sub;
    
    for(int i = 1; i <= order.size(); i++)
    {
        q.push(i);
    }
    
    // 메인 = queue
    // 보조 = stack
    int idx = 0;
    while(q.size() > 0 || sub.size() > 0)
    {
        int ord = order[idx];
        
        // 보관함에 박스가 있다.
        if(sub.size() > 0)
        {
            // 제일 위에 것
            int subBox = sub.back();
            
            // 제일 위에것이 찾던 것이라면 -> 꺼냄
            if(subBox == ord)
            {
                answer++;
                idx++;
                sub.pop_back();
                continue;
            }
            else if(subBox > ord)
            {
                // 기사님이 요구한 것이 밑에 있음
                break;
            }
        }
        
        int box = 0;
        if(q.size() > 0)
        {
            box = q.front();
            q.pop();
            
            if(ord == box)
            {
                answer++;
                idx++;
                continue;
            }
            
            sub.push_back(box);
        }
    }
    
    return answer;
}