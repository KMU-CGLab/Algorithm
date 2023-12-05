// 최댓값과 최솟값, 문자열을 숫자로 변환하는 방법, string pos를 생각
// getline (istringstream(s), token, " ");

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> Numbers;
    
    int CurrentPos = 0;
    while(CurrentPos < s.length())
    {
        int NextPos = s.find(" ", CurrentPos);
        
        if(NextPos == string::npos)
            NextPos = s.length();
        
        int SubstrCount = NextPos - CurrentPos;
        int Number = stoi(s.substr(CurrentPos, SubstrCount));
        Numbers.push_back(Number);
        CurrentPos = NextPos + 1;
    }
    
    sort(Numbers.begin(), Numbers.end(), greater<int>());
    
    answer += to_string(Numbers.back());
    answer += " ";
    answer += to_string(Numbers.front());
    
    return answer;
}