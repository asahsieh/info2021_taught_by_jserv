#include <stdio.h>
#include <stdlib.h>

#define NUM_NODE 7  // could be elimiated?
#define null 101

/**
 * Definition for a binary tree node.
 */

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} treenode_t;

treenode_t* init_node(int value) {
    treenode_t *new_node = malloc(sizeof(treenode_t));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_child_nodes(treenode_t *parent, int tree_list[], unsigned int parent_idx) {
   /* Assume that root may not be NULL
    * The checker will early terminate subtrees after level-2 tree
    */
   //if (tree_list[parent_idx++] == null) {
   //    printf("Parent is null, skip process to add child nodes.\n");
   //    return;
   //}
 
   printf("Parent   [%0d]=%0d\n", parent_idx, parent->val);

   // Create child nodes and links to connect parent and the nodes
   if (++parent_idx < NUM_NODE && tree_list[parent_idx] != null) {
       /*
       treenode_t* left_node = malloc(sizeof(treenode_t));
       left_node->val = tree_list[parent_idx++];
       left_node->next = NULL;
       */
       treenode_t *left_node = init_node(tree_list[parent_idx]);
       parent->left = left_node;

       printf("LeftNode [%0d]=%0d\n", parent_idx, parent->left->val);

       // Check whether the right node is existed
       if ((parent_idx+1)+1 < NUM_NODE)
           add_child_nodes(left_node, tree_list, parent_idx+1);
   } else {
       parent->left = NULL; 
       printf("LeftNode [%0d]=NULL\n", parent_idx);
   }

   if (++parent_idx < NUM_NODE && tree_list[parent_idx] != null) {
       /*
       treenode_t* right_node = malloc(sizeof(treenode_t));
       right_node->val = tree_list[parent_idx++];
       right_node->next = NULL;
       */
       treenode_t *right_node = init_node(tree_list[parent_idx]);

       parent->right = right_node;

       printf("RightNode[%0d]=%0d\n", parent_idx, parent->right->val);

       if ((parent_idx+2)+1 < NUM_NODE)
           add_child_nodes(right_node, tree_list, parent_idx+2);
   } else {
       parent->right = NULL;
       printf("RightNode[%0d]=NULL\n", parent_idx-1);
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
    treenode_t *root = NULL;
    /*
     * main.c:91:17: error: expected expression before ‘{’ token
          91 |     tree_list = {3, 9, 20, null, null, 15, 7};
             |                 ^

       int *tree_list = (int*) calloc(NUM_NODE, sizeof(int));
       if (tree_list==NULL) exit(1);
       ...
       free(tree_list);
     */

    // use Pointers to Compound Literals defined in C99, setion 12.1 in `C PROGRAMMING, A Modern Approach, 2ed`
    int tree_list[] = {3, 9, 20, null, null, 15, 7};

    root = init_node(3); 
    add_child_nodes(root, tree_list, 0);
    printf("\nmaxDepth(root)=%d\n", maxDepth(root));;
    return 0;
}
