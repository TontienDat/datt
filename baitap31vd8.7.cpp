#include<stdio.h>
#define MAX 255
  main()
  {
  	char path[50];
  	FILE *fp;
  	
  	printf("\nNhap duong dan: ");
  	fflush(stdin);
  	gets(path);
	fp=fopen(path,"at");
	if(fp==NULL)
	{
		printf("\nLoi mo file");
		
	}
	else
	{
	fprintf(fp,"\nAi nhut thi toi dung nhi");
	fprintf(fp,"\nAI ma hon nua thi dung dung ba");
	fclose(fp);
	}
  	
  }
