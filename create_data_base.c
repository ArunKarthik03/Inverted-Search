
#include"main.h"

//funcction defination of create database
int create_database(Slist **head,m_node *hash_table[]) 
{
		//created file pointer
		FILE *file_pointer;

		//cretaed temp pointer nad assigned to head of list
		Slist *temp=*head;

		//running while tile temp reaches null in linked list
		while(temp)
		{
				//opening the file in read mode and saved in file pointer
				file_pointer=fopen(temp->data,"r");
				char buffer[50];
				int index,flag;

				//running while loop to scan the each words in the file and stored each word seperately in the buffer
				//running till the file content reache's end of file value[-1]
				while(fscanf(file_pointer,"%s",buffer)!=EOF)
				{
						flag=0;

						//collecting the 1st charatcter in the word and converting into upper case by using isupper function
						//here convertion is neccessary to find the index number in the hash table
						if(isupper(buffer[0])!=0)
						{
								//finding the index number by character ascii value with modules of 65
								index=buffer[0]%65;
						}
						else
						{
								//same for lower case
								index=buffer[0]%97;
						}

						//if the index value is away from the range of 0 to 25,then index is 26 for specail character
						if(!(index>=0 && index <=25))
						{
								index=26;
						}

						//checking the hash table is empty to store the word from the file
						if(hash_table[index]==NULL)
						{
								//if file empty,then creating two node
								//main node memory allocation
								m_node *main_new=malloc(sizeof(m_node));

								//checking the memory is created or not
								if(main_new==NULL)
								{
										return FAILURE;
								}

								//sub node memory allocation
								s_node *sub_new=malloc(sizeof(s_node));

								//checking the memory is allocated or not
								if(sub_new==NULL)
								{
										return FAILURE;
								}

								//updating sub node content's
								sub_new->word_count=1;
								strcpy(sub_new->file_name,temp->data);
								sub_new->subnode_link=NULL;

								//updating main node content's
								main_new->file_count = 1;
								strcpy(main_new->arr,buffer);
								main_new->main_link = NULL;
								main_new->sub_link = sub_new;

								//updating sub node content's
								hash_table[index]=main_new;
						}

						//if hash table not equal to null
						else
						{
								//creating two pinter's
								m_node *main_temp=hash_table[index];
								m_node *previous_main_temp=main_temp;

								//running while loop till the main node reach's null
								while(main_temp!=NULL)
								{
										//comparing the main node word with buffer word
										if(strcmp(main_temp->arr,buffer)==0)
										{

												//if equal,then creating 2 pointer's in sub node
												s_node *sub_temp=main_temp->sub_link;
												s_node *previous_sub_temp=sub_temp;

												//running while loop till the sun node reach's null
												while(sub_temp!=NULL)
												{
														//comparing the file name in sun node with the filename in the linked list
														if((strcmp(sub_temp->file_name,temp->data))==0)
														{
																//if the file name matched,then incrementing the word count in sub node
																sub_temp->word_count++;//incrementing word count
																flag=1;
																break;
														}
														else
														{
																//updating sub node pointer's
																previous_sub_temp=sub_temp;
																sub_temp=sub_temp->subnode_link;

														}
												}

												//if the file name is matched then we updated the count,so no need to create another sub node
												if(flag==1)
												{
														break;
												}

												//if filename doesn't mactched,then create new sub node and update to the previous sub node
												if(sub_temp==NULL)
												{
														//updating the sub node conten's
														s_node *sub_new=malloc(sizeof(s_node));
														strcpy(sub_new->file_name,temp->data);
														sub_new->word_count=1;
														sub_new->subnode_link=NULL;
														previous_sub_temp->subnode_link=sub_new;
														main_temp->file_count++;
														break;
												}
										}
										else
										{
												//updating main node pointer's
												previous_main_temp=main_temp;
												main_temp=main_temp->main_link;
										}
								}
								        //if the word doesn,t matched,then create another main node and update previous main node with new
										if(main_temp==NULL)
										{
												//updating main node content's
												m_node *main_new=malloc(sizeof(m_node));
												strcpy(main_new->arr,buffer);
												main_new->main_link=NULL;
												main_new->sub_link=NULL;
												main_new->file_count=1;

												//updating sub node content's
												s_node *sub_new=malloc(sizeof(s_node));
												strcpy(sub_new->file_name,temp->data);
												sub_new->word_count=1;
												sub_new->subnode_link=NULL;
												main_new->sub_link=sub_new;
												previous_main_temp->main_link=main_new;
										}
								}
						}
				//updating temp for linked list
				temp=temp->link;
       }
return SUCCESS;
}
