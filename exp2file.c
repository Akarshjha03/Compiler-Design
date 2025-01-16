#include <stdio.h>
#include <ctype.h>

void countDigitsVowelsSymbols(const char *str) {
    int digits = 0, vowels = 0, symbols = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isdigit(ch)) {
            digits++;
        } else if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
        } else {
            symbols++;
        }
    }

    printf("Digits: %d\n", digits);
    printf("Vowels: %d\n", vowels);
    printf("Symbols: %d\n", symbols);
}

int main() {
    char filename[100];
    char str[1000];
    FILE *file;

    // Ask user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read the file content into the string
    fread(str, sizeof(char), sizeof(str) - 1, file);
    str[999] = '\0'; // Ensure null termination

    // Close the file
    fclose(file);

    printf("\nContents of the file:\n%s\n", str);
    
    // Call the function to count digits, vowels, and symbols
    countDigitsVowelsSymbols(str);

    return 0;
}
