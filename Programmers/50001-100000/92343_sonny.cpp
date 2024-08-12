// 92343 : 양과 늑대 Lv3
// - recursive와 stack으로 구성된 dfs의 차이를 알 수 있음
// - recursive는 함수이기 때문에, 독립적인 정보들을 가질 수 있음 (매개변수들을 복사해서 받는다면)
// - 이렇게 각 정보가지고, 독립적인 공간에 몰아넣어서 문제를 해결

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

map<int, set<int>> tree;
int answer = 0;

map<int, set<int>> GetTree(const vector<vector<int>>& edges);

void DFS(int s, int w, int node, set<int> visit, const vector<int>& info)
{
    if(info[node] == 0)
        s++;
    else
        w++;
    
    answer = max(answer, s);
    
    if(w >= s)
        return;
    
    visit.erase(node);
    
    for(int next : tree[node])
    {
        visit.emplace(next);
    }
    
    for(int next : visit)
    {
        DFS(s, w, next, visit, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    tree = GetTree(edges);
    
    set<int> visit;
    visit.emplace(0);
    DFS(0, 0, 0, visit, info);
    
    return answer;
}

map<int, set<int>> GetTree(const vector<vector<int>>& edges)
{
    map<int, set<int>> tree;
    
    for(auto edge : edges)
    {
        for(int j = 0; j < 2; j++)
        {
            int left = edge[0];
            int right = edge[1];
            
            if(tree.count(left) > 0)
            {
                tree[left].emplace(right);
            }
            else
            {
                set<int> link;
                link.emplace(right);
                tree.emplace(left, link);
            }
            
            // if(tree.count(right) > 0)
            // {
            //     tree[right].emplace(left);
            // }
            // else
            // {
            //     set<int> link;
            //     link.emplace(left);
            //     tree.emplace(right, link);
            // }
        }
    }
    
    // for(auto s : tree)
    // {
    //     cout << s.first << " : ";
    //     for(int t : s.second)
    //     {
    //         cout << t << " ";
    //     }
    //     cout << endl;
    // }
    
    return tree;
}