#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;   
    int maxX=0,maxY=0;

    //큰값을 한쪽으로 몰아줌
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<=sizes[i][1])
        {
            int temp= sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    
    //max 값 계산
    for(int z=0;z<sizes.size();z++){
        if(maxX<sizes[z][0]) maxX = sizes[z][0];
        if(maxY<sizes[z][1]) maxY = sizes[z][1];
    }

    answer=maxX*maxY;
    
    return answer;
}