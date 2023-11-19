#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int visited[101][101];
int n,m;
vector<int> values;
int answer = 0;

//dfs가 아닌 bfs로 구성해야함
void bfs(int startY,int startX,vector<vector<int>> map,int arrow[4][2]){
    
    queue<pair<int,int>> q;
    queue<int> values;      //queue<pair<pair<int,int>,int> 대신 따로 최단거리 비용 값을 queue를 이용해 관리

    //처음 시작 값
    q.push(make_pair(startY,startX));
    values.push(1);

    //방문 표시
    visited[startY][startX]++;
    
    int curY,curX;
    answer=10000;
    int count=0;
    while(!q.empty()){
        int currentY = q.front().first;
        int currentX = q.front().second;
        count = values.front();
        q.pop();
        values.pop();
        for(int i=0;i<4;i++){
            int nextY = currentY+arrow[i][0];
            int nextX = currentX+arrow[i][1];
            
            //만약 방문하지 않고, Y와 X값이 범위안에 있을 때
            if(!visited[nextY][nextX]&&nextY>=0&&nextY<n&&nextX>=0&&nextX<m){ 
                //벽이 아닌 길일 경우
                if(map[nextY][nextX]==1){
                    visited[nextY][nextX]=1;
                    q.push(make_pair(nextY,nextX));     //다음 경로를 탐색 큐에 추가
                    values.push(count+1);
                    if(nextY==n-1&&nextX==m-1){     //만약 골에 도달했을 경우
                        answer=min(answer,count+1);     //지금 계산한 비용이 현재 최단거리 비용보다 적다면 교체
                    }
                }
            }
            
        }
        
    }

}

int solution(vector<vector<int> > maps)
{
    int arrow[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
    n = maps.size();
    m = maps[0].size();
    bfs(0,0,maps,arrow);
    
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }*/

    //만약 방문할 수 없다면
    if(!visited[n-1][m-1]) answer = -1;
    
    return answer;
}