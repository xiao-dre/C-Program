#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct Node {
    int value;
    Node *next, *prev;
} *head[SIZE], *tail[SIZE], *curr;

Node *create_node(int value) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->value = value;
    temp->next = temp->prev = NULL;
    return temp;
}

int hashing(int value) {
    int key = value % SIZE;
    return key;
}

void initiate_variable() {
    int size = SIZE;
    for(int i = 0; i < size; i++) {
        head[i] = tail[i] = NULL;
    }
}

void push(int value) {
    Node *temp = create_node(value);
    int index = hashing(value);
    if(head[index]) {
        tail[index]->next = temp;
        temp->prev = tail[index];
        tail[index] = temp;
    }
    else {
        head[index] = tail[index] = temp;
    }
}

void print() {
    int size = SIZE;
    for(int i = 0; i < size; i++) {
        if(head[i]) {
            printf("[%d]: ", i + 1);
            curr = head[i];
            while(curr) {
                printf("%d -> ", curr->value);
                curr = curr->next;
            }
            printf("NULL");
            puts("");
        }
    }
}

void search(int value) {
    int key = hashing(value);
    if(!head[key]) {
        puts("NOT FOUND!");
    }
    else {
        curr = head[key];
        int position = 1; 
        while(curr) {
            if(curr->value == value) break;
            else {
                curr = curr->next;
                position += 1;
            }
        }
        if(curr == NULL) puts("NOT FOUND");
        else {
            printf("%d found, At table number %d, position %d\n", value, key, position);
        }        
    }
}

void pop(int value) {
        int key = hashing(value);
    if(!head[key]) {
        puts("NOT FOUND! Can't delete");
    }
    else if(head[key] == tail[key] && head[key]->value == value) {
        Node *temp = head[key];
        head[key] = tail[key] = NULL;
        free(temp);
    }
    else if(head[key] == tail[key] && head[key]->value != value) {
        puts("NOT FOUND! Can't delete");
    }
    else {
        if(head[key]->value == value) {
            //pophead
            Node *temp = head[key];
            head[key] = head[key]->next;
            temp->next = head[key]->prev = NULL;
            free(temp);
        }   
        else if(tail[key]->value == value) {
            // poptail
            Node *temp = tail[key];
            tail[key] = tail[key]->prev;
            temp->prev = tail[key]->next = NULL;
            free(temp);
        }   
        else {
            curr = head[key];
            while(curr->next->value != value && curr->next != tail[key]) {
                curr = curr->next;
            }
            if(curr->next == tail[key]) {
                puts("NOT FOUND! Can't delete");
            }
            else {
                Node *temp2 = curr->next;
                curr->next = temp2->next;
                temp2->next->prev = curr;
                temp2->next = temp2->prev = NULL;
                free(temp2);
            }
        } 
    }
}

int main() {
    initiate_variable();
    push(13);
    push(15);
    push(23);
    push(17);
    print();
    search(99);
    search(23);
    pop(99);
    pop(23);
    system("cls");
    print();
    return 0;
}