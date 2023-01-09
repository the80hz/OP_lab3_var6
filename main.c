#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

#define MAXLINE 1000

void replace(char* orig, char* old_fragment, char* new_fragment) {
    char result[MAXLINE] = "";
    char text[MAXLINE] = "";

    old_fragment[strlen(old_fragment) - 1] = '\0';
    new_fragment[strlen(new_fragment) - 1] = '\0';

    while (*orig) {
        if (strncmp(orig, old_fragment, strlen(old_fragment)) == 0) {
            strcat_s(result, "(");
            strcat_s(result, new_fragment);
            strcat_s(result, ")");

            strcat_s(text, "(");
            strcat_s(text, old_fragment);
            strcat_s(text, ")");

            orig += strlen(old_fragment);
        }
        else {
            strncat_s(result, orig, 1);
            strncat_s(text, orig, 1);
            orig++;
        }
    }

    strcpy_s(new_fragment, MAXLINE, result);
    strcpy_s(old_fragment, MAXLINE, text);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    printf("Enter the original string: \n");
    char text[MAXLINE];
    fgets(text, MAXLINE, stdin);
    printf("Enter the fragment to be replaced: \n");
    char old[MAXLINE];
    fgets(old, MAXLINE, stdin);
    printf("Enter the new fragment: \n");
    char new_str[MAXLINE];
    fgets(new_str, MAXLINE, stdin);

    replace(text, old, new_str);

    printf("Original string: %s", old);
    printf("Replaced string: %s", new_str);

    return 0;
}
