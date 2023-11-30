#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int solution(string numbers) {
    int answer=0;
    
    //next_permutation을 사용
    //순열 계산에서 1자리,2자리 ~ n자리만 사용하는 모든 경우의 수 구하기
    sort(numbers.begin(),numbers.end());
    vector<unsigned int> nums;
    string sub;
    do {
        for (int i = 1; i <=  numbers.size(); i++)
        {
            sub = numbers.substr(0, i);
            nums.push_back(stoi(sub));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    //중복된 숫자 제거하기
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()), nums.end());
    
    //에라토스테네스체 구하기
    unsigned int nn=9999999;
    vector<bool> isPrimeNum(nn+1);
    isPrimeNum[1] = true; // 1은 소수가 아니므로 true
    for(unsigned int i = 2; i <= sqrt(nn); i++){
        if(isPrimeNum[i]) continue; // 이미 true면 계산 제외
        for(unsigned int j = i + i; j <= nn; j += i) // i를 제외한 i의 배수들은 소수가 아니다.
            isPrimeNum[j] = true;
    }

    for(int i=0;i<nums.size();i++){
	    if(!isPrimeNum[nums[i]]&nums[i]>0)      //0인 경우 제외
            answer++;
    }
    
    return answer;
}