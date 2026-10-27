#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n, data, key;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    printf("Enter the %d elements of the tree:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("The inputted tree is (inorder traversal): ");
    inorderTraversal(root);
    printf("\nEnter the key to be searched: ");
    scanf("%d", &key);
    struct node *result = search(root, key);
    if (result != NULL)
    {
        printf("%d found in the tree\n", key);
    }
    else
    {
        printf("%d not found in the tree\n", key);
    }
    return 0;
}