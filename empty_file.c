
#include"main.h"

//function defination
int empty_file(FILE *file_pointer)
{
		//using fseek function to check the file is having conten or empty
		fseek(file_pointer,0,SEEK_END);

		//using function ftell,the return macro will be sended
		if(ftell(file_pointer)==0)
		{
				return SUCCESS;
		}
		else
		{
				return FAILURE;
		}
}
