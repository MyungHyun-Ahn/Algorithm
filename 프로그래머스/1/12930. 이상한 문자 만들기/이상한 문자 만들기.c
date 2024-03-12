#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BIT_MASK 0b00100000

char *solution(const char *s) {

	char *answer = (char *)malloc(strlen(s) + sizeof(char)); // 문자열 공간 할당 + 널 문자
    memcpy(answer, s, strlen(s) + sizeof(char));
    
    int strIdx = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (*(answer + i) == ' ')
        {
            strIdx = 0;
            continue;
        }

        if (strIdx % 2)
            *(answer + i) = *(answer + i) | BIT_MASK;
        else
            *(answer + i) = *(answer + i) & ~BIT_MASK;

       strIdx++;
    }
    
	return answer;
}