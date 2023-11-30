#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    //옷을 종류별로 나눈다음에 각 종류의 옷 개수를 저장(단, 안 입는다는 경우도 합해서 저장한다. ex. 안경이 총 3개면 안경을 안쓴다는 경우를 합해 4를 저장
    map<string, int> hash;
    int count = clothes.size();
    int answer = 1;
    for (int i = 0; i < count; i++)
    {
        if (hash.find(clothes[i].at(1)) != hash.end())
            hash[clothes[i].at(1)] += 1;
        else
            hash.emplace(clothes[i].at(1), 2);
    }

    for (auto i = hash.begin(); i != hash.end(); i++)
    {
        answer *= i->second;
    }
    //적어도 하나의 옷을 입기 때문에 아무것도 안입는다는 경우인 1를 뺀다.
    answer -= 1;
    return answer;
}