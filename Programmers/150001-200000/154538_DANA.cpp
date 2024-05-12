#include <string>
#include <vector>

using namespace std;
int MAX = 1000001;
int arr[1000001] = { 0, };

//재귀를 통한 최솟값 찾기
int convert(int x, int y, int n, int count){
    if(arr[x] != 0 && arr[x] <= count)
        return MAX;

    arr[x] = count;
    
    if(x == y)
        return count;

    int plusN = MAX;
    int mul2 = MAX;
    int mul3 = MAX;
    
    if(x + n <= y){
        plusN = convert(x + n, y, n, count + 1);
    }
    if(x * 2 <= y){
        mul2 = convert(x * 2, y, n, count + 1);
    }
    if(x * 3 <= y){
        mul3 = convert(x * 3, y, n, count + 1);
    }
    return min(plusN, min(mul2, mul3));
}

int solution(int x, int y, int n) {
    int answer = convert(x, y, n, 0);
    if(answer == MAX){
        answer = -1;
    }
    return answer;
}