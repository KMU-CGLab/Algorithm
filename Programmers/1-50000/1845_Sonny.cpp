#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    std::map<int, int> monster = std::map<int, int>();
    
    for(auto i : nums)
    {
        // 있다
        if(monster.find(i) != monster.end())
        {
            monster.at(i)++;
        }
        // 처음이다
        else
        {
            monster.insert({i, 1});
        }
    }
    
    int vector_half = nums.size() * 0.5f;
    int map_size = monster.size();
    
    if(map_size >= vector_half)
    {
        answer = vector_half;
    }
    else
    {
        answer = map_size;
    }
    
    return answer;
}