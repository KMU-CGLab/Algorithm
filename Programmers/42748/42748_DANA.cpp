#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> cutArray;       //잘라낸 배열을 담을 vector
    for(int i=0;i<commands.size();i++){
        for(int j=commands[i][0]-1;j<commands[i][1];j++){
            cutArray.push_back(array[j]);
        }
        sort(cutArray.begin(),cutArray.end());
        answer.push_back(cutArray[commands[i][2]-1]);
        cutArray.clear();
    }
    
    return answer;
}