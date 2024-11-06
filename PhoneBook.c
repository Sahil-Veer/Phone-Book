#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRIES 100
#define PHONE_NUMBER_LENGTH 15
#define LOCATION_LENGTH 50

typedef struct {
    char phoneNumber[PHONE_NUMBER_LENGTH];
    char location[LOCATION_LENGTH];
} DirectoryEntry;

void initializeDirectory(DirectoryEntry directory[], int *size) {
    // Sample data for the directory
    strcpy(directory[0].phoneNumber, "9270079658");
    strcpy(directory[0].location, "Pune");
    
    strcpy(directory[1].phoneNumber, "8698727165");
    strcpy(directory[1].location, "Mumbai");
    
    strcpy(directory[2].phoneNumber, "7387973558");
    strcpy(directory[2].location, "Vapi");
    
    *size = 3; // Number of entries initialized
}

bool searchDirectory(DirectoryEntry directory[], int size, const char *phoneNumber, char *location) {
    for (int i = 0; i < size; i++) {
        if (strcmp(directory[i].phoneNumber, phoneNumber) == 0) {
            strcpy(location, directory[i].location);
            return true;
        }
    }
    return false;
}

int main()
{
    DirectoryEntry directory[MAX_ENTRIES];
    int size = 0;
    char inputPhoneNumber[PHONE_NUMBER_LENGTH];
    char location[LOCATION_LENGTH];

    initializeDirectory(directory, &size);

    printf("Enter a phone number to search: ");
    if (scanf("%14s", inputPhoneNumber) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    // Validate phone number length
    if (strlen(inputPhoneNumber) != 10) {
        printf("Error: Phone number must be 10 digits long.\n");
        return 1;
    }

    // Search for the phone number
    if (searchDirectory(directory, size, inputPhoneNumber, location)) {
        printf("Phone number found! Location: %s\n", location);
    } else {
        printf("Phone number not found in the directory.\n");
    }

    return 0;
}
