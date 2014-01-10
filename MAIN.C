/*
 *	Authors: Shadman Kolahzary
 *	File: MAIN.C
 *	Date: 2013/05/12
 *	Language: C
 *	Assignment: Advanced C Programming Project for University
 *	Description: simple program in c language to managing products and sales in a shop
 */

#include "C:\CPROJECT\SETTINGS.H"	// this file contains include(s), struct(s), definition of constants like true, false, filePath and eoarr variable
#include "C:\CPROJECT\FUNCS.H"		// other functions are in this file
#include "C:\CPROJECT\MENUS.H"		// munu functions like menu_main() are in this file

void sell();	/* This function is for creating and managing a new sale factor */
void list();	/* This function will show all records in main array on screen */
void create();	/* This function appends a new record to main array */
void edit();	/* This function will edit an existing record */
void del();		/* This function will remove a record */
void sort();	/* This function sorts all array contents by code, name or price */
void search();	/* This function will search a record by code, name or price */

//////////////////////////////////////////////////////////////////////////////////////
void main()/* This is Main function. This function will executed on program startup */
{
	short int blnRun=true;
	do{
		switch(menu_main())
		{
			case 1: sell();		break;
			case 2: list();		break;
			case 3: create();	break;
			case 4: edit();		break;
			case 5: del();		break;
			case 6: sort();		break;
			case 7: search();	break;
			case 8: fSave();	break;
			case 9: fLoad();	break;

			case 0: default:	blnRun=false;
		}
	}while(blnRun==true);
	clrscr();
	puts("Press Enter to exit application...");
	getch();
}




/////////////////////////////////////////////////////////////////////////////
void sell()/* This function is for creating and managing a new sale factor */
{
	unsigned long long sum=0;
	struct product factor[100];
	unsigned int code,count=0;
	int eofac=0,i=0,blnFound,blnRun=true,index;

	do
	{
		blnFound=false;
		clrscr();
		puts("\t\t\tNew Sale Factor\n\n\n");
		puts("Code \t\t Name \t\t Price \n");
		for(i=0;i<eofac;i++)
		{
			if(factor[i].blnInclude==true)
			{
				printf("%u \t\t %s \t\t %llu \n",factor[i].code,factor[i].name,factor[i].price);
				blnFound=true;
			}
		}
		if(blnFound==false)
			puts("There are no any products factored yet...\n\n");


		puts("Enter code of product to append to factor (0 for end): ");	scanf("%u",&code); // Get a new code
		if(code!=0)
		{
			index=getIndexByCode(code);
			if(index!=false)
			{
						factor[eofac].blnInclude=	true				;		// take this record into account
						factor[eofac].code		=	arrMain[index].code	;		// Put code into factor array
				strcpy(	factor[eofac].name		,	arrMain[index].name	);		// Put name into factor array
						factor[eofac].price		=	arrMain[index].price;		// Put price into factor array
				eofac++;
				puts("Added, Press any key to continue...");
			}
			else
				puts("Not found, Press any key to continue...");
		}
		else
			blnRun=false;	// stop editing factor
		getch(); // wait to see results
	}
	while(blnRun==true);

	clrscr();
	puts("\t\t\tSale Factor for Print\n\n\n");	// Title of page
	puts("Code \t\t Name \t\t Price \n");		// Table Header

	if( !(eofac==0) )
	{
		for(i=0;i<eofac;i++)
		{
			if(factor[i].blnInclude==true)
			{
				printf("%u \t\t %s \t\t %llu \n",factor[i].code,factor[i].name,factor[i].price);
				sum+=factor[i].price;
				count++;
			}
		}

		printf("\n\n Number of products in this factor: %i",count);
		printf("\n Sum of Prices: %llu",sum);
	}else
		puts("There are no any records in this factor...");
	getch();
}

/////////////////////////////////////////////////////////////////////////////
void list() /* This function will show all records in main array on screen */
{
	int current=0;
	unsigned int count=0;
	unsigned long long sum=0;
	clrscr();	// clear screen

	puts("\t\t\tList of Products\n\n\n");	// Title of page
	puts("Code \t\t Name \t\t Price \n");	// Table Header
	for(current=0;current<eoarr;current++)																		// loop for all records
	{
		if(arrMain[current].blnInclude==true)															// if not removed
		{
			printf("%u \t\t %s \t\t %llu \n",arrMain[current].code,arrMain[current].name,arrMain[current].price); // show it
			sum+=arrMain[current].price;
			count++;
		}
	}
	if(count>0)																// if any items found
	{
		printf("\n\n Number of all products: %i",count);						// Show count
		printf("\n Sum of Prices: %llu",sum);											// show sum
	}
	else																			// if any items not found
		puts("There are no any records saved yet...");									// tell user

	getch(); // wait...
}


