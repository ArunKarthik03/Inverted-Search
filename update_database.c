#include "main.h"
int update_database(char *word, m_node *hash_table[], Slist **backup_head) 
{
		// Check the all the index is empty to perform the update database
		for (int i = 0; i < 27; i++)
		{

				//checkking the current hash table index is empty or not
				if (hash_table[i] != NULL) 
				{
						return FAILURE; // If any element is not NULL, return failure
				}
		}

		//cretaing file pointer
		FILE *file_pointer;

		//opening the word with read mode
		file_pointer = fopen(word, "r");
		char line[100];

		//getting filepointe to line
		fgets(line, 100, file_pointer);

		//checking for ## in begining and end to confirm the backupfile
		if (line[0] != line[strlen(line) - 2]) 
		{
				printf("Enter valid file\n");
				return FAILURE;
		}

		//rewing the cursor to start of the file
		rewind(file_pointer);
		int index;
		while (fgets(line, 100, file_pointer) != NULL)
		{
				char *tok = strtok(line, "#;");
				index = atoi(tok);

				if (hash_table[index] == NULL) 
				{
						// Allocate memory for a new mainnode and set its values
						m_node *main = malloc(sizeof(m_node));

						//updating main node content's
						tok = strtok(NULL, "#;");
						strcpy(main->arr, tok);
						tok = strtok(NULL, "#;");
						int fc = atoi(tok);
						main->file_count = fc;
						main->main_link = NULL;

						// Process file and word counts for the mainnode
						for (int i = 0; i < fc; i++)
						{
								if (i == 0)
								{
										// Handle the first subnode differently
										s_node *sub = malloc(sizeof(s_node));
										tok = strtok(NULL, "#;");
										strcpy(sub->file_name, tok);
										// Update backup_head linked list
										Slist *new = malloc(sizeof(Slist));
										strcpy(new->data, tok);
										new->link = NULL;
										*backup_head = new;
                                        
										//updating subnode content
										tok = strtok(NULL, "#;");
										int wc = atoi(tok);
										sub->word_count = wc;
										sub->subnode_link = NULL;
										main->sub_link= sub;
								} 
								else
								{
										// For subsequent subnodes, find the end of the linked list and add new elements
										s_node *t3 = main->sub_link;
										while (t3->subnode_link != NULL) 
										{
												t3 = t3->subnode_link;
										}
										s_node *sub = malloc(sizeof(s_node));
										tok = strtok(NULL, "#;");
										strcpy(sub->file_name, tok);
										// Update head1 linked list
										Slist *new = malloc(sizeof(Slist));
										strcpy(new->data, tok);
										new->link = NULL;
										Slist *temp = *backup_head;
										//running while loop till temp->link reach null
										while (temp->link != NULL) 
										{
												temp = temp->link;
										}

										temp->link = new;
										tok = strtok(NULL, "#;");
										int wc = atoi(tok);
										sub->word_count = wc;
										sub->subnode_link = NULL;
										t3->subnode_link= sub;
								}
						}
						hash_table[index] = main;
				}

		}
		return SUCCESS; // Return success after updating the array and linked list


}	




