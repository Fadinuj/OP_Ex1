#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 512

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "%s FirstName [LastName] PhoneNumber\n", argv[0]);
        return 1;
    }

    char name[MAX_NAME_LENGTH];

    if (argc == 3) {
        // First name only
        snprintf(name, sizeof(name), "%s", argv[1]);
    } else if (argc == 4) {
        // First name + last name
        snprintf(name, sizeof(name), "%s %s", argv[1], argv[2]);
    }

    // The phone number is always the last argument
    char *phone;
    if (argc == 3) {
        phone = argv[2];
    } else { // argc == 4
        phone = argv[3];
    }

    // Open phonebook.txt in append mode
    FILE *fp = fopen("phonebook.txt", "a");
    if (fp == NULL) {
        perror("Failed to open phonebook.txt");
        return 1;
    }

    // Write entry: Name,Phone
    fprintf(fp, "%s,%s\n", name, phone);

    printf("Entry added successfully to phonebook.txt!\n");

    fclose(fp);
    return 0;
}
