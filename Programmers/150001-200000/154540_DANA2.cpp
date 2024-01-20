#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool isVisited[101][101]={0,};
int area[101][101];
int arrow[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

void splitMap(string s,int y){
    for(int i=0;i<s.size();i++){
        if(s[i]!='X'){
            area[y][i]=stoi(s.substr(i,1));
        }
        else area[y][i]=0;
    }
}

int bfs(int y,int x){
    queue<vector<int>> q;
    vector<int> temp;
    temp.push_back(y);
    temp.push_back(x);
    q.push(temp);

    int sum=0;
    while(!q.empty()){
        int curY=q.front()[0];
        int curX=q.front()[1];
        if(area[curY][curX]!=0&&!isVisited[curY][curX]){
            isVisited[curY][curX]=true;
            //cout<<curY<<" "<<curX<<endl;
            sum+=area[curY][curX];

            for(int i=0;i<4;i++){
                vector<int> temp;
                int nextY=curY+arrow[i][0];
                int nextX=curX+arrow[i][1];
                if(nextY>=0&&nextX>=0&&nextY<n&&nextX<m){
                    if(!isVisited[nextY][nextX]){
                        temp.push_back(nextY);
                        temp.push_back(nextX);
                        q.push(temp);
                    }
                }
            }
        }
        q.pop();
    }
    //cout<<endl;
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n=maps.size();
    m=maps[0].size();
    for(int i=0;i<maps.size();i++){
        splitMap(maps[i],i);
    }

    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(!isVisited[i][j]){
                int sum = bfs(i,j);
                if(sum>0)
                    answer.push_back(sum);
            }

        }
    }


    if(answer.size()>0)
        sort(answer.begin(),answer.end());
    else
        answer.push_back(-1);

    return answer;
}