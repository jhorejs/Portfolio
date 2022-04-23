//  c
//  CS 130U assignment 1
//  Created by Joshua Horejs on 6/30/17.
//  Copyright © 2017 Joshua Horejs. All rights reserved.
/*
		*************   ASSIGNMENT REQUIREMENTS   *************
    Write an introductory screen to your store.
    Requirements:
        - greet the guests by name
        - introduce them to your line of products.
 
    At a minimum, your lab should include the following:
        - THREE LINES OF a nicely formatted text MESSAGE, printed to the user.
        - Prompt the user for a number, 
            • read it in 
            • store it in a variable
            • use the number to greet the user.
 
        - Store a VALUE AS A CONSTANT and PRINT it to the user during the introductory message
        - Clear comments
 
 
    All programming labs will contain the following components:
            1) A copy of the code.
            2) Proof that the code works.
            3) Proper comments in the code.
            4) A one paragraph summary of the lab. This should include a description of the lab as well as your personal assessment of the lab.

		*************   PERSONAL ASSESSMENT   *************
This lab required us to create a welcome screen for a digital store. I chose to use this assignment to brush up on the my use of charactor arrays. I find anything to do with char's to be vital to my coding knowledge, since they are essentially the backbone to codding. Much in the way of writting english on pen and paper this is to me the best practice for understanding fundimentals of coding. 

For this assignment I kept the code as short and sweet as possible. I wanted to go ahead and make the acutal cart function but I allowed some room for feedback before I went too far down the line whith this puppy. I hope you have some good technique notes for me. I am very rusty so any and all comments are very welcome. 

*/
//

#include <stdio.h>

int main(void) {
    
    char user_name[90]; // this delcaires a char array of up to 90 charactors.
    int i; // this will allow for a loop that will get rid of the \n after the user enters their user name. 

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
    printf("Hello, %s.\n", user_name);
    
    // The user is then introduced to the suit of goods available through this program.
    printf("%s, we would like to offer you the following items: \n item 1: \n item 2: \n item 2: \n item 4: \n\n", user_name);
    
    // Now the user will be asked to select the item they would like to add to the cart.
    printf("What would you like to add to the cart today %s?\n\n", user_name);
    
    // Future code to be added to make a selection and clear the program. 

    return 0;
}

