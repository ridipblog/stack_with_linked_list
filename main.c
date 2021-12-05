#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack * next;
};
struct stack *top=NULL;
struct stack * insert(int val,struct stack * top)
{
    struct stack *ptr;
    ptr=(struct stack *)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
};
struct stack * pop(struct stack *top)
{
    struct stack *ptr=top;
    if(top==NULL)
        printf("\nStack is empty");
    else
        top=top->next;
        printf("\nRemove %d ",ptr->data);
        free(ptr);
    return top;
};
int peek(struct stack * top)
{
    struct stack *ptr=top;
    if(ptr==NULL)
    {
        printf("\nstack is empty ");
        return -1;
    }
    else
    {
        int index;
        printf("\nEnter Index ");
        scanf("%d",&index);
        int i=0;
        while(i!=index-1)
        {
            ptr=ptr->next;
            i++;
        }
        return ptr->data;
    }
}
void display(struct stack *top)
{
    struct stack *ptr=top;
    if(ptr==NULL)
        printf("\nStack is empty");
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    int option,val;
    while(1)
    {
        printf("\n1 for exit ");
        printf("\n2 for insert value");
        printf("\n3 for remove value ");
        printf("\n4 for display value ");
        printf("\n5 for display all values ");
        scanf("%d",&option);
        if(option==1)
        {
            break;
        }
        else if(option==2)
        {
            while(1)
            {
                printf("\n0 for exit ");
                printf("\nEnter Data ");
                scanf("%d",&val);
                if(val==0)
                    break;
                else
                    top=insert(val,top);
            }
        }
        else if(option==3)
        {
            top=pop(top);
        }
        else if(option==4)
        {
            printf("\nItem %d ",peek(top));
        }
        else if(option==5)
        {
            display(top);
        }
    }
    return 0;
}
