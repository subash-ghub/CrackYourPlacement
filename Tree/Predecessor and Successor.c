struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int item) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* node, int key) 
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
void findPreSuc(struct Node* root, struct Node** pre, struct Node** succ, int key) 
{
    if (root == NULL) return;
    if (root->key == key) 
    {
        if (root->left != NULL) 
        {
            struct Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            *pre = tmp;
        }
        if (root->right != NULL) 
        {
            struct Node* tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            *succ = tmp;
        }
        return;
    }
    if (key < root->key) 
    {
        *succ = root;
        findPreSuc(root->left, pre, succ, key);
    }
    else { // go to right subtree
        *pre = root;
        findPreSuc(root->right, pre, succ, key);
    }
}
void inorder(struct Node* root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
