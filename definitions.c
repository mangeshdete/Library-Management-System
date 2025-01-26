#include "declarations.h"
#include<stdio.h>
int ctr=0;

book* StoreNewBook(book* b, int* size)
{
    if (ctr == *size)
    {
        b=ResizeArray(b,size);
    }
    else
    {
        int newBookId,i,categoryChoice;

            printf("\nEnter Book Id: ");
            scanf("%d", &newBookId);

            int idExists = 0;
            for (i = 0; i < ctr; i++)
            {
                if (b[i].bookid == newBookId)
                {
                    idExists = 1;
                    printf("Book ID %d already exists. Please enter a unique Book ID.\n", newBookId);
                    break;
                }
            }

            if (!idExists)
            {
                b[ctr].bookid = newBookId;

                printf("\nEnter the Name of the Book: ");
                fflush(stdin);
                gets(b[ctr].bookname);

                printf("\nEnter the Author of the Book: ");
                fflush(stdin);
                gets(b[ctr].author);

                printf("\nEnter the Category of the Book: \n");
                printf("1. Fiction\n2. Science\n3. Motivation\n4. Horror\n5. History\n6. Unknown\n");
                printf("Enter the corresponding number for the category: ");
	            scanf("%d", &categoryChoice);
	
	            switch (categoryChoice)
	            {
	                case 1:
	                    strcpy(b[ctr].category, "Fiction");
	                    break;
	                case 2:
	                    strcpy(b[ctr].category, "Science");
	                    break;
	                case 3:
	                    strcpy(b[ctr].category, "Motivation");
	                    break;
	                case 4:
	                    strcpy(b[ctr].category, "Horror");
	                    break;
	                case 5:
	                    strcpy(b[ctr].category, "History");
	                    break;
	                case 6:
	                    strcpy(b[ctr].category, "Unknown");
	                    break;
	                    
	                default:
					printf("\nInvalid Choice, category will be set to 'Unknown'\n");
					strcpy(b[ctr].category, "Unknown"); 
	            }

                printf("\nEnter the Price of the Book: ");
                scanf("%lf", &b[ctr].price);

                printf("\nEnter the Rating of the Book (1-10): ");
                scanf("%lf", &b[ctr].rating);
					while(b[ctr].rating < 1 || b[ctr].rating > 10)
            		{
                		printf("Invalid rating. Please enter a rating between 1 and 10: ");
                		scanf("%lf", &b[ctr].rating);
            		}
				
                printf("\n\nBook Added Successfully****************************************************\n\n");
				
				ctr++;
            }
    }
    return b;
}

