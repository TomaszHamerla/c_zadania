#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Address book is full.\n");
        return;
    }

    Contact newContact;
    printf("Enter first name: ");
    scanf("%s", newContact.firstName);
    printf("Enter last name: ");
    scanf("%s", newContact.lastName);
    printf("Enter phone number: ");
    scanf("%s", newContact.phoneNumber);

    contacts[numContacts++] = newContact;
    printf("Contact added.\n");
}

void findContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter last name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, searchName) == 0) {
            printf("Contact found:\n");
            printf("First name: %s\n", contacts[i].firstName);
            printf("Last name: %s\n", contacts[i].lastName);
            printf("Phone number: %s\n", contacts[i].phoneNumber);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter last name of contact to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, deleteName) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayContacts() {
    printf("Address book contains the following contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s %s, %s\n", i+1, contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
    }
}

int main() {
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Find contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addContact();
                break;
            case '2':
                findContact();
                break;
            case '3':
                deleteContact();
                break;
            case '4':
                displayContacts();
                break;
            case '5':
                printf("Thank you, goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '5');

    return 0;
}
