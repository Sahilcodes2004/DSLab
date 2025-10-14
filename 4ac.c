#include <stdio.h>
#include <alloc.h>

struct Node
{
    int info;
    Node *next;
};
// *head;

// struct Node *head;

struct Node *getNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    return temp;
}

void traverse(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertBeg(struct Node **head, int info)
{
    Node *newNode = getNode(info);
    newNode->next = head;
    head = newNode;
}
void insertLast(Node *&head, int info)
{
    Node *newNode = new Node(info);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

Node *search(Node *&head, int data)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->info == data)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void insertAfter(Node *&head, int data, int info)
{
    Node *temp = search(head, data);
    if (temp == nullptr)
    {
        cout << data << " not found" << endl;
        return;
    }
    Node *newNode = new Node(info);
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeBeg(Node *&head)
{
}
void removeLast(Node *&head)
{
}
void removeAfter(Node *&head, Node *current)
{
}

int main()
{
    struct Node *head = NULL;

    int ch, info;
    do
    {
        cout << "1.........Add Begining" << endl
             << "2.........Add Last" << endl
             << "3.........Add After" << endl
             << "4.........Remove Begining" << endl
             << "5.........Remove Last" << endl
             << "6.........Remove After" << endl
             << "7.........Search" << endl
             << "8.........Show" << endl
             << "9.........Exit" << endl
             << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter info: ";
            cin >> info;
            insertBeg(&head, info);
            break;
        case 2:
            cout << "Enter info: ";
            cin >> info;
            cout << "unimplementd" << endl;
            break;
        case 3:
            cout << "unimplementd" << endl;
            break;
        case 4:
            cout << "unimplementd" << endl;
            break;
        case 5:
            cout << "unimplementd" << endl;
            break;
        case 6:
            cout << "unimplementd" << endl;
            break;
        case 7:
            cout << "unimplementd" << endl;
            break;
        case 8:
            traverse(head);
            break;
        case 9:
            cout << "See you later" << endl;
            break;
        default:
            cout << "Not defined yet" << endl;
        }
    } while (ch != 9);
    cout<<"This program is created by Sahil Prakash Jackson"<<endl;
}