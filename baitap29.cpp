#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n;
	FILE *fi;
	char path[500];
	strcpy(path,"28output.txt");
	fi=fopen(path,"rt");
	fscanf(fi,"%d",&n);
	int *p=(int *)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		fscanf(fi,"%d",&p[i]);
	}
	printf("\n cac gia tri:  \n");
	printf("%d\n",n);
	for (int i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	fclose(fi);
	free(p);
	return 0;
}
