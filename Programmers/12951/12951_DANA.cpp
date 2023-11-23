#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char ch[201];
    strcpy(ch, s.c_str());
    
    char* ptr;    
    ptr = strtok(ch," ");
    
    int size;
    
    while(ptr!=NULL){
        for(int i=1;i<(int)strlen(ptr);i++)
        {
            if(ptr[i]>='A'&&ptr[i]<='Z')
                ptr[i]+=32;
        }
        if(ptr[0]>='a'&&ptr[0]<='z') 
            ptr[0]-=32;
        
        answer+=ptr; 
        
        ptr = strtok(NULL," ");
        
    }
    
    for(int i=0;i<s.length();i++){
        if(isspace(s[i])!=0){
            answer=answer.insert(i," ");
        }
    }
    
    return answer;
}