#include <vector>
#include<map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    bool isSame=false;
    map<int,int> poke;
    for(int i=0;i<nums.size();i++){
        isSame=false;
        for(auto iter:poke){
            //만약 같은 값이 존재한다면
            if(iter.first==nums[i]){
                iter.second++;      //수량만 더해줌
                isSame=true;        //같은게 있으면 새로 더해주지 않음
                break;
            }
        }
        if(!isSame)
            poke.insert({nums[i],1});       //새로운 값 더해주기
    }
    
    
    if(poke.size()<(nums.size()/2)){
        answer=poke.size();
    }
    else{
        //만약 폰켓몬의 종류가 갯수의 1/2보다 크면 1/2만큼까지만 받을 수 있음
        answer=nums.size()/2;
    }
    
    return answer;
}