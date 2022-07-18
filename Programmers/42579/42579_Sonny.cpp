#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 내림차순
bool compare_pair_genre_play(pair<string, int> p1, pair<string, int> p2)
{
   return p1.second < p2.second;
}

// 내림차순
bool compare_pair_id_play(pair<int, int> p1, pair<int, int> p2)
{
   // 이름이 같은 경우 더 작은 값을 취함
   if(p1.second == p2.second)
      return p1.first > p2.first;

   return p1.second < p2.second;
}

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays)
{
   vector<int> answer;
   map<string, vector<pair<int, int>>> map_gen_stack = map<string, vector<pair<int, int>>>();
   map<string, int> map_gen_play = map<string, int>();

   for (int i = 0; i < genres.size(); i++)
   {
      string g = genres[i];
      int p = plays[i];

      // 같은 장르들을 key(genre), value(stack<id, play>) 로 묶음
      // 장르 키로 스택에 접근하여, 해당 아이디의 플레이 횟수를 가져올 수 있음
      if (map_gen_stack.count(g) > 0)
      {
         map_gen_stack[g].push_back(pair<int, int>(i, p));
      }
      else
      {
         vector<pair<int, int>> vec = vector<pair<int, int>>();
         map_gen_stack[g].push_back(pair<int, int>(i, p));
         map_gen_stack.insert_or_assign(g, vec);
      }

      // 가장 많은 플레이 횟수를 가진 장르를 구하기 위한 플레이 횟수 누적 map
      if (map_gen_play.count(g) > 0)
      {
         map_gen_play[g] += p;
      }
      else
      {
         map_gen_play.insert({ g, p });
      }
   }

   // 플레이 횟수가 가장 많은 장르를 기준으로 내림차순
   vector<pair<string, int>> order_map = vector<pair<string, int>>(map_gen_play.begin(), map_gen_play.end());
   sort(order_map.begin(), order_map.end(), compare_pair_genre_play);
   
   // 각 장르는 스택으로 관리되고, 스택에는 id와 플레이 횟수 piar로 묶여있음
   // auto for 구문을 사용하면, value 자체에 영향을 미치지 못하기 때문에, iter로 사용
   for (auto m = map_gen_stack.begin(); m != map_gen_stack.end(); m++)
   {
      // stack에서도 플레이 횟수를 기준으로 내림차순 정렬
      sort((*m).second.begin(), (*m).second.end(), compare_pair_id_play);
   }

   // 플레이 횟수를 기준으로 내림차순 정렬된 vector -> 0번부터 가장 큰 수
   for (auto m : order_map)
   {
      // 장르 기준으로 검색
      string g = m.first;

      // 해당 장르의 -> 가장 많은 플래이 횟수의 -> id
      answer.push_back(map_gen_stack[g][0].first);

      // 해당장르가 2이상이면 1개 더 가지고 옴
      if (map_gen_stack[g].size() > 1)
         answer.push_back(map_gen_stack[g][1].first);
   }

   return answer;
}