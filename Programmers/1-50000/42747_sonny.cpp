#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();

    // 오름차순
    sort(citations.begin(), citations.end(), less<int>());

    int h = 0;
    int max = 0;
    for(h = 0; h < n; h++)
    {
        int counter = 0;
        for(int i = 0; i < n; i++)
        {
            // h번 이상 인용된 논문의 수 = counter
            if(citations[i] >= h)
            {
                counter++;
            }
        }
        
        // h번 이상 인용된 논문이 h이상인가?
        if(counter >= h)
            max = h;
    }

    answer = max;
    
    // 최소로 인용된 논문조차, 전체 논문 수 보다 많은 경우 (위 수식에서 커버 못하는 한가지 경우)
    if(citations[0] > n)
        answer++;

    return answer;
}