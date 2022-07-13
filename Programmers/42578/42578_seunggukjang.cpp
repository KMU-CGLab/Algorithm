#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    //���� �������� ���������� �� ������ �� ������ ����(��, �� �Դ´ٴ� ��쵵 ���ؼ� �����Ѵ�. ex. �Ȱ��� �� 3���� �Ȱ��� �Ⱦ��ٴ� ��츦 ���� 4�� ����
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
    //��� �ϳ��� ���� �Ա� ������ �ƹ��͵� ���Դ´ٴ� ����� 1�� ����.
    answer -= 1;
    return answer;
}