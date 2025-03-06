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
    FILE *fp = fopen(filename, "w");
    puts("Enter words:");
    char ch = getchar();
    while (ch != '\n') {
        fprintf(fp, "%c", ch);
        ch = getchar();
    }
    fclose(fp);}
void outputFile(char *filename){
    FILE * fp = fopen(filename,"r");
    char c;
    while(fscanf(fp,"%c", &c)!= EOF){
        printf("%c",c);
    }
    printf("\n");
    fclose(fp);}




char* findWord(char *filename, int point) {

    FILE *fp = fopen(filename, "r");
    char* word = NULL, ch = '\0';
    int i = 0;
    FILE *file = fopen(filename, "r");
    fseek(file, point, SEEK_SET);

    while (fread(&ch, sizeof(char), 1, file) != 0 && ch != ' ') {
        word = (char*)realloc(word, (i + 2) * sizeof(char));
        word[i++] = ch;
    }

    if (word != NULL) word[i] = '\0';
    fclose(file);


    fclose(fp);
    return word;
    }
   void reverse(char *filename, int pos, int length ){
       FILE *file = fopen(filename, "r+");
       for (int i = 0; i < length / 2; i++) {
           char chB, chE;
           fseek(file, pos + i, SEEK_SET);
           fscanf(file, "%c", &chB);
           fseek(file, pos + length - i - 1, SEEK_SET);
           fscanf(file, "%c", &chE);
           fseek(file, pos + i, SEEK_SET);
           fprintf(file, "%c", chE);
           fseek(file, pos + length - i - 1, SEEK_SET);
           fprintf(file, "%c", chB);
       }
       fclose(file);
}

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
            reverse(filename, point, wordlen);

        }

        point += wordlen + 1;
        free(word);

        word = findWord(filename, point);
    } outputFile(filename);
   }




