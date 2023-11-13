// 68645, 삼각 달팽이, 월간 코드 체린지 시즌1

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> pyramid;

    // 밑으로
    for (int row = 0; row < n; ++row)
    {
        pyramid.push_back(vector<int>());
        for (int col = 0; col < n; ++col)
        {
            pyramid[row].push_back(0);
        }
    }
    
    int number = 0;
    int counter = 0;
    int switcher = n;
    int row = -1;
    int col = 0;
    while (1)
    {
        // flag 1
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

        // flag 2
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

        // flag 3
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