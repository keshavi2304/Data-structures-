#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Patient Details
struct Patient
{
    int id;
    char name[50];
    int priority; // 1 = Critical, 2 = Urgent, 3 = Moderate, 4 = Routine
    struct Patient* next;
};

struct Patient* head = NULL;

// Helper: Check if a Patient ID is real

int checkIdExists(int id)
{
    struct Patient* temp = head;

    while(temp != NULL)
    {
        if(temp->id == id) return 1; // 1 means True (Found)
        temp = temp->next;
    }
    return 0; // 0 means False (Not Found)
}


// 2. Add Patient (Enqueue)

void addPatient(int id, char name[], int priority)
{
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));

    newNode->id = id;
    strcpy(newNode->name, name);

    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || head->priority > priority)
    {
        newNode->next = head;
        head = newNode;
        printf("Added: %s with Priority %d\n", name, priority);
        return;
    }

    struct Patient* temp = head;

    // THE FIX IS HERE: Make sure it says <= (less than or equal to)
    // It keeps moving forward as long as the next patient has a smaller or equal priority number

    while (temp->next != NULL && temp->next->priority <= priority)
    {
        temp = temp->next;
    }

    // Put patient in their correct sorted spot
    newNode->next = temp->next;
    temp->next = newNode;

    printf(">>> Added: %s with Priority %d\n", name, priority);
}

// 3. Call Next Patient (Dequeue)

void callPatient()
{
    if(head == NULL)
    {
        printf("No patients waiting.\n");
        return;
    }

    struct Patient* temp = head;

    printf("\nDOCTOR IS CALLING: %s (ID: %d) \n", temp->name, temp->id);

    head = head->next;
    free(temp);
}


// 4. Show Waiting Room

void showQueue()
{
    if(head == NULL)
    {
        printf("Waiting room is empty.\n");
        return;
    }

    struct Patient* temp = head;

    printf("\n Waiting Room (Sorted by Priority) \n");

    while(temp != NULL)
    {
        printf("ID: %d | Name: %s | Priority: %d\n", temp->id, temp->name, temp->priority);

        temp=temp->next;
    }

}


// 5. Cancel Patient

void cancelPatient(int id)
{
    struct Patient *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id)
    {
        head = temp->next;
        free(temp);

        printf("Patient ID %d has been canceled.\n", id);
        return;
    }

    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next=temp->next;
    free(temp);

    printf("Patient ID %d has been canceled.\n", id);
}


// 6. Update Patient Priority

void updatePriority(int id, int newPriority)
{
    struct Patient* temp = head;
    char tempName[50];

    // Find the patient to save their name

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            strcpy(tempName, temp->name);
            break;
        }

        temp=temp->next;
    }

    // Remove old spot

    cancelPatient(id);

    // Add back to new spot

    printf("Updating... ");
    addPatient(id, tempName, newPriority);
}


// Main Function with Menu

int main()
{
    int choice, id, priority;
    char name[50];

    while (1)
    {
        printf("\n=== HOSPITAL QUEUE SYSTEM ===\n");
        printf("1. Add New Patient\n");
        printf("2. Call Next Patient\n");
        printf("3. Show Waiting Room\n");
        printf("4. Cancel Patient\n");
        printf("5. Update Patient Priority\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name (no spaces): ");
                scanf("%s", name);
                printf("Enter Priority (1=Critical, 2=Urgent, 3=Moderate, 4=Routine): ");
                scanf("%d", &priority);
                addPatient(id, name, priority);
                break;

            case 2:
                callPatient();
                break;

            case 3:
                showQueue();
                break;

            case 4:
                while(1)
                {
                    if(head == NULL)
                    {
                        printf("Queue is empty.\n");
                        break;
                    }

                    printf("Enter Patient ID to cancel (or 0 to go back): ");
                    scanf("%d", &id);

                    if(id == 0) break; // Go back to menu

                    if(checkIdExists(id) == 1)
                    {
                        cancelPatient(id);
                        break; // Success, break the loop
                    }
                    else
                    {
                        printf("WRONG ID! Patient %d not found. Try again.\n\n", id);
                    }
                }
                break;

            case 5:
                while(1)
                {
                    if(head == NULL)
                    {
                        printf("Queue is empty. No one to update.\n");
                        break;
                    }

                    printf("Enter Patient ID to update (or 0 to go back): ");
                    scanf("%d", &id);

                    if(id == 0) break; // Go back to menu

                    if(checkIdExists(id) == 1)
                    {
                        printf("Enter NEW Priority (1-4): ");
                        scanf("%d", &priority);

                        updatePriority(id, priority);
                        break; // Success, break the loop
                    }
                    else
                    {
                        printf("WRONG ID! Patient %d not found. Try again.\n\n", id);
                    }
                }
                break;

            case 6:
                printf("Exiting system. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
