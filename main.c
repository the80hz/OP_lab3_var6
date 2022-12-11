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

    // input string
    char text[MAX_LEN];
    fgets(text, MAX_LEN, stdin);

    // get words from text
    char word[MAX_LEN];
    char *str = text;
    char temp[MAX_LEN];

    while (*str) {
        str = get_word(str, word);
        if (strchr(punctuation_marks, word[strlen(word) - 1])) {
            word[strlen(word) - 1] = '\0';
        }
        to_lower(word);
        if (strlen(word) > 0) {
            strcat(temp, word);
            strcat(temp, " ");
        }
    }


    return 0;
}

