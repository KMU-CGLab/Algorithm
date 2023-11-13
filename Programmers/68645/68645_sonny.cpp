// 68645, 삼각 달팽이, 월간 코드 체린지 시즌1

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> pyramid;

    // 0으로 grid 채우기
    for (int row = 0; row < n; ++row)
    {
        pyramid.push_back(vector<int>());
        for (int col = 0; col < n; ++col)
        {
            pyramid[row].push_back(0);
        }
    }
    
    // 삼각형 달펭이 체우기
    int number = 0;
    int counter = 0;
    int switcher = n;
    int row = -1;
    int col = 0;
    while (1)
    {
        // 남쪽
        for (int counter = 0; counter < switcher ; counter++)
        {
            row++;
            number++;
            pyramid[row][col] = number;
        }

        switcher--;
        if(switcher == 0)
        {
            break;
        }

        // 동쪽
        for (int counter = 0; counter < switcher ; counter++)
        {
            col++;
            number++;
            pyramid[row][col] = number;
        }

        switcher--;
        if(switcher == 0)
        {
            break;
        }

        // 북서쪽
        for(int counter = 0; counter < switcher ; counter++)
        {
            --col;
            --row;
            number++;
            pyramid[row][col] = number;
        }

        switcher--;
        if(switcher == 0)
        {
            break;
        }
    }

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            int num = pyramid[row][col];
            
            if(num == 0)
                break;

            answer.push_back(num);
        }
    }

    return answer;
}