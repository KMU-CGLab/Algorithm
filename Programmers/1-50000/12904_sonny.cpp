// 12904, 가장 긴 팰린드롬
// &를 붙여서 파라미터로 보내면, 복사가 아니라 레퍼런스 참조 -> 더 빠름

#include <iostream>
#include <string>

using namespace std;

bool IsPalind(int start, int end, const string& s)
{   
    int len = end - start + 1;
    int mid = (start + end + 1) / 2;
    int foward = mid;
    int backward = mid;  // mid는 backward의 시작점
    
    // 문장이 홀수면 두 포인터는 같고, 짝수면 foward를 하나 당김
    // 0, 1 -> len = 2, mid = 1, foward = 0, backward = 1
    // 0, 2 -> len = 3, mid = 1, foward = 1, backward = 1
    // 1, 2 -> len = 2, mid = 2, foward = 1, backward = 2
    if(len % 2 == 0)
        foward--;
    
    // 가운데서 출발해서 양극으로 진행
    while(foward >= start && backward <= end)
    {
        if(s[foward] != s[backward])
            return false;
        
        foward--;
        backward++;
    }
    
    return true;
}

int solution(string s)
{
    int answer = 0;
    int Len = s.length();
    int AnswerLimit = Len;
    
    // 0번부터 시작해서 시작포인터를 앞으로 밀어가며, 투포인터 브루트포스
    // a, ab, abc, ..., b, bc, ... c
    for(int i = 0; i < Len; ++i)
    {
        for(int j = i; j < Len; ++j)
        {
            int Start = i;
            int End = j;
            if(IsPalind(Start, End, s))
            {
                int PalindLength = End - Start + 1;
                answer = max(answer, PalindLength);
            }
        }
        
        // 확인 : 현재 가질 수 있는 가장 높은 값
        if(answer == AnswerLimit)
            break;
        
        AnswerLimit--;
    }
    
    return answer;
}