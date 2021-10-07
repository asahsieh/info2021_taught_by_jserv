#include <stdio.h>
#include <stdlib.h>

define NUM_NODE 7 
define null 101 

/**
 * Definition for a binary tree node.
 */

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} treenode_t;

treenode_t* init_node(int value) {
    TeeNode *new_node = malloc(sizeof(treenode_t));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
}

/**
 * list_cur_idx is increased by 1 on each check of whether node is null
 */

void add_child_nodes(TreeNode *parent, int *tree_list[], list_cur_idx) {
   if (tree_list[list_cur_idx++] == null) {
       printf("Parent is null, skip process to add child nodes.\n");
       return;
   }

   printf("Parent[%0d]\n", *parent->val);

   // Create child nodes and links to connect parent and the nodes
   if (tree_list[list_cur_idx] != null) {
       /*
       TeeNode *left_node = malloc(sizeof(treenode_t));
       left_node->val = tree_list[list_cur_idx++];
       left_node->next = NULL;
       */
       treenode_t *left_node = init_node(tree_list[list_cur_idx++]);

       parent->left = left_node;
       
       if ((list_cur_idx+1)+1 < NUM_NODE) // check whether the right node is existed 
           add_child_nodes(left_node, tree_list, list_cur_idx+1);
   } else {
       parent->left = NULL; 
   }

   if (tree_list[list_cur_idx] != null) {
       /*
       TeeNode *right_node = malloc(sizeof(treenode_t));
       right_node->val = tree_list[list_cur_idx++];
       right_node->next = NULL;
       */
       treenode_t *right_node = init_node(tree_list[list_cur_idx++]);

       parent->right = right_node;

       if ((list_cur_idx+2)+1 <  NUM_NODE)
           add_child_nodes(right_node, tree_list, list_cur_idx+2);
   } else {
       parent->right = NULL;
   }
}

/** By recursive way
  *
  */

int maxDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    } else {
        if (root->left != NULL || root->right != NULL)
            return (1 + maxDepth(root->left) + maxDepth(root->right));
        else
            return 1;
    }
}

int main(int argc, char const *argv[]){
    TreeNode *root = NULL;    
    int *tree_list = calloc(NUM_NODE, sizeof(int));
    tree_list = {3, 9, 20, null, null, 5, 7};

    root = init_node(3); 
    add_child_nodes(root, tree_list, 1);
    maxDepth(root);
}
