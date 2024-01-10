#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

/*

Return
- 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수

Rule
- A와B의 선물 기록을 비교 더 많이 준 사람이 한개를 받음
- 기록이 하나도 없거나 주고 받은 수가 같다면, 선물 지수가 더 큰 사람(+1) 선물 지수가 더 작은 사람(-1)

*/

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<vector<int>> presentTable;   //선물 지수(받은선물,준선물)
    
    for(int i=0;i<friends.size();i++){
        vector<int> low;
        for(int j=0;j<friends.size();j++){
            low.push_back(0);
        }
        presentTable.push_back(low);
    }
    // 공백 분리
    for(int i=0;i<gifts.size();i++){
        stringstream ss(gifts[i]);
        vector<int> words;
        string word;
        while(getline(ss,word,' ')){
            int i;
            for(i=0;i<friends.size();i++){
                if(word==friends[i]) break;
            }
            words.push_back(i);
        }
        presentTable[words[0]][words[1]]++;   
    }
    
    //선물 지수 테이블
    vector<int> presentFactor;
    vector<int> receiveSums;
    vector<int> additional;
    for(int i=0;i<presentTable.size();i++){
        additional.push_back(0);
        // receiveSum : 받은 선물 합, toSum : 준 선물 합
        int receiveSum=0,toSum=0;
        for(int j=0;j<presentTable.size();j++){
            if(j!=i) toSum+=presentTable[i][j];
            //cout<<presentTable[i][j]<<" ";
        }
        
        for(int j=0;j<presentTable.size();j++){
            if(j!=i) receiveSum+=presentTable[j][i];
            //cout<<presentTable[i][j]<<" ";
        }
        
        presentFactor.push_back(toSum-receiveSum);
        receiveSums.push_back(receiveSum);
        
        //cout<<"       "<<toSum-receiveSum;
        //cout<<endl;
    }
    //cout<<endl;


    // 얼만큼 더 받을 것인지 계산
    for(int i=0;i<presentTable.size();i++){
        for(int j=0;j<presentTable.size();j++){
            if(i==j) continue;
            else if(presentTable[j][i]-presentTable[i][j]==0&&
              presentFactor[i]-presentFactor[j]==0){
                continue;
            }
            else if(presentTable[j][i]==presentTable[i][j]){
                if(presentFactor[i]<presentFactor[j]){
                    //cout<<"Factor another call! :"<<i<<" "<<j<<endl;
                    additional[j]++;
                }
            }
            else{
                if(presentTable[j][i]>presentTable[i][j]){
                    //cout<<"Factor call! :"<<i<<" "<<j<<endl;
                    additional[j]++;
                }
            }
        }
    }
    //cout<<endl;
    
    sort(additional.begin(),additional.end(),greater<>());
    answer = additional[0];
    
    return answer;
}