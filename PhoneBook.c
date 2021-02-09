#include <stdio.h>
#include <process.h>
#include <string.h>

struct contacts
{
    char name[24], email[40], address[60], phone[15];
};

struct contacts list[100];
char searchIndex[40];
int systemCallback = 0;
int a, b, noOfContacts = 0;

void fileSave()
{
    FILE *filePointer;
    filePointer = fopen("contacts.dll", "w");
    if (filePointer == NULL)
    {
        printf("\n[ERROR] An error has occured.");
    }

    fprintf(filePointer, "Total Data: %d\n", noOfContacts);
    for (int i = 0; i < noOfContacts; i++)
    {
        fwrite(&list[i], sizeof(list[i]), 1, filePointer);
    }

    printf("\n\nAll Data Exported!\n");
    fclose(filePointer);
}

void fileRead()
{
    FILE *filePointer;
    filePointer = fopen("contacts.dll", "r");
    if (filePointer == NULL)
    {
        printf("\n[ERROR] An error has occured.");
    }

    fscanf(filePointer, "Total Data: %d\n", &noOfContacts);
    for (int i = 0; i < noOfContacts; i++)
    {
        fread(&list[i], sizeof(list[i]), 1, filePointer);
    }

    printf("\n\nAll Data Exported!\n");
    fclose(filePointer);
}

void icsExport()
{
    FILE *filePointer;
    filePointer = fopen("contacts.ics", "w");
    if (filePointer == NULL)
    {
        printf("\n[ERROR] An error has occured.");
    }

    for (int i = 0; i < noOfContacts; i++)
    {
        fprintf(filePointer, "BEGIN:VCARD\nVERSION:2.1\nX-STARRED:1\nN:;%s;;;\nFN:%s\nTEL;CELL:%s\nEMAIL;HOME:%s\nADR;HOME:%sEND:VCARD\n", list[i].name, list[i].name, list[i].phone, list[i].email, list[i].address);
    }

    printf("\n\nAll Data Exported!\n");
    fclose(filePointer);
}

void decorator()
{
    printf("   ______ _   _ _____ _   _  ___________  _____  _____ _   __\n   | ___ \\ | | |  _  | \\ | ||  ___| ___ \\|  _  ||  _  | | / /\n   | |_/ / |_| | | | |  \\| || |__ | |_/ /| | | || | | | |/ / \n   |  __/|  _  | | | | . ` ||  __|| ___ \\| | | || | | |    \\ \n   | |   | | | \\ \\_/ / |\\  || |___| |_/ /\\ \\_/ /\\ \\_/ / |\\  \\\n   \\_|   \\_| |_/\\___/\\_| \\_/\\____/\\____/  \\___/  \\___/\\_| \\_/\n                                                             \n");
}

