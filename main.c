#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_LEN 1000

char *get_word(char *str, char *word) {
    int i = 0;
    while (isspace(*str))
        str++;
    while (!isspace(*str) && *str != '\0')
        word[i++] = *str++;
    word[i] = '\0';
    return str;
}

void to_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() {
    const char *punctuation_marks = " .,!?;:-<>[]{}()";
    char dictionary[MAX_LEN][MAX_LEN];
    char result[MAX_LEN] = "";

    char text[MAX_LEN];
    fgets(text, MAX_LEN, stdin);

    char *main = text;
    char word1[MAX_LEN];
    char word1_clean[MAX_LEN];

    while (*main) {
        int flag_is_next = 0;
        int flag_is_in_dictionary = 0;
        main = get_word(main, word1);
        strcpy(word1_clean, word1);
        strcat(word1, " ");
        if (strchr(punctuation_marks, word1_clean[strlen(word1_clean) - 1]))
            word1_clean[strlen(word1_clean) - 1] = '\0';

        if (strlen(word1_clean) > 0) {
            to_lower(word1_clean);
            char *main2 = main;
            char word2[MAX_LEN];
            char word2_clean[MAX_LEN];

            // проверка на будущее совпадение
            while(*main2){
                main2 = get_word(main2, word2);
                strcpy(word2_clean, word2);
                strcat(word2, " ");
                if(strchr(punctuation_marks, word2_clean[strlen(word2_clean) - 1]))
                    word2_clean[strlen(word2_clean) - 1] = '\0';
                if(strlen(word2_clean) > 0) {
                    to_lower(word2_clean);
                    if(strcmp(word1_clean, word2_clean) == 0)
                        flag_is_next = 1;
                }
            }

            // проверка на наличие в словаре
            for(int i = 0; i < MAX_LEN; i++)
                if(strcmp(dictionary[i], word1_clean) == 0)
                    flag_is_in_dictionary = 1;

            if(flag_is_in_dictionary == 0){
                for(int i = 0; i < MAX_LEN; i++)
                    if(strlen(dictionary[i]) == 0) {
                        strcpy(dictionary[i], word1_clean);
                        break;
                    }
            }
        }

        if(flag_is_next == 1 && flag_is_in_dictionary == 0){
            strcat(result, "(");
            strcat(result, word1);
            result[strlen(result) - 1] = '\0';
            strcat(result, ") ");
        }
        if(flag_is_next == 0 && flag_is_in_dictionary == 0)
            strcat(result, word1);
    }


    printf("%s", result);
    return 0;
}

