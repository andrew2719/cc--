#include<stdio.h>

#include<stdlib.h>

struct node

{

    int data;

    struct node*left;

    struct node*right;

};

struct node*result,*big,*small,*result1,*temp;

void insd( struct node*,int);

void Inorder(struct node *root)

{

    if( root != NULL)

    {

        Inorder(root->left);

        printf(" %d ",root->data);

        Inorder(root->right);

    }

}

struct node* presuc(struct node*root,struct node* pre, struct node* suc,int key)

{

    if(root==NULL)

        return NULL;

    while(root!=NULL)

    {

        if(root->data ==key)

        {

           if(root->right!=NULL)

           {

               suc=root->right;

               while(suc->left!=NULL)

               {

                   suc=suc->left;

               }

           }

           if(root->left!=NULL)

           {

               pre=root->left;

               while(pre->right!=NULL)

               {

                   pre=pre->right;

               }

           }

            printf("suc data %d",suc->data);

           return pre,suc ;

        }

        else if(root->data < key)

        {

            pre=root;

            root=root->right;

        }

        else

        {

            suc=root;

            root=root->left;

        }

    }

   

}

void Preorder(struct node *root)

{

    if( root != NULL)

    {

        printf(" %d ",root->data);

        Preorder(root->left);

        Preorder(root->right);

    }

}

 

void Postorder(struct node *root)

{

    if( root != NULL)

    {

        Postorder(root->left);

        Postorder(root->right);

        printf(" %d ",root->data);

    }

}

struct node*create(struct node*root,int item)

{

    if(root==NULL)

    {

        root=(struct node*)malloc(sizeof(struct node));

        root->data=item;

        root->right=root->left=NULL;

        return root;

    }

    else

    {

        if(item<root->data)

        {

            root->left=create(root->left,item);

        }

        else if(item>root->data)

        {

            root->right=create(root->right,item);

        }

       

        return root;

    }

}

 

struct node* search(struct node* root, int key)

{

   

    if (root == NULL || root->data == key)

       return root;

      

    if (root->data < key)

       return search(root->right, key);

    else if(root->data>key)

       return search(root->left, key);

}

 

struct node*biggest(struct node*root)

{

   

   if(root->right!=NULL)

    return biggest(root->right);

   else

    return root;

}

struct node*smallest(struct node*root)

{

   

   if(root->left!=NULL)

    return biggest(root->left);

   else

    return root;

}

struct node*delete(struct node*root,int de)

{

    struct node*ptr;

    if(root==NULL)

    {

        return NULL;

    }

    if(root->data<de)

    {

        root->right=delete(root->right, de);

    }

    else if(root->data>de)

    {

        root->left=delete(root->left, de);

    }

    else

    {

       if(root->right!=NULL && root->left!=NULL)

       {

           ptr=biggest(root->left);

           root->data=ptr->data;

           root->left=delete(root->left,ptr->data);

       }

       else if(root->right==NULL && root->left==NULL)

       {

           free(root);

           return NULL;

       }

       else if(root->left!=NULL && root->right==NULL)

       {

           ptr=root->left;

           free(root);

           return ptr;

       }

       else

       {

           ptr=root->right;

           free(root);

           return ptr;

       }

    }

    return root;

}

int main()

{

  struct node* root=NULL;

  int n,i,a[n];

  scanf("%d",&n);

  for(i=0;i<n;i++)

  {

      scanf("%d",&a[i]);

      root=create(root,a[i]);

  }

    printf("\nBST Traversal in INORDER \n");

    Inorder(root);

    printf("\nBST Traversal in PREORDER \n");

    Preorder(root);

    printf("\nBST Traversal in POSTORDER \n");

    Postorder(root);

    int value;

    printf("\n enter value for insd\n");

    scanf("%d",&value);

    insd(root,value);

}

void insd( struct node*root,int value)

{  

    struct node *pre,*suc;

    big=biggest(root);

    printf("\n the biggest element is:%d\n",big->data);

    printf("\n the data in root is :%d\n",root->data);

    result=search(root,value);

    if(result->data==big->data && result->right ==NULL)

    {

        printf(" inorder successor deletion is not possible\n");

    }

    else

    {

        if(result->right==NULL)

        {

            printf(" \nresult val %d",result->data);

            if(pre==NULL)

            {

                printf("\n NULL");

            }

            if(suc==NULL)

            {

                printf("\n NULL");

            }

            int super=result->data;

            pre=root;

            suc=root;

            pre,suc=presuc(root,pre,suc,super);

           printf("suc data %d",suc->data);

           root=delete(root,suc->data);

           printf("\ntejesh%d",root->data);

           printf("\nBST Traversal in INORDER \n");

            Inorder(root);

        }

        else

        {

            small=smallest(result->right);

            int dup=small->data;

            printf("%d",dup);

            root=delete(root,dup);

            printf("\nBST Traversal in INORDER \n");

            Inorder(root);

        }

    }

   

}