void initContenter()
{
    printf("+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| No. |          Name          |   Phone Number   |                       Email                        |                             Address                          |\n");
    printf("+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
}
void DisplaySelect(int crossOver)
{
    printf("| %3d | %22s | %16s | %50s | %60s |\n", crossOver + 1, list[crossOver].name, list[crossOver].phone, list[crossOver].email, list[crossOver].address);
}

void concluder()
{
    printf("+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
}

int main()
{
input_part:
    fileRead();
    system("cls");
    decorator();
    initContenter();
    for (int i = 0; i < noOfContacts; i++)
    {
        DisplaySelect(i);
    }
    if (noOfContacts == 0)
    {
        printf("|                                                                 NO CONTACTS FOUND                                                               |\n");
        printf("|                                                                   Try adding one                                                                |\n");
    }
   concluder();
    printf("\n\t\t\t\t\t\t\t======================================\n\t\t\t\t\t\t\t\t\tMain Menu\n\t\t\t\t\t\t\t======================================\n\t\t\t\t\t\t\t\t[1] Add a contact\n\t\t\t\t\t\t\t\t[2] Edit a contact\n\t\t\t\t\t\t\t\t[3] Search a contact\n\t\t\t\t\t\t\t\t[4] Export as ics\n\t\t\t\t\t\t\t\t[5] Format Storage\n\t\t\t\t\t\t\t\t[6] Exit");
    printf("\n\t\t\t\t\t\t\tEnter an input: ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        do
        {
            system("cls");
            decorator();
            printf("\n[ADD CONTACT]\n");
            printf("Enter Name: ");
            fflush(stdin);
            gets(list[noOfContacts].name);
            fflush(stdin);
            printf("Enter Phone Number: ");
            gets(list[noOfContacts].phone);
            printf("Enter Email: ");
            fflush(stdin);
            gets(list[noOfContacts].email);
            printf("Enter Address: ");
            fflush(stdin);
            gets(list[noOfContacts].address);
            initContenter();
            DisplaySelect(noOfContacts);
            concluder();
            noOfContacts = noOfContacts + 1;
            printf("Add new contact? Press 1 to add or any other number to exit: ");
            scanf("%d", &a);
        } while (a == 1);
        fileSave();
        goto input_part;
        break;
    case 2:
        printf("Enter the contact ID: ");
        scanf("%d", &a);
        system("cls");
        decorator();
        printf("\n[EDIT CONTACT]\n");
        initContenter();
        DisplaySelect(a - 1);
        concluder();
        printf("Press \n\t[1] Edit Phone Number\n\t[2] Edit Name\n\t[3] Edit Address\n\t[4] Edit Email\nInput: ");
        scanf("%d", &b);
        decorator();
        system("cls");
        switch (b)
        {
        case 1:
            system("cls");
            printf("EDIT CONTACT'S PHONE NUMBER\n\tOld Phone Number: %s\n\tNew Phone Number: ", list[a - 1].phone);
            fflush(stdin);
            gets(list[a - 1].phone);
            printf("Contact Modified Successfully. Press any key to continue");
            scanf("%d", &a);
            break;
        case 2:
            system("cls");
            printf("EDIT CONTACT'S NAME\n\tOld Name: %s\n\tNew Name: ", list[a - 1].name);
            fflush(stdin);
            gets(list[a - 1].name);
            printf("Contact Modified Successfully. Press any key to continue");
            scanf("%d", &a);
            break;
        case 3:
            system("cls");
            printf("EDIT CONTACT'S Address\n\tOld Address: %s\n\tNew Address: ", list[a - 1].address);
            fflush(stdin);
            gets(list[a - 1].address);
            printf("Contact Modified Successfully. Press any key to continue");
            scanf("%d", &a);
            break;
        case 4:
            system("cls");
            printf("EDIT CONTACT'S Email\n\tOld Email: %s\n\tNew Email: ", list[a - 1].email);
            fflush(stdin);
            gets(list[a - 1].email);
            printf("Contact Modified Successfully. Press any key to continue");
            scanf("%d", &a);
            break;
        default:
            printf("Invalid Selection... Terminating Process");
            break;
        fileSave();
        gets(searchIndex);
        goto input_part;
        break;
        }
    case 3:
        system("cls");
        decorator();
        printf("\n[SEARCH CONTACT]\n");
        printf("Search for a\n\t[1] Phone Number\n\t[2] Name\n\t[3] Address\n\t[4] Email");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter Phone Number to be searched");
            fflush(stdin);
            gets(searchIndex);
            initContenter();
            for (int i = 0; i < noOfContacts; i++)
            {
                if (strcmp(searchIndex, list[i].phone) == 0)
                {
                    DisplaySelect(i);
                    systemCallback = 1;
                }
            }
            if (systemCallback == 0)
            {
                printf("|                                                                 NO MATCHED FOUND                                                                |\n");
            }
            concluder();
            break;
        case 2:
            printf("Enter Name to be searched");
            fflush(stdin);
            gets(searchIndex);
            initContenter();
            for (int i = 0; i < noOfContacts; i++)
            {
                if (strcmp(searchIndex, list[i].name) == 0)
                {
                    DisplaySelect(i);
                    systemCallback = 1;
                }
            }
            if (systemCallback == 0)
            {
                printf("|                                                                 NO MATCHED FOUND                                                                |\n");
            }
            concluder();
            break;
        case 3:
            printf("Enter Address to be searched");
            fflush(stdin);
            gets(searchIndex);
            initContenter();
            for (int i = 0; i < noOfContacts; i++)
            {
                if (strcmp(searchIndex, list[i].address) == 0)
                {
                    DisplaySelect(i);
                    systemCallback = 1;
                }
            }
            if (systemCallback == 0)
            {
                printf("|                                                                 NO MATCHED FOUND                                                                |\n");
            }
            concluder();
            break;
        case 4:
            printf("Enter Email to be searched");
            fflush(stdin);
            gets(searchIndex);
            initContenter();
            for (int i = 0; i < noOfContacts; i++)
            {
                if (strcmp(searchIndex, list[i].email) == 0)
                {
                    DisplaySelect(i);
                    systemCallback = 1;
                }
            }
            if (systemCallback == 0)
            {
                printf("|                                                                 NO MATCHED FOUND                                                                |\n");
            }
            concluder();
            systemCallback = 0;
            break;
        default:
            printf("Invalid Selection... Terminating Process");
            break;
        }
        gets(searchIndex);
        goto input_part;
        break;
    case 4:
        decorator();
        icsExport();
        printf("\nPress enter to continue");
        gets(searchIndex);
        break;
    case 5:
        if (remove("contacts.dll") == 0)
            printf("\nDeleted successfully");
        else
            printf("\nUnable to delete the file");
        gets(searchIndex);
        goto input_part;
        break;
    case 6:
        return 0;
    default:
        goto input_part;
        break;
    }
}