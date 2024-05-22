// 43163 : 단어변환 Lv3
// BFS
// 옛날 문제라, 요즘 Lv2 정도 되는듯

#include <string>
#include <vector>
#include <queue>

using namespace std;

int Compare(const string& a, const string& b)
{
    int equalCount = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == b[i])
        {
            equalCount++;
        }
    }
    
    return equalCount;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    const int rule = begin.length() - 1;
    queue<pair<string, int>> q;
    vector<bool> visit = vector<bool>(words.size(), false);
    // bfs
    
    q.push({begin, 0});
    int visitCount = 0;
    while(q.size() > 0)
    {
        string current = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(current == target)
        {
            return level;
        }
        
        for(int i = 0; i < words.size() - visitCount; i++)
        {
            if(visit[i])
                continue;
            
            // char가 1개만 차이나야함
            if(Compare(current, words[i]) == rule)
            {
                q.push({words[i], level + 1});
                visit[i] = true;
            }
        }
    }
    
    return 0;
}