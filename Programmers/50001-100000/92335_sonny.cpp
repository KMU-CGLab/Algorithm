// 92335 : k진수에서 소수 개수 구하기 Lv2

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// k진수로 바꿔주는 함수 : Q가 1일때까지 나누고, 나머지는 계속 붙임
string GetKSerial(int num, int k)
{
    string serial;
    
    while(num > k)
    {
        int R = num % k;
        
        serial += to_string(R);
        
        num /= k;
    }
    serial += to_string(num);
    
    return serial;
}

// 숫자 추출 함수 : 
// '0'이 나오면 지금까지 나온 숫자를 stoi 해서 vector에 집에넣는다.
vector<unsigned long long> Get10Serial(string num)
{
    string stringNum;
    vector<unsigned long long> nums;
    
    while(num.length() > 0)
    {
        char c = num.back();
        num.pop_back();
        
        if(c != '0')
            stringNum += c;
        else
        {
            if(stringNum.length() > 0)
            {
                unsigned long long newNumber = stoll(stringNum);                
                nums.push_back(newNumber);
                stringNum = "";
            }
        }
    }
    
    // 마지막 남은것
    if(stringNum.length() > 0)
    {
        unsigned long long newNumber = stoll(stringNum);
        nums.push_back(newNumber);
    }
    
    return nums;
}

// 소수인지 구별하는 함수 : sqrt까지 나누어서, 나누어떨어지지 않으면, 소수
bool IsPrimeNumber(unsigned long long num)
{
    if(num == 0 || num == 1)
        return false;
    
    if(num == 2 || num == 3)
        return true;
    
    unsigned long long end = sqrt(num);
    for(unsigned long long i = 2; i <= end; i++)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k)
{
    int answer = 0;
    vector<unsigned long long> nums;
    nums = Get10Serial(GetKSerial(n, k));
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(IsPrimeNumber(nums[i]))
        {
            answer++;
        }
    }
    
    return answer;
}