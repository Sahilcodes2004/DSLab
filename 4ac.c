#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

// Create a new node
struct Node* getNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->info = data;
    temp->next = NULL;
    return temp;
}

// Display the linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at beginning
void insertBeg(struct Node** head, int info) {
    struct Node* newNode = getNode(info);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertLast(struct Node** head, int info) {
    struct Node* newNode = getNode(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Search node by value
struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->info == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Insert after a given node
void insertAfter(struct Node* head, int afterData, int info) {
    struct Node* temp = search(head, afterData);
    if (temp == NULL) {
        printf("%d not found\n", afterData);
        return;
    }
    struct Node* newNode = getNode(info);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove from beginning
void removeBeg(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Remove from end
void removeLast(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Remove after a given node
void removeAfter(struct Node* head, int afterData) {
    struct Node* temp = search(head, afterData);
    if (temp == NULL || temp->next == NULL) {
        printf("Cannot remove after %d\n", afterData);
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

int main() {
    struct Node* head = NULL;
    int ch, info, afterData;

    do {
        printf("\n1.........Add Beginning"
               "\n2.........Add Last"
               "\n3.........Add After"
               "\n4.........Remove Beginning"
               "\n5.........Remove Last"
               "\n6.........Remove After"
               "\n7.........Search"
               "\n8.........Show"
               "\n9.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter info: ");
                scanf("%d", &info);
                insertBeg(&head, info);
                break;
            case 2:
                printf("Enter info: ");
                scanf("%d", &info);
                insertLast(&head, info);
                break;
            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &afterData);
                printf("Enter info: ");
                scanf("%d", &info);
                insertAfter(head, afterData, info);
                break;
            case 4:
                removeBeg(&head);
                break;
            case 5:
                removeLast(&head);
                break;
            case 6:
                printf("Enter value after which to remove: ");
                scanf("%d", &afterData);
                removeAfter(head, afterData);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &info);
                if (search(head, info) != NULL)
                    printf("%d found in the list.\n", info);
                else
                    printf("%d not found.\n", info);
                break;
            case 8:
                traverse(head);
                break;
            case 9:
                printf("See you later\n");
                break;
            default:
                printf("Not defined yet\n");
        }
    } while (ch != 9);

    printf("This program is created by Sahil Prakash Jackson\n");
    return 0;
}
