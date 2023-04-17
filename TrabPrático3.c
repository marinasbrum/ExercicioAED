#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* right;
    struct tree* left;
};

struct tree* insertTree(struct tree **root, int number){
    struct tree* aux = *root;
    aux = (struct tree*)malloc(sizeof (struct tree));
    
    //MÉTODO 1
    while(aux){
        if(number > (aux->data)){
            root = &aux->left;
        } else {
            root = aux->right;
            aux = *root;
	    }
        aux->data = number;
        aux->left = NULL;
        aux->right = NULL;
        *root = aux;    

    /* MÉTODO 2
        root->left = NULL;
        root->right = NULL;
        root->data = number;
        //root = aux;
    }
    else {
	    if(number > (root->data)){
            root->left = insertTree(&(root->left), number);
        } else {
            root->right = insertTree(&(root->right), number);
	    }
	}*/
    free(aux);
    //return root;
}
}

void leafCounter(struct tree* root, int *leaves, int *numLeaves){
    if(root == NULL){
        return 1;
    }    
    if((root->left == NULL) && (root->right == NULL)){
            //numLeaves++;
            leaves[(*numLeaves)++] = root->data;
            printf("test!!!");
            //return *numLeaves;
    }
    /*/leaves[numLeaves] = */leafCounter(root->left, leaves, numLeaves);

    /*/leaves[numLeaves] = */leafCounter(root->right, leaves, numLeaves);
    
    //return *leaves;
}

bool leafSimilar(struct tree *root1, struct tree *root2){
    int numLeaves1 = 0;
    int numLeaves2 = 0;
    int leaves1[200];
    int leaves2[200];

    leafCounter(root1, leaves1, &numLeaves1);
    leafCounter(root2, leaves2, &numLeaves2);

    if (numLeaves1 != numLeaves2) {
        printf("The number of leaves is not compatible, both the trees are not similar!");
        return false;
    }
    for (int i = 0; i < numLeaves1; i++){
        if (leaves1[i] != leaves2[i]) {
            printf("The leaves of both trees are not similar!");
            return false;
        }
    }
    return true;
}    

int main (){
    struct tree* root1 = (struct tree*)malloc(sizeof(struct tree));
    struct tree* root2 = (struct tree*)malloc(sizeof(struct tree));

    root1 = NULL;
    root2 = NULL;

    insertTree(root1, 1);
    insertTree(root1, 2);
    insertTree(root1, 3);

    insertTree(root2, 1);
    insertTree(root2, 3);
    insertTree(root2, 2);

    leafSimilar(root1, root2);

    free(root1);
    free(root2);
    return 0;
}