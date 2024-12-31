#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortIndex;

bool cmp(vector<int> lValue,vector<int> rValue){
    if(lValue[sortIndex]==rValue[sortIndex]) return lValue[0]>rValue[0];
    return lValue[sortIndex]<rValue[sortIndex];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sortIndex=col-1;
    
    sort(data.begin(),data.end(),cmp);

    int s2;
    for(int i=row_begin-1;i<row_end;i++){
        s2=0;
        for(int j=0;j<data[i].size();j++){
            s2+=data[i][j]%(i+1);
        }
        answer= answer^s2;
    }
    
    return answer;
}