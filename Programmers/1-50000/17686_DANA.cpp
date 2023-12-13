#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool comp(pair<int,vector<string>> lValue,pair<int,vector<string>> rValue){
    if(lValue.second[0]==rValue.second[0]){
        if(stoi(lValue.second[1])==stoi(rValue.second[1])){
            return lValue.first<rValue.first;
        }
        else{
            return stoi(lValue.second[1])<stoi(rValue.second[1]);
        }
    }
    else{
        return lValue.second[0]<rValue.second[0];
    }
        
}

string transfToLow(string str){
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }
    return str;
}

int getIndexOfNumber(string mid){
    int idx=0;
    for(int i=0;i<mid.length();i++){
        if(mid[i]<='9'&&mid[i]>='0') idx=i;
        else break;
    }
    return idx;
}

string removeZero(string str){
    string temp="";
    for(int i=0;i<str.length();i++){
        if(str[i]!='0') break;
        temp+=str[i];
    }
    return temp;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<pair<int,vector<string>>> splitTable;
    
    for(int i=0;i<files.size();i++){
        vector<string> content;
        for(int j=0;j<files[i].length();j++){
            if(files[i][j]>='0'&&files[i][j]<='9'){
                string front;
                front = files[i].substr(0,j);
                front = transfToLow(front);
                content.push_back(front);
                string context = files[i].substr(j,files[i].length()-j);
               
                int index=0;
                index=getIndexOfNumber(context);
                //cout<<"index:"<<index<<endl;
                string number,tail;
                number = context.substr(0,index+1);
                //number = removeZero(number);
                tail = context.substr(index+1,context.length()-index);
                front = transfToLow(tail);
                content.push_back(number);
                content.push_back(tail);
                //cout<<"front:"<<context<<" number:"<<number<<" tail:"<<tail<<endl;
            }
        }
        //cout<<content[0]<<" "<<content[1]<<endl;
        splitTable.push_back(make_pair(i,content));
    }
    //cout<<"----------------------------------"<<endl;
    //sort
    sort(splitTable.begin(),splitTable.end(),comp);
    
    for(int i=0;i<files.size();i++){
        answer.push_back(files[splitTable[i].first]);
    }
    
    return answer;
}