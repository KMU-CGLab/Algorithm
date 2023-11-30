#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool fun(int a, int b)
{
    return a < b;
}

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
    vector<int> answer;
    int count = commands.size();
    for (int i = 0; i < count; i++)
    {
        std::vector<int> slice(arr.begin() + commands[i][0] - 1, arr.begin() + commands[i][1]);
        std::sort(slice.begin(), slice.end(), fun);
        answer.push_back(slice[commands[i][2] - 1]);
    }

    return answer;
}

int main()
{
    vector<int> v = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> c = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    vector<int> a = solution(v, c);
    return 0;
}
