#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(nullptr), right(nullptr){}
};

void PreOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void InOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
    return;
}

void PostOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
    return;
}

TreeNode* Insert(TreeNode* root, int x){
    if(root == nullptr){
        root = new TreeNode(x);
    } else if(x < root->data){
        root->left = Insert(root->left, x);
    }  else if(x > root->data){
        root->right = Insert(root->right, x);
    }
    return root;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        TreeNode* root = nullptr;
        while (n--){
            int x;
            scanf("%d", &x);
            root = Insert(root, x);
        }
        PreOrder(root);
        printf("\n");
        InOrder(root);
        printf("\n");
        PostOrder(root);
        printf("\n");

    }
    return 0;
}

