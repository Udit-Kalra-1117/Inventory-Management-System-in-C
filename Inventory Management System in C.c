#include <stdio.h>
struct node{
    char pname [100];
    int pcode;
    int price;
    int quantity;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
struct node* create(struct node* root,int x,int y,int z,char b[100]){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    strcpy(temp->pname,b);
    temp->pcode=x;
    temp->price=y;
    temp->quantity=z;
    if(root==NULL){
    root=temp;
    return root;
    }else{
        if(temp->pcode>root->pcode){

            root->right=create(root->right,x,y,z,b);
        }else{
            root->left=create(root->left,x,y,z,b);
        }
    }
    return root;
}
struct node* search(struct node* root,char c[100]){
    if(root->left != NULL){
    search(root->left,c);
    }
    if(atoi(c)==root->pcode || strcmp(c,root->pname)==0){
        printf("Data found.");
        printf("\n%s\t\t%d\t\t%d\t\t\t%d",root->pname,root->pcode,root->price,root->quantity);
        return;
    }
    if(root->right != NULL){
    search(root->right,c);
    }
        return 0;

}
struct node* printinorder(struct node* root){
    if(root==NULL){
            return;
        }
    if(root->left != NULL){
    printinorder(root->left);
    }
    printf("\n%s\t\t%d\t\t%d\t\t\t%d",root->pname,root->pcode,root->price,root->quantity);
    if(root->right != NULL){
    printinorder(root->right);
    }
    return 0;
}
struct node* findmin(struct node* r)
{
    while(r->left!=NULL)
    {
        r=r->left;
    }
    return r;
}

struct node* deleteNode(struct node* r, int c)
{
   if (r == NULL)
   return r;
   if (c < r->pcode)
   {
     r->left = deleteNode(r->left, c);
   }
   else if (c > r->pcode)
   {
     r->right = deleteNode(r->right,c );
   }
   else{
      if (r->left == NULL)
      {
        struct node *temp = r->right;
        free(r);
        return temp;
      }
      else if (r->right == NULL)
      {
        struct node *temp = r->left;
        free(r);
        return temp;
      }
      struct node* temp = findmin(r->right);
      strcpy(r->pname,temp->pname);
      r->pcode = temp->pcode;
      r->price = temp->price;
      r->quantity = temp->quantity;
      r->right = deleteNode(r->right, temp->pcode);
   }
   return r;
}
struct node* buy(struct node* root,char d[100],int y){
    if(root->left != NULL){
    buy(root->left,d,y);
    }
    if(atoi(d)==root->pcode || strcmp(d,root->pname)==0){
        if(y>root->quantity){
            printf("\n%s\t\t%d\t\t%d\t\t\t%d",root->pname,root->pcode,root->price,root->quantity);
            printf("\nQuantity unavailable.");
        }else{
        root->quantity-=y;
        }
        if(root->quantity==0){
            printf("\nProduct finished.");

        }
    }
    if(root->right != NULL){
    buy(root->right,d,y);
    }
        return 0;
        }


int main()
{int n,i,x,y,z,w;
char a[100],b[100],c[100],d[100];
    printf("\t\t\t\t\t|-----------------------------------|\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|     Welcome to Maverick Stores    |\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|                                   |\n");
    printf("\t\t\t\t\t|-----------------------------------|\n");
    while(strcmp(a,"/")!=0){
    printf("\n");
        printf("a.Enter new product details.\n");
        printf("b.Print list of products.\n");
        printf("c.Search  product.\n");
        printf("d.Buy Product.\n");
        printf("e.Delete Product.\n");
        printf("Enter 'a','b','c','d' or 'e' for executing the respective operation and '/' for ending process: ");

        scanf("%s",a);
        if(strcmp("a",a)==0){
            printf("Enter the product name:");
            scanf("%s",b);
            printf("Enter the product code:");
            scanf("%d",&x);
            printf("Enter the product price:Rs ");
            scanf("%d",&y);
            printf("Enter the product quantity available:");
            scanf("%d",&z);
            root=create(root,x,y,z,b);

        }
        else if(strcmp("b",a)==0){
            printf("Product name:\tProduct code:\tProduct price(Rs):\tProduct quantity:");
            printinorder(root);
        }
        else if(strcmp("c",a)==0){
            printf("Enter product code or product name : ");
            scanf("%s",c);
            search(root,c);
        }
        else if(strcmp("d",a)==0){
            printf("Enter product code or product name : ");
            scanf("%s",d);
            printf("Enter product quantity: ");
            scanf("%d",&i);
            buy(root,d,i);
        }
        else if(strcmp("e",a)==0){
            printf("Enter product code:");
            scanf("%d",&w);
            root=deleteNode(root,w);
        }
}
    return 0;
}