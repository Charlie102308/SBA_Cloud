#include <stdio.h>
#include <stdlib.h>
FILE *fp;
int i = 0, k, pass, comp, j, n, Finish = 0, storage_num = 0, count, usb_drive[100];
float storage_size[501], storage_total, total_size = 0;
char tempstr[100];
int main()
{
	//open file
	fp = fopen("c:\\files_more.txt", "r");
	while(!feof(fp))
	{
		fgets(tempstr, 5, fp);
		if(atof(tempstr) != 0)
		{
			i++;
			storage_size[i] = atof(tempstr);
		}
	}
	fclose(fp);
	//sort to ascending order
	for(pass = i - 2;pass >= 1;pass --)
	{
		for(comp = 1;comp <= pass;comp++)
		{
			if(storage_size[comp] > storage_size[comp + 1])
			{
				storage_size[0] = storage_size[comp];
				storage_size[comp] = storage_size[comp + 1];
				storage_size[comp + 1] = storage_size[0];
			}
		}
	}
	printf("Size of each files in GB:\n");
	for(n = 1;n <= i - 1;n++)
	{
		printf("%0.2f ",storage_size[n]);
	}
	printf("\n\n");
	while(Finish < i - 1)
	{
		storage_num++;
		count = 1;
		storage_total = 0;
		for(k = i - 1;k >= 1;k--)
		{
			if(storage_total + storage_size[k] <= 32 && storage_size[k] != 0)
			{
				usb_drive[count] = k;
				storage_total += storage_size[k];
				count++;
				Finish++;
			}
		}
		printf("USB %d (space used %0.3f):", storage_num, storage_total);
		for(k = 1;k < count;k++)
		{
			printf("%0.2f ",storage_size[usb_drive[k]]);
		}
		printf("\n");
		total_size += storage_total;
		for(k = 1;k < count;k++)
		{
			storage_size[usb_drive[k]] = 0;
		}
	}
	printf("Total USB drive space:%d\n",storage_num * 32);
	printf("Total files size:%0.2f\n",total_size);
	printf("Total USB space wasted:%0.2f",(float)storage_num * 32 - total_size);
    return 0;
}