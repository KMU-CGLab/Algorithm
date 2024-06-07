// 160585 : 혼자서 하는 틱택토 Lv2
// 조건을 잘 맞추기
// 하드코딩이 안좋지만은 않다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool Bingo(const vector<string>& board, char sign)
{

    // 가로, 세로방향으로 확인
    for(int y = 0; y < 3; y++)
    {
        bool HCheck = sign == board[y][0] && sign == board[y][1] && sign == board[y][2] ? true : false;
        bool VCheck = sign == board[0][y] && sign == board[1][y] && sign == board[2][y] ? true : false;
        
        // 둘중 하나라도 빙고
        if(HCheck || VCheck)
        {
            return true;
        }
    }
    
    // 대각선
    if(sign == board[0][0] && sign == board[1][1] && sign == board[2][2])
    {
        return true;
    }
    
    if(sign == board[0][2] && sign == board[1][1] && sign == board[2][0])
    {
        return true;
    }
    
    return false;
}

int solution(vector<string> board) 
{
    int answer = 1;
    
    int countO = 0;
    int countX = 0;

    // 갯수 체크
    for(string row : board)
    {
        for(char c : row)
        {
            switch(c)
            {
                case 'O':
                    countO++;
                    break;
                case 'X':
                    countX++;
                    break;
            }
        }
    }
    
    // O가 2개 이상 더 많다.
    if(countO >= countX + 2)
    {
        return 0;
    }
    
    // X가 O보다 많다.
    if(countX > countO)
    {
        return 0;
    }
    
    // O가 이겼다면 O의 개수는 X보다 한 개 많다.
    if(Bingo(board, 'O'))
    {
        if(countO != countX + 1)
        {
            return 0;
        }
    }
    
    // X가 이겼다면 O의 개수와 X의 개수는 같다.
    if(Bingo(board, 'X'))
    {
        if(countO != countX)
        {
            return 0;
        }
    }
    
    // O와 X는 동시에 이길 수 없다.
    if(Bingo(board, 'O') && Bingo(board, 'X'))
    {
        return 0;
    }
    
    return 1;
}