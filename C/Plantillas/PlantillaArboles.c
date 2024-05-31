#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
    int value;
    struct Treenode* left;
    struct Treenode* right;

};

struct Treenode *Createnode(int value)
{
    struct Treenode* node = (struct Treenode*)malloc(sizeof(struct Treenode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;

};

struct Treenode *minValueNode(struct Treenode* node)
{
    struct Treenode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Treenode *Deletenode(int value, struct Treenode *root)
{
    struct Treenode *temp = NULL;
    if (root == NULL)
        return root;
    if (value < root->value)
    {
        root->left = Deletenode(value, root->left);
    }
    else if (value > root->value)
    {
        root->right = Deletenode(value, root->right);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {   
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = Deletenode(temp->value, root->right);
    }
    return root;
};

struct Treenode *Insertnode(struct Treenode *root, int value )
{
    if (root == NULL)
        return Createnode(value);
    if (value < root->value)
    {
        Insertnode(root->right,value);
    }
    if (value > root->value)
    {
        Insertnode(root->right,value);
    }
    return root;
};

void InorderTraversal(struct Treenode *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d ", root->value);
        InorderTraversal(root->right);
    }
}

void PreorderTraversal(struct Treenode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

void PostorderTraversal(struct Treenode *root)
{
    if (root != NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d ", root->value);
    }
}

struct Treenode *Search(struct Treenode *root, int value)
{
    if (root == NULL || root->value == value)
        return root;

    if (value < root->value)
        return Search(root->left, value);

    return Search(root->right, value);
}

int GetHeight(struct Treenode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int GetMinValue(struct Treenode *root)
{
    if (root == NULL)
    {
        printf("Error: Arbol vacio\n");
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->value;
}

int GetMaxValue(struct Treenode *root)
{
    if (root == NULL)
    {
        printf("Error: Arbol vacio\n");
        return -1;
    }

    while (root->right != NULL)
        root = root->right;

    return root->value;
}
int main(){

    return 0;
}