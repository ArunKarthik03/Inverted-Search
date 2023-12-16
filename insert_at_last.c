#include"main.h"

//function defination 
int insert_at_last(Slist **head,char *data)
{
		//creating memory allocation for the node to store the file name
		Slist *new=malloc(sizeof(Slist));

		//checking the memory is created or not
		if(new==NULL) 
		{
				return FAILURE;
		}

		//copying the file name into the data of sigle linked list node
		strcpy(new->data,data);

		//assigning address of node with null initially
		new->link=NULL;

		//checking the head of linked list is empty or not
		if(*head==NULL)
		{
				*head=new; //updating head
				return SUCCESS; 
		}

		//creating temp pointer and assigned with head
		Slist *temp=*head;

		//running while loop til temp of link reach's null and the loop is to check the duplicate file name in the list
		while(temp->link)
		{
				//compare the filename with linked list data
				if(strcmp(temp->data,data)==0)
				{
						return FAILURE;
				}
				temp=temp->link; //updating temp
		}

		//if data not matched in the list,then create new node and update the data and link part
		if(strcmp(temp->data,data)!=0)
		{
				temp->link=new; //updating temp of link with new node address
				return SUCCESS;
		}
		else
		{
				return SUCCESS;
		}

}
