#include"main.h"

//function defination for display data base
void display_database(m_node *hash_table[])
{
		int i;
		sleep(1);
		printf("\033[1;33m[INDEX]\t\t\tWord\t\t   File_count\t\t        File_name    \t    Word_count\033[0m\n");

		//running for loop for 26 index in hash table
		for(i=0;i<=26;i++)
		{
				//checking index is null or not
				if(hash_table[i]!=NULL)
				{
						//creating main node temp pointer
						m_node *main_temp=hash_table[i];

						//running while loop till main node temp reache's null
						while(main_temp!=NULL)
						{

								printf("\033[1;32m%d\t\t\t%s\t\t\t%d\033[0m",i,main_temp->arr,main_temp->file_count);
								//creating sub node temp pointer
								s_node *sub_temp=main_temp->sub_link;

								//running while loop til sub node temp reach's null
								while(sub_temp!=NULL)
								{
										sleep(1);
										printf("\033[1;32m\t\t\t%s\t	%d\033[0m",sub_temp->file_name,sub_temp->word_count);
										printf("\n");
										//updating sub node temp
										sub_temp=sub_temp->subnode_link;
								}
								//updating main node temp
								main_temp=main_temp->main_link;
						}
				}
		}
		printf("\n");
}
