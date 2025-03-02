
#include "funcss.h"

int main(int argc, char*argv[]) {

    char *filename = "file";
    nameFile(&filename, argc, argv);

    srand(time(0));
    int ans;
    do {
        system("cls");
        fflush(stdin);
        puts("What task you want to test?");
        setNumber(&ans);
        switch(ans) {
            case 1:fillFile(filename); break;
            case 2:fillFile(filename); outputWord(filename); break;
            case 3:fillFile(filename); outputReversedWords(filename); break;
            default: puts("Task number must be from 1 to 3!"); break;
        }
        puts("Do you want to try again?(y/n)");
        ans = Try_answer();
    }while (ans != 'n' && ans != 'N');
    return 0;
}
