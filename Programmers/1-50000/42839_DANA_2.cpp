#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime2(int n) {
    if(n==0||n==1) return false;
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> nums;
    
    sort(numbers.begin(), numbers.end());
    string str;
  
    do {
         for(int i=1;i<=numbers.size();i++){
            str = numbers.substr(0,i);
            nums.push_back(stoi(str));
         }
    } while(next_permutation(numbers.begin(), numbers.end()));

    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    for(int i=0;i<nums.size();i++){
        if(isPrime2(nums[i]))
            answer++; 
    }
    
    return answer;
}