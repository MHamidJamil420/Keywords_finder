#include<stdio.h>
#include<stdlib.h>

int SizeFinder(char inputChar[15]) {
    int i = 0;
    while (inputChar[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    FILE *fp;
    char userInput[15];
    int indexFinded = 0;
    int inputCharSize = 0;
    int stringFinded = 0;
    printf("Enter String : ");
    scanf("%s", userInput);
    inputCharSize = SizeFinder(userInput);
//    printf("%d", inputCharSize);
    fp = fopen("keywords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    } else if (fp != NULL) {
        char c;
        while ((c = fgetc(fp)) != EOF) {
//            printf("%c",c);
            if (c == ' ') {
                if(indexFinded == inputCharSize){
                    stringFinded = 1;

                }
                indexFinded = 0;
            } else if (c == userInput[indexFinded]) {
                indexFinded++;
            } else {
                indexFinded = 0;
            }
        }

        fclose(fp);
    }
    if(stringFinded == 1){
        printf("\nString is a keyword");
    }else{
        printf("\nString is not a keyword");
    }
    return 0;
}
