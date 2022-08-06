#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    bool answer = true;
    int i = 0;
    while (*s == '(' || *s == ')')
    {
        if (*s == '(')
        {
            i++;
        }
        else if (*s == ')')
        {
            i--;
        }
        if (i < 0)
        {
            return false;
        }
        s++;
    }
    if (i != 0)
        return false;


    return answer;
}