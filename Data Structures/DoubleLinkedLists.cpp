#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int value;
    Node *next, *prev;
} *head, *tail, *curr;

//linked lists
Node *create_node(int value);
void push_head(int value);
void push_tail(int value);
void push_mid(int value);
void pop_head();
void pop_tail();
void pop_mid(int value);
void pop_all();
// utility
void delay();
void print_list();
void menu();
void disclaimer();
void exit();

void delay() {
    for(int i = 0; i < 100000000; i++);
}

Node *create_node(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = temp->prev = NULL;
    return temp;
}

void push_head(int value) {
    Node *temp = create_node(value);
    if(!head) head = tail = temp;
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    menu();
}

void push_tail(int value) {
    Node *temp = create_node(value);
    if(!tail) head = tail = temp;
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    menu();
}

void push_mid(int value) {
  if(!head) {
    Node *temp = create_node(value);
    head = tail = temp;
  }
  else if(value < head->value) push_head(value);
  else if(value > tail->value) push_tail(value);

  else {
    Node *temp = create_node(value);
    Node *curr = head;

    while(curr->value < value) {
      curr = curr->next;
    }
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev->next = temp;
    curr->prev = temp;
  }
  menu();
}

void pop_head() {
    if(!head) return;
    else if(head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        Node *new_head = head->next;
        head->next = new_head->prev = NULL;
        free(head);
        head = new_head;
    }
    menu();
}

void pop_tail() {
    if(!tail) return;
    else if(head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        Node *new_tail = tail->prev;
        tail->prev = new_tail->next = NULL;
        free(tail);
        tail = new_tail;
    }
    menu();
}

void pop_mid(int value) {
    if(!head) return;
    else if(head->value == value) pop_head();
    else if(tail->value == value) pop_tail();
    else {
        curr = head;
        while(curr && curr->value != value) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = curr->next = NULL;
        curr = NULL;
        free(curr);
    }
    menu();
}

void pop_all() {
	if(!head) return;
	if(head) pop_head();
	// if(tail) pop_tail();
	curr = head;
    while(curr) {
        pop_all();
	}
    menu();
}

void print_list() {
    Node *curr = head;
    printf("Linked Lists: ");
    while(curr) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    puts("");
}

void exit() {
    system("cls");
    puts("  _______ _                 _     __     __         "); delay();
    puts(" |__   __| |               | |    \\ \\   / /         "); delay();
    puts("    | |  | |__   __ _ _ __ | | __  \\ \\_/ /__  _   _ "); delay();
    puts("    | |  | '_ \\ / _` | '_ \\| |/ /   \\   / _ \\| | | |"); delay();
    puts("    | |  | | | | (_| | | | |   <     | | (_) | |_| |"); delay();
    puts("    |_|  |_| |_|\\__,_|_| |_|_|\\_\\    |_|\\___/ \\__,_|"); delay();

    puts("Press Enter to Continue..."); getchar();
}

void disclaimer() {
    system("cls");
    puts("Disclaimer: ");
    char str[2005] = "This program is created by: \n  Name: Andreas Alexander\n  NIM: 2401959023\n  Class: LL01\nThis program has several linked lists functions. Please try every features!";
    for(int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
        delay();
    }
    puts("");
    printf("Press Enter to Continue..."); getchar();
}

void menu() {
    system("cls");
    puts(" _     _       _            _     _     _     _  ");
    puts("| |   (_)     | |          | |   | |   (_)   | |  ");
    puts("| |    _ _ __ | | _____  __| |   | |    _ ___| |_ ");
    puts("| |   | | '_ \\| |/ / _ \\/ _` |   | |   | / __| __|");
    puts("| |___| | | | |   <  __/ (_| |   | |___| \\__ \\ |_ ");
    puts("\\_____/_|_| |_|_|\\_\\___|\\__,_|   \\_____/_|___/\\__|");
    puts("");
    print_list(); delay();
    puts("Name : Andreas Alexander"); delay();
    puts("NIM  : 2401959023"); delay();
    puts("Class: LL01"); delay();
    puts("1. Push Head"); delay();
    puts("2. Push Tail"); delay();
    puts("3. Push Mid (for sorted nodes)"); delay();
    puts("4. Pop Head"); delay();
    puts("5. Pop Tail"); delay();
    puts("6. Pop Mid"); delay();
    puts("7. Pop All"); delay();
    puts("8. Exit"); delay();

    int option;
    do {
        printf(">> ");
        scanf("%d", &option); getchar();
    } while(option < 1 || option > 7);
    int value;
    switch(option) {
        case 1:
            printf("Insert Value: ");
            scanf("%d", &value);
            push_head(value);
            break;
        case 2:
            printf("Insert Value: ");
            scanf("%d", &value);
            push_tail(value);
            break;
        case 3:
            printf("Insert Value: ");
            scanf("%d", &value);
            push_mid(value);
            break;
        case 4:
            pop_head();
            break;
        case 5:
            pop_tail();
            break;
        case 6:
            printf("Insert Value: ");
            scanf("%d", &value);
            pop_mid(value);
            break;

        case 7:  
            pop_all();
            break;
        case 8:
            exit();
            return;
            break;
    }
}

int main() {
    disclaimer();
    menu();
}
