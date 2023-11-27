#include <string>
#include <vector>
#include <iostream>

using namespace std;

string zeroRemoveStr;

//10진수 2진수로 만들기
void toBinary(int n)
{
    zeroRemoveStr="";
    if (n / 2 != 0) {
        toBinary(n / 2);
    }
    zeroRemoveStr+=to_string(n%2);
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCount=0,transCount=0;
    string str="";
    zeroRemoveStr = s;
    while(zeroRemoveStr!="1"){  
        str="";
        for(int i=0;i<zeroRemoveStr.length();i++){
            if(zeroRemoveStr.at(i)=='0'){ 
                zeroCount++;
            }
            else str+="1";
        }
        //cout<<str.length()<<endl;
        toBinary(str.length());
        //cout<<zeroRemoveStr<<endl;
        transCount++;
    }
    
    answer.push_back(transCount);
    answer.push_back(zeroCount);
    
    return answer;
}