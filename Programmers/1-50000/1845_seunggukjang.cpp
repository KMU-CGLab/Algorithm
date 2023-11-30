#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> pokes;
    int answer = 0;
    int count = nums.size();
    int pokesCount = (int)(count * 0.5);
    int i = 0;
    while (i < count)
    {
        pokes.emplace(nums[i], 0);
        i++;
        if (pokes.size() >= pokesCount)
        {
            break;
        }
    }
    answer = pokes.size();
    return answer;
}