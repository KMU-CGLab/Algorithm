#include <vector>
#include <iostream>

using namespace std;



vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    //비교할 앞의 숫자
    int contiNum=-1;
    for(int i=0;i<arr.size();i++){
        if(contiNum!=-1){
            if(contiNum!=arr[i])
                answer.push_back(arr[i]);
        }
        else{
            answer.push_back(arr[i]);
        }
        contiNum=arr[i];        //비교할 앞의 숫자
    }
    

    return answer;
}