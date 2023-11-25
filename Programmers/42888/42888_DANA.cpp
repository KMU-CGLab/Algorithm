#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> nicknameTable;
    vector<string> id;
    vector<string> action;
    
    for(int i=0;i<record.size();i++){
        
        stringstream ss(record[i]);
        ss.str(record[i]);

        string word;
        if(ss >> word) {action.push_back(word);}    //첫번째 명령(Enter,Leave,Change)
        if(ss>>word){id.push_back(word);}           //id 입력
        if(ss>>word){nicknameTable[id.back()]=word;}    //최근에 삽입된 id를 가지고 value값을 변경, id가 중복되더라도 탐색은 Map에서 하는 것임으로 상관 x
    }
    
    string strCommand;
    for(int i=0;i<action.size();i++){
        strCommand=nicknameTable[id[i]];        //처음 명령으로 들어왔던 id를 기준으로 바뀐 닉네임을 불러옴
        if(action[i]=="Enter") 
            strCommand+="님이 들어왔습니다.";
        else if(action[i]=="Leave") 
            strCommand+="님이 나갔습니다.";
        else continue;                              //Change의 경우 건너띔 
        answer.push_back(strCommand);
    }
    
    return answer;
}