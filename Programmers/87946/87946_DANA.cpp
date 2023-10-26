#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    //수열 next_permutation을 활용하여서 풀이
    //경우의 수를 다 계산한 다음 차례로 검증함
    vector<int> v;
    
    // 1부터 4까지 벡터에 저장
	for(int i=0; i<dungeons.size(); i++){
		v.push_back(i);
	}
    
    do{
        int pirodo=k;
        int count=0;
		for(int i=0; i<v.size(); i++){
            if(pirodo>=dungeons[v[i]][0]){
                //피로도 차감 및 던전 갯수 올리기
                count++;
                pirodo-=dungeons[v[i]][1];
            }
		}
        answer=max(answer,count);

	}while(next_permutation(v.begin(),v.end()));

    
    return answer;
}