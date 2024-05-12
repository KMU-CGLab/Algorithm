// 67257 : [카카오 인턴] 수식 최대화 Lv2
// next_permutation

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

long long Calculate(long long a, long long b, char op)
{   
    long long result = 0;
    switch(op)
    {
        case '+':
            result = a + b;
        break;
        case '-':
            result = a - b;
        break;
        case '*':
            result = a * b;
        break;
    }
    
    return result;
}

long long solution(string expression) 
{
    long long answer = 0;
    string priority = "+-*";
    vector<long long> numbers;
    vector<char> operators;
    
    string numberString;
    long long numberReal;
    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if(c == '+' || c == '-' || c == '*')
        {
            operators.push_back(c);
            numbers.push_back( stoll(numberString) );
            numberString = "";
        }
        else
        {
            numberString += c;
        }
    }
    numbers.push_back( stoll(numberString) );
    
    sort(priority.begin(), priority.end(), less<char>());
    vector<long long> copyNumbers = numbers;
    vector<char> copyOperators = operators;
    do {
        for(int i = 0; i < 3; i++)
        {
            char op = priority[i];
            for(int j = 0; j < operators.size(); j++)
            {
                if(operators[j] == op)
                {
                    //cout << numbers[j] << op << numbers[j + 1] << " = ";  
                    numbers[j] = Calculate(numbers[j], numbers[j + 1], op);
                    //cout << numbers[j] << endl;
                    numbers.erase(numbers.begin() + j + 1);
                    operators.erase(operators.begin() + j);
                    j--;
                }
            }
        }
        
        answer = max(answer, abs(numbers[0]));
        numbers = copyNumbers;
        operators = copyOperators;
        
    } while(std::next_permutation(priority.begin(), priority.end()));
    
    
    return answer;
}