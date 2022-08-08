#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> heapQ;
    int count = scoville.size();
    for (int i = 0; i < count; i++)
    {
        heapQ.push(scoville[i]);
    }
    int newScoville = 0;

    while (heapQ.top() < K)
    {
        if (heapQ.size() < 2)
        {
            answer = -1;
            return answer;
        }
        int a1 = heapQ.top();
        heapQ.pop();
        int a2 = heapQ.top();
        heapQ.pop();
        newScoville = a1 + (a2 * 2);
        heapQ.push(newScoville);
        answer++;
    }

    return answer;
}