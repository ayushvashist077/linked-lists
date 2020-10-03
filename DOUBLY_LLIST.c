#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
}*newnd, *first=NULL, *last=NULL,*temp, *ptr;

struct node* create(int d)
{
    newnd=((struct node*)malloc(sizeof(struct node)));
    newnd->data=d;
    newnd->next=NULL;
    newnd->prev=NULL;
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
        first->next=first->prev=NULL;
        last->next=last->prev=NULL;
    }
    else
    {
        temp=first;
        first=newnd;
        first->next=temp;
        temp->prev=first;
    }
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
        first->next=first->prev=NULL;
        last->next=last->prev=NULL;
    }
     else
    {
        while(last->next != NULL)
         last=last->next;
        ptr=last;
        last->next=newnd;
        last=newnd;
        last->next=NULL;  
        last->prev=ptr;
    }
}



void del()
{
    int p;
    struct node *pre;
    ptr=first;
    printf("Enter position: ");
    scanf("%d",&p);
    int c=1;
    for(c=1;c<p;c++)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    if(ptr == first)
    {
        first=first->next;
        first->prev=NULL;
        free(ptr);
    }
    else if(ptr == last)
    {
        last=pre;
        last->next=NULL;
        free(ptr);
    }
    else
    {
    pre->next=ptr->next;
    ptr->next->prev=pre;
    free(ptr);
    }
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
        printf("\n\n1->INSERT FROM FRONT\n2-> INSERT FROM END\n3-> DELETE FORM POS\n4-> DISPLAY\n5-> EXIT\n\nEnter: ");
        scanf("%d",&ch);
        system("cls");
        if(ch==1)
         firstt();
        else if(ch==2)
         lastt();
        else if(ch==3)
         del();
        else if(ch==4)
         display();
        else
         exit(0);
    }
    return 0;
}