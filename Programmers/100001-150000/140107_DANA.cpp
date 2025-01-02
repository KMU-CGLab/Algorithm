#include <string>
#include <vector>
#include <cmath>

// 점 찍기
using namespace std;


long long solution(int k, int d) {
    long long answer = 0;
    
    for(long long i=0;i<=d;i+=k){
        int y = sqrt(pow(d,2)-pow(i,2));
        answer+=y/(long long)k+1;
    }
    
    return answer;
}