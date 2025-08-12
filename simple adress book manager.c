#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define FILE_NAME "contacts.txt"

typedef struct
{
    char name[50];
    char phone[20];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;
void loadContacts()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
        return;

    contact_count = 0;
    while (fscanf(file, "%49[^\n]\n%19[^\n]\n", contacts[contact_count].name,
                  contacts[contact_count].phone) == 2)
    {
        contact_count++;
        if (contact_count >= MAX_CONTACTS)
            break;
    }
    fclose(file);
}
void saveContacts()
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL)
    {
        printf("error in saving the file\n");
        return;
    }
    for (int i = 0; i < contact_count; i++)
    {
        fprintf(file, "%s\n %s \n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
}
void addContact()
{
    if (contact_count == MAX_CONTACTS)
    {
        printf("completed \n");
        return;
    }
    printf("please enter the name of the contact: ");
    getchar();
    fgets(contacts[contact_count].name, 50, stdin);
    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = 0;

    printf(" enter the phone number: ");
    fgets(contacts[contact_count].phone, 20, stdin);
    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = 0;

    contact_count++;
    printf(" contact added successfully\n");
}
void showContacts()
{
    if (contact_count == 0)
    {
        printf(" no contact found \n");
        return;
    }
    printf("contacts \n");
    for (int i = 0; i < contact_count; i++)
    {
        printf("%d. %s  %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}
void searchContact()
{
    if (contact_count == 0)
    {
        printf("no contact found \n");
        return;
    }
    char query[50];
    printf("please enter your contact name for search ");
    getchar();
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < contact_count; i++)
    {
        if (strstr(contacts[i].name, query) != NULL)
        {
            printf("%d. %s %s\n", i + 1, contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    if (!found)
    {
        printf(" no contact found with the name %s \n", query);
    }
}
void deleteContact()
{
    if (contact_count == 0)
    {
        printf(" no contact found to delete \n");
        return;
    }
    int num;
    printf("please enter the number of the contact to be added: ");
    scanf("%d", &num);

    if (num < 1 || num > contact_count)
    {
        printf("incorrect number. \n");
        return;
    }
    for (int i = num - 1; i < contact_count - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    contact_count--;
    printf("the contact is deleted. \n");
}

int main()
{
    loadContacts();
    int choice;

    while (1)
    {
        printf("\n choose: \n 1-add new contact \n 2- view contact\n 3- search for contact \n 4- "
               "Delet contact \n 5- save and exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                showContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContacts();
                printf(" Data saving done, Bye! \n");
                return 0;
            default:
                printf("incorrect choice \n");
        }
    }

    return 0;
}
