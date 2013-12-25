/*
 *	Authors: Shadman Kolahzary and Houshyar Mohammady
 *	File: FUNCS.H
 *	Date: 2013/05/12
 *	Language: C
 *	Assignment: first term final project
 *	Description: simple program in c language to managing products and sales in a shop
 */

/***************************************************** I/O Functions ********************************************************/
int yesno(char *);							/* This Function gets answer of message from user and returns true or false*/
unsigned int getExistingCode(char *);		/* This Function gets a code from user that is exist in main array*/
unsigned int getNewCode(char *);			/* This Function gets a code from user that isn't exist in main array*/
char * getNewName(char *);					/* This Function gets a name from user that isn't exist in main array*/
unsigned long long getNewPrice(char *);		/* This Function gets a code from user */

/**************************************************** Sort Functions ******************************************************/
void sortByCode();							/* This function sorts all array contents by code */
void sortByName();							/* This function sorts all array contents by name */
void sortByPrice();							/* This function sorts all array contents by price */
void Reverse(int,int);						/* This function gets index of two records and reverse the place of them */

/**************************************************** Search Functions ******************************************************/
int getIndexByCode(unsigned int code);			/* This Function gets code  & after search, returns it's Index in array */
int getIndexByName(char * name);				/* This Function gets name  & after search, returns it's Index in array */
int getIndexByPrice(unsigned long long price);	/* This Function gets price & after search, returns it's Index in array */
int getNext(int current);						/* This Function gets current index & after search, returns next index  */

/**************************************************** Filing Functions ******************************************************/
void fLoad();				/* This function will load all file contents to main array */
void fSave();				/* This Function will save all contents of main array to file */


