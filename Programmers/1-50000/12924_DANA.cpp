#include <string>
#include <vector>

using namespace std;

int solution(int n) {
     int answer = 0;
    int divider = 1;
    while (divider <= n)
    {
        //a~a+k-1등차수열의 합 공식 : k(2a+k-1)/2 = n
        //a=n/k-(1-k)/2
        //a는 자연수여야하기 때문에 n/k 또한 나누어 떨어져야함 -> k는 n의 약수
        //(1-k)/2 또한 자연수여야하기 때문에 나누어 떨어져야함 -> 1-k 는 2로 나누어 떨어져야함 -> k는 홀수
        if (0 == n % divider) // 홀수 약수를 구하는 조건
        {
            answer++;
        }
        divider += 2;
    }

    return answer;
}