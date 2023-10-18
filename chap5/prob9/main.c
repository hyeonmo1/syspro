#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 100

int main() {
    char savedText[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;

    
    FILE *file = fopen("test.txt", "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    
    while (lineCount < MAX_LINES && fscanf(file, "%99[^\n]%*c", savedText[lineCount]) != EOF) {
        lineCount++;
    }

    
    for (int i = lineCount - 1; i >= 0; i--) {
        printf("%s\n", savedText[i]);
    }

   
    fclose(file);

    return 0;
}
