#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc;
    struct node *rc;
};
struct node*search(struct node*root,char x)
{
    if(root==NULL)
    {
     printf("\n Data Not Found\n");
     //return NULL;
    }
    if(root->data==x)
        printf("\n Node is found");
    else if(x>root->data)
          return search(root->rc,x);
    else
        return search(root->lc,x);
};
struct node *new_node(char x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->lc=NULL;
    p->rc=NULL;
};
struct node*insert(struct node*root,char x)
{
    if(root==NULL)
        return new_node(x);
    else if(x>=root->data)
        root->rc=insert(root->rc,x);
    else
        root->lc=insert(root->lc,x);
};

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->lc);
        printf("\t%c",root->data);
        inorder(root->rc);

    }
}
int node_count(struct node*root)
{
    int tot,ld,rd;
    if(root==NULL)
        return 0;
    else{
        rd=node_count(root->rc);
        ld=node_count(root->lc);
        tot=ld+rd+1;
        return tot;
    }
}
int node_level(struct node*root)
{
    int ld,rd;
    if(root==NULL)
        return 0;
    else{
        ld=node_level(root->lc);
        rd=node_level(root->rc);
        if(ld>rd)
            return ld+1;
        else return rd+1;
    }
}
int main()
{
    struct node*root;
    root=new_node('A');
    insert(root,'B');
    insert(root,'C');
    insert(root,'T');
    insert(root,'D');
    insert(root,'F');
    insert(root,'E');
    inorder( root);
    printf("\n");
    printf("%d",node_count(root));
    search(root,'F');
    printf("\nHeight is %d",node_level(root));
    printf("\n Level is %d",node_level(root)-1);
       // search(14);


}
