// ========== STACK =========

#include <string>
#include <vector>

using namespace std;

struct node
{
    int num;
    int count;

    node(int in_num, int in_count) : num(in_num), count(in_count) { }
};

bool compare_stack_target(vector<int> stack, int target)
{
    int sum = 0;
    for(int& item : stack)
    {
        sum += item;
    }

    return sum == target;
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    vector<node> stack;
    node positive_start_node = node(numbers[0], 0);
    node negative_start_node = node(-numbers[0], 0);

    stack.push_back(negative_start_node);
    stack.push_back(positive_start_node);
    
    while(!stack.empty())
    {
        int num = stack.back().num;
        int count = stack.back().count;
        int level = count + 1;
        stack.pop_back();

        // 숫자를 전부 소비한 상태
        if(level >= numbers.size())
        {
            if(num == target)
                answer++;

            continue;
        }

        // 하위 노드로
        count++;

        // 현재값 +, - num으로 두개의 노드 스택으로 (+를 나중으로 해야, +가 먼저)
        stack.push_back( {num - numbers[count], count} );
        stack.push_back( {num + numbers[count], count} );
    }

    return answer;
}

// ========== RECULSIVE =========

// #include <string>
// #include <vector>

// using namespace std;

// // DFS로 구현
// void get_target_number(vector<int> numbers, int target, int sum, int index, int& out_answer)
// {
//     // 모든 numbers를 소모했다면
//     if(index == numbers.size())
//     {
//         // 모든 숫자를 소모했을 때, 결과값이 target과 같을때만 ++
//         if(sum == target)
//         {
//             out_answer++;
//         }
        
//         return;
//     }
    
//     // +로 분기
//     get_target_number(numbers, target, sum + numbers[index], index + 1, out_answer);
    
//     // -로 분기
//     get_target_number(numbers, target, sum - numbers[index], index + 1, out_answer);
// }

// int solution(vector<int> numbers, int target) 
// {
//     int answer = 0;
    
//     get_target_number(numbers, target, 0, 0, answer);
    
//     return answer;
// }