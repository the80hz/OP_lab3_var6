/* The text is given. Convert it as follows:
 * Remove all repetitions of the word except the first occurrence, for all words that occur more than once in this text.
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

int main() {
    char text[MAX_LEN];

    printf("Enter text: ");
    fgets(text, MAX_LEN, stdin);



    return 0;
}
