#include"main.h"

//function defination of search database function
void search_database(m_node *hash_table[], char *word)
{
		int index;

		//converting the 1st character of the word to calculate the index value
		if(isupper(word[0])!=0)
		{
				//for upper case
				index=word[0]%65;
		}
		else
		{
				//for lower case
				index=word[0]%97;
		}
		if(!(index>=0 && index<=25))
		{
				//for special character
				index=26;
		}
		int flag=1;

		//creating main node pointer
		m_node *main_temp=hash_table[index];

		//running while loop till main node temp  reache's null
		while(main_temp)
		{
				//comparing the given word with main node word
				if(strcmp(main_temp->arr,word)==0)
				{
						flag=0;
						sleep(1);
						printf("\033[1;34mWord %s is found in %d File\033[0m\n",word,main_temp->file_count);

						//creating sub node pointer
						s_node *sub_temp=main_temp->sub_link;

						//running sub node temp till reach's null
						while(sub_temp)
						{
								sleep(1);
								printf("\033[1;34m-> Is present in the file %s with count of %d\033[0m\n",sub_temp->file_name,sub_temp->word_count);

								//updating sub node temp
								sub_temp=sub_temp->subnode_link;
						}
				}

				//updating main node temp
				main_temp=main_temp->main_link;
		}

		//checking flag,if word found then flag is equal to 0,if not flag remain's same 1
		if(flag)
		{
				sleep(1);
				printf("\033[1;31mThe word %s is not present in the database\033[0m\n",word);
		}
}
