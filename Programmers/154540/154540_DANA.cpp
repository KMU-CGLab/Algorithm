#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> answer;
bool visited[101][101];
int n,m;
int countNum;

//bfs를 사용하여 방문한 곳을 표시하여 상하좌우 노드들을 탐색함
void bfs(int yint x,vector<string> maps,int arrow[4][2]){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    
    visited[y][x]=true;
    
    while(!q.empty()){
        int currentY = q.front().first;
        int currentX = q.front().second;

        string num = maps[currentY].substr(currentX,1);
        
        countNum+=stoi(num);
        q.pop();
        
        
        for(int i=0;i<4;i++){
            int nextY = currentY+arrow[i][0];
            int nextX = currentX+arrow[i][1];
            
            if(nextY>=0&&nextY<n&&nextX>=0&&nextX<m&&!visited[nextY][nextX]){
                string val = maps[nextY].substr(nextX,1);
                if(val!="X"){
                    visited[nextY][nextX]=true;
                    q.push(make_pair(nextY,nextX));
                }
            }
        }
    } 
    
    answer.push_back(countNum);
}

vector<int> solution(vector<string> maps) {
    
    n=maps.size();
    m=maps[0].size();
    
    int arrow[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            string val = maps[i].substr(j,1);
            if(val=="X"){
                visited[i][j]=true;
            }
            else if(!visited[i][j]){
                countNum=0;
                bfs(i,j,maps,arrow);
            }        
        }
    }
    
    if(answer.size()>0)
        sort(answer.begin(),answer.end());
    else
        answer.push_back(-1);
    
    return answer;
}