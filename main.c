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
    // massive of words and their number of repetitions
    char dict[MAX_LEN][MAX_LEN][int];


    // input string
    char text[MAX_LEN];
    fgets(text, MAX_LEN, stdin);
    char *str = text;
    char word_clean[MAX_LEN];
    char word[MAX_LEN];
    char result[MAX_LEN] = "";

    // добавление в словарь
    while (*str) {
        str = get_word(str, word);
        //word_clean = word
        strcpy(word_clean, word);
        if (strchr(punctuation_marks, word_clean[strlen(word_clean) - 1])) {
            word_clean[strlen(word_clean) - 1] = '\0';
        }
        if (strlen(word_clean) > 0) {
            to_lower(word_clean);
            // if this word_clean is not in the dictionary add it
            int i = 0;
            while (i < MAX_LEN && strlen(dict[i]) > 0) {
                if (strcmp(dict[i], word_clean) == 0) {
                    break;
                }
                i++;
            }
            if (i == MAX_LEN || strlen(dict[i]) == 0) {
                strcpy(dict[i], word_clean);
                // word = word + " "
                strcat(word, " ");
                strcat(result, word);
            }
            else {

            }
        }
    }



    printf("%s", result);

    return 0;
}

