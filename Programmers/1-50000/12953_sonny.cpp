// 12953 : N개의 최소공배수 Lv2
// 공약수, 공배수 구하는 방법
// CommonDivisor
// CommonMultiplier

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> CDs;  // 공약수들

// 공약수 중, 소수만 가져오기
void GetNonCommonDivisor()
{
    for(int i = 0; i < CDs.size(); i++)
    {
        int number = CDs[i];
        bool isFind = false;
        
        for(int j = 2; j <= number / 2; j++)
        {
            int R = number % j;
            if(R == 0)
            {
                isFind = true;
                break;
            }
        }
        
        if(isFind)
        {
            CDs.erase(CDs.begin() + i);
            i--;
        }
    }
}

// 공약수 전부 구하기
void GetCommonDivisor(const vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int number = arr[i];
        
        for(int j = 1; j <= number / 2; j++)
        {
            int Q = number / j;
            int R = number % j;
            if(R == 0)
            {
                CDs.push_back(Q);
            }
        }
    }
    
    sort(CDs.begin(), CDs.end(), less<int>());
    CDs.erase(unique(CDs.begin(), CDs.end()), CDs.end());
}

int solution(vector<int> arr) 
{
    int answer = 1;
    vector<vector<int>> costs;
    
    GetCommonDivisor(arr);
    GetNonCommonDivisor();
    
    // 공약수를 가지고 소인수분해
    for(int i = 0; i < CDs.size(); i++)
    {
        int powCount = 0;  // 공약수가 필요한 최대 갯수 (8 = 2 * 2 * 2)
        int CD = CDs[i];
        for(int j = 0; j < arr.size(); j++)
        {
            int number = arr[j];
            int devideCount = 0;
            while(number > 1)
            {
                int R = number % CD;
                
                if(R == 0)
                {
                    number /= CD;
                    devideCount++;
                }
                else
                {
                    // 나누어지지 않으면 다음 공약수(CD)로
                    break;
                }
            }
            
            powCount = max(devideCount, powCount);
        }
        
        answer *= pow(CDs[i], powCount);
    }
    
    return answer;
}