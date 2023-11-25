#include <iostream>
#include <ctype.h>
#define size 20

using namespace std;

class btree
{
public:
    char data;
    btree *left;
    btree *right;
};

class EXP_TREE
{
    btree *stack[size];
    int top;

public:
    btree *root;
    EXP_TREE();
    void create(char exp[]);
    void push(btree *);
    void push1(btree *item, int *top, btree *s[10]);
    void inorder(btree *root);
    void preorder(btree *root);
    void postorder(btree *root);
    void nonrecinorder(btree *root);
    void nonrecpreorder(btree *root);
    void nonrecpostorder(btree *root);
    btree *pop();
    void pop1(int *top, btree *s[10], btree **current);
    int stempty1(int);
};

EXP_TREE::EXP_TREE()
{
    root = NULL;
    top = -1;
}

void EXP_TREE::create(char exp[])
{
    int pos;
    char ch;
    pos = 0;
    ch = exp[pos];

    while (ch != '\0')
    {
        root = new btree;
        root->left = root->right = NULL;
        root->data = ch;

        if (isalpha(ch))
            push(root);
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            root->right = pop();
            root->left = pop();
            push(root);
        }
        else
            cout << "Invalid character in expression";

        pos++;
        ch = exp[pos];
    }

    root = pop();
}

void EXP_TREE ::push(btree *Node)
{
    if (top + 1 >= size)
        cout << "Error: Stack is full";
    top++;
    stack[top] = Node;
}

btree *EXP_TREE ::pop()
{
    btree *Node;
    if (top == -1)
        cout << "Error: Stack is empty";
    Node = stack[top];
    top--;
    return (Node);
}

void EXP_TREE ::inorder(btree *root)
{
    btree *temp;
    temp = root;
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

void EXP_TREE::nonrecinorder(btree *root)
{
    btree *current, *s[10];
    int top1 = -1;
    if (root == NULL)
    {
        cout << "\n Tree is empty";
        return;
    }
    current = root;
    for (;;)
    {
        while (current != NULL)
        {
            push1(current, &top1, s);
            current = current->left;
        }
        if (!stempty1(top1))
        {
            pop1(&top1, s, &current);
            cout << " " << current->data;
            current = current->right;
        }
        else
            return;
    }
}

void EXP_TREE ::preorder(btree *root)
{
    btree *temp;
    temp = root;
    if (temp != NULL)
    {
        cout << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void EXP_TREE ::nonrecpreorder(btree *root)
{
    btree *current, *s[10];
    int top1 = -1;
    if (root == NULL)
    {
        cout << "\n The Tree is empty\n";
        return;
    }
    current = root;
    for (;;)
    {
        while (current != NULL)
        {
            cout << " " << current->data;
            push1(current, &top1, s);
            current = current->left;
        }
        if (!stempty1(top1))
        {
            pop1(&top1, s, &current);
            current = current->right;
        }
        else
            return;
    }
}

void EXP_TREE ::postorder(btree *root)
{
    btree *temp;
    temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << " " << temp->data;
    }
}

void EXP_TREE ::nonrecpostorder(btree *root)
{
    struct stack
    {
        btree *element;
        int check;
    } st[10];
    int top = -1;
    btree *current;
    if (root == NULL)
    {
        cout << "\n The tree is empty";
        return;
    }
    current = root;
    for (;;)
    {
        while (current != NULL)
        {
            top++;
            st[top].element = current;
            st[top].check = 1;
            current = current->left;
        }
        while (st[top].check == 0)
        {
            current = st[top].element;
            top--;
            cout << " " << current->data;
            if (stempty1(top))
                return;
        }
        current = st[top].element;
        current = current->right;
        st[top].check = 0;
    }
}

void EXP_TREE ::push1(btree *item, int *top1, btree *s[])
{
    *top1 = *top1 + 1;
    s[*top1] = item;
}

void EXP_TREE ::pop1(int *top, btree *s[], btree **current)
{
    *current = s[(*top)--];
}

int EXP_TREE ::stempty1(int top1)
{
    if (top1 == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[80];
    EXP_TREE obj;
    cout << "Enter the postfix expression: ";
    cin >> exp;
    obj.create(exp);
    cout << "\n The tree is created.\n";
    cout << "\n The inorder traversal of it: ";
    obj.inorder(obj.root);
    cout << "\n The non recursive inorder traversal of it: ";
    obj.nonrecinorder(obj.root);
    cout << "\n The preorder traversal of it: ";
    obj.preorder(obj.root);
    cout << "\n The non recursive preorder traversal of it: ";
    obj.nonrecpreorder(obj.root);
    cout << "\n The postorder traversal of it: ";
    obj.postorder(obj.root);
    cout << "\n The non recursive postorder traversal of it: ";
    obj.nonrecpostorder(obj.root);
    return 0;
}
