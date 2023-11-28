// 42842, 카펫, 규칙 및 수식을 찾아서 해결

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int Size = brown + yellow;
    int Vertices = 4;
    int Row = 1;
    int Col = 1;
    
    // 12 * 4 = 48
    
    // 12 -> 48 + 4 - 22 = 30
    // 6 * 2 -> 52 - 32 = 20
    // 4 * 3 -> 52 - 34 = 18

    // 4 * 2 - (2 * 0 + (2 - 1) * 1) * 2  = 6
    // 6+ 4 = brown
    
    for(; Row < Size; ++Row)
    {
        // 12 * 0 + (12 - 1) * 1 * 2 = 22
        // (6 * 1 + (6 - 1) * 2) * 2 = 32
        // (4 * 2 + (4 - 1) * 3) * 2 = 34
        int Brown_Check = 0;
        int Overlaps = 0;
        if(yellow % Row == 0)
        {
            Col = yellow / Row;
            Overlaps = (Col * (Row - 1) + (Col - 1) * Row) * 2;
            Brown_Check = yellow * 4 - Overlaps + 4;
            //cout << Row << " " << Col;
            //cout << " : " << Brown_Check << endl;
        }
        
        if(brown == Brown_Check)
        {
            //cout << "Sol : " << Row << " " << Col << endl;
            break;
        }
    }
    
    // yellow 정렬 끝나면 사방으로 행 렬 늘어남 붙이기
    Row += 2;
    Col += 2;
    
    answer.push_back(Col);
    answer.push_back(Row);
    
    return answer;
}