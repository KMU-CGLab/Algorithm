#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Heap : priority_queue라고도 함
// 트리구조로 저장돼 있으며, 자료를 넣으면 내림차순으로 자동 정렬
int solution(vector<int> scoville, int K)
{
    // 1. 스코빌지수 오름차순으로 정렬 -> 우선순위큐를 사용
    // 2. front를 연속해서 꺼냄
    // 3. 수식에 맞게 적용해서 새로운 스코빌지수의 음식을 만들어내고, 다시 queue에 삽입
    // 4. front에 있는 데이터가 K를 넘으종료

    int answer = 0;  // counter
    std::priority_queue<int, vector<int>, greater<int>> pq = 
    std::priority_queue<int, vector<int>, greater<int>>();

    for(auto unit : scoville)
    {
        pq.push(unit);
    }

    while(pq.top() < K)
    {
        if(pq.size() < 2)
        {
            answer = -1;
            break;
        }

        int old1 = pq.top(); pq.pop();
        int old2 = pq.top(); pq.pop();
        
        int new_s = old1 + old2 * 2;

        pq.push(new_s);

        answer++;
    }
    
    return answer;
}