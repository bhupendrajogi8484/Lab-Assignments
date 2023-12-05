#include<iostream>
#include<conio.h>
#include<process.h>

struct tree_node {
    tree_node* left;
    tree_node* right;
    int data;
};

class bst {
private:
    tree_node* root;

public:
    bst() {
        root = NULL;
    }

    int isempty() {
        return (root == NULL);
    }

    void insert(int item);
    void inordertrav();
    void inorder(tree_node*);
    void postordertrav();
    void postorder(tree_node*);
    void preordertrav();
    void preorder(tree_node*);
};

void bst::insert(int item) {
    tree_node* p = new tree_node;
    tree_node* parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;

    if (isempty())
        root = p;
    else {
        tree_node* ptr = root;
        while (ptr != NULL) {
            parent = ptr;
            if (item > ptr->data)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }

        if (item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }
}

void bst::inordertrav() {
    inorder(root);
}

void bst::inorder(tree_node* ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        std::cout << " " << ptr->data << " ";
        inorder(ptr->right);
    }
}

void bst::postordertrav() {
    postorder(root);
}

void bst::postorder(tree_node* ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        std::cout << " " << ptr->data << " ";
    }
}

void bst::preordertrav() {
    preorder(root);
}

void bst::preorder(tree_node* ptr) {
    if (ptr != NULL) {
        std::cout << " " << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main() {
    bst b;
    b.insert(52);
    b.insert(25);
    b.insert(50);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(20);

    std::cout << "Inorder" << std::endl;
    b.inordertrav();
    std::cout << std::endl << "Postorder" << std::endl;
    b.postordertrav();
    std::cout << std::endl << "Preorder" << std::endl;
    b.preordertrav();

    getch();
    return 0;
}
