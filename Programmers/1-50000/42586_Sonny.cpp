#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int size = progresses.size();
    int complete = 100;
    int start = 0;  // start는 배포하지 않은 부분 중 제일 앞
    int end = 0;  // end는 배포완료된 부분 까지의 ptr

    while(start != size)
    {
        // 배포하지 않은 부분의 바로 직전은 배포완료
        end = start - 1;

        // Progress Update (Start 이전까지는 전부 Complete)
        for(int i = start; i < size; i++)
        {
            progresses[i] += speeds[i];
        }

        // 완료된 버전까지 포인터를 이동 (제일 처음이 완료되지 않으면 뒤로 넘어갈 수 없음)
        for(int i = start; i < size; i++)
        {
            if(progresses[i] >= complete)
                end++;

            if(progresses[i] < complete)
            {
                break;
            }
        }

        // 완료된 부분 - 시작 부분 (포함은 + 1)
        int accu = end - start + 1;
        
        // 배포할 것이 1개 이상이면 배포하고, start ptr을 이동
        if(accu > 0)
        {
            answer.push_back(accu);
            start = end + 1;
        }
    }

    return answer;
}