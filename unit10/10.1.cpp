#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : data(c), left(nullptr), right(nullptr){}
};

TreeNode* Build(string preOrder, string inOrder){
    //先序遍历和中序遍历确定二叉树
    if(preOrder.size() == 0){
        return nullptr;
    }
    char c = preOrder[0];
    TreeNode* root = new TreeNode(c);
    int position = inOrder.find(c);
    //inOrder中 position之前的即为该节点的左子树，右边为右子树
    //左子树的节点数目是固定的，在preOrder中，第一个节点为根节点，然后从第一个节点到position位置，为该节点的左子树
    root->left = Build(preOrder.substr(1, position), inOrder.substr(0, position));
    root->right = Build(preOrder.substr(position + 1), inOrder.substr(position + 1));
    return root;
}

void PostOrder(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c", root->data);
}

int main() {
    string preOrder, inOrder;
    while(cin >> preOrder >> inOrder){
        TreeNode* root = Build(preOrder, inOrder);
        PostOrder(root);
        printf("\n");
    }
    return 0;
}
