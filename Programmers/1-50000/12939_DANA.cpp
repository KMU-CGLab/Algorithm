#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    
    vector<int> numbers;
    
    string word;
    while(getline(ss,word,' ')){
        int tmp = stoi(word);
        numbers.push_back(tmp);
    }
    
    sort(numbers.begin(),numbers.end());
    
    answer = to_string(numbers[0])+" "+to_string(numbers[numbers.size()-1]);
    
    
    return answer;
}