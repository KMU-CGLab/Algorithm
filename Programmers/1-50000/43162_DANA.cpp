#include <vector>

using namespace std;


void dfs(int level, int n,vector<vector<int>> network,bool* visited)
{
    visited[level]=true;
    
    for(int i=0;i<n;i++){
        //방문하지 않고 연결된 경우 다시 재 탐색
        if(!visited[i]&&network[level][i]==1){
            dfs(i,n,network,visited);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    bool visited[201]={false};
    
    for(int i=0;i<n;i++){
        //방문하지 않은 노드만 재탐색
        if(!visited[i]){
            dfs(i,n,computers,visited);
            
            //dfs함수가 끝난 후엔 연결된 한개의 네트워크가 생겨남으로 한개를 더해줌
            answer++;
        }
    }
    
    
    return answer;
}