#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;

void move(int from, int to)
{
    //cout << from << " -> " << to << '\n';
    vector<int> slot;
    slot.push_back(from);
    slot.push_back(to);
    answer.push_back(slot);
}

void hanoi(int n, int from, int by, int to)
{
    //cout<<"n:"<<n<<" from:"<<from<<" to:"<<to<<endl;
    if(n == 0) return;
    hanoi(n - 1, from, to, by);     //맨 위의 고리를 1에서 3을 거쳐서 2로 옮김
    move(from, to);                 //처음 : 맨 위의 고리를 1 -> 3 으로 옮김
    hanoi(n - 1, by, from, to);     //맨 위의 고리를 1로 옮김
}

vector<vector<int>> solution(int n) {
    
    hanoi(n,1,2,3);
    
    return answer;
}