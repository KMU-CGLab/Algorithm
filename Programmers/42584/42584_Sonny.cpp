#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++)
    {
        int price = prices[i];
        int upper = 0;

        for(int j = i + 1; j < prices.size(); j++)
        {
            int cmp = prices[j];
            upper++;  // 어떤 장이라도 1초는 지나기 때문에 ++ 하고 시작
            
            // 하락장이 열리면 Break
            if(cmp < price)
                break;
        }
        
        answer.push_back(upper);
    }
    
    return answer;
}