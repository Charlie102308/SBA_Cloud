//simple queue
#include <stdio.h>
#include <string.h>

void 	read_data(void);
void 	print_data(void);
char	data[10][30];   // total 10 data , each data stores max 30 chars

int main() {
	
	int		option;
	int		front = 0;
	int		rear = 9;
	int		i;
	
	char	queuedata[30];

	read_data();
	print_data();
	
	do  {
		printf("(1) Enqueue / (2) Dequeue / (3) Exit =>");
		scanf("%d",&option);		
		fflush(stdin);
		
		if(option==1) {
			if(rear==9) {
				printf("* The queue is full.\n");
			} else {	
				//enqueue		
				printf("Data = > ");
				gets(queuedata);		
				strcpy(data[rear + 1],queuedata);
				rear++;
			
			}		
		} else if(option==2) {
			if(rear<0) {
				printf("* The stack is empty.\n");				
			} else 
			{
				//dequeue
				printf("Data dequeue from the queue:%s",data[front]);			
				strcpy(data[front],"");
				for(i = 0;i < rear;i++)
				{
					strcpy(data[i], data[i + 1]);
				}
				strcpy(data[rear], "");
				rear--;
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
	printf("\n\nFront\n");
	for(i=0; i<10; i++) {
		printf("%d %s\n",i,data[i]);
	}
	return;
}
