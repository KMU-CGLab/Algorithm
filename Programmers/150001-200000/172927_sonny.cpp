// 172927 : 광물 캐기 Lv2
// BFS + struct
// limit -> numeric_limits<int>::max();

#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int pick;
    int stress;
    int count;
    vector<int> remains;
    
    Node(int inPick, int inStress, int inCount, vector<int> inRemains)
    {
        pick = inPick;
        stress = inStress;
        count = inCount;
        remains = inRemains;
    }
};

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = numeric_limits<int>::max();
    queue<Node> Q;
    vector<int> V;
    vector<int> powers;
    
    powers.push_back(25);
    powers.push_back(5);
    powers.push_back(1);
    
    int total = 0;
    for(int i = 0; i < 3; i++)
    {
        total += picks[i];
    }
    
    for(int i = 0; i < minerals.size(); i++)
    {
        string mineral = minerals[i];
        switch(mineral[0])
        {
            case 'd':
                V.push_back(25);
                break;
            case 'i':
                V.push_back(5);
                break;
            case 's':
                V.push_back(1);
                break;
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        if(picks[i] > 0)
        {
            Node node(i, 0, 0, picks);  // 사용한건 아님
            Q.push(node);
        }
    }
    
    while(Q.size() > 0)
    {
        int pick = Q.front().pick;
        int count = Q.front().count;
        int stress = Q.front().stress;
        vector<int> pickVec = Q.front().remains;
        Q.pop();
        
        // 사용
        pickVec[pick]--;
        
        int index = count * 5;
        int i;
        for(i = index; i < index + 5; i++)
        {
            if(V.size() <= i)
                break;
            
            stress += max(V[i] / powers[pick], 1);
        }
        count++;
        
        if(count >= total || i >= V.size())
        {
            answer = min(answer, stress);
            continue;
        }
        
        for(int i = 0; i < 3; i++)
        {
            if(pickVec[i] > 0)
            {
                Node node(i, stress, count, pickVec);  // 사용한건 아님
                Q.push(node);
            }
        }
    }
    
    return answer;
}