void DeleteBook(book* b)
{
 	int bookiddelete,found=0,i,j;
    
	printf("\nEnter the Book ID to delete: ");
    scanf("%d", &bookiddelete);
    
    for(i=0;i<ctr;i++)
    {
    	if(b[i].bookid==bookiddelete)
    	{
    		found=1;
    		for (j=i ; j<ctr-1 ; j++) 
			{
                b[j] = b[j + 1];
			}
			
			ctr--;
            printf("Book with ID %d deleted successfully.\n",bookiddelete);
            break;	
		}
	}
	if (!found)
		{
        	printf("Book with ID %d not found.\n",bookiddelete);
		}
}
void SearchBook(book* b)
{
	int choice,bookidtosearch,i;
	
	printf("Search By 1 or 2: \n\n1. Book ID. \n2. Book Name. \n3. Book Author. \n4. Book Category.");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			
			printf("\nEnter the Book ID to search: ");
		    scanf("%d", &bookidtosearch);
		
			for(i=0;i<ctr;i++)
			{
				if(b[i].bookid==bookidtosearch)
				{
					printf("\nBook Id			:	%d",b[i].bookid);
					printf("\nBook Name		:	%s",b[i].bookname);
					printf("\nBook Author		:	%s",b[i].author);
					printf("\nBook Category		:	%s",b[i].category);
					printf("\nBook Price		:	%.2lf",b[i].price);
					printf("\nBook Rating/10		:	%.2lf\n",b[i].rating);
					return;
				}
			}
			printf("\nBook ID not found.\n");
			break;
		
		case 2:
			
			printf("\nEnter the Book Name to search: ");
			fflush(stdin);
			char booknametosearch[50];
			gets(booknametosearch);
			
			int namefound=0;
            for (i = 0; i < ctr; i++) 
			{
                if (strstr(strlwr(b[i].bookname),strlwr(booknametosearch)) != '\0') 
				{
					namefound=1;
                    printf("\nBook Id          : %d", b[i].bookid);
                    printf("\nBook Name        : %s", b[i].bookname);
                    printf("\nBook Author      : %s", b[i].author);
                    printf("\nBook Category    : %s", b[i].category);
                    printf("\nBook Price       : %.2lf", b[i].price);
                    printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
                }
        	}
        	if(!namefound)
        	{
        		printf("\nBook name not found.\n");
			}
            
			break;	
			
		case 3:
			printf("\nEnter the Book Author to search: ");
			fflush(stdin);
			char bookauthortosearch[50];
			gets(bookauthortosearch);
			
			int authorfound=0;
            for (i = 0; i < ctr; i++) 
			{
                if (strstr(strlwr(b[i].author),strlwr(bookauthortosearch)) != '\0') 
				{
					authorfound=1;
                    printf("\nBook Id          : %d", b[i].bookid);
                    printf("\nBook Name        : %s", b[i].bookname);
                    printf("\nBook Author      : %s", b[i].author);
                    printf("\nBook Category    : %s", b[i].category);
                    printf("\nBook Price       : %.2lf", b[i].price);
                    printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
                }
        	}
        	if(!authorfound)
        	{
        		printf("\nBook author not found.\n");
			}
            
			break;	
			
			case 4:
			printf("\nEnter the Book Category to search: ");
			fflush(stdin);
			char bookcattosearch[50];
			gets(bookcattosearch);
			
			int catfound=0;
            for (i = 0; i < ctr; i++) 
			{
                if (strstr(strlwr(b[i].category),strlwr(bookcattosearch)) != '\0') 
				{
					catfound=1;
                    printf("\nBook Id          : %d", b[i].bookid);
                    printf("\nBook Name        : %s", b[i].bookname);
                    printf("\nBook Author      : %s", b[i].author);
                    printf("\nBook Category    : %s", b[i].category);
                    printf("\nBook Price       : %.2lf", b[i].price);
                    printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
                }
        	}
        	if(!catfound)
        	{
        		printf("\nNo book found, with the entered category.\n");
			}
            
			break;		
	}	
}
void UpdateBook(book* b)
{
	int bookidtoupdate,i,choice,found=0;
		printf("\nEnter the Book ID to Update the Book Details: ");
		scanf("%d", &bookidtoupdate);
		
	int newbookid,categoryChoice;
	char newbookname[50];
	char newauthor[20];
	char newcategory[20];
	double newbookprice;	
	double newbookrating;
		
	for(i=0;i<ctr;i++)
	{
		if(bookidtoupdate==b[i].bookid)
		{
			found++;
			printf("\nThe details of the Book are:\n");
				printf("\nBook Id          : %d", b[i].bookid);
                printf("\nBook Name        : %s", b[i].bookname);
                printf("\nBook Author      : %s", b[i].author);
                printf("\nBook Category    : %s", b[i].category);
                printf("\nBook Price       : %.2lf", b[i].price);
                printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
			
			printf("\nWhat details are to be updated? ");
			printf("\n1. Category \n2. Book Price. \n3. Book Rating. \n0. Back to Main Menu\n");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
					printf("\nEnter the new Category of the Book: \n");
	                printf("1. Fiction\n2. Science\n3. Motivation\n4. Horror\n5. History\n6. Unknown\n");
	                printf("Enter the corresponding number for the category: ");
		            scanf("%d", &categoryChoice);
		
		            switch (categoryChoice)
		            {
		                case 1:
		                    strcpy(b[ctr].category, "Fiction");
		                    printf("\nBook Category updated to 'Fiction'\n");
		                    break;
		                case 2:
		                    strcpy(b[ctr].category, "Science");
		                    printf("\nBook Category updated to 'Science'\n");
		                    break;
		                case 3:
		                    strcpy(b[ctr].category, "Motivation");
		                    printf("\nBook Category updated to 'Motivation'\n");
		                    break;
		                case 4:
		                    strcpy(b[ctr].category, "Horror");
		                    printf("\nBook Category updated to 'Horror'\n");
		                    break;
		                case 5:
		                    strcpy(b[ctr].category, "History");
		                    printf("\nBook Category updated to 'History'\n");
		                    break;
		                case 6:
		                    strcpy(b[ctr].category, "Unknown");
		                    printf("\nBook Category updated to 'Unknown'\n");
		                    break;
		                    
		                default:
						printf("\nInvalid Choice, category will be set to 'Unknown'\n");
						strcpy(b[ctr].category, "Unknown"); 
	            }
					break;
					
				case 2:
					printf("\nEnter New Price of the Book: ");
					scanf("%lf",&newbookprice);
					b[i].price=newbookprice;
					printf("\nBook Price Updated Succesfully.\n");
					break;
					
				case 3:
					printf("\nEnter New Rating of the Book: ");
					scanf("%lf",&newbookrating);
					while(newbookrating<0 || newbookrating>10)
					{
						printf("Invalid rating. Please enter a rating between 1 and 10: ");
                		scanf("%lf",&newbookrating);
					}
					b[i].rating=newbookrating;
					printf("\nBook Rating Updated Succesfully.\n");
					break;
					
				case 0:
				return;
					
				default:
				printf("\nEnter valid Choice.");						
			}
		}
			if(bookidtoupdate!=b[i].bookid)
			{
				printf("\nEntered Book ID not found. Enter again.");
				UpdateBook(b);	
			}	
	}
		
}
void SortBooks(book* b)
{
	if(ctr==0)
	{
		printf("\nNo Books found, please add a few books to proceed with this function.\n");
		return;
	}
	else
	{
		int choice,sortbyprice,sortbyrating;
		printf("\nHow do you want to sort the books?\n1. Based on Price.\n2. Based on Ratings.\n0. Back to main menu\n\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		int i,j;
		book temp;
		
		switch(choice)
		{
			case 1:		//based on price
				printf("\n1. Price: Highest to Lowest.\n2. Price: Lowest to Highest.\n\nEnter your Choice: ");
				scanf("%d",&sortbyprice);
					switch(sortbyprice)
					{
						case 1:
							for(i=0;i<ctr;i++)
							{
								for(j=i+1;j<ctr;j++)
								{
									if(b[i].price<b[j].price)
									{
										temp=b[i];
										b[i]=b[j];
										b[j]=temp;
									}
								}
							}
							printf("\nThe Highest price books starts from:\n");
							for(i=0;i<ctr;i++)
							{
								printf("\n%d:\n",i+1);
								printf("\nBook Id          : %d", b[i].bookid);
				                printf("\nBook Name        : %s", b[i].bookname);
				                printf("\nBook Author      : %s", b[i].author);
				                printf("\nBook Category    : %s", b[i].category);
				                printf("\nBook Price       : %.2lf", b[i].price);
				                printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
							}
							break;
							
						case 2:
							for(i=0;i<ctr;i++)
							{
								for(j=i+1;j<ctr;j++)
								{
									if(b[i].price>b[j].price)
									{
										temp=b[i];
										b[i]=b[j];
										b[j]=temp;
									}
								}
							}
							printf("\nThe Lowest price books starts from:\n");
							for(i=0;i<ctr;i++)
							{
								printf("\n%d:\n",i+1);
								printf("\nBook Id          : %d", b[i].bookid);
				                printf("\nBook Name        : %s", b[i].bookname);
				                printf("\nBook Author      : %s", b[i].author);
				                printf("\nBook Category    : %s", b[i].category);
				                printf("\nBook Price       : %.2lf", b[i].price);
				                printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
							}
							break;
							
							default:
							printf("\nEnter Valid Choice.");		
					}
			break;	
				
			case 2:		//based on rating
				printf("\n1. Rating: Highest to Lowest.\n2. Rating: Lowest to Highest.\n\nEnter your Choice: ");
				scanf("%d",&sortbyrating);
				switch(sortbyrating)
					{
						case 1:
							for(i=0;i<ctr;i++)
							{
								for(j=i+1;j<ctr;j++)
								{
									if(b[i].rating<b[j].rating)
									{
										temp=b[i];
										b[i]=b[j];
										b[j]=temp;
									}
								}
							}
							printf("\nThe Highest Rated books starts from:\n");
							for(i=0;i<ctr;i++)
							{
								printf("\n%d:\n",i+1);
								printf("\nBook Id          : %d", b[i].bookid);
				                printf("\nBook Name        : %s", b[i].bookname);
				                printf("\nBook Author      : %s", b[i].author);
				                printf("\nBook Category    : %s", b[i].category);
				                printf("\nBook Price       : %.2lf", b[i].price);
				                printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
							}
							break;
							
						case 2:
							for(i=0;i<ctr;i++)
							{
								for(j=i+1;j<ctr;j++)
								{
									if(b[i].rating>b[j].rating)
									{
										temp=b[i];
										b[i]=b[j];
										b[j]=temp;
									}
								}
							}
							printf("\nThe Lowest Rated books starts from:\n");
							for(i=0;i<ctr;i++)
							{
								printf("\n%d:\n",i+1);
								printf("\nBook Id          : %d", b[i].bookid);
				                printf("\nBook Name        : %s", b[i].bookname);
				                printf("\nBook Author      : %s", b[i].author);
				                printf("\nBook Category    : %s", b[i].category);
				                printf("\nBook Price       : %.2lf", b[i].price);
				                printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
							}
							break;
							
							default:
							printf("\nEnter Valid Choice.");		
					}
			break;
				
			case 0:
				return;
				
			default:
				printf("\nEnter Valid Choice.");		
		}
	}
}
void DisplayAllBooks(book* b)
{
	printf("\nThere are %d Books stored in the Library.\n",ctr);
	
	int i;
	if(ctr>0)
	{
		for(i=0;i<ctr;i++)
			{
				printf("\n%d:\n",i+1);
				printf("\nBook Id          : %d", b[i].bookid);
				printf("\nBook Name        : %s", b[i].bookname);
				printf("\nBook Author      : %s", b[i].author);
				printf("\nBook Category    : %s", b[i].category);
				printf("\nBook Price       : %.2lf", b[i].price);
				printf("\nBook Rating/10   : %.2lf\n", b[i].rating);
			}	
		printf("\nAll Books are Displayed.\n");
	}
	else if(ctr==0)
	{
		printf("\nPlease store few books to proceed further.\n");
	}
}
book* ResizeArray(book *b,int *size) 
{
	int additionalBooks;
	printf("\nFirstbit Library Capacity is full!\n\nEnter the number of additional books you want to store: ");
    scanf("%d", &additionalBooks);
	
	int newSize=(*size)+additionalBooks;
    b = (book *)realloc(b, newSize * sizeof(book));

    *size = newSize;
    printf("\nFirstBit Library capacity updated to store a total of %d books.\n", newSize);

    return b;
}
