/*
 *	Authors: Shadman Kolahzary
 *	File: SETTINGS.H
 *	Date: 2013/05/12
 *	Language: C
 *	Assignment: Advanced C Programming Project for University
 *	Description: simple program in c language to managing products and sales in a shop
 */

#include<stdio.h>
#include<conio.h>
#include<string.h>

#define filePath "ShopDatabase.dat"
#define true -10
#define false -11

struct product{
	short int blnInclude; // if this variable is false, this program don't take this record into account
	unsigned int code; // unsigned int is a number between 0 and 65536 (2^16)
	char name[20]; // a string with 50 characters (string is an array of characters)
	unsigned long long price; //unsigned long long is a number between 0 and 4294967296 (2^32)
}arrMain[100]; // this program can manage up to 100 records
int eoarr=0;
