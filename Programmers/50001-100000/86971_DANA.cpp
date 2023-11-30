#include <string>
#include <vector>

using namespace std;

//dfs, visited 방법

int graph[101][101];
int visited[101];

int dfs(int cur, int n)
{
    if(visited[cur]) return 0;      //한번 방문한 곳은 재방문 X
    int child=1;      //하위 노드의 갯수
    visited[cur]=true;
    for(int i=1;i<=n;i++)
    {
        if(graph[cur][i])       //연결, 간적 없는 곳만
        {
            child+=dfs(i,n);
        }
    }
    return child;
}

void setGraph(int x,int y,int value)
{
    graph[x][y]=value;
    graph[y][x]=value;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    //연결되어 있는 모든 송전탑 1로 초기화
    for(int i=0;i<wires.size();i++){
        setGraph(wires[i][0],wires[i][1],1);
    }
    
    for(int i=0;i<wires.size();i++){
        //방문 배열 초기화
        fill_n(visited,101,false);
        
        //끊을 전선 0으로 만들어주기 -> 전선 끊기
        setGraph(wires[i][0],wires[i][1],0);

        vector<int> diff;
        for(int i=1;i<=n;i++)
        {
            int tmp=dfs(i,n);       //깊이 탐색
            if(!tmp)continue;       //방문한 경우 생략
            diff.push_back(tmp);
        }
        answer = min(answer, abs(diff[0]-diff[1]));
        if(answer==0)break;
        //원상태로 돌려놓기
        setGraph(wires[i][0],wires[i][1],1);
    }
    
    return answer;
}