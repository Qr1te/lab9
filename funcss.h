//
// Created by qr1tiooo on 25.02.2025.
//

#ifndef LAB9_FUNCSS_H
#define LAB9_FUNCSS_H
#endif //LAB9_FUNCSS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char Try_answer();
void setNumber(int* number);
void nameFile(char **filename, int n_arg, char *arg[]);
void fillFile(char *filename);
void scanString(char **string, int *size);
char* findWord(char *filename, int point);
void outputWord(char *filename);
void outputReversedWords(char *filename);
void reverse(char *filename, int pos, int length);
void reverse1(char *word, int len);
