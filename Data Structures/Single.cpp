#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char name[255];
    int age;
    Node *next;
} *head, *tail, *curr;

Node *create_node(char *name, int age) {
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->next = NULL;
    return temp;
}

void push_head(char *name, int age) {
    Node *temp = create_node(name, age);
    if(!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void push_tail(char *name, int age) {
    Node *temp = create_node(name, age);
    if(!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void push_mid(char *name, int age) {
    Node *temp = create_node(name, age);
    if(!head) head = tail = temp;
    else {
        curr = head;
        while(curr->next && strcmp(curr->next->name, name) <= 0) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;

        if(curr == tail) {
            tail = temp;
        }
    }
}

void pop_head() {
    if(!head) return;
    else if(head && head == tail) {
        head = tail = NULL;
        free(head);
    }
    else {
        Node *new_head = head->next;
        head->next = NULL;
        head = new_head;
    }
}

void pop_tail() {
    if(!tail) return;
    else {
        curr = head;
        Node *temp;
        while(curr->next) {
            if(curr->next == tail) {
                temp = curr;
                break;
            }
            curr = curr->next;
        }
        temp->next = NULL;
        tail = temp;
        free(temp->next);
    }
}

void pop_mid(char *name) {
    if(head) {
        curr = head;
        while (curr->next && strcmp(curr->next->name, name) != 0) {
            curr = curr->next;
        }
        if(curr->next != NULL) {
            Node *temp = curr->next;
            curr->next = temp->next;
            free(temp);

        }
        else {
            puts("Not Found!");
            return;
        }
    }
}

void pop_all() {
    if(!tail) return;
    while(tail) {
        pop_head();
    }
}

void view() {
    curr = head;
    while(curr) {
        printf("[%s | %d] -> ", curr->name, curr->age);
        curr = curr->next;
    }
    puts("NULL");
    printf("Head = [%s | %d]\n", head->name, head->age);
    printf("tail = [%s | %d]\n", tail->name, tail->age);
}

int main() {
    system("cls");
    push_mid("Andre", 20);
    push_mid("Budi", 21);
    push_mid("Alexander", 12);
    view();
    // pop_mid("Alexander");
    // pop_tail();
    pop_all();
    view();
}