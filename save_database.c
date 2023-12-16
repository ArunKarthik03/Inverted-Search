#include "main.h"
#include <unistd.h>
int save_database(m_node **arr)
{
		int i;
		char str1[20];
		printf("\n\033[38;5;208mEnter  filename to save the database: \033[0m");
		scanf("%s",str1);

		//checking the passed file is . file or not
		if ( !(strstr(str1,"." ) ))
		{

				return FAILURE;
		}

		//checking passed file is .txt extension or not
		if ( strcmp ( strstr( str1, "." ) , ".txt" ) != 0 )
		{

				return FAILURE;
		}

		//checking the given file is empty or not
		FILE *fptr = fopen(str1 , "r");


		//if the file is empty calling the function to save the data
		if ( fptr == NULL )
		{

				hash_table_to_backup( arr, str1 );

				return SUCCESS;

		}

		//similarly checking for the size of given file
		fseek ( fptr, 0, SEEK_END );

		if ( ftell(fptr) == 0 )
		{
				fclose(fptr);

				hash_table_to_backup( arr, str1 );

				return SUCCESS;
		}
}

//function defination of saveing to backup file
int hash_table_to_backup ( m_node **arr, char *str )
{

		//opening the .txt file in write mode
		FILE *fptr = fopen ( str , "w" );

		//running for loop the check all 26 index 0f hash table
		for ( int i=0; i<27; i++ )
		{
				//checking index is empty or not
				if ( arr[i] != NULL )
				{
						//creating temp pointer and assigned to main node
						m_node *temp = arr[i];

						while ( temp )
						{
								//getting the content and saving in .txt fil

								fprintf ( fptr, "#%d;%s;%d;", i,temp->arr, temp->file_count);

								//creating subtemp pointer and assigned to sub node
								s_node *subtemp = temp->sub_link;
								while ( subtemp )
								{
										fprintf ( fptr , "%s;%d;",subtemp->file_name, subtemp->word_count);

										//updating subtemp
										subtemp = subtemp->subnode_link;
								}
								//updating temp
								temp = temp->main_link;

								fprintf(fptr,"#\n");
						}
				}

		}
		fclose(fptr);
}
