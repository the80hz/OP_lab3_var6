/* The text is given. Convert it as follows:
 * Remove all repetitions of the word except the first, for all words that occur more than once in this text.
 * The first word should be marked with brackets
 */

// Смелый человек совершает смелые поступки. Но смелые поступки не всегда делают его героем.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// Function to get the next word from the string
char *get_word(char *str, char *word) {
    int i = 0;
    while (isspace(*str)) {
        str++;
    }
    while (*str && !isspace(*str)) {
        word[i++] = *str++;
    }
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

    char final[MAX_LEN];

    while (*main) {
        main = get_word(main, word1);
        if (strchr(punctuation_marks, word1[strlen(word1) - 1])) {
            word1[strlen(word1) - 1] = '\0';
        }
        if (strlen(word1) > 0) {
            to_lower(word1);
            //printf("%s!", word1);

            char *main2 = main;
            char word2[MAX_LEN];
            while(*main2){
                main2 = get_word(main2, word2);
                if(strchr(punctuation_marks, word2[strlen(word2) - 1])) {
                    word2[strlen(word2) - 1] = '\0';
                }
                if(strlen(word2) > 0) {
                    to_lower(word2);
                    if(strcmp(word1, word2) == 0) {
                        printf("same");
                    }

                }
            }
            //printf("\n");
        }

    }

    return 0;
}

