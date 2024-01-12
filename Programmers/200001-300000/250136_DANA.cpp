#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/*

Return
- 시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량

Rule
- 석유 덩어리의 일부를 지나면 해당 덩어리에 속한 모든 석유를 뽑을 수 있음
- 뽑을 수 있는 석유량은 지나는 석유 덩어리들의 크기를 모두 합한 값

Solution
- bfs를 이용하여 맵 영역 생성

- 1. 드릴을 뚫을때 접촉한 영역을 저장
- 2. 중복 영역을 제거
- 3. 영역의 cost를 더한 후 현재 값보다 크면 변경

*/

bool visited[501][501];
int area[501][501];
int arrow[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
vector<vector<int>> landCopy;

// bfs를 이용하여 영역(구역) 맵(배열) 설정 
int bfs(int y,int x,int areaNum){
    
    queue<vector<int>> q;
    vector<int> first;
    first.push_back(y);
    first.push_back(x);
    q.push(first);
    
    int sum=0;
    while(!q.empty()){
        vector<int> curPos =q.front();
        int curY = curPos[0];
        int curX = curPos[1];
        if(!visited[curY][curX])
        {
            visited[curY][curX]=true;
            area[curY][curX]=areaNum;
            sum++;
            
            // 상,하,좌,우 탐색
            for(int i=0;i<4;i++){
                int nextY=curPos[0]+arrow[i][0];
                int nextX=curPos[1]+arrow[i][1];
                if(nextY<n&&nextY>=0&&nextX<m&&nextX>=0){
                    if(!visited[nextY][nextX]&&landCopy[nextY][nextX]==1)
                    {
                        vector<int> location;
                        location.push_back(nextY);
                        location.push_back(nextX);
                        q.push(location);
                    }
                }
            }
        }
        q.pop();
    }
    
    return sum;
    
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    landCopy = land;
    //세로 길이 n, 가로 길이 m
    n = land.size();
    m = land[0].size();
    
    //areaCost : 영역의 넓이(cost)
    vector<int> areaCost;
    int idx=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&land[i][j]==1){
                int sum=0;
                sum = bfs(i,j,idx);
                idx++;
                areaCost.push_back(sum);
            }
        }
        
    }
    
    for(int i=0;i<m;i++){
        int total=0;
        vector<int> allArea;
        
        // 드릴이 뚫는 영역 모두 저장
        for(int j=0;j<n;j++){
            allArea.push_back(area[j][i]);
        }
        
        // 중복 제거
        sort(allArea.begin(),allArea.end());
        allArea.erase(unique(allArea.begin(),allArea.end()),allArea.end());
        
        // 모든 석유량 합산
        for(int j=0;j<allArea.size();j++){
            total+= areaCost[allArea[j]-1];
        }
        
        if(total>answer){
            answer=total;
        }
    }
    
    return answer;
}