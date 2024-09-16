#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Customer {
    int custid;
    char custname[50];
    char custphno[15];
};

struct Customer hashTable[TABLE_SIZE];

int hashFunction(int custid) {
    return custid % TABLE_SIZE;
}

void insertCustomer(int custid, const char *custname, const char *custphno) {
    int index = hashFunction(custid);

    while (hashTable[index].custid != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    hashTable[index].custid = custid;
    strcpy(hashTable[index].custname, custname);
    strcpy(hashTable[index].custphno, custphno);

    printf("Customer with ID %d inserted successfully.\n", custid);
}

void searchCustomer(int custid) {
    int index = hashFunction(custid);
    int originalIndex = index;

    while (hashTable[index].custid != custid && hashTable[index].custid != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            printf("Customer with ID %d not found.\n", custid);
            return;
        }
    } 

    if (hashTable[index].custid == custid) {
        printf("Customer with ID %d found:\n", custid);
        printf("Name: %s\n", hashTable[index].custname);
        printf("Phone Number: %s\n", hashTable[index].custphno);
    } else {
        printf("Customer with ID %d not found.\n", custid);
    }
}

void displayRecords() {
    printf("Customer Records:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].custid != -1) {
            printf("Index %d - ID: %d, Name: %s, Phone Number: %s\n", i, hashTable[i].custid,
                   hashTable[i].custname, hashTable[i].custphno);
        }
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].custid = -1; // Indicates an empty slot
    }

    int choice, custid;
    char custname[50], custphno[15];

    do {
        printf("\nSupermarket Customer Information System:\n");
        printf("1. Insert a new customer\n");
        printf("2. Search for customer information\n");
        printf("3. Display customer records\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &custid);
                printf("Enter customer name: ");
                scanf("%s", custname);
                printf("Enter customer phone number: ");
                scanf("%s", custphno);
                insertCustomer(custid, custname, custphno);
                break;

            case 2:
                printf("Enter customer ID to search: ");
                scanf("%d", &custid);
                searchCustomer(custid);
                break;

            case 3:
                displayRecords();
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
