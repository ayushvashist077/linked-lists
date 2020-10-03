
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*newnd, *first=NULL, *last=NULL,*temp, *ptr;

struct node* create(int d)
{
    newnd=((struct node*)malloc(sizeof(struct node)));
    newnd->data=d;
    newnd->next=NULL;
    return newnd;
}

void firstt()
{
    int v;
    printf("\nEnter value: ");
    scanf("%d", &v);
    newnd=create(v);
    if(first==NULL && last==NULL)
    {
        first=last=newnd;
        first->next=NULL;
        last->next=NULL;
    }
    else
    {
        temp=first;
        first=newnd;
        first->next=temp;
    }
}



void pos()
{
    int p;
    struct node *prev;
    ptr=first;
    printf("Enter position: ");
    scanf("%d",&p);
    int c;
    for(c=1;c<p;c++)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    int v;
    printf("\nEnter value: ");
    scanf("%d", &v);
    newnd=create(v);
    prev->next=newnd;
    newnd->next=ptr;
}
void lastt()
{
    int v;
    printf("\nEnter value: ");
    scanf("%d", &v);
    newnd=create(v);
    last=first;
    if(first==NULL && last==NULL)
    {
        first=last=newnd;
        first->next=NULL;
        last->next=NULL;
    }
     else
    {
        while(last->next != NULL)
         last=last->next;
        last->next=newnd;
        last=newnd;
        last->next=NULL;  
    }
}

void del()
{
    int p;
    struct node *prev;
    ptr=first;
    printf("Enter position: ");
    scanf("%d",&p);
    int c=1;
    for(c=1;c<p;c++)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr == first)
    {
        first=first->next;
        free(ptr);
    }
    else if(ptr == last)
    {
        last=prev;
        last->next=NULL;
        free(ptr);
    }
    else
    {
    prev->next=ptr->next;
    free(ptr);
    }
}


  struct node* reverse(struct node* nd) 
    { 
        if (nd == NULL) 
            return NULL; 
        if (nd->next == NULL) { 
            first = nd; 
            return nd; 
        } 
        struct node* nd1 = reverse(nd->next); 
        nd1->next = nd; 
        nd->next = NULL; 
        return nd; 
    } 


void display()
{
    ptr=first;
    printf("\nLinked List: ");
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n\n1->INSERT FROM FRONT\n2->INSERT AT POS\n3-> INSERT FROM LAST\n4-> DELETE FORM POS\n5-> DISPLAY\n6-> REVERSE\n7-> EXIT\n\nEnter: ");
        scanf("%d",&ch);
        system("cls");
        if(ch==1)
         firstt();
        else if(ch==2)
         pos();
         else if(ch==3)
         lastt();
        else if(ch==4)
         del();
        else if(ch==5)
         display();
        else if(ch==6)
         reverse(first);
        else
         exit(0);
    }
    return 0;
}


