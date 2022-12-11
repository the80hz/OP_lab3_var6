/* The text is given. Convert it as follows:
 * Remove all repetitions of the word except the first, for all words that occur more than once in this text.
 * The first word should be marked with brackets
 */

// Смелый человек совершает смелые поступки. Но смелые поступки не всегда делают его героем.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX_LEN 1000

// Function to get the next word with next symbol from the string
char *get_word(char *str, char *word) {
    int i = 0;
    while (isspace(*str)) {
        str++;
    }
    while (!isspace(*str) && *str != '\0') {
        word[i++] = *str++;
    }
    //word[i] = ' ';
    word[i] = '\0';
    return str;
}

// Function that converts all letters to lowercase
void to_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}


int main() {
    // dictionary of punctuation marks
    const char *punctuation_marks = " .,!?;:-<>[]{}()";
    char dictionary[MAX_LEN];

    // input string
    char text[MAX_LEN];
    fgets(text, MAX_LEN, stdin);

    char *main = text;
    char word1[MAX_LEN];
    char word1_clean[MAX_LEN];

    char prev_sentence[MAX_LEN];

    char result[MAX_LEN] = "";

    while (*main) {
        int flag_is_next = 0;
        main = get_word(main, word1);
        strcpy(word1_clean, word1);
        if (strchr(punctuation_marks, word1_clean[strlen(word1_clean) - 1])) {
            word1_clean[strlen(word1_clean) - 1] = '\0';
        }
        if (strlen(word1_clean) > 0) {
            to_lower(word1_clean);


            // проверка на будущее совпадение
            char *main2 = main;
            char word2[MAX_LEN];
            char word2_clean[MAX_LEN];
            while(*main2){
                main2 = get_word(main2, word2);
                strcpy(word2_clean, word2);
                if(strchr(punctuation_marks, word2_clean[strlen(word2_clean) - 1]))
                    word2_clean[strlen(word2_clean) - 1] = '\0';
                if(strlen(word2_clean) > 0) {
                    to_lower(word2_clean);
                    if(strcmp(word1_clean, word2_clean) == 0)
                        flag_is_next = 1;
                }
            }

        }
        if(flag_is_next == 1){
            strcat(result, "(");
            strcat(result, word1);
            strcat(result, ")");
        }
        if(flag_is_next == 0){
            strcat(result, word1);
        }
    }


    printf("%s", result);
    return 0;
}

