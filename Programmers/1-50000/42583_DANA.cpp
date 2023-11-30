#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    
    int answer = 0;
    int bridge_in_num=0;
    int bridge_truck_weight=0;
    int temp,font_truck_b;
    

    queue<int> truck;
    deque<int> truck_b;
    truck = queue<int>();
    truck_b = deque<int>();
    
    for(int i=0;i<truck_weights.size();i++){
        truck.push(truck_weights[i]);
    }

    for(int i=0;i<bridge_length;i++)
        truck_b.push_back(0);
    
    while(truck.size()>0)
    {
        temp = truck.front();
        font_truck_b=truck_b.front();

       
        if(truck_b.size()>0){
            truck_b.pop_front();
            if(font_truck_b>0){
                bridge_truck_weight-=font_truck_b;
                bridge_in_num--;
            }
        }

        int next_weight = bridge_truck_weight+temp;
        int next_length = bridge_in_num+1;

        
        if(next_length<=bridge_length&&next_weight<=weight){
                //팝업해서 넣어주기
                truck_b.push_back(temp);
            
                bridge_truck_weight+=temp;
                bridge_in_num++;

                truck.pop();
        }
        else  
        {
            truck_b.push_back(0);
        }
        
        answer+=1;

    }
    
    if(bridge_in_num>0)
        answer+=bridge_length;

    return answer;
}