///////////////////////////////////////////////////////////////////
void create()/* This function appends a new record to main array */
{
	struct product tempProduct;
	do{
		clrscr();
		puts("\t\t\tNew Product\n\n\n");

				tempProduct.code	=	getNewCode("Enter a new code between 0 and 65535(0 for cancel): ")				;	// Get a valid Code
						if(tempProduct.code==0) return; // if 0 was entered, return to main menu
		strcpy(	tempProduct.name	,	getNewName("Enter a new name without spaces (max 50 characters): ")	);	// Get a valid Name
				tempProduct.price	=	getNewPrice("Enter a new price between 0 and 4294967295: ")			;	// Get a valid Price

				arrMain[eoarr].blnInclude	=	true				;		// take this record into account
				arrMain[eoarr].code			=	tempProduct.code	;		// Put code into main array
		strcpy(	arrMain[eoarr].name			,	tempProduct.name	);		// Put name into main array
				arrMain[eoarr].price		=	tempProduct.price	;		// Put price into main array

		eoarr++;	// plus one array counter, a new record is appended to array

		puts("\n Saved...");

	}while(yesno("Do you want to enter a new Product details?")==true);
	getch();
}

////////////////////////////////////////////////////////////
void edit() /* This function will edit an existing record */
{
	int index;
	struct product tempProduct;
	unsigned int oldcode=0;
	do{
		clrscr();
		puts("\t\t\tProduct Edit\n\n\n");

		oldcode=getExistingCode("Enter Code of product to Edit(0 for cancel): "); // Get a valid Code, This is previous code
		if(oldcode==0) return; // if 0 was entered, return to main menu
		index=getIndexByCode(oldcode);	// Get index of valid code

				tempProduct.code	=	getNewCode("Enter a new code for change between 0 and 65535: ")					;	// Get a valid Code, This is new code
		strcpy(	tempProduct.name	,	getNewName("Enter a new name for change without spaces (max 50 characters): ")	);	// Get a valid Name
				tempProduct.price	=	getNewPrice("Enter a new price for change between 0 and 4294967295: ")			;	// Get a valid Price

				arrMain[index].code		=	tempProduct.code	;		// Put code into main array
		strcpy(	arrMain[index].name		,	tempProduct.name	);		// Put name into main array
				arrMain[index].price	=	tempProduct.price	;		// Put price into main array

		puts("\n Saved...");			// Record Edited, tell user
	}while(yesno("Do you want to edit a new product? ")==true);
	getch();		// wait...
}

///////////////////////////////////////////////////
void del() /* This function will remove a record */
{
	unsigned int code=0;
	int index=0;
	clrscr();
	puts("\t\t\tProduct Remove\n\n\n");

	do
	{
		code=getExistingCode("Enter Code of product to remove(0 for cancel): ");	// Get a valid Code
		if(code==0) return; // if 0 was entered, return to main menu

		index=getIndexByCode(code);								// Get index of valid code

		arrMain[index].blnInclude=false;	// don't take it into account
		puts("Removed...");					// Product removed, tell user
	}
	while(yesno("Do you want to remove a new product? ")==true);

	getch();
}

/////////////////////////////////////
void sort()
{
	clrscr();
	puts("\t\t\t Sort Products \n\n\n");
	
	switch(menu_sort())
	{
		case 1: // Sort by code
			sortByCode();
			puts("Sorted by code successfully...");
			break;
		case 2: // Sort by name
			sortByName();
			puts("Sorted by name successfully...");
			break;
		case 3:// Sort by price
			sortByPrice();
			puts("Sorted by price successfully...");
			break;
		case 4:
		default:
			break;
	}
	getch();
}
	
/////////////////////////////////////////////////////////////////////////////
void search() /* This function will search a record by code, name or price */
{
	unsigned int code;
	char name[50];
	unsigned long long price;
	int index=0;
	clrscr();
	puts("\t\t\t Product Search \n\n\n");
	switch(menu_search())
	{
		case 1: // Search by code
			clrscr();
			puts("Enter Code to search: ");
			scanf("%u",&code);
			puts("Code \t\t Name \t\t Price \n");

			index=getIndexByCode(code);
			if(index!=false)
				printf("%u \t\t %s \t\t %llu \n",arrMain[index].code,arrMain[index].name,arrMain[index].price);
					else
						puts("Any products with this code not found...");
			break;
		case 2: // Search by name
			clrscr();
			puts("Enter Name to search: ");
			scanf("%s",name);
			puts("Code \t\t Name \t\t Price \n");

			index=getIndexByName(name);
			if(index!=false)
				printf("%u \t\t %s \t\t %llu \n",arrMain[index].code,arrMain[index].name,arrMain[index].price);
					else
						puts("Any products with this name not found...");
			break;
		case 3:// Search by price
			clrscr();
			puts("Enter Price to search: ");
			scanf("%llu",&price);
			puts("Code \t\t Name \t\t Price \n");
		
			index=getIndexByPrice(price);
			if(index!=false)
				printf("%u \t\t %s \t\t %llu \n",arrMain[index].code,arrMain[index].name,arrMain[index].price);
					else
						puts("Any products with this price not found...");
			break;
		case 4:
		default:
			break;
	}
	getch();
}



// Looking for other functions? goto FUNCS.H
