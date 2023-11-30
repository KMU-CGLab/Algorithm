#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int& a, int& b)
{
    return a < b;
}
int solution(vector<int> priorities, int location) {
    int answer = 1;
    int count = priorities.size();
    int local = priorities[location];
    //현재 찾는 것(local) 보다 크거나 같은 priority를 저장
    vector<int> bigs;
    for (int i = 0; i < count; i++)
    {
        if (priorities[i] >= local)
        {
            bigs.push_back(priorities[i]);
        }
    }
    //정렬
    sort(bigs.begin(), bigs.end(), cmp);
    //[1,2,2,3]
    //circular queue
    for (int i = 0; i < priorities.size(); i++)
    {
        int big = bigs.back();
        if (priorities[i] == big)
        {
            bigs.pop_back();
            if (i % count == location)
            {
                break;
            }
            answer++;
        }
        priorities.push_back(priorities[i]); 
    }
    return answer;
}