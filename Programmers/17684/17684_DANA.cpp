#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string,int> dictionary;
    
    for(int i=1;i<=26;i++){
        char ch = (char)(i+64);
        string val = string(1,ch);
        dictionary.insert({val,i});
    }
    
    int idx=0;
    while(idx<msg.length())
    {
        string val = msg.substr(idx,1);
        if (dictionary.find(val) != dictionary.end()) {
	        //cout << "find" << endl;
            int addition=0;
            int value=0;
            val = msg.substr(idx,1+addition);
            while(idx+addition<msg.length()){
                if (dictionary.find(val) == dictionary.end()){
                    dictionary.insert({val,dictionary.size()+1});
                    break;
                }
                else{
                    value =dictionary[val];
                }
                addition++;
                val = msg.substr(idx,1+addition);
            }
            answer.push_back(value);
            idx+=addition-1;  
        }
        else {
            dictionary.insert({val,dictionary.size()});
        }
        idx++;
    }
    
    return answer;
}