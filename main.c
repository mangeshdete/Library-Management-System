#include <stdio.h>
#include "declarations.h"
void main()
{
	int choice;
	int arraysize=50;
    book*b=(book*)malloc(arraysize * sizeof(book));
	
		printf("\n********************************************************************************************************************\n");
		printf("\n\t\t\t\t\t\tFirstBit Library\n");
		printf("\n********************************************************************************************************************\n");
	
	while (1) 
	{	
		printf("\n1. Store New Book. \n2. Delete Existing Book. \n3. Search for a Book. \n4. Update Existing Book Info. ");
		printf("\n5. Sort Books. \n6. Display all Books. \n0. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		

		switch(choice)
		{
			case 1:
				b=StoreNewBook(b,&arraysize);
				break;
				
			case 2:
				DeleteBook(b);
				break;
				
			case 3:
				SearchBook(b);
				break;
				
			case 4:
				UpdateBook(b);
				break;
				
			case 5:
				SortBooks(b);
				break;
				
			case 6:
				DisplayAllBooks(b);
				break;
				
			case 0:
				free(b);
				exit(0);
				
			default:
			printf("Enter valid Choice.");					
		}
	}
}
