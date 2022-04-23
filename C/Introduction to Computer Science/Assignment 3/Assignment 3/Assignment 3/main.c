/*
 
 
 Hello, 
 
 I made a farly simple program that utilizes some ot the functions introduced in lecture and from google searches that I wanted to try. I found some formatting and an attempt at pointers. It has been a while and I am still not quite sure how the pointers work in C. I am having some issues with the pointers in the reading in of the code. 
 I want to make sure I fix this but it is time to submit for gradding... so I will have to work them out later...
 
 
 
 
 
 
 
 */


#include <stdio.h>


struct date   // struct this is the date function

{
    
    int d;
    
    int month;
    
    int year;
    
};



struct details // struct for the item of an item

{
    
    char product[20];
    
    int price;
    
    int code;
    
    int qty;
    
    struct date cart;
    
};

// function to read the number of items

int readNumberOfItems()

{
    
    int n;
    
    printf("How many entries: "); // allows user to enter how many products will be entered
    
    scanf("%d", &n);
    
    fflush(stdin);
    
    return n;
    
}



void readInventory(struct details item[50], int n) // this fuction takes in a item information

{
    
    int i;
    
    for (i = 0; i < n; i++)
        
    {
        
        fflush(stdin);
        
        printf("\nProduct name: ");
        
        scanf("%s", item[i].product);
        
        fflush(stdin);
        
        printf("ID #: ");
        
        scanf("%d", &item[i].code);
        
        fflush(stdin);
        
        printf("How many: ");
        
        scanf("%d", &item[i].qty);
        
        fflush(stdin);
        
        printf("Cost: ");
        
        scanf("%d", &item[i].price);
        
        fflush(stdin);
        
        printf("Made on(mm/dd/yy: ");
        
        scanf("%d", &item[i].cart.d);
        scanf("%d", &item[i].cart.month);
        scanf("%d", &item[i].cart.year);
        
    }
    
}

// function to diplay the inventory

void displayInventory(struct details item[50], int n)

{
    
    int i;
    
    printf(" welcome to the updated/ completely new cart \n\n");
    
    printf("#   product   name   ID  How many  Cost  cart.DATE \n");
    
   
    
    for (i = 0; i < n; i++)
        
        printf("%-4d %-12s %-6d %-8d %-8d %d/%d/%d\n", (i +1 ), item[i].product, item[i].code, item[i].qty, item[i].price, item[i].cart.d, item[i].cart.month, item[i].cart.year);

    
}

// main function

void main()

{
    
    struct details item[50];
    
    int n;
    
    // readNumberOfItems function calling
    
    n = readNumberOfItems();
    
    // fromUser function calling
    
    readInventory(item, n);
    
    // displayInventory function calling
    
    displayInventory(item, n);
    
}
