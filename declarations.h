#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book
{
	int bookid;
	char bookname[50];
	char author[50];
	char category[20];
	double price;
	double rating;	
	
}book;

extern int ctr;
book* StoreNewBook(book*,int*);
void DeleteBook(book*);
void SearchBook(book*);
void UpdateBook(book*);
void SortBooks(book*);
void DisplayAllBooks(book*);
book* ResizeArray(book *, int *);
