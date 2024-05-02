#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*

return 미로를 탈출하는데 필요한 최소 시간, 불가능하다면 -1

soluation
1. 레버까지 제일 빠르게 이동
2. 레버에서부터 다시 목표 지점까지 이동

S : 시작지점 / E : 출구 / L : 레버 / O : 통로 / X : 벽

*/


int costArr[101][101];
int arrow[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int sizeY,sizeX;

bool bfs(vector<int>& startP, vector<int>& endP,vector<string>& maps){
 
    queue<vector<int>> que;
    bool isVisited[101][101]={false,};
    
    startP.push_back(0);
    que.push(startP);
    isVisited[startP[0]][startP[1]]=true;
    
    int currentY,currentX;
    while(!que.empty()){
        currentY = que.front()[0];
        currentX = que.front()[1];
        int cost=que.front()[2];
        
        que.pop();

        costArr[currentY][currentX]=cost;
        
        if(currentY==endP[0]&&currentX==endP[1]){
            return true;
        }
        
        for(int i=0;i<4;i++){
            //갈수 있는 곳인지 확인
            int nextY = currentY + arrow[i][0];
            int nextX = currentX + arrow[i][1];
            if(nextY>=0&&nextY<sizeY&&nextX>=0&&nextX<sizeX&&!isVisited[nextY][nextX]){
                if(maps[nextY][nextX]=='X') continue;
                else {
                    vector<int> next;
                    next.push_back(nextY);
                    next.push_back(nextX);
                    next.push_back(cost+1);
                    que.push(next);
                }
                
                isVisited[nextY][nextX]=true;
            }
        }
    }

    if(currentY!=endP[0]||currentX!=endP[1])
        return false;
    
    return true;
}

int solution(vector<string> maps) {
    int answer = 0;
    vector<int> startPos;
    vector<int> endPos;
    vector<int> laborPos;
    
    sizeY=maps.size();
    sizeX=maps[0].size();
    
    int findCount=0;
    
    for(int i=0;i<sizeY;i++){
        char word;
        string str = maps[i];
        for(int j=0;j<sizeX;j++){
            word = str[j];
            
            if(findCount==3) break;
            
            if(word=='S'){
                startPos.push_back(i);
                startPos.push_back(j);
                findCount++;
            }
            else if(word=='E'){
                endPos.push_back(i);
                endPos.push_back(j);
                findCount++;
            }
            else if(word=='L'){
                laborPos.push_back(i);
                laborPos.push_back(j);
                findCount++;
            }
        }
    }


    if(!bfs(startPos,laborPos,maps)) return -1;
    else
        answer += costArr[laborPos[0]][laborPos[1]];   
    
    if(!bfs(laborPos,endPos,maps))return -1;
    else
        answer += costArr[endPos[0]][endPos[1]];
    
    return answer;
}