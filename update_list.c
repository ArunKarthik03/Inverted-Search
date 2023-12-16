#include"main.h"
void update_list(Slist **head,Slist *backup_head)
{

		//creating t2 pointer
		Slist *t2=backup_head;
		while(t2)
		{
				//creating previous and t1 pointer
				Slist *previous=NULL;
				Slist *t1=*head;
				while(t1)
				{
						//comparing head of data with backup head of data
						if(strcmp(t1->data,t2->data)==0)
						{
								if(previous==NULL)
								{
										//updating head with temp of link and freeing the temp
										*head=t1->link;
										free(t1);

										//assiging t1 and t2
										t1=*head;
										t2=backup_head;
								}
								else
								{
										//updating previous and freeing t1
										previous->link=t1->link;
										free(t1);
										t1=previous->link;
								}
								break;
						}
						else
						{
								//updating previous and t1
								previous=t1;
								t1=t1->link;
						}
				}
				//updating t2
				t2=t2->link;
		}
}
