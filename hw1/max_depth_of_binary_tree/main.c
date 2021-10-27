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

void print_sub_tree(treenode_t *parent) {
   printf("\n===== Print_sub_tree =====\n");
   printf("\tParent[%0d]\n", parent->val);
   printf("\t/\t\\\n");

   if (parent->left != NULL) {
       printf("LeftNode[%0d]", parent->left->val);
   } else printf("\tNULL");
   if (parent->right != NULL) {
       printf("\tRightNode[%0d]", parent->right->val);
   } else printf("\tNULL");

   printf("\n");
}

void add_child_nodes(treenode_t *parent, int tree_list[], unsigned int parent_idx) {
   /* Assume that root may not be NULL
    * The checker will early terminate subtrees after level-2 tree
    */
   //if (tree_list[parent_idx++] == null) {
   //    printf("Parent is null, skip process to add child nodes.\n");
   //    return;
   //}
 
   printf("Parent   [%0d]\n", parent->val);

   // Create child nodes and links to connect parent and the nodes
   if (++parent_idx < NUM_NODE && tree_list[parent_idx] != null) {
       /*
       treenode_t* left_node = malloc(sizeof(treenode_t));
       left_node->val = tree_list[parent_idx++];
       left_node->next = NULL;
       */
       treenode_t *left_node = init_node(tree_list[parent_idx]);
       parent->left = left_node;

       printf("LeftNode [%0d]\n", parent->left->val);

       // Check whether the right node is existed
       if ((parent_idx+1)+1 < NUM_NODE) {
           add_child_nodes(left_node, tree_list, parent_idx+1);
	   printf("\n");
       }
   } else {
       parent->left = NULL; 
       printf("LeftNode [NULL]\n");
   }
   if (++parent_idx < NUM_NODE && tree_list[parent_idx] != null) {
       /*
       treenode_t* right_node = malloc(sizeof(treenode_t));
       right_node->val = tree_list[parent_idx++];
       right_node->next = NULL;
       */
       treenode_t *right_node = init_node(tree_list[parent_idx]);

       parent->right = right_node;

       printf("RightNode[%0d]\n", parent->right->val);

       if ((parent_idx+2)+1 < NUM_NODE) {
           add_child_nodes(right_node, tree_list, parent_idx+2);
	   printf("\n");
       }
   } else {
       parent->right = NULL;
       printf("RightNode[NULL]\n");
   }
}

/** By recursive way
  *
  */

int maxDepth(struct TreeNode* root){
    int unsigned result = 0, maxDepth_left = 0, maxDepth_right = 0;

    if (root == NULL) {
        return 0;
    } else {
	/*
        if (root->left != NULL || root->right != NULL)
            return (1 + maxDepth(root->left) + maxDepth(root->right));
        else
            return 1;
	*/

        if (root->left == NULL && root->right == NULL) // end to traverse
            result = 1;
	else {
	    //result = (1+maxDepth(root->left))>(1+maxDepth(root->right))?(1+maxDepth(root->left)):(1+maxDepth(root->right));
	    maxDepth_left  = maxDepth(root->left);
	    maxDepth_right = maxDepth(root->right);
	    result = 1 + (maxDepth_left>maxDepth_right ? maxDepth_left:maxDepth_right);
	}
	print_sub_tree(root);
        printf("* maxDepth_left=%d maxDepth_right=%d result=%d\n", maxDepth_left, maxDepth_right, result);

        return result;
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

    root = init_node(tree_list[0]);
    add_child_nodes(root, tree_list, 0);
    printf("\nmaxDepth(root)=%d\n", maxDepth(root));
    return 0;
}
