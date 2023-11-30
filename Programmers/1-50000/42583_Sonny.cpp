#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    // bridge_length : 최대 대수
    // weight : 최대 하중
    // truck_weights : 트럭 무게
    int answer = 0;
    int counter = 0;
    int flag = bridge_length;
    int weight_total = 0;
    int length_total = 0;

    deque<int> dq_on_bridge = deque<int>();  // 다리 위
    queue<int> q_trucks = queue<int>();  // 대기열

    // 다리 위는 모두 0으로 초기화 (트럭이 없는 상태)
    for (int i = 0; i < bridge_length; i++)
    {
        dq_on_bridge.push_back(0);
    }

    // 대기열에 트럭을 담아줌
    for (auto unit : truck_weights)
    {
        q_trucks.push(unit);
    }

    // 대기열의 다리를 모두 소모할 때까지 진행
    while (q_trucks.size() > 0)
    {
        // 다리 위의 결승선(?)에 있는 트럭
        int truck = dq_on_bridge.front();

        // 결승선에 트럭이 있다면 트럭 1개 완주
        if (truck > 0)
        {
            weight_total -= truck;
            length_total--;
        }

        // 트럭이 있으면 weight를 빼내고, 없더라도 0을 빼냄
        dq_on_bridge.pop_front();

        // 대기열에 있는 트럭
        truck = q_trucks.front();
        int assumpt_w = weight_total + truck;  // 다리 위 트럭들의 전체 무게 + 방금 꺼낸 대기열 트럭
        int assumpt_l = length_total + 1;  // 다리 위 트럭들의 전체 길이 + 방금 꺼낸 대기열 트럭 1개

        dq_on_bridge.push_back(truck);

        // 다리가 버틸 수 있는 무게와 길이를 비교해서 다리위에 트럭을 올릴지 말지 결정
        if (truck > 0 && weight >= assumpt_w && bridge_length >= assumpt_l)
        {
            // 다리위에 올렸으면 다리 위의 트럭 전체 무게와 길이를 갱신해주고 대기열에서 트럭 하나 삭제
            weight_total = assumpt_w;
            length_total = assumpt_l;

            q_trucks.pop();
        }
        
        // 시간이 지남
        counter++;
    }

    // 대기열 트럭을 모두 소모하면 바로 나오게 되고, 마지막 트럭을 넣은 시점부터 다리 길이만큼 시간이 경과되어야 완주
    if (weight_total > 0)
        counter += bridge_length;

    answer = counter;

    return answer;
}