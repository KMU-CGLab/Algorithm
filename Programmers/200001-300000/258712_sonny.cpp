// 258712 : 가장 많이 받은 선물

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> KeyMap;
vector<vector<int>> GiftTable;
int FriendNum;

int GetGiftValue(int key)
{
    int SendValue = 0;
    int ReceiveValue = 0;
    
    for(int i = 0; i < FriendNum; ++i)
    {
        SendValue += GiftTable[key][i];
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
            
            if(GiftTable[i][j] > GiftTable[j][i])
                GiftCounter[i]++;
            else if(GiftTable[i][j] == GiftTable[j][i])
            {
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