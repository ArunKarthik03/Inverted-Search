#include"main.h"

//function defination for read and validate function
int read_and_validation(char **argv,Slist **head)
{
		//creating file pointer
		FILE *file_pointer;

		int i=1;

		//running while loop till argument value reach null
		while(argv[i]!=NULL)
		{
				//opening the respective argument value file in read mode and saving in file pointer
				file_pointer=fopen(argv[i],"r");

				//checking the file pointer having file or not
				if(file_pointer==NULL)
				{
						sleep(1);
						printf("\033[1;31mERROR : File %s not fount\033[0m\n",argv[i]);
				}

				//checking the argument value file have with .txt extenstion or not
				else if(strcmp(strstr(argv[i],"."),".txt")!=0)
				{
						sleep(1);
						printf("\033[1;31mERROR : %s is not .txt extenstion\nPlease pass files with .txt extension\033[0m\n",argv[i]);
				}

				//checking the file pointer having content or not
				else if(empty_file(file_pointer)==SUCCESS)
				{
						sleep(1);
						printf("\033[1;31mERROR : File %s is empty\033[0m\n",argv[i]); 
				}
				else
				{
						//insert at last function calling
						if(insert_at_last(head,argv[i])==SUCCESS)
						{
								sleep(1);
								printf("INFO : File %s Added to list successfully\n",argv[i]);
						}
						else
						{
								sleep(1);
								printf("\033[1;31mINFO : File with name %s already exits in the list,can't add file's with duplicate name\033[0m\n",argv[i]);
						}
				}
				i++; //incrementing i for while loop (argv)
		}
		return SUCCESS; //returning success macro
}

