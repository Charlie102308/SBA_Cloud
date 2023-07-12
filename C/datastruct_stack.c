//Stack
#include <stdio.h>
#include <string.h>

void 	read_data(void);
void 	print_data(void);
char	data[10][30];   // total 10 data , each data stores max 30 chars

int main()
{
	int		option;
	int		top = 9;
	char	pushdata[30];
	char	popdata[30];

	read_data();
	print_data();
	
	do  {
		option = -1; // clear value of option 
		printf("(1) Push / (2) Pop / (3) Exit =>");
		scanf("%d",&option);
		if(option==1) {
			if(top==9) {
				printf("* The stack is full.\n");
			} else {			
				printf("Data = > ");
				fflush(stdin);
				gets(pushdata);	
				top++;
				strcpy(data[top], pushdata);
			}		
		} else if(option==2) {
			if(top<0) {
				printf("* The stack is empty.\n");				
			} else {
				// Pop data
				strcpy(popdata, data[top]);
				strcpy(data[top],"");
				printf("Data popped out from the stack:%s",popdata);
				printf("\n");		
				top--;
			}
		}
		print_data();			
	} while(option !=3); // end while
	return 0;
}

void read_data() {
	int 	i;
	FILE	*fp;
	
	fp=fopen("c:\\data.txt","r");
	
	if(fp==NULL) {
		printf("Cannot open the file.");
		return;
	}
	
	for(i=0; i<10; i++) {
		fgets(data[i],29,fp);
		data[i][strlen(data[i])-1]='\0';  //remove \n and add \0
	}
	fclose(fp);
	return;
}

// print the array
void print_data() {
	int i;
	
	for(i=9; i>=0; i--) {
		printf("%d %s\n",i,data[i]);
	}
	return;
}
