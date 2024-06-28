// 43162 : 네트워크 Lv3

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckVisited(const vector<bool>& visited)
{
    bool result = visited[0];
    
    for(bool element : visited)
    {
        result &= element;
    }
    
    return result;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool> visited = vector<bool>(n, false);
    vector<vector<int>> stack;
    
    while(!CheckVisited(visited))
    {
        answer++;
        if(stack.size() == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(visited[i] == false)
                {
                    stack.push_back(computers[i]);
                    break;
                }
            }
        }

        while(stack.size() > 0)
        {
            vector<int> computer = stack.back();
            stack.pop_back();

            for(int i = 0; i < computer.size(); i++)
            {
                if(visited[i] == false && computer[i] == 1)
                {
                    visited[i] = true;
                    stack.push_back(computers[i]);
                }
            }
        }
    }
    
    return answer;
}