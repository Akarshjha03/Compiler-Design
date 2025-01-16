#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *keywords[] = {"int", "float", "return", "if", "else", "while", "for", "char", "double", "void"};
char operators[] = "+-*/=%";
char separators[] = ",;(){}[]";
char identifier[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";


int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}


int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}


int isSeparator(char ch) {
    for (int i = 0; i < strlen(separators); i++) {
        if (ch == separators[i])
            return 1;
    }
    return 0;
}

int isIdentifierChar(char ch) {
    for (int i = 0; i < strlen(identifier); i++) {
        if (ch == identifier[i])
            return 1; 
    }
    return 0; 
}

int main() {
    FILE *file;
    char filename[100], line[200];
    int keywordsCount = 0, identifiersCount = 0, separatorsCount = 0, operatorsCount = 0, totalTokens = 0;

    // Ask the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Process the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " \t\n"); // Split the line into tokens
        while (token != NULL) {
            totalTokens++;
            if (isKeyword(token)) {
                keywordsCount++;
                printf("Keyword: %s\n", token);
            } else if (isOperator(token[0])) {
                operatorsCount++;
                printf("Operator: %s\n", token);
            } else if (isSeparator(token[0])) {
                separatorsCount++;
                printf("Separator: %s\n", token);
            } else if (isalpha(token[0]) || token[0] == '_') { // Identifier check
                identifiersCount++;
                printf("Identifier: %s\n", token);
            } else {
                printf("Unknown token: %s\n", token);
            }
            token = strtok(NULL, " \t\n"); // Move to the next token
        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("\nToken Counts:\n");
    printf("Total Tokens: %d\n", totalTokens);
    printf("Keywords: %d\n", keywordsCount);
    printf("Identifiers: %d\n", identifiersCount);
    printf("Operators: %d\n", operatorsCount);
    printf("Separators: %d\n", separatorsCount);

    return 0;
}




