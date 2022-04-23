//
//  main.c
//  CS 130U Assignment 2, Cart
//
//  Created by Joshua Horejs on 7/9/17.
//  Copyright © 2017 Joshua Horejs. All rights reserved.

/*  Your store is open and your customers are eager to start making purchases. This week you will create ms of your products and then do a mock checkout. 
 
        To complete this lab, your program should:
    • Create nested menus of your product. Three items in a category is enough.
    • In at least one menue, allow users to browse to a sub-category.
    • After each purchase, customers may choose to buy more stuff or stop buying (Hint: use a while loop here)
    • For a mock checkout, read in two numbers (the prices) from the user.
    • Add these two numbers together to create a subtotal.
    • Calculate a 7.25% sales tax and add it to the order.

        At a minimum, your lab should include the following:
    • Use at least 3 different control structures (if, switch, while, for, etc)
    • Print out all intermediate steps of your calculations.
    • All values should be printed out as dollar amounts (with a $ sign and to only 2 decimal places)
        
        All programming labs will contain the following components:
    • A copy of the code.
    • Proof that the code works.
    • Proper comments in the code.
    • A one paragraph summary of the lab. This should include a description of the lab as well as your personal assessment of the lab.
 */

#include <stdio.h>


int main(void) {
    
    char user_name[90]; // this delcaires a char array of up to 90 charactors.
    int i; // this will allow for a loop that will get rid of the \n after the user enters their user name.
    float a= 2.99, b = 8.99, c = 3.45, d = 3.19; // item values
    float t=.0725, total = 0, gtotal = 0; // cart: tax, total, and grand total
    float payment = 0;
    char m; // case loop char
    
    
    // Openning program with question: what is your name?
    printf("Name: ");
    
    // User response is inserted as a char to the variable user_name up to 90 charactors long.
    fgets(user_name, 90, stdin);
    // This loop will get rid of the unneeded \n charactor entered by the user.
    for (i = 0; i < 90; i++ ) {
        if ( user_name[i] == '\n' ) {
            user_name[i] = '\0';
            break;
        }
    }
    
    getchar(); // this is the end of the reading in user name portion of the code.
    
    // The user is now greeted by name
    printf("Hello %s, ", user_name);
    
    
    // The user is then introduced to the suit of goods available through this program.
    printf(" we would like to offer you the following items: ");
    do{
        // Now the user will be asked to select the item they would like to add to the cart.
    printf("\n\t item 1 %.2f: \n\t item 2 %.2f: \n\t item 3 %.2f: \n\n\t QUIT 4: \n\nWhat item would you like to add to the cart today %s?\n\n#", user_name, a, d,b,c);
    scanf(" %c", &m);

        switch(m){
                
            case '1':
                
                printf("\nWhich version of tem 1? \n version 1 %.2f: \n version 2 %.2f:\n#", a,d);
                scanf(" %c", &m);
                switch(m){ // Sub selection menu
                        case '1':
                            printf("\nItem 1.1, added to cart");
                            total += a;
                            break;
                        case '2':
                        printf("\nItem 1.2, added to cart");
                            total += d;
                            break;
                        default:
                            printf("\nINVALID SELECTION...Please try again");
                }
                break;
            case '2':
                printf("\nItem 2, added to cart");
                total += b;
                break;
            case '3':
                total += c;
                printf("\nItem 3, added to cart");
                break;
            case '4':
                break;
            default:
                printf("\nINVALID SELECTION...Please try again");
        }
    }while(m !='4');
    
    //This is the end of the cart app. This asks for the payment and reads out the subtotal
    gtotal = (total*t)+total;
    printf("\nYour total is $%.2f\n\n", gtotal);
    printf("CHECK OUT:\nHow much would you like to pay? $");
    scanf("%f", &payment);
    gtotal -= payment;
    // If the user is due money
    if (gtotal <= 0){
        gtotal *= -1;
        printf("%s your change is $%.2f\n\n\n\n", user_name, gtotal);
    }
    // If the user owes more money
    else if(gtotal > 0){
        printf("Your balance due is: $%.2f\n\n\n\n\n", gtotal);
    }
    
    return 0;
}


