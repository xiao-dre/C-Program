#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int height;
    Node *left, *right;
};

Node *root = NULL;

Node *create_node(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}

int get_balance_factor(Node *root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

Node *left_rotation(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;

    //update height
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node *right_rotation(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    y->right = x;

    //update height
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node *LL(Node *root) {
    root = right_rotation(root);
    return root;
}

Node *LR(Node *root) {
    root->left = left_rotation(root->left);
    root = right_rotation(root);
    return root;
}

Node *RL(Node *root) {
    root->right = right_rotation(root->right);
    root = left_rotation(root);
    return root;
}

Node *RR(Node *root) {
    root = left_rotation(root);
    return root;
}

Node *push(Node *root, int value) {
    if(root == NULL) {
        return create_node(value);
    }
    	else if(value < root->value) {
		root->left = push(root->left,value);
	}
	else if(value > root->value) {
		root->right = push(root->right,value);
	}
    else {
        return root;
    }

    //Update Height
    root->height = 1 + max(height(root->left), height(root->right));

    //Get Balance Factor
    int BF = get_balance_factor(root);

    if(BF > 1) { //LEFT
        if(value < root->left->value) { // LEFT
            root = LL(root);
        }
        else if(value > root->left->value) {
            root = LR(root);
        }
    }

    if(BF < -1) { //RIGHT
        if(value < root->right->value) {
            root = RL(root);
        }
        else if(value > root->right->value) {
            root = RR(root);
        }
    }

    return root;
}

void pre_order(Node *root) {
    if(!root) return;
    printf("%d -> ", root->value);
    pre_order(root->left);
    pre_order(root->right);
}

Node *update(Node *root, int old_value, int new_value) {
    // root = delete(root, old_value);
    root = push(root, new_value);
    return root;
}

bool search(Node *root, int key) {
    if(!root) return false;
    else if(key < root->value) return search(root->left, key);
    else if(key > root->value) return search(root->right, key);
    else return true;
}

Node *pop(Node *root, int value) {
    if(!root) {
        printf("%d Not Found!\n", value);
        return NULL;
    }
    else if(value < root -> value) {
        root->left = pop(root->left, value);
    }
    else if(value > root -> value) {
        root->right = pop(root->right, value);
    }
    else {
        if(!root->left && !root->right) {
            root = NULL;
            free(root);
        }
        else if(!root->left || !root->right) {
            Node *temp = NULL;
            if(root->left) {
                temp = root->left;
            }
            else if(root->right) {
                temp = root->right;
            }
            *root = *temp;
            free(temp);
        }
        else {
            Node *temp = root->left;
            while(temp->right) {
                temp = temp->right;
            }
            root->value = temp->value;
            root->left = pop(root->left, temp->value);
        }
    }

    if(!root) {
        printf("%d Found !\n", value);
        return root;
    }


    int BF = get_balance_factor(root);

    if(BF > 1) { //LEFT
        if(value < root->left->value) { // LEFT
            root = LL(root);
        }
        else if(value > root->left->value) {
            root = LR(root);
        }
    }

    if(BF < -1) { //RIGHT
        if(value < root->right->value) {
            root = RL(root);
        }
        else if(value > root->right->value) {
            root = RR(root);
        }
    }
    return root;
}

void pop_all() {
    while(root) {
        root = pop(root, root->value);
    }
}

int main() {
    root = push(root, 6);
    root = push(root, 27);
    root = push(root, 19);
    root = push(root, 11);
    root = push(root, 36);
    root = push(root, 14);
    root = push(root, 81);
    root = push(root, 63);
    root = push(root, 1);
    root = push(root, 2);
    root = push(root, 3);
    root = push(root, 4);
    root = push(root, 5);
    root = push(root, 7);
    root = push(root, 8);
    root = push(root, 9);
    root = push(root, 10);
    pre_order(root);
    puts("");
    // delete 14, 75, 36, 19, 11
    root = pop(root, 14);
    pre_order(root);
    puts("");
    root = pop(root, 75);
    pre_order(root);
    puts("");
    root = pop(root, 36);
    pre_order(root);
    puts("");
    root = pop(root, 19);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
    root = pop(root, 11);
    pre_order(root);
    puts("");
}