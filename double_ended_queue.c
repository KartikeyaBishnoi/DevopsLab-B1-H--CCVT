//Author: Sanskriti Gupta
/*Aim: Using array functions implement Double Ended Queue (Input Restricted Dequeue and Output
 Restricted Dequeue) and its operations */
 #include<stdio.h>
 #include<stdlib.h>
 #define CAPACITY 100
 int queue[CAPACITY],n=0;
 void insert_front(int item)
 {
     if(n==CAPACITY-1)
     {
         printf("\nOVERFLOW");
     }
     else if(n==0)
     {
         queue[0]=item;
         n++;
     }
     else
     {
         for(int i=n;i>=0;i--)
         {
             queue[i+1]=queue[i];
         }
         queue[0]=item;
         n++;
     }
 }
 void insert_rear(int item)
 {
     if(n==CAPACITY-1)
     {
         printf("\nOVERFLOW");
     }
     else if(n==0)
     {
         queue[0]=item;
         n++;
     }
     else
     {
         queue[n]=item;
         n++;
     }
 }
 int delete_front()
 {
     if(n==0)
     {
         printf("\nUnderflow");
     }
     else
     {
         int item=queue[0];
         for(int i=0;i<n-1;i++)
         {
             queue[i]=queue[i+1];
         }
         n--;
         return item;
     }
 }
 int delete_rear()
 {
     if(n==0)
     {
         printf("\nUNDERFLOW");
     }
     else
     {
         int item=queue[n-1];
         n--;
         return item;
     }
 }
 void display()
 {
     for(int i=0;i<n;i++)
     {
         printf("%d ",queue[i]);
     }
 }
 void main()
 {
     int choice,internal_choice,item;
     while(1)
     {
         printf("\n1. Input Restricted Dequeue");
         printf("\n2. Output Restricted Dequeue\n");
         printf("\n3. Exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             printf("\nINPUT RESTRICTED DEQUEUE\n");
             while(1)
             {
                 printf("\n1. Insert");
                 printf("\n2. Delete from front");
                 printf("\n3. Delete from rear");
                 printf("\n4. Display");
                 printf("\n5. Exit\n");
                 scanf("%d",&internal_choice);
                 switch(internal_choice)
                 {
                     case 1:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_rear(item);
                     break;
                     case 2:
                     item=delete_front();
                     printf("\nDeleted Item: %d",item);
                     break;
                     case 3:
                     item=delete_rear();
                     printf("\nDeleted Item: %d",item);
                     display();
                     break;
                     case 4:
                     display();
                     break;
                     case 5:
                     exit(0);
                     default:
                     printf("\nWrong Choice");
                 }
             }
             case 2:
             printf("\nOUTPUT RESTRICTED QUEUE\n");
             while(1)
             {
                 printf("\n1. Insert from front");
                 printf("\n2. Insert from rear");
                 printf("\n3. Delete");
                 printf("\n4. Display");
                 printf("\n5. Exit\n");
                 scanf("%d",&internal_choice);
                 switch(internal_choice)
                 {
                     case 1:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_front(item);
                     break;
                     case 2:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_rear(item);
                     break;
                     case 3:
                     item=delete_front();
                     printf("\nDeleted Item: %d",item);
                     break;
                     case 4:
                     display();
                     break;
                     case 5:
                     exit(0);
                     default:
                     printf("\nWrong Choice");
                 }
             }
        case 3:
            exit(0);
        default:
            printf("\nWrong Choice");
         }
     }
 }