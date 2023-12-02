#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<vector<int>>> visited;

int solution(string dirs) {
    int answer = 0;
    
    for(int i=0;i<11;i++){
        vector<vector<int>> col;
        for(int j=0;j<11;j++){
            vector<int> value;
            value.push_back(0);
            value.push_back(0);
            value.push_back(0);
            value.push_back(0);
            col.push_back(value);
        }
        visited.push_back(col);
    }
    
    int x=5,y=5,dir=0,redir=0;      //dir:방향 redir:역방향
    int nextX=0,nextY=0;
    for(int i=0;i<dirs.size();i++){
        nextX=x;nextY=y;
        if(dirs[i]=='U'){
            dir=0;
            redir=2;
            nextY-=1;
        }
        else if(dirs[i]=='D'){ 
            dir=2;
            redir=0;
            nextY+=1;
        }
        else if(dirs[i]=='R'){ 
            dir=1;
            redir=3;
            nextX+=1;
        }
        else if(dirs[i]=='L'){ 
            dir=3;
            redir=1;
            nextX-=1;
        }
        //만약 범위내에 그 다음값이 들어오지 않는다면 갱신하지 않고 넘어감
        if(nextX<0||nextX>=11||nextY<0||nextY>=11) continue;
        //그 다음값이 한번도 방문하지 않았다면
        if(visited[nextY][nextX][dir]!=1){ 
            answer++;
            visited[nextY][nextX][dir]=1;       //그 다음 지점 -> 현재 지점으로의 길 체크
            visited[y][x][redir]=1;             //현재 지점 -> 그 다음 지점으로의 길 체크
        }
        //위치값 갱신
        y=nextY;
        x=nextX;
    }
    
    return answer;
}