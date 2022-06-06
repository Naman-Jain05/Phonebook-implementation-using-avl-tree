#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include"funct.c"


int main() //driver function
{ 
	int run=1,choice,t,pno;
	Entry e;
	profEntry pe;
	
	struct per_tree_node* head_per=NULL;
	struct prof_tree_node* head_prof=NULL;
	struct per_tree_node* per_name=NULL;
	struct prof_tree_node* prof_name=NULL;
	
	
	while(run!=0)
  	{
	
	printf("\npress\t1 to insert \t 2 to edit \t 3 to delete\n \t4 to search \t 5 to sort \t 6 to display\n"
	 "\t7 to range search\t8 to sort based on name \n\n");
	printf("enter choice:");
	scanf("%d",&choice);
	
	switch(choice)
		{
		case 1:
			printf("choose 0 for personal 1 for professional:\n");
			scanf("%d",&t);
			sc=success;
			if(t==0)
			{
				printf("enter your name,last-name,email,mobileNo:\n");
				scanf("%s",e.name);
				scanf("%s",e.last_name);
				scanf("%s",e.mail);
				scanf("%d",&pno);
				/*inserting taking phone number a main key*/
				head_per=insertNode(head_per,pno,e);
				 
				 /* also inserting based on name just for question(case) 8*/
				per_name=insert_name(per_name,pno,e);
				if(sc==fail)
				{
				 	printf("Given entry already exist\n");
				}
				else
				{
				 	printf("\npersonal Contact has been created\n");
				}
				 
			}
			else
			{
				printf("enter your name,last-name,email,address,institute,mobileNo,officeNo:\n");
				
				scanf("%s%s%s%s%s%d%d",pe.name,pe.last_name,pe.mail,pe.address,pe.institute,&pno,&pe.officeNo);
				/*inserting taking phone number a main key*/
				head_prof=profinsertNode(head_prof,pno,pe);
				
				/* also inserting based on name just for question(case) 8*/
				 prof_name=insert_prof_name(prof_name,pno,pe);
				if(sc==fail)
				{
				 	printf("Given entry already exist\n");
				}
				else
				{
				 	printf("\nprofessional Contact has been created\n");
				}
				
			}
			printf("\n");
			break;
			
		case 2:
			printf("choose 0 to edit personal 1 to edit professional:\n");
			scanf("%d",&t);
			sc=fail;
			printf("enter number(key) of contact which is to be edited:\n");
			int pNo;
			scanf("%d",&pNo);
			if(t==0)
			{
				printf("enter edited name,last-name,email:\n");
				scanf("%s",e.name);
				scanf("%s",e.last_name);
				scanf("%s",e.mail);
				edit_per(head_per,pNo,e);
				if(sc!=fail)
				{
					printf("\npersonal Contact has been edited\n");
				}
				
			}
			else
			{
				printf("enter edited name,last-name,email,address,institute,officeNo:\n");
				scanf("%s%s%s%s%s%d",pe.name,pe.last_name,pe.mail,pe.address,pe.institute,&pe.officeNo);
				edit_prof(head_prof,pNo,pe);
				if(sc!=fail)
				{
					printf("\nprofessional Contact has been edited\n");
				}
				
			}
			printf("\n");
			break;
			
		case 3:
			printf("choose 0 to delete personal 1 to delete professional:\n");
			scanf("%d",&t);
			sc=fail;
			printf("enter number whose contact has to be deleted:\n");
			int mobNo;
			scanf("%d",&mobNo);
			if(t==0)
			{
				head_per=deleteNode(head_per,mobNo);
				printf("\npersonal Contact has been deleted\n");
			}
			else
			{
				head_prof=profdeleteNode(head_prof,mobNo);
				printf("\nprofessional Contact has been deleted\n");
			}
			printf("\n");
			break;
			
		case 4:
			printf("choose 0 to search personal 1 to search professional:\n");
			scanf("%d",&t);
			sc=fail;
			printf("enter mobile number:\n");
			int mobn;
			
			scanf("%d",&mobn);
			if(t==0)
			{
				search_per(head_per,mobn);
			}
			else
			{
				search_prof(head_prof,mobn);
				
			}
			printf("\n");
			break;
			
		case 5:
			printf("choose 0 to print personal in ascending 1 print personal in descending\n"
			" choose 2 to print professional in ascending 3 print professional in descending:\n");
			scanf("%d",&t);
			sc=fail;
			if(t==0)
			{
				printf("phone-no,balance-factor,first-name,last-name,email:\n");
				per_inorder(head_per);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			else if(t==1)
			{
				printf("phone-no,balance-factor,first-name,last-name,email:\n");
				per_inorder_rev(head_per);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			else if(t==2)
			{
				printf("phone-no,balance-factor,first-name,last-name,email,address,institute,office-no:\n");
				prof_inorder(head_prof);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			else
			{
				printf("phone-no,balance-factor,first-name,last-name,email,address,institute,office-no:\n");
				prof_inorder_rev(head_prof);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			printf("\n");
			break;
			
		case 6:
			printf("choose 0 to display personal 1 to display professional:\n");
			scanf("%d",&t);
			sc=fail;
			if(t==0)
			{
				printf("phone-no,balance-factor,first-name,last-name,email:\n");
				per_inorder(head_per);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			else
			{
				printf("phone-no,balance-factor,first-name,last-name,email,address,institute,office-no:\n");
				prof_inorder(head_prof);
				if(sc==fail)
				{
					printf("\nTree is empty\n");
				}
			}
			printf("\n");
			break;
			
		case 7:
			printf("choose 0 to range search in personal 1 to range search in professional:\n");
			scanf("%d",&t);
			sc=fail;
			if(t==0)
			{
				int n1,n2;
				printf("enter num1,num2:");
				scanf("%d%d",&n1,&n2);
				printf("phone-no,height,first-name,last-name,email:\n");
				per_range(head_per,n1,n2);
				if(sc==fail)
				{
					printf("\nNo such number exist in given range\n");
				}
			}
			else
			{
				int n1,n2;
				printf("enter num1,num2:");
				scanf("%d%d",&n1,&n2);
				printf("phone-no,height,first-name,last-name,email,address,institute,office-no:\n");
				prof_range(head_prof,n1,n2);
				if(sc==fail)
				{
					printf("\nNo such number exist in given range\n");
				}
				
			}
			printf("\n");
			break;
					
		
		case 8:
			
			printf("choose 0 to display personal sorted on name 1 to display professional sorted on name:\n");
			scanf("%d",&t);
			if(t==0)
			{
				printf("phone-no,balance-factor,first-name(sorted)),last-name,email:\n");
				/* if we have inserted taking name as key in case 1 then tree would be:*/
				per_inorder(per_name);
				/*similarly if we have taken key as name we can delete,edit,search based on name also*/
			}
			else
			{
				printf("phone-no,balance-factor,first-name(sorted),last-name,email,address,institute,office-no:\n");
				/* if we have inserted taking name as key in case 1 then tree would be:*/
				prof_inorder(prof_name);
				/*similarly if we have taken key as name we can delete,edit,search based on name also*/
			}
			printf("\n");
			break;
		
		default:
			printf("\nWrong argument try next time :)\n\n");
			break;		
		}
	
    printf("press 0 to exit 1 to continue:");
    scanf("%d",&run);	
    printf("\n");
	}
	
	printf("\nThank you !!!!!!!!!!!!!!!!!!!!\n");
	return  0;
}
