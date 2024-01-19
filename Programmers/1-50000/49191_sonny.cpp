// 49191 : 순위 LV.3
// 그래프
// 정확한 순위를 알 수 있는 사람들 찾기
// A가 B에게 지고, C는 A에게 진다면, C는 B에게도 진다.
// Winner -> Loser -> LoserLoser -> LoserLoserLoser ... (DFS로 이길 수 있는 모든 사람 찾기)

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// contain value in vector
bool IsContain(int n, vector<int> &v)
{
    for (auto value : v)
    {
        if (value == n)
            return true;
    }

    return false;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    map<int, vector<int>> WinMap;  // 이길 수 있는 사람들만 저장
    map<int, vector<int>> Players;  // 대결한 사람 모두 저장

    for (auto result : results)
    {
        int Winner = result[0];
        int Loser = result[1];

        // Winner 기준 Loser 저장
        if (Players.count(Winner) == 0)
        {
            vector<int> Rivals;
            Rivals.push_back(Loser);
            Players.emplace(make_pair(Winner, Rivals));
            WinMap.emplace(make_pair(Winner, Rivals));  // WinMap 따로 저장
        }
        else
        {
            Players[Winner].push_back(Loser);
            WinMap[Winner].push_back(Loser);
        }

        // Loser 기준 Winner 저장 (대결한 사람 모두 저장을 위해)
        if (Players.count(Loser) == 0)
        {
            vector<int> Rivals;
            Rivals.push_back(Winner);
            Players.emplace(make_pair(Loser, Rivals));
        }
        else
        {
            Players[Loser].push_back(Winner);
        }
    }

    // DFS
    for (auto Winner : WinMap)
    {
        int WinKey = Winner.first;
        vector<int> Losers = Winner.second;  // Winner에게 진 사람들
        vector<int> Visit = Losers;

        while (Visit.size() > 0)
        {
            int Loser = Visit.back();
            Visit.pop_back();
            vector<int> LoserLosers = WinMap[Loser];  // 루저에게 진 사람들
            
            // 대결해보진 않았지만, 나에게 진 사람한테 지기 때문에, 나에게도 짐
            for (int LoserLoser : LoserLosers)
            {
                if (IsContain(LoserLoser, Players[WinKey]))
                    continue;

                Players[WinKey].push_back(LoserLoser);
                Players[LoserLoser].push_back(WinKey);
                Visit.push_back(LoserLoser);
            }
        }
    }

    // 모두와 싸워본 사람만 체크
    for (auto Player : Players)
    {
        if (Player.second.size() == n - 1)
            answer++;
    }

    return answer;
}