#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare_pair_n(pair<string, int> p1, pair<string, int> p2)
{
   return p1.second < p2.second;
}

bool compare_pair_nn(pair<int, int> p1, pair<int, int> p2)
{
   return p1.second < p2.second;
}

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays)
{
   vector<int> answer;
   map<string, vector<pair<int, int>>> map_ = map<string, vector<pair<int, int>>>();
   map<string, int> map__ = map<string, int>();

   for (int i = 0; i < genres.size(); i++)
   {
      string g = genres[i];
      int p = plays[i];

      if (map_.count(g) > 0)
      {
         map_[g].push_back(pair<int, int>(i, p));
         
         for(auto n : map_[g])
         {
             std::cout << n.first << ":" << n.second << std::endl;
         }
      }
      else
      {
         vector<pair<int, int>> vec = vector<pair<int, int>>();
         map_[g].push_back(pair<int, int>(i, p));
         map_.insert_or_assign(g, vec);
      }

      if (map__.count(g) > 0)
      {
         map__[g] += p;
      }
      else
      {
         map__.insert({ g, p });
      }
   }

   // 장르 플레이 정렬
   vector<pair<string, int>> order_map = vector<pair<string, int>>(map__.begin(), map__.end());
   sort(order_map.begin(), order_map.end(), compare_pair_n);
   
   // 장르별 스택, 플레이 숫자별로 정렬
   for (auto m = map_.begin(); m != map_.end(); m++)
   {
       
      sort((*m).second.begin(), (*m).second.end(), compare_pair_nn);
       
       std::cout << (*m).first << " : ";
       for(auto n : (*m).second)
       {
           std::cout << "(" << n.first << ", " << n.second << ")" << " / ";
       }
       std::cout << std::endl;
   }

   //map_ 안에 stack의 앞에 두개만 빼기
    for(auto m : order_map)
    {
        string g = m.first;
        
        answer.push_back(map_[g][0].first);
        
        if(map_[g].size() > 1)
            answer.push_back(map_[g][1].first);
    }
    
   return answer;
}