#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct itemType
{
    char category[30];
    char brand[30];
    char product[50];
    float price;
    int barcode;
};
struct itemType item[100];
struct transactionType
{
    char td[13];
    char tt[11];
    int id;
    float price;
    int qty;
    int barcode;
};
struct transactionType transaction[100];
struct UserType
{
    char Name[30];
    char Role[10];
    int id;
};
struct UserType User[10];
 
FILE *fp;
 
int Inv_cnt = 0, Trn_cnt = 0, Cnt = 0, i, k, User_ID;
char tempstr[1000];
char Password[12] = "StmcPos1983";
void Search_inv();
int Read_inv();
void Print_inv();
void Print_inv_in_order(struct itemType item[], int);
void New_inv();
void Write_Inv();
void Edit_inv();
void Update_Inv();

int Read_Trn();
void Print_Trn();
void Complete_Trn(int);

int Check_User(char[30]);
void start_admin();
int Authentication();

int main()
{
    do{
		printf("Main Menu Name\n");
		printf("1. Self Help Sale\n");
		printf("2. Search an item\n");
		printf("3. Admin\n");
		printf("9. Quit\n");
		printf("Select a function: ");
		gets(tempstr);
        if(strcmp(tempstr, "1") == 0)
        {
			// sale sub program
        }
        else if(strcmp(tempstr, "2") == 0)
        {
            Inv_cnt = Read_inv();
			Search_inv();
		}
        else if(strcmp(tempstr, "3") == 0)
        {
		    start_admin();
		}
	} while(strcmp(tempstr, "9") != 0);
	return 0;
}
void start_admin()
{
    int Access = 0;
    char tempstr[99];
	
    char Continue;
	do
    {
        if(Access == 0)
        {
            Access = Authentication();
        }
        if(Access == 1)
        {
			printf("Hello %s, id:%d\n", User[User_ID].Name, User[User_ID].id);
		    printf("Sub Menu Name\n");
		    printf("1. Inventory LIST\n");
            printf("2. Inventory LIST(Category with sorting)\n");
            printf("3. Inventory LIST(Product with sorting)\n");
            printf("4. Add New Inventory\n");
            printf("5. Edit Inventory\n");
            printf("6. Update Inventory\n");
		    printf("7. Transaction LIST\n");
		    printf("9. Quit\n");
		    printf("Select a function: ");
		    gets(tempstr);
		    if(strcmp(tempstr,"1") == 0)
            {
			    Inv_cnt = Read_inv();
			    Print_inv();
            }
            else if(strcmp(tempstr,"2") == 0)
            {
                Inv_cnt = Read_inv();
                Print_inv_in_order(item, 1);
            }
            else if(strcmp(tempstr,"3") == 0)
            {
                Inv_cnt = Read_inv();
                Print_inv_in_order(item, 0);
            }
            else if(strcmp(tempstr,"4") == 0)
            {
                Inv_cnt = Read_inv();
                New_inv();
            }
            else if(strcmp(tempstr,"5") == 0)
            {
                Edit_inv();
            }
            else if(strcmp(tempstr, "6") == 0)
            {
                Update_Inv();
            }
            else if(strcmp(tempstr,"7") == 0)
            {
                Trn_cnt = Read_Trn();
                Print_Trn();
            }
        }
        else
        {
            printf("Continue?(y/n):");
            scanf("%c", &Continue);
            fflush(stdin);
            if(Continue == 'n')
            {
                strcpy(tempstr, "9");
            }
        }
    } while(strcmp(tempstr,"9") != 0);
}
int Authentication()
{
    char Input[31];
    printf("Name/Id:");
    fgets(Input, 30, stdin);
    if(Check_User(Input) == 1)
    {
        printf("Password:");
        fgets(Input, 12, stdin);
        fflush(stdin);
        Input[11] = '\0';
        if(strcmp(Input, Password) == 0)
        {
            
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int Read_inv()
{
    fp = fopen("c:\\inventory.txt", "r");
    fgets(tempstr, 99 ,fp);
    Cnt = 0;
    while(!feof(fp))
    {
        Cnt++;
        fgets(item[Cnt].category, 99 ,fp);
        item[Cnt].category[strlen(item[Cnt].category) - 1] = '\0';
        fgets(item[Cnt].brand, 99, fp);
        item[Cnt].brand[strlen(item[Cnt].brand) -1] = '\0';
        fgets(item[Cnt].product, 99, fp);
        item[Cnt].product[strlen(item[Cnt].product) - 1] = '\0';
        fgets(tempstr, 99, fp);
        item[Cnt].price = atof(tempstr);
        fgets(tempstr, 99, fp);
        item[Cnt].barcode = atoi(tempstr);
    }
    fclose(fp);
    return Cnt - 1;
}
void Print_inv()
{
    for(i = 1;i <= Inv_cnt;i++)
    {
        printf("%d Category:%s\nBrand:%s\nProduct:%s\nPrice:$%0.2f\nBarcode:%d\n\n", i, item[i].category, item[i].brand, item[i].product, item[i].price, item[i].barcode);
    }
}
void Print_inv_in_order(struct itemType tempitem[], int sort)
{
    int pass, last, order;
    printf("Ascending or Descending(1/2):");
    gets(tempstr);
    order = atoi(tempstr);
    for(pass = 2;pass <= Inv_cnt;pass++)
    {
        if(sort == 1)
        {
            if(order == 1)
            {
                strcpy(tempitem[Inv_cnt + 1].category, tempitem[pass].category);
                strcpy(tempitem[Inv_cnt + 1].brand, tempitem[pass].brand);
			    strcpy(tempitem[Inv_cnt + 1].product, tempitem[pass].product);
			    tempitem[Inv_cnt + 1].price = tempitem[pass].price;
			    tempitem[Inv_cnt + 1].barcode = tempitem[pass].barcode;
                last = pass - 1;
                while(strcmp(tempitem[Inv_cnt + 1].category, tempitem[last].category) < 0 && last >= 1)
                {
                    strcpy(tempitem[last + 1].category, tempitem[last].category);
                    strcpy(tempitem[last + 1].brand, tempitem[last].brand);
                    strcpy(tempitem[last + 1].product, tempitem[last].product);
                    tempitem[last + 1].price = tempitem[last].price;
                    tempitem[last + 1].barcode = tempitem[last].barcode;
                    last--;
                }
                strcpy(tempitem[last + 1].category, tempitem[Inv_cnt + 1].category);
                strcpy(tempitem[last + 1].brand, tempitem[Inv_cnt + 1].brand);
                strcpy(tempitem[last + 1].product, tempitem[Inv_cnt + 1].product);
                tempitem[last + 1].price = tempitem[Inv_cnt + 1].price;
                tempitem[last + 1].barcode = tempitem[Inv_cnt + 1].barcode;
            }
		    if(order == 2)
            {
                strcpy(tempitem[Inv_cnt + 1].category, tempitem[pass].category);
			    strcpy(tempitem[Inv_cnt + 1].brand, tempitem[pass].brand);
			    strcpy(tempitem[Inv_cnt + 1].product, tempitem[pass].product);
			    tempitem[Inv_cnt + 1].price = tempitem[pass].price;
			    tempitem[Inv_cnt + 1].barcode = tempitem[pass].barcode;
                last = pass - 1;
                while(strcmp(tempitem[Inv_cnt + 1].category, tempitem[last].category) > 0 && last >= 1)
                {
                    strcpy(tempitem[last + 1].category, tempitem[last].category);
                    strcpy(tempitem[last + 1].brand, tempitem[last].brand);
                    strcpy(tempitem[last + 1].product, tempitem[last].product);
                    tempitem[last + 1].price = tempitem[last].price;
                    tempitem[last + 1].barcode = tempitem[last].barcode;
                    last--;
                }
                strcpy(tempitem[last + 1].category, tempitem[Inv_cnt + 1].category);
                strcpy(tempitem[last + 1].brand, tempitem[Inv_cnt + 1].brand);
                strcpy(tempitem[last + 1].product, tempitem[Inv_cnt + 1].product);
                tempitem[last + 1].price = tempitem[Inv_cnt + 1].price;
                tempitem[last + 1].barcode = tempitem[Inv_cnt + 1].barcode;
            }
        }
        else
        {
		    if(order == 1)
            {
                strcpy(tempitem[Inv_cnt + 1].category, tempitem[pass].category);
			    strcpy(tempitem[Inv_cnt + 1].brand, tempitem[pass].brand);
			    strcpy(tempitem[Inv_cnt + 1].product, tempitem[pass].product);
			    tempitem[Inv_cnt + 1].price = tempitem[pass].price;
			    tempitem[Inv_cnt + 1].barcode = tempitem[pass].barcode;
                last = pass - 1;
                while(strcmp(tempitem[Inv_cnt + 1].product, tempitem[last].product) < 0 && last >= 1)
                {
                    strcpy(tempitem[last + 1].category, tempitem[last].category);
                    strcpy(tempitem[last + 1].brand, tempitem[last].brand);
                    strcpy(tempitem[last + 1].product, tempitem[last].product);
                    tempitem[last + 1].price = tempitem[last].price;
                    tempitem[last + 1].barcode = tempitem[last].barcode;
                    last--;
                }
                strcpy(tempitem[last + 1].category, tempitem[Inv_cnt + 1].category);
                strcpy(tempitem[last + 1].brand, tempitem[Inv_cnt + 1].brand);
                strcpy(tempitem[last + 1].product, tempitem[Inv_cnt + 1].product);
                tempitem[last + 1].price = tempitem[Inv_cnt + 1].price;
                tempitem[last + 1].barcode = tempitem[Inv_cnt + 1].barcode;
            }
		    if(order == 2)
            {
                strcpy(tempitem[Inv_cnt + 1].category, tempitem[pass].category);
			    strcpy(tempitem[Inv_cnt + 1].brand, tempitem[pass].brand);
			    strcpy(tempitem[Inv_cnt + 1].product, tempitem[pass].product);
			    tempitem[Inv_cnt + 1].price = tempitem[pass].price;
			    tempitem[Inv_cnt + 1].barcode = tempitem[pass].barcode;
                last = pass - 1;
                while(strcmp(tempitem[Inv_cnt + 1].product, tempitem[last].product) > 0 && last >= 1)
                {
                    strcpy(tempitem[last + 1].category, tempitem[last].category);
                    strcpy(tempitem[last + 1].brand, tempitem[last].brand);
                    strcpy(tempitem[last + 1].product, tempitem[last].product);
                    tempitem[last + 1].price = tempitem[last].price;
                    tempitem[last + 1].barcode = tempitem[last].barcode;
                    last--;
                }
                strcpy(tempitem[last + 1].category, tempitem[Inv_cnt + 1].category);
                strcpy(tempitem[last + 1].brand, tempitem[Inv_cnt + 1].brand);
                strcpy(tempitem[last + 1].product, tempitem[Inv_cnt + 1].product);
                tempitem[last + 1].price = tempitem[Inv_cnt + 1].price;
                tempitem[last + 1].barcode = tempitem[Inv_cnt + 1].barcode;
            }
        }
    }
	for(i = 1;i <= Inv_cnt;i++)
    {
        printf("%d Category:%s\nBrand:%s\nProduct:%s\nPrice:$%0.2f\nBarcode:%d\n\n", i, tempitem[i].category, tempitem[i].brand, tempitem[i].product, tempitem[i].price, tempitem[i].barcode);
    }
}
void New_inv()
{
    char Continue;
    do
    {
        printf("Item's Category(Max15):");
        fgets(item[Inv_cnt + 1].category, 15, stdin);
        item[Inv_cnt + 1].category[strlen(item[Inv_cnt + 1].category) - 1] = '\0';
        printf("Item's Brand(Max30):");
        fgets(item[Inv_cnt + 1].brand, 30, stdin);
        item[Inv_cnt + 1].brand[strlen(item[Inv_cnt + 1].brand) - 1] = '\0';
        printf("Item's Product(Max50):");
        fgets(item[Inv_cnt + 1].product, 50, stdin);
        item[Inv_cnt + 1].product[strlen(item[Inv_cnt + 1].product) - 1] = '\0';
        printf("Item's Selling Price(Max15):");
        fgets(tempstr, 15, stdin);
        item[Inv_cnt + 1].price = atof(tempstr);
        printf("Item's Barcode(Max15):");
        fgets(tempstr, 15, stdin);
        item[Inv_cnt + 1].barcode = atoi(tempstr);
        Inv_cnt++;
        printf("Continue?(y/n)");
        scanf("%c", &Continue);
        fflush(stdin);
    } while(Continue == 'y');
    Write_Inv();
}
void Write_Inv()
{
    fp = fopen("c:\\inventory.txt", "w");
    fprintf(fp, "#category,brand,product,price,barcode\n");
    for(i = 1;i <= Inv_cnt;i++)
    {
        fprintf(fp, "%s\n", item[i].category);
        fprintf(fp, "%s\n", item[i].brand);
        fprintf(fp, "%s\n", item[i].product);
        fprintf(fp, "%0.1f\n", item[i].price);
        fprintf(fp, "%d\n", item[i].barcode);
    }
    fclose(fp);
    printf("New Inventory\n");
    Print_inv();
}
void Search_inv()
{
	char Continue, Search[50];
	int Found[Inv_cnt], l, Flag;
	do
	{
		l = 0;
        for(i = 0;i < Inv_cnt;i++)
        {
            Found[i] = 0;
        }
		printf("What item do you want to search:");
		fgets(Search, 50, stdin);
		Search[strlen(Search) - 1] = '\0';
		for(i = 1;i <= Inv_cnt;i++)
		{
			k = 0;
			Flag = 0;
			while(k < strlen(item[i].product) && Flag == 0)
			{
				strncpy(tempstr, item[i].product + k, strlen(Search));
                tempstr[strlen(Search)] = '\0';
				if(strcmp(tempstr, Search) == 0)
				{
					Found[l] = i;
					l++;
					Flag = 1;
				}
                k++;
			}
		}
		if(l == 0)
		{
			printf("No result found\n");
		}
		else
		{
            printf("Result:\n");
			for(i = 0;i < l;i++)
			{
				printf("%d.Product name:%s\n", i + 1, item[Found[i]].product);
				printf("  Price:%0.1f\n", item[Found[i]].price);
			}
		}
		printf("Continue?(y/n):");
		scanf("%c", &Continue);
		fflush(stdin);
	} while (Continue == 'y');
}
void Edit_inv()
{
    char Continue;
    int Inv_No;
    do
    {
        Inv_cnt = Read_inv();
        Print_inv();
        printf("Which Inventory do you want to change(No.):");
        fgets(tempstr, 5, stdin);
        Inv_No = atoi(tempstr);
        if(Inv_No <= Inv_cnt)
        {
            printf("Which part you want to change:(Category/Brand/Product/Price/Barcode):");
            fgets(tempstr, 15, stdin);
            tempstr[strlen(tempstr) - 1] = '\0';
            if(strcmp(tempstr, "Category") == 0 || strcmp(tempstr, "category") == 0)
            {
                printf("New Category:");
                fgets(tempstr, 30, stdin);
                tempstr[strlen(tempstr) - 1] = '\0';
                strcpy(item[Inv_No].category, tempstr);
                Write_Inv();
            }
            else if(strcmp(tempstr, "Brand") == 0 || strcmp(tempstr, "brand") == 0)
            {
                printf("New Brand:");
                fgets(tempstr, 30, stdin);
                tempstr[strlen(tempstr) - 1] = '\0';
                strcpy(item[Inv_No].brand, tempstr);
                Write_Inv();
            }
            else if(strcmp(tempstr, "Product") == 0 || strcmp(tempstr, "product") == 0)
            {
                printf("New Product:");
                fgets(tempstr, 50, stdin);
                tempstr[strlen(tempstr) - 1] = '\0';
                strcpy(item[Inv_No].product, tempstr);
                Write_Inv();
            }
            else if(strcmp(tempstr, "Price") == 0 || strcmp(tempstr, "price") == 0)
            {
                printf("New Price:");
                fgets(tempstr, 50, stdin);
                item[Inv_No].price = atof(tempstr);
                Write_Inv();
            }
            else if(strcmp(tempstr, "Barcode") == 0 || strcmp(tempstr, "barcode") == 0)
            {
                printf("New Barcode:");
                fgets(tempstr, 50, stdin);
                item[Inv_No].barcode = atoi(tempstr);
                Write_Inv();
            }
            else
            {
                printf("Invalid Input\n");
            }
        }
        printf("Continue?(y/n):");
        scanf("%c", &Continue);
        fflush(stdin);
    } while(Continue == 'y');
}
int Read_Trn()
{
    fp = fopen("c:\\transaction.txt", "r");
    fgets(tempstr, 99, fp);
    Cnt = 0;
    while(!feof(fp))
    {
        Cnt++;
        fgets(transaction[Cnt].td, 13, fp);
        transaction[Cnt].td[strlen(transaction[Cnt].td) - 1] = '\0';
        fgets(transaction[Cnt].tt, 11, fp);
        transaction[Cnt].tt[strlen(transaction[Cnt].tt) - 1] = '\0';
        fgets(tempstr, 99, fp);
        transaction[Cnt].id = atoi(tempstr);
        fgets(tempstr, 99, fp);
        transaction[Cnt].price = atof(tempstr);
        fgets(tempstr, 99, fp);
        transaction[Cnt].qty = atoi(tempstr);
        fgets(tempstr, 99, fp);
        transaction[Cnt].barcode = atoi(tempstr);
    }
    fclose(fp);
    return Cnt - 1;
}
void Print_Trn()
{
    for(i = 1;i <= Trn_cnt;i++)
    {
        printf("%d Date:%s\nTimes:%s\nId:%d\nPrice:%0.2f\nQuantity:%d\nBarcode:%d\n\n", i, transaction[i].td, transaction[i].tt, transaction[i].id, transaction[i].price, transaction[i].qty, transaction[i].barcode);
    }
}

int Check_User(char Input[30])
{
    Input[strlen(Input) - 1] = '\0';
    fp = fopen("c:\\user.txt", "r");
    fgets(tempstr, 99, fp);
    Cnt = 0;
    while(!feof(fp))
    {
        Cnt++;
        fgets(User[Cnt].Name, 30, fp);
        User[Cnt].Name[strlen(User[Cnt].Name) - 2] = '\0';
        fgets(User[Cnt].Role, 10, fp);
        User[Cnt].Role[strlen(User[Cnt].Role) - 2] = '\0';
        fgets(tempstr, 10, fp);
        User[Cnt].id = atoi(tempstr);
    }
    fclose(fp);
    for(i = 1;i <= Cnt;i++)
    {
        if(strcmp(User[i].Role, "teacher") == 0)
        {
            if(strcmp(Input, User[i].Name) == 0 || User[i].id == atoi(Input))
            {
				User_ID = i;
                return 1;
            }
        }
    }
    return 2;
}
void Update_Inv()
{
    int Flag = 1;
    transaction[Trn_cnt + 1].id = User[User_ID].id;
    printf("Price:");
    fgets(tempstr, 15, stdin);
    transaction[Trn_cnt + 1].price = atof(tempstr);
    printf("Quantity:");
    fgets(tempstr, 5, stdin);
    transaction[Trn_cnt + 1].qty = atoi(tempstr);
    printf("Barcode:");
    fgets(tempstr, 5, stdin);
    transaction[Trn_cnt + 1].barcode = atoi(tempstr);
    do
    {
         printf("Add/Decrease(A/D):");
        fgets(tempstr, 15, stdin);
        if((Flag = strcmp(tempstr, "A")) == 0)
        {
            Complete_Trn(1);
        }
        else if((Flag = strcmp(tempstr, "D")) == 0)
        {
            Complete_Trn(0);
        }
        else
        {
            printf("Invalid Input\n");
        }
    } while (Flag != 0);
}
void Complete_Trn(int Positive)
{
    
}