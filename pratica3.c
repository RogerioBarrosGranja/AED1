struct TreeNode* criarNode(int val){
    struct TreeNode* novoNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(novoNode == NULL){
        return NULL;
    }
     
    
    novoNode->val = val;
    novoNode->left = NULL;
    novoNode->right = NULL;
    return novoNode;

}

void atravessar(struct TreeNode* root, int* nodes, int* index){
     
     if(root == NULL){
        return;
     }

    atravessar(root->left, nodes, index);
    nodes[(*index)++] = root->val;
    atravessar(root->right, nodes, index);


}
struct TreeNode* buildBalencedBST(int* node, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start)/2;
    struct TreeNode* root = criarNode(node[mid]);
    if(root == NULL){
        return NULL;
    }

    root->left = buildBalencedBST(node, start, mid -1);
    root->right = buildBalencedBST(node, mid + 1, end);
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
int node[1000];
int index = 0;

  atravessar(root, node, &index);

  return buildBalencedBST(node, 0, index - 1);

}