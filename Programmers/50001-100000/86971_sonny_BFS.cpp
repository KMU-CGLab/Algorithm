#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> edges;

void print()
{
    for (int i = 1; i < edges.size(); ++i)
    {
        cout << i << " : ";
        for (int j = 0; j < edges[i].size(); ++j)
        {
            cout << " [" << edges[i][j] << "] ";
        }
        cout << endl;
    }
}

int Tree(int from, int to)
{
    // 현재 뻗어나온 브랜치
    vector<int> branch = edges[to];

    bool is_linked = false;
    for (int i = 0; i < branch.size(); ++i)
    {
        int leaf = branch[i];
        if (leaf == from)
        {
            is_linked = true;
        }
    }

    // 서로 연결 안돼있으면 return;
    if (!is_linked)
        return 0;

    int edge_count = 0;
    for (int i = 0; i < branch.size(); ++i)
    {
        int leaf = branch[i];

        if (leaf == from)
            continue;
        else
        {
            edge_count += Tree(to, leaf);
            edge_count++;
        }
    }

    return edge_count;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 0;

    for (int i = 0; i <= n; ++i)
    {
        edges.push_back(vector<int>());
    }

    // Point 별 연결된 edge
    for (auto wire : wires)
    {
        int v1 = wire[0];
        int v2 = wire[1];

        // point에 어떤 edge?
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    // 간선 잘라보면서, 체크
    vector<int> edge_counts;
    for (int i = 1; i < edges.size(); ++i)
    {
        auto branch = edges[i];

        for (int j = 0; j < branch.size(); ++j)
        {
            int except = branch[j];

            int edge_count = 0;
            // 간선 끊어내고, 그래프 순회
            for (int k = 0; k < branch.size(); ++k)
            {
                if(branch[k] == except)
                    continue;

                edge_count += Tree(i, branch[k]) + 1;  // 보내는 간선 + 1
            }
        edge_counts.push_back(edge_count);
        }

    }

    sort(edge_counts.begin(), edge_counts.end(), less<int>());

    while(edge_counts.size() > 2)
    {
        edge_counts.erase(edge_counts.begin());
        edge_counts.pop_back();
    }

    // 중간값 결정 (가장 고르게 분포되야 하니까)
    answer = edge_counts[1] - edge_counts[0];

    return answer;
}