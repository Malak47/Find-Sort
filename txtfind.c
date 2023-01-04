//
// Created by malak on 1/3/2023.
//
#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define ROW 250

char word[WORD];
char text[ROW][LINE];

/**
 * Line of words: Gets a string input from user till [new_line, end_of_file], maximum characters 255.
 * @param s: String that save the input string.
 * @return: How many characters the user entered.
 */
int getLine(char s[]) {
    int ch;
    int count = 0;
    while (count < LINE - 1 && (ch = getchar()) != EOF && ch != '\n') {
        *(s + count++) = (char) ch;
    }
    *(s + count) = '\0';
    if (ch == '\n') {
        ++count;
    }
    return count;
}

/**
 * Word of characters: Gets a string input from user till [new_line, end_of_file, tab, space], maximum characters 29.
 * @param w: String that save the input string.
 * @return: How man characters the user entered.
 */
int getWord(char w[]) {
    int ch;
    int count = 0;
    while ((ch = getchar()) != '\n' && (ch != EOF) && ch != '\t' && ch != ' ' && count < WORD - 1) {
        *(w + count++) = (char) ch;
    }

    *(w + count) = '\0';

    return count;
}

/**
 * Find if str1 contains str2.
 * @param str1: String to search in.
 * @param str2: String to search for.
 * @return: [0/1]: 1 = if str1 contains str2 ; 0 = if str1 doesn't contains str2.
 */
int substring(char *str1, char *str2) {
    int str2len = (int) strlen(str2);
    int count;

    while (*str1 != '\0') {
        count = 0;
        if (strlen(str1) < strlen(str2)) {  //if str2 length is grater that str1 length, then return 0.
            return 0;
        }
        while (*(str1++) == *(str2++)) {    //Check as long as there is equality between str1[i] and str2[j]

            if (++count == str2len) {   //if we inside the loop and we reached str2 length, then return 1.
                return 1;
            }
        }
        if (count != 0) {
            str1 = str1 - count; //moving the str1 pointer one cell to the right.
        }
        str2 = str2 - (count + 1);  //resetting str2 pointer to str2 start.
    }
    return 0;
}

/**
 * Checks if removing n characters from s can be similar to t.
 * @param s: String to remove from.
 * @param t: String to be reached.
 * @param n: Characters to remove from s.
 * @return
 */
int similar(char *s, char *t, int n) {
    int sLen = (int) strlen(s);
    int tLen = (int) strlen(t);

    if (tLen > sLen || tLen != sLen - n) {
        return 0;
    }
    while (*s != '\0') {
        if (*s == *t) {
            t++;
        } else {
            n--;
        }
        if (n < 0) {
            return 0;
        }
        s++;
    }
    return 1;
}

/**
 * Checks if word is substring in each line.
 */
void printLines() {
    int i = 0;
    while (i < ROW) {
        if (substring(*(text + i), word) == 1) {
            printf("%s\n", *(text + i));
        }
        i++;
    }
}

/**
 * Checks if word is similar in each line.
 */
void printSimilarWords() {
    char currWord[WORD];
    int row = 0;
    int cal;
    int curr;
    while (row < ROW) {
        cal = 0;
        while (cal < strlen(*(text + row))) {
            curr = 0;
            while ((*(*(text + row) + cal) != '\0') && (*(*(text + row) + cal) != ' ')) {
                *(currWord + curr++) = *(*(text + row) + cal++);
            }
            *(currWord + curr) = '\0';
            if (similar(currWord, word, 1) == 1 || similar(currWord, word, 0) == 1) {
                printf("%s\n", currWord);
            }
            cal++;
        }
        row++;
    }
}

int main() {
    // get the search key
    getWord(word);

    // get which function to run [a,b]
    char ch;
    ch = (char) getchar();

    // get text
    int row = 0;
    while (row < ROW) {
        getLine(*(text + row++));
    }
    if (ch == 'a') {
        printLines();
    } else if (ch == 'b') {
        printSimilarWords();
    } else {
        printf("invalid input.");
        return 1;
    }
    return 0;
}



