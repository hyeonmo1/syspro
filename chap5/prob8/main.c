#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 100

int main() {
    char savedText[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;
    char buffer;
    int lineNumber;

    FILE *file = fopen("test.txt", "r");

    if (file == NULL) {
        return 1;
    }

    
    while (lineCount < MAX_LINES && fscanf(file, "%99[^\n]%*c", savedText[lineCount]) != EOF) {
        lineCount++;
    }

    
    printf("원하는 라인을 입력하세요 (n, n-m, * 형식): ");
    char input[20];
    scanf("%19s", input);

    
    if (input[0] == '*') {
        
        for (int i = 0; i < lineCount; i++) {
            printf("%s\n", savedText[i]);
        }
    } else if (sscanf(input, "%d", &lineNumber) == 1) {
        
        if (lineNumber >= 1 && lineNumber <= lineCount) {
            printf("%s\n", savedText[lineNumber - 1]);
        } else {
            printf("유효하지 않은 라인 번호입니다.\n");
        }
    } else {
        int start, end;
        if (sscanf(input, "%d-%d", &start, &end) == 2) {
           
            if (start >= 1 && end >= start && end <= lineCount) {
                for (int i = start; i <= end; i++) {
                    printf("%s\n", savedText[i - 1]);
                }
            } else {
                printf("유효하지 않은 범위입니다.\n");
            }
        } else {
            printf("올바른 형식이 아닙니다. (n, n-m, * 형식 사용)\n");
        }
    }

    
    fclose(file);

    return 0;
}
