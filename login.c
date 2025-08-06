#include <stdio.h>
#include <string.h>

int main() {
    char username[50], password[50];
    char file_user[50], file_pass[50];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s", file_user, file_pass) != EOF) {
        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful. Welcome, %s!\n", username);
    } else {
        printf("Login failed. Invalid credentials.\n");
    }

    return 0;
}
