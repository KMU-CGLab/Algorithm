#include <string>
#include <vector>
#include <map>

using namespace std;

<<<<<<< HEAD
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> map_participant = map<string, int>();
    
    for(auto i : participant)
    {
        // participant 리스트 삽입하되, 이미 존재한다면 ++
        if(map_participant.find(i) != map_participant.end())
=======
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> map_participant = map<string, int>();

    for (auto i : participant)
    {
        // map에 participat를 복제하되, 동명이인 수 만큼 ++
        if (map_participant.find(i) != map_participant.end())
>>>>>>> 01e8e1ab6db5c964a15cf90f459788245f3434a4
        {
            map_participant[i]++;
        }
        else
        {
            map_participant.insert({i, 1});
        }
    }
<<<<<<< HEAD
    
    for(auto i : completion)
    {
        map_participant[i]++;
    }
    
    for(auto i : map_participant)
    {
        if(i.second % 2 != 0)
=======

    for (auto i : completion)
    {
        map_participant[i]++;
    }

    // 2개의 목록이 있기 때문에 (참여자, 완주자) 2의 배수가 나와야 하지만, 완주자 목록에 존재하지 않는 인원이 있다면 홀 수가 나옴
    for (auto i : map_participant)
    {
        if (i.second % 2 != 0)
>>>>>>> 01e8e1ab6db5c964a15cf90f459788245f3434a4
        {
            answer = i.first;
            break;
        }
    }
<<<<<<< HEAD
    
=======

>>>>>>> 01e8e1ab6db5c964a15cf90f459788245f3434a4
    return answer;
}