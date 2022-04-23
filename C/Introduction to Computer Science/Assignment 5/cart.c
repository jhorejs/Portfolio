#include <stdio.h>


struct date // struct this is the date function

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
  
  
return n;
  
}



void readInventory(struct details * item, int n) // this fuction takes in a item information

{
  
int i;
char ch;
for (i = 0; i < n; i++)
  
{
  
  
printf("\nProduct name: ");
  
scanf("%s", item[i].product);
  
  
printf("ID #: ");
  
scanf("%d", &item[i].code);
  
  
printf("How many: ");
  
scanf("%d", &item[i].qty);
  
  
printf("Cost: ");
  
scanf("%d", &item[i].price);
  
  
printf("Made on(mm/dd/yy: ");
  
scanf("%d%c", &item[i].cart.d,&ch);
scanf("%d%c", &item[i].cart.month,&ch);
scanf("%d", &item[i].cart.year);
  
}
  
}

// function to diplay the inventory

void displayInventory(struct details * item, int n)

{
  
int i;
  
printf(" welcome to the updated/ completely new cart \n\n");
  
printf("# product name ID How many \tCost\tcart.DATE \n");
  
  
  
for (i = 0; i < n; i++)
  
printf("%-4d %-12s %-6d %-8d %-8d %d/%d/%d\n", (i +1 ), item[i].product, item[i].code, item[i].qty, item[i].price, item[i].cart.d, item[i].cart.month, item[i].cart.year);
  
  
}

// main function

int main()

{
  
struct details item[50];
  
int n;
  
// readNumberOfItems function calling
  
n = readNumberOfItems();
  
// fromUser function calling
  
readInventory(item, n);
  
// displayInventory function calling
  
displayInventory(item, n);
return 0;
}
