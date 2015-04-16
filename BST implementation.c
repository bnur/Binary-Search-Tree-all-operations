#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
	int value;
	struct bstnode *left;
	struct bstnode *right;
};

    int flag = 1;


    /* To insert a node in the tree */
    void insert()
    {
        create();
        if (root == NULL) 
            root = temp;
        else    
            search(root);    
    }
     
    /* To create a node */
    void create()
    {
        int data;
        printf("Enter data of node to be inserted : ");
        scanf("%d", &data);
        temp = (struct bstnode *)malloc(1*sizeof(struct bstnode));
        temp->value = data;
        temp->left = temp->right = NULL;
    }
     

    /* Function to search the appropriate position to insert the new node */
    void search(struct bstnode *t)
    {
        if ((temp->value > t->value) && (t->right != NULL))      /* value more than root node value insert at right */
            search(t->right);
        else if ((temp->value > t->value) && (t->right == NULL))
            t->right = temp;
        else if ((temp->value < t->value) && (t->left != NULL))    /* value less than root node value insert at left */
            search(t->left);
        else if ((temp->value < t->value) && (t->left == NULL))
            t->left = temp;
    }     


    /* recursive function to perform inorder traversal of tree */
    void inorder(struct bstnode *t)
    {
        if (root == NULL)
        {
            printf("No elements in a tree to display");
            return;
        }
        if (t->left != NULL)    
            inorder(t->left);
        printf("%d -> ", t->value);
        if (t->right != NULL)    
            inorder(t->right);
    }
     
    
    /* To find the preorder traversal */
    void preorder(struct bstnode *t)
    {
        if (root == NULL)
        {
            printf("No elements in a tree to display");
            return;
        }
        printf("%d -> ", t->value);
        if (t->left != NULL)    
            preorder(t->left);
        if (t->right != NULL)    
            preorder(t->right);
    }

     
    /* To find the postorder traversal */
    void postorder(struct bstnode *t)
    {
        if (root == NULL)
        {
            printf("No elements in a tree to display ");
            return;
        }
        if (t->left != NULL) 
            postorder(t->left);
        if (t->right != NULL) 
            postorder(t->right);
        printf("%d -> ", t->value);
    }


    /* To check for the deleted node */
    void delete()
    {
        int data;
        if (root == NULL)
        {
            printf("No elements in a tree to delete");
            return;
        }
        printf("Enter the data to be deleted : ");
        scanf("%d", &data);
        t1 = root;
        t2 = root;
        search1(root, data);
    }

     
    /* Search for the appropriate position to insert the new node */
    void search1(struct bstnode *t, int data)
    {
        if ((data>t->value))
        {
            t1 = t;
            search1(t->right, data);
        }
        else if ((data < t->value))
        {
            t1 = t;
            search1(t->left, data);
        }
        else if ((data==t->value))
        {
            delete1(t);
        }
    }
     

    /* To delete a node */
    void delete1(struct bstnode *t)
    {
        int k;
        /* To delete leaf node */
        if ((t->left == NULL) && (t->right == NULL))
        {
            if (t1->left == t)
            {
                t1->left = NULL;
            }
            else
            {
                t1->right = NULL;
            }
            t = NULL;
            free(t);
            return;
        }
     
        /* To delete node having one left hand child */
        else if ((t->right == NULL))
        {
            if (t1 == t)
            {
                root = t->left;
                t1 = root;
            }
            else if (t1->left == t)
            {
                t1->left = t->left;
            }
            else
            {
                t1->right = t->left;
            }
            t = NULL;
            free(t);
            return;
        }
        /* To delete node having right hand child */
        else if (t->left == NULL)
        {
            if (t1 == t)
            {
                root = t->right;
                t1 = root;
            }
            else if (t1->right == t)
                t1->right = t->right;
            else
                t1->left = t->right;
            //t == NULL;
            free(t);
            return;
        }

        /* To delete node having two child */
        else if ((t->left != NULL) && (t->right != NULL))  
        {
            t2 = root;
            if (t->right != NULL)
            {
                k = smallest(t->right);
                flag = 1; //////////////////////////////////////////////// flag
            }
            else
            {
                k =largest(t->left);
                flag = 2;
            }
            search1(root, k);
            t->value = k;
        }
    }

    /* To find the smallest element in the right sub tree */
    int smallest(struct bstnode *t)
    {
        t2 = t;
        if (t->left != NULL)
        {
            t2 = t;
            return(smallest(t->left));
        }
        else    
            return (t->value);
    }

    /* To find the largest element in the left sub tree */
    int largest(struct bstnode *t)
    {
        if (t->right != NULL)
        {
            t2 = t;
            return(largest(t->right));
        }
        else    
            return(t->value);
    }

    int main()
    {
        int option;
        printf("\n# # OPERATIONS / Functions for Binary search tree :-");
        printf("\n1 - Insert an element into tree\n");
        printf("2 - Delete an element from the tree\n");
        printf("3 - Inorder Traversal\n");
        printf("4 - Preorder Traversal\n");
        printf("5 - Postorder Traversal\n");
        printf("6 - Exit\n");
        while(1)
        {
            printf("\nEnter your choice :- ");
            scanf("%d", &option);
            switch (option)
            {
            case 1:    
                insert();
                break;
            case 2:    
                delete();
                break;
            case 3:    
                inorder(root);
                break;
            case 4:    
                preorder(root);
                break;
            case 5:    
                postorder(root);
                break;
            case 6:    
                exit(0);
            default :     
                printf("Wrong choice, Please enter correct choice  ");
                break;    
            }
        }
	return 0;
    }
