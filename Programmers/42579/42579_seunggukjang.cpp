#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
bool cmpstring(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genresTotal; //total plays by genres
    unordered_map<string, vector<pair<int, int>>> hash;

    int count = genres.size();
    for (int i = 0; i < count; i++)
    {
        string g = genres[i];
        if (genresTotal.find(g) != genresTotal.end())
        {
            genresTotal[g] += plays[i];
            hash.at(g).push_back(make_pair(plays[i], i));
        }
        else
        {
            genresTotal.emplace(make_pair(genres[i], plays[i]));
            vector<pair<int, int>> tmp;
            tmp.push_back(make_pair(plays[i], i));
            hash.emplace(make_pair(genres[i], tmp));
        }

    }
    vector<pair<string, int>> vec(genresTotal.begin(), genresTotal.end());
    sort(vec.begin(), vec.end(), cmpstring);
    count = genresTotal.size();
    for (unordered_map<string, vector<pair<int, int>>>::iterator i = hash.begin(); i != hash.end(); i++)
    {
        sort(i->second.begin(), i->second.end(), cmp);
    }
    for (auto genreName : vec)
    {
        auto ids = hash.at(genreName.first);
        int idsCount = ids.size();
        if (idsCount >= 2)
        {
            for (int i = 0; i < 2; i++)
            {
                answer.push_back(ids[i].second);
            }
        }
        else
        {
            answer.push_back(ids[0].second);
        }
    }
    return answer;
}