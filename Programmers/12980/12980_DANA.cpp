#include <iostream>
using namespace std;

//(currentDist) * 2 to teleport
int solution(int n)
{
    int ans = 0;

    int value=n;
    while(value!=1){
        if(value%2!=0){
            value-=1;
            ans++;
        }
        value/=2;
    }

    ans++;

    return ans;
}