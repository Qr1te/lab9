//
// Created by qr1tiooo on 25.02.2025.
//

#include "funcss.h"
char Try_answer() {
    char answer;
    scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin);
        puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}
    char answer;
    scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin);
        puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}
void setNumber(int* number)
{
    int i = 0, hasnegative = 1;
    *number = 0;
    char digits[20];
    scanf("%s", digits);
    if(digits[0] == '-') hasnegative = -1;
    do {

        if (digits[i] < '0' || digits[i] > '9') {
            puts("Invalid input. Try again");
            fflush(stdin); setNumber(number);  break;
        }
        else { *number = *number * 10 + digits[i] - '0'; }
    } while(digits[++i] != 0);
    *number*=hasnegative;

}
void nameFile(char **filename, int n_arg, char *arg[])
{
    char txt[5] = ".txt" ; txt[4] ='\0';
    if (n_arg > 1){
        *filename = (char*)malloc(sizeof(arg[1]));
        *filename = arg[1];

    }

    *filename = strcat(*filename,txt);

}
void fillFile(char *filename){
    FILE *fp =   fopen(filename, "w");
    puts("enter words");
    int s = getchar();
    while(s != '\n' ){
        fprintf(fp, "%c", s);
        s = getchar();
    }
    printf("\n");
    fclose(fp);
    fopen(filename,"r");
    char c;
    while(fscanf(fp,"%c", &c)!= EOF){
        printf("%c",c);
    }
    printf("\n");
    fclose(fp);
}


char* findWord(char *filename, int point) {

    FILE *fp = fopen(filename, "r");
    fseek(fp, point, SEEK_SET);
    char c;
    int size = 1;
    char *word = (char *) malloc( sizeof(char));
    int i = 0;
    while (fscanf(fp, "%c", &c) == 1) {
        if (c == ' ' || c == '\n') {
            break;
        }
        word[i++] = c;
        if (i >= size - 1) {
            size *= 2;
            char *temp = (char *) realloc(word, size);
            word = temp;
        }
    }
    word[i] = '\0';
    fclose(fp);
    return word;
    }
   /*void reverse(char *filename, int pos, int length ){
        FILE *fp = fopen(filename, "r+");

        int end = pos + length - 1;
        char chB, chE;

        while (pos < end) {
            fseek(fp, pos, SEEK_SET);
            fread(&chB, sizeof(char), 1, fp);

            fseek(fp, end, SEEK_SET);
            fread(&chE, sizeof(char), 1, fp);

            fseek(fp, pos, SEEK_SET);
            fwrite(&chE, sizeof(char), 1, fp);

            fseek(fp, end, SEEK_SET);
            fwrite(&chB, sizeof(char), 1, fp);

            pos++;
            end--;
        }

        fclose(fp);
}*/

   void reverse1(char *word, int len){
       for (int j = 0; j < len / 2; j++) {
           char temp = word[j];
           word[j] = word[len - j - 1];
           word[len - j - 1] = temp;
       }
   }

void outputWord(char *filename) {
    printf("Enter the length\n");
    int len;
    setNumber(&len);

    int point = 0;
    char *word = findWord(filename, point);

    while (word != NULL) {
        int wordlen = (int) strlen(word);
        if (wordlen == len) {
            printf("%s\n", word);
        }

        point += wordlen + 1;
        free(word);

        word = findWord(filename, point);
    }
}

void outputReversedWords(char *filename){
    printf("Enter the length\n");
    int len;
    setNumber(&len);

    int point = 0;
    char *word = findWord(filename, point);

    while (word != NULL) {
        int wordlen = (int) strlen(word);
        if (wordlen > len) {
            reverse1(word, wordlen);
            printf("%s\n", word);
        }

        point += wordlen + 1;
        free(word);

        word = findWord(filename, point);
    }
   }




