#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

map<string,string> termTable;

int calculatePastDay(const vector<int> today,const vector<int> date){
    int todayDay=today[0]*12*28+today[1]*28+today[2];
    int pastDay=date[0]*12*28+date[1]*28+date[2];
    return todayDay-pastDay;
}

bool isPastTerms(const int pastDay,const int termMonth){
    bool isPast=false;
    (termMonth*28<=pastDay)?isPast=true:isPast=false;
    return isPast;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //save terms to map
    for(int i=0;i<terms.size();i++){
        string type = terms[i].substr(0,1);
        string month = terms[i].substr(1,terms[i].size()-1);
        termTable.insert({type,month});
    }
    stringstream stream(today);
    
    vector<int> todays;
    string todayStr;
    while(getline(stream,todayStr,'.')){
        todays.push_back(stoi(todayStr));
    }
    
    for(int i=0;i<privacies.size();i++)
    {
        stream=stringstream(privacies[i]);
        
        string word;
        vector<string> content;
        while(getline(stream,word,' ')){
            content.push_back(word);
        }
        
        //date split
        stream=stringstream(content[0]);
        vector<int> date;
        while(getline(stream,word,'.')){
            date.push_back(stoi(word));
        }
        //calculate
        string termsMonth = termTable[content[1]];
        if(isPastTerms(calculatePastDay(todays,date),stoi(termsMonth))){
            answer.push_back(i+1);    
        }
    }
    
    return answer;
}