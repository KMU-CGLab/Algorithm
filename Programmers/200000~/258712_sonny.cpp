// 258712, 가장 많이 받은 선물
// Level 1임, 근데 카카오라서 개빡침
// 풀고나면 쉽다고 생각되는데, 테이블 만드는게 관건인듯
// 테이블 한번 그려보고, 안그려보고 차이가 큼

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> KeyMap;
vector<vector<int>> GiftTable;
int FriendNum;

// 테이블을 참고해서, 선물 지수 가져오기
int GetGiftValue(int key)
{
    int SendValue = 0;
    int ReceiveValue = 0;
    
    for(int i = 0; i < FriendNum; ++i)
    {
        // 준 횟수
        SendValue += GiftTable[key][i];
        
        // 받은 횟수
        ReceiveValue += GiftTable[i][key];
    }
    
    return SendValue - ReceiveValue;
}

int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    FriendNum = friends.size();
    vector<int> GiftCounter = vector<int>(FriendNum);
    
    int key = 0;
    for(auto f : friends)
    {
        KeyMap.emplace(make_pair(f, key));
        GiftTable.push_back(vector<int>(friends.size()));
        key++;
    }
    
    for(auto G : gifts)
    {
        int Space = G.find(" ");
        string Sender = G.substr(0, Space);
        string Receiver = G.substr(Space + 1, G.length());
        int SenderKey = KeyMap[Sender];
        int ReceiverKey = KeyMap[Receiver];
        
        GiftTable[SenderKey][ReceiverKey]++;
        
        //cout << Sender << " -> " << Receiver << endl;
    }
    
    for(int i = 0; i < FriendNum; i++)
    {
        for(int j = 0; j < FriendNum; j++)
        {
            if(i == j)
                continue;

            // Sender가 Receiver보다 많이 줬으면 하나 받을 권한        
            if(GiftTable[i][j] > GiftTable[j][i])
                GiftCounter[i]++;
            else if(GiftTable[i][j] == GiftTable[j][i])
            {
                // 둘이 주고받은 횟수가 같을 때, 선물 지수를 비교
                if(GetGiftValue(i) > GetGiftValue(j))
                    GiftCounter[i]++;
            }
        }
    }
    
    for(auto value : GiftCounter)
    {
        answer = max(answer, value);
    }
    
    return answer;
}