/***************************************************** I/O Functions ********************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int yesno(char * message) /* This Function gets answer of message from user and returns true or false*/
{
	char str[4];
	printf("%s (yes/no)",message);	// show message
	scanf("%s",str); // get string
	if( str[0]=='y' )	// if entered string starts with 'y'(eg. yes)
		return true; // answer is true
	else // if not
		return false;  // answer is false
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int getExistingCode(char * message) /* This Function gets a code from user that is exist in main array*/
{
		unsigned int code;

		printf("%s",message);	// Show message
		scanf("%u",&code);		// Get a new code from user
		if(code==0) return 0;	// if entered 0(that means exit) return 0, other function will check it...
		if(getIndexByCode(code)!=false)						// if code is existing
		{
			puts("\t\t\t\t\tOk...");						// Code is good, Tell user
			return code;									// return it
		}
		else												// if code isn't existing
		{
			puts("\t\t\t\t\tThis code is now valid!...");	// Code is bad, Tell user
			return getExistingCode(message);				// use recursive method to get a valid code
		}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int getNewCode(char * message) /* This Function gets a code from user that isn't exist in main array*/
{
	unsigned int code;

	printf("%s",message);	// Show message
	scanf("%u",&code);		// Get a new code from user
	if(getIndexByCode(code)==false)							// if code is not existing
	{
		puts("\t\t\t\t\tOk...");							// Code is good, Tell user
		return code;										// return it
	}
	else													// if code isn't duplicate
	{
		puts("\t\t\t\t\tThis code is duplicate!...");		// Code is duplicate, Tell user
		return getNewCode(message);							// use recursive method to get a valid code
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
char * getNewName(char * message) /* This Function gets a name from user that isn't exist in main array*/
{
	char * name;
	printf("%s",message);	// Show message
	scanf("%s",name);		// Get a new name from user
	if(getIndexByName(name)==false)							// if name isn't existing
	{
		puts("\t\t\t\t\tOk...");							// Name is good, Tell user
		return name;										// return it
	}
	else													// if code is duplicate
	{
		puts("\t\t\t\t\tThis name is duplicate!...");		// Name is duplicate, Tell user
		return getNewName(message);							// use recursive method to get a valid name
	}
}
/////////////////////////////////////////////////////////////////////////////////
unsigned long long getNewPrice(char * message) /* This Function gets a code from user */
{
		unsigned long long price;
		printf("%s",message);		// Show message
		scanf("%llu",&price);		// Get a new price from user
		return price;				// Return it

}

/***************************************************** Sort Functions *******************************************************/
////////////////////////////////////////////////////////////////////////
void sortByCode()	/* This function sorts all array contents by code */
{
	int level,current,next=0;
	for(level=eoarr-1;level>=0;level--)
	{
		for(current=0;current<level;current++)
		{
			next=getNext(current);
			if(next!=false)
			{
				if(arrMain[current].code>arrMain[next].code)
				{
					Reverse(current,next);
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
void sortByName()	/* This function sorts all array contents by name */
{
	int level,current,next=0;
	for(level=eoarr-1;level>=0;level--)
	{
		for(current=0;current<level;current++)
		{
			next=getNext(current);
			if(next!=false)
			{
				if(strcmp( arrMain[current].name , arrMain[next].name )>0) // strcmp returns a positive number if first argument is smaller than second argument
				{
					Reverse(current,next);
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////
void sortByPrice()	/* This function sorts all array contents by price */
{
	int level,current,next=0;
	for(level=eoarr-1;level>=0;level--)
	{
		for(current=0;current<level;current++)
		{
			next=getNext(current);
			if(next!=false)
			{
				if(arrMain[current].price>arrMain[next].price)
				{
					Reverse(current,next);
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Reverse(int index1,int index2) /* This function gets index of two records and reverse the place of them */
{
	struct product tempProduct;
	// first to temp
			tempProduct.code		=	arrMain[index1].code	;		// Put code into main array
	strcpy(	tempProduct.name		,	arrMain[index1].name	);		// Put name into main array
			tempProduct.price		=	arrMain[index1].price	;		// Put price into main array

	// second to first
			arrMain[index1].code	=	arrMain[index2].code	;		// Put code into main array
	strcpy(	arrMain[index1].name	,	arrMain[index2].name	);		// Put name into main array
			arrMain[index1].price	=	arrMain[index2].price	;		// Put price into main array

	// temp to second
			arrMain[index2].code	=	tempProduct.code		;		// Put code into main array
	strcpy(	arrMain[index2].name	,	tempProduct.name		);		// Put name into main array
			arrMain[index2].price	=	tempProduct.price		;		// Put price into main array
}

/**************************************************** Search Functions ******************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int getIndexByCode(unsigned int code) /* This Function gets a code and after search returns it's Index in array */
{
	int i=0;
	for(i=0;i<eoarr;i++) // loop for check all records one by one
	{
		if(arrMain[i].blnInclude==true) // check if is taked into account
		{
			if(arrMain[i].code==code) // compare codes
			{
				return i; // if a valid record found return it's index
			}
		}
	}
	return false; // if anything not found return false
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getIndexByName(char * name) /* This Function gets a code and after search returns it's Index in array */
{
	int i=0;
	for(i=0;i<eoarr;i++) // loop for check all records one by one
	{
		if(arrMain[i].blnInclude==true) // check if is taked into account
		{
			if(strcmp(arrMain[i].name,name)==0) // compare names with strcmp
			{
				return i; // if a valid record found return it's index
			}
		}
	}
	return false; // if anything not found return false
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getIndexByPrice(unsigned long long price) /* This Function gets a price from user that isn't exist in main array*/
{
	int i=0;
	for(i=0;i<eoarr;i++) // loop for check all records one by one
	{
		if(arrMain[i].blnInclude==true) // check if is taked into account
		{
			if(arrMain[i].price==price) // compare prices
			{
				return i; // if a valid record found return it's index
			}
		}
	}
	return false; // if anything not found return false
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
int getNext(int current)	/* This Function gets current index & after search, returns next index  */
{
	int next;
	for(next=current+1;next<eoarr;next++)
	{
		if(arrMain[next].blnInclude==true)
		{
			return next;
		}
	}
	return false;
}

/**************************************************** Filing Functions ******************************************************/
//////////////////////////////////////////////////////////////////////////
void fLoad() /* This function will load all file contents to main array */
{
	FILE *db;
	db=fopen(filePath,"r"); // open file for read
	if(!db) // if not opened
	{
		puts("Cannot open main file for reading... \n\n\n\n\n \t\t Press any key to return to main menu...");	// Show error Message
		getch(); // Wait for user input
		return; // get out of this function
	}
	while(!feof(db))
	{
		fread(&arrMain[eoarr],sizeof(struct product),1,db);	// read a record from file
		eoarr++;
	}
	fclose(db);
	puts("All records loaded... ");		// tell user it's done
	getch();							// wait...
}
/////////////////////////////////////////////////////////////////////////////
void fSave() /* This Function will save all contents of main array to file */
{
	int current=0;
	FILE *db;
	db=fopen(filePath,"w");		// open file for write
	if(!db)						// if not opened
	{
		puts("Cannot open main file for reading... \n\n\n\n\n \t\t Press any key to return to main menu...");	// Show error Message
		getch(); // Wait for user input
		return; // get out of this function
	}
	for(current=0;current<eoarr;current++)														// loop for all records
	{
		if(arrMain[current].blnInclude==true)													// if not removed
		{
			fwrite(&arrMain[current],sizeof(struct product),1,db);								// write a record to file
		}
	}
	fclose(db);
	puts("All records saved... ");		// tell user it's done
	getch();							// wait...
}
