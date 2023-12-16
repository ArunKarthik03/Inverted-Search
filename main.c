/*
Name:Arun karthik k
Date:14/12/2023
Description:Inverted Search project on data structure

 */

#include"main.h"

//main function defination
int main(int argc,char **argv)
{
		//creating head pointer
		Slist *head=NULL;
		Slist *backup_head=NULL;
		int ret=0,ret1=0;

		//creating array of pointer called hash tavble
		m_node *hash_table[27]={ NULL };

		char word[50];
		int flag=0;

		//checking if condition for the argument count in the command line
		if(argc==1) 
		{
				sleep(1);
				printf("\033[1;31mInvalid input\nINFO : Please pass the files\033[0m\n");
				return FAILURE;
		}
		else
		{
				//calling read and validate function
				if(read_and_validation(argv,&head)==SUCCESS)
				{
						sleep(1);
						printf("\nINFO : Read and validation successfully completed\n");
				}
		}

		printf("\n");

		//creating temp pointer and assigned to head
		Slist *temp=head;

		//running while loop till temp reach's null
		while(temp)
		{
				sleep(1);
				printf("\033[0;35m%s\033[0m -> ",temp->data);
				temp=temp->link; //updating temp
		}
		printf("NULL\n\n");

		while(1)
		{
				sleep(1);

				//printing Main menu to perform the project
				printf("SELECT THE OPTION :\n\n1.Create database\n2.display database\n3.Search database\n4.save database\n5.update database\n6.Exit");
				printf("\n");
				int option;
				sleep(1);
				printf("Enter your option : ");
				scanf("%d",&option);

				//performing switch operationn according to user's input
				switch(option)
				{
						//if the user choice is creating the database,then case 1 is executed
						case 1:
								if(flag==0)
								{
										flag=1;

										//calling creat data base function
										create_database(&head,hash_table);
										sleep(1);
										printf("\n\033[1;32mINFO : Successfully data base created\033[0m\n");
										printf("\n");
								}
								else
								{
										printf("\n\033[0;35mWARNING : Only create and update the database is possible\033[0m\n");
								}
								break;
								//if the user choice is displaying the content in the database,then case 2 is executed		
						case 2:
								//calling display database function
								display_database(hash_table);
								break;
								//if the user choice is to serach a particular word in the database,then case 3 is execute
						case 3:
								sleep(1);
								printf("Enter the word to be searched in database : ");
								scanf("%s",word);

								//search database function calling
								search_database(hash_table,word);
								break;
						case 4:
								//if the user choice is to save the data base ,then case 4 is executed
								//save database function declaration

								ret=save_database(hash_table);
								if(ret==NOT_EMPTY_FILE)
								{
										sleep(1);
										printf("\n\033[1;31mERROR : File is not empty\033[0m\n");
								}	
								else if(ret==FAILURE)
								{
										sleep(1);
										printf("\n\033[0;31mERROR: Please pass .txt extension file\033[0m\n");
								}
								else
								{
										sleep(1);
										printf("\nINFO : Successfully data saved backup file\n\n");
								}

								break;
						case 5 :
								//if the user choice is to update the database,then case 5 is executed
								if(flag==0)
								{
										char word[20];
										printf("\n\033[38;5;208mEnter the .txt file to update the database : \033[0m");
										getchar();
										scanf("%[^\n]",word);
                                        
										if(strstr(word,".txt"))
										{
												update_database(word,hash_table,&backup_head);
												update_list(&head,backup_head);

										}
										else
										{
												printf("\n\033[1;31mERROR : Please enter .txt extemsion file\033[0m\n");
										}
								}
								else
								{
										printf("\n\033[0;35mWARNING: Hash table full,cannot perfrom update database\033[0m\n\n");
								}
								break;	
				        case 6:
								return 0;
						default:
								sleep(1);
								printf("\n\033[1;31mPlease pass the valid option above from the main menu\033[0m\n");
								printf("\n");
	        	}
		}
}




