/*
 *	Authors: Shadman Kolahzary
 *	File: MENUS.H
 *	Date: 2013/05/12
 *	Language: C
 *	Assignment: Advanced C Programming Project for University
 *	Description: simple program in c language to managing products and sales in a shop
 */

int menu_main();
int menu_search();

////////////////////////////////////////////////////////////////////////////////
int menu_main() /* This function shows Main Menu and returns number of choice */
{
	char c='1'; // This is a temp variable, user choice number will stored in this variable before converting to Integer
	short int choice=-1; // User Choice will stored in this variable
	clrscr(); // Clear Screen

	// Show Menu
	puts("1. New Sale(+factor)\n");
	puts("2. List all products\n");
	puts("3. Add new product\n");
	puts("4. Edit a product\n");
	puts("5. Remove a product\n");
	puts("6. Sort Products\n");
	puts("7. Find a product\n");
	puts("8. Save Database\n");
	puts("9. Load Database\n");
	puts("0. Exit Program\n");
	puts("Enter the number of your choice(1-9): ");
	for(;;)	// unlimited loop
	{
		c=getchar(); // get a character and store it in c variable
		if( (c>47) && (c<58) ){ // 0 ascii code = 48 & 9 ascii code = 57
			choice=c-48; // for example 50 is 2's ascii code, 50-48=2!
			if((choice>=0) && (choice<10)){	// if smaller than 10 and bigger than or equals to 0
				return choice; // this is good! return the choosed number
			}else{
				continue; // this char is bad!, get a new character...
			}
		}else{
			continue; // this char is bad!, get a new character...
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
int menu_search() /* This function shows Search Menu and returns number of choice */
{
	char c='1'; // This is a temp variable, user choice number will stored in this variable before converting to Integer
	short int choice=-1; // User Choice will stored in this variable
	clrscr(); // Clear Screen

	// Show Menu
	puts("1. Search by Code\n");
	puts("2. Search by Name\n");
	puts("3. Search by Price\n");
	puts("4. Return to the main menu\n");

	puts("Enter the number of your choice(1-4): ");
	for(;;)	// unlimited loop
	{
		c=getchar(); // get a character and store it in c variable
		if( (c>47) && (c<58) ){ // 0 ascii code = 48 & 9 ascii code = 57
			choice=c-48; // for example 50 is 2's ascii code, 50-48=2!
			if((choice>0) && (choice<5)){ // if bigger than 0 and smaller than 5
				return choice; // this is good! return the choosed number
			}else{
				continue; // this char is bad!, get a new character...
			}
		}else{
			continue; // this char is bad!, get a new character...
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
int menu_sort() /* This function shows Search Menu and returns number of choice */
{
	char c='1'; // This is a temp variable, user choice number will stored in this variable before converting to Integer
	short int choice=-1; // User Choice will stored in this variable
	clrscr(); // Clear Screen

	// Show Menu
	puts("1. Sort by Code\n");
	puts("2. Sort by Name\n");
	puts("3. Sort by Price\n");
	puts("4. Return to the main menu\n");

	puts("Enter the number of your choice(1-4): ");
	for(;;)	// unlimited loop
	{
		c=getchar(); // get a character and store it in c variable
		if( (c>47) && (c<58) ){ // 0 ascii code = 48 & 9 ascii code = 57
			choice=c-48; // for example 50 is 2's ascii code, 50-48=2!
			if((choice>0) && (choice<5)){ // if bigger than 0 and smaller than 5
				return choice; // this is good! return the choosed number
			}else{
				continue; // this char is bad!, get a new character...
			}
		}else{
			continue; // this char is bad!, get a new character...
		}
	}
}
