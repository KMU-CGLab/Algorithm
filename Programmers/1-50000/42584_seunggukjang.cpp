#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len�� �迭 prices�� �����Դϴ�.
int* solution(int prices[], size_t prices_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(prices_len * sizeof(int));
    //���� Ȯ���ϴ� �ֽ��� �������� �� ���� ��ġ�� ���� �ֽ��� ��ġ�� ���� ����
    //|2|1|0|3|5|
    
    for (int i = 0; i < prices_len; i++)
    {
        bool isDes = false;
        for (int j = i + 1; j < prices_len; j++)
        {
            if (prices[i] > prices[j])
            {
                answer[i] = j - i;
                isDes = true;
                break;
            }
        }
        if (!isDes)
            answer[i] = prices_len - i - 1;
    }
    return answer;
}