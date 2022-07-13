#include <string>
#include <vector>
#include<algorithm>
using namespace std;

//string 적은 순서대로 1부터 정렬
bool comp(string s1, string s2){
    return s1 < s2;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    //빠른 계산을 위한 정렬
    sort(phone_book.begin(),phone_book.end(),comp);

    for(int i=0;i<size-1;i++){
        //비교할 대상의 길이
        int lenI = phone_book[i].length();
        //길이만큼 phone_book[i+1]에서 떼어냄
        string tmp = phone_book[i+1].substr(0,lenI);
        //비교후 둘이 같으면 false 출력
        if(phone_book[i].compare(tmp)==0)
            return answer=false;

    }
    //그렇지 않으면 true 출력
    return answer;
}