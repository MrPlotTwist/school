#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define length 80

int main() {
    char sentence[length + 1];
    int wordLengths[length] = {0};
    int currentWordLength = 0;

    fgets(sentence, length + 1, stdin);
    printf(": ");

    if (strlen(sentence) > length - 1) {
        printf("NOT VALID\n");
        return 0;
    }



    for (int i = 0; i < strlen(sentence); i++) {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            currentWordLength++;
        }
            else if (sentence[i] == '?' || sentence[i] == ':') {
                printf("NOT VALID\n");
                return 0;
                break;
            } else if (sentence[i] == ' ' || sentence[i] == '.') {
            if (currentWordLength > 0) {
                wordLengths[currentWordLength]++;
                currentWordLength = 0;
            }

        }
    }

    for (int i = 0; i < length; i++) {
        if (wordLengths[i] > 0) {
            printf("Length %d: %d \n", i, wordLengths[i]);
        }
    }

    return 0;
}
