#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> tracksInBridge;

    int count = truck_weights.size();
    int i = 0;
    int tracksOutBridgeCount = 0;
    int tracksInBridgeTotalWeights = 0;
    //bridge를 queue라고 여겨 queue의 사이즈가 bridge_length이고 앞에 있는 트럭부터 나온다.
    //bridge통과 시간은 bridge_length와 같기 때문에 queue에 무게가 없는 트럭을 bridge_length만큼 채운다.
    for (int j = 0; j < bridge_length; j++)
    {
        tracksInBridge.push(0);
    }
    while (tracksOutBridgeCount < count)
    {
        if (tracksInBridge.size() < bridge_length && (tracksInBridgeTotalWeights + truck_weights[i]) <= weight)
        {
            tracksInBridge.push(truck_weights[i]);
            tracksInBridgeTotalWeights += truck_weights[i];
            i++;
        }
        //다음 트럭이 이전 트럭의 무게 때문에 다리에 못 들어가면 0인 무게의 트럭으로 queue의 자리를 채운다.
        // |0|0| 0초
        // |0|7| 1초
        // |7|0| 2초
        // |0|4| 3초
        else if(tracksInBridge.size() < bridge_length)
        {
            tracksInBridge.push(0);
        }
        if (tracksInBridge.size() > 0)
        {
            int outWeight = tracksInBridge.front();
            tracksInBridgeTotalWeights -= tracksInBridge.front();
            tracksInBridge.pop();
            if(outWeight > 0)
                tracksOutBridgeCount++;
        }
        answer++;
    }
    return answer;
}

