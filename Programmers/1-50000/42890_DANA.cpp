#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

/*

return 
릴레이션을 나타내는 문자열 배열 relation이 매개변수로 주어질 때, 이 릴레이션에서 후보키의 개수

solution
set는 기본적으로 오름차순 정렬, 중복인자 갖지 않음
비트마스킹을 사용한 경우의 수 체크
비트마스킹 활용 풀이 : https://zrr.kr/2wWe
비트마스킹 설명 : https://zrr.kr/5cww

*/

// 최소성 확인
bool isDuplicate(vector<int>& vec,int now){
    for(int i = 0; i < vec.size(); i++)
        // ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인
        if((vec[i] & now) == vec[i])        //비트 연산을 했을 때 모두 같은 경우
            return true;
    return false;
}

int solution(vector<vector<string>> relation) {
    
    vector<int> ans;

    //총 조합의 가짓수
    for(int i=1;i<(1<<relation[0].size());i++){
        set<string> s;
        //세로 row size
        for(int j=0;j<relation.size();j++){
            string now ="";
            //가로 column size
            for(int k=0;k<relation[0].size();k++){
                if(i&(1<<k))
                    now+=relation[j][k];
            }
            s.insert(now);
        }
        
        if(s.size() == relation.size() && !isDuplicate(ans,i))
            ans.push_back(i);
        
    }
    
     return (int)ans.size();
}