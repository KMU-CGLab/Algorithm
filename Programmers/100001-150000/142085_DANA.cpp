#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//greedy
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    if(enemy.size()<=k) return enemy.size();
    
    //priority queue, greater
    priority_queue<int,vector<int>,greater<int>> priEnemy;
    
    int last;
    for(int i=0;i<enemy.size();i++){
        priEnemy.push(enemy[i]);
        if(priEnemy.size()>k){      //one must delete
            last = priEnemy.top();
            priEnemy.pop();
            if(last>n)
                return i;
            n-=last;
        }
    }
    
    return enemy.size();
}