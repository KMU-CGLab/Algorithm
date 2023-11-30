#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int half_num = nums.size() * 0.5f;

    sort(nums.begin(), nums.end(), std::greater<int>());
    // 중복 제거 -> 종류 수 나옴
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (auto n : nums)
    {
        std::cout << n << std::endl;
    }

    int poketmon_count = nums.size();

    if (poketmon_count > half_num)
        answer = half_num;
    // 종류가 가지고 갈 수 잇는 포켓몬보다 적을 때, 포켓몬 종류 자체가
    else
        answer = poketmon_count;

    return answer;
}