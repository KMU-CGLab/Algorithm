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

    deque<int> dq_on_bridge = deque<int>();
    queue<int> q_trucks = queue<int>();

    for (int i = 0; i < bridge_length; i++)
    {
        dq_on_bridge.push_back(0);
    }

    for (auto unit : truck_weights)
    {
        q_trucks.push(unit);
    }

    while (q_trucks.size() > 0)
    {
        int truck = dq_on_bridge.front();

        if (truck > 0)
        {
            weight_total -= truck;
            length_total--;
        }

        dq_on_bridge.pop_front();

        truck = q_trucks.front();
        int assumpt_w = weight_total + truck;
        int assumpt_l = length_total + 1;

        if (truck > 0 && weight >= assumpt_w && bridge_length >= assumpt_l)
        {
            dq_on_bridge.push_back(truck);

            weight_total = assumpt_w;
            length_total = assumpt_l;

            q_trucks.pop();
        }
        else
        {
            dq_on_bridge.push_back(0);
        }

        counter++;
    }

    if (weight_total > 0)
        counter += bridge_length;

    answer = counter;

    return answer;
}