#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidUsername(const char *username) {
    int len = strlen(username);
    if (len < 5 || len > 15) {
        return 0; // Invalid length
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum(username[i])) {
            return 0; // Invalid character
        }
    }
    return 1; // Valid username
}

int isValidPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int len = strlen(password);

    if (len < 8) {
        return 0; // Invalid length
    }

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char username[50], password[50];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove trailing newline

    if (isValidUsername(username)) {
        printf("Username is valid.\n");
    } else {
        printf("Invalid username. It must be 5-15 characters long and contain only alphanumeric characters.\n");
    }

    if (isValidPassword(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Invalid password. It must be at least 8 characters long and include uppercase, lowercase, digit, and special character.\n");
    }

    return 0;
}
