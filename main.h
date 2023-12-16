#define SUCCESS 1
#define FAILURE 0
#define NOT_EMPTY_FILE -1
#define EMPTY_FILE -3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

//sturcture declaration for single linked lisr
typedef struct node
{
		char data[50];
		struct node *link;
}Slist;

//structure declaration for main node
typedef struct main_node
{
		char arr[50];
		int file_count;
		struct main_node *main_link;
		struct sub_node *sub_link;
}m_node;

//structure declaration for sub node
typedef struct sub_node
{
		int word_count;
		char file_name[20];
		struct sub_node *subnode_link;
}s_node;

//Read and validate function declaration
int read_and_validation(char **argv,Slist **head);

//Empty file function declaration
int empty_file(FILE *file_pointer);

//Insertion data function declaration 
int insert_at_last(Slist **head,char *data);

//create database function declaration
int create_database(Slist **head, m_node *hash_table[]);

//display database function declartion
void display_database(m_node *hash_table[]);

//search database function declaration
void search_database(m_node *hash_table[],char *word);

//save data base function declartaion
int save_database(m_node *hash_table[]);

//function defination of saving in back up file
int hash_table_to_backup(m_node **array,char *str);

//fuction declaration for update database
int update_database(char *,m_node *hash_table[],Slist **backup_head);

void update_list(Slist **,Slist *);



