#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "onlineshopping.h"
int main() 
{
	start=NULL;
	char pass[20];
	int choice,del;
	int flag;
	char address[100];
	char name[20],ch,ch2;
	long pincode;
	char brands[15][60]={"Onelpus Nord","Samsung A71","Samsung A51","Samsung M31s","Nokia X6","Sony bravia 55 inches UHD Led             ","LG 55 inches Smart UHD OLED               ","Sony Curved TV 55 inches              ","Samsung 55 Inches Super 6 Series UHD QLED","Panasonic 43 inches Full HD Smart     ","Lg 260L Double door              ","Samsung 265L Inverter Double Door","Whirpool 292L Inverter Double Door","Haier 320L Inverter Double Door","Haier 570L Side-bySide        "};
	long price[15]={27999,30999,25999,21499,23300,63999,126990,59999,93800,59000,30690,31150,34400,40300,105000};
	int id[15]={101,102,103,104,105,201,202,203,204,205,301,302,303,304,305};
	int i,j,qty,ids;
	do
	{
		front=NULL;
		system("CLS");
		printf("\n\n\n\t\t\tEnter username:");
		scanf("%s",name);
		printf("\n\t\t\tPassword:");
		scanf("%s",pass);
		while(strlen(pass)<=7)
		{
			printf("\n\t\t\tYour password should at least contain 8 characters..");
			printf("\n\t\t\tRe-Enter your password:");
			scanf("%s",pass);
		}
		while(strlen(pass) >15)
		{
			printf("\n\t\t\tYour password should contain maximum 15 characters..");
			printf("\n\t\t\tRe-Enter your password:");
			scanf("%s",pass);
		}
		printf("\n\t\t\tEnter your address for delivery (. when done) :");
		i=-1;
		while(address[i]!='.')
		{
			i++;
			address[i]=getchar();
		}
		address[0]=' ';
		address[i]='\0';
		printf("\n\t\t\tEnter pincode:");
		scanf("%ld",&pincode);
		create(name,pass,address,pincode);
		do
		{
			system("CLS");
			printf("username:%s",temp->name);
			printf("\n\n\t\tWelcome to,");
			printf("\n---------------------- City of Electronics --------------------\n");
			printf("Categories:\n");
			printf("\t1> Mobile \n\t2> Television \n\t3> Refrigerator \n\t4> Display Your Cart \n\t5> Search Item in cart \nEnter your choice:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\n\t\t Best selling products available \n");
					printf("\nProduct ID \t Product Name \t\t Price");
					for(i=0;i<5;i++)
					{
						printf("\n-----------------------------------------------------\n");
						printf("%d \t\t %s \t\t %ld",id[i],brands[i],price[i]);
					}
					printf("\n\nEnter the Product id to add it in cart:");
					scanf("%d",&j);
					for(i=0;i<5;i++)
					{
						if(j==id[i])
						{
							flag=1;
							printf("\nEnter the Quantity Of the product:");
							scanf("%d",&qty);
							cart(id[i],brands[i],price[i],qty);
						}
					}
					if(flag!=1)
					{
						printf("\nProduct Id not found!");
					}
					break;
				case 2:
					printf("\n\t\t Best selling products available \n");
					printf("\nProduct ID \t Product Name \t\t\t\t\t Price");
					for(i=5;i<10;i++)
					{
						printf("\n----------------------------------------------------------------------\n");
						printf("%d \t\t %s \t %ld",id[i],brands[i],price[i]);
					}
					printf("\n\nEnter the Product id to add it in cart:");
					scanf("%d",&j);
					for(i=5;i<10;i++)
					{
						if(j==id[i])
						{
							flag=1;
							printf("\nEnter the Quantity Of the product:");
							scanf("%d",&qty);
							cart(id[i],brands[i],price[i],qty);
						}
					}
					if(flag!=1)
					{
						printf("\nProduct Id not found!");
					}
					break;
				case 3:
					printf("\n\t\t Best selling products available \n");
					printf("\nProduct ID \t Product Name \t\t\t\t Price");
					for(i=10;i<15;i++)
					{
						printf("\n-----------------------------------------------------------\n");
						printf("%d \t\t %s \t %ld",id[i],brands[i],price[i]);
					}
					printf("\n\nEnter the Product id to add it in cart:");
					scanf("%d",&j);
					for(i=10;i<15;i++)
					{
						if(j==id[i])
						{
							flag=1;
							printf("\nEnter the Quantity Of the product:");
							scanf("%d",&qty);
							cart(id[i],brands[i],price[i],qty);
						}
					}
					if(flag!=1)
					{
						printf("\nProduct Id not found!");
					}
					break;
				case 4:
					display();
					break;
				case 5:
					printf("Enter the Product ID to search it:");
					scanf("%d",&ids);
					search(ids);
					break;
				default:
					printf("Invailid Choice!!!");
			}
			printf("\n\nDo you want buy something more? [y/n]:");
			scanf("%s",&ch2);
		}while(ch2=='y'||ch2=='Y');
		system("CLS");
		printf("\n");
		display();
		if(front!=NULL)
		{
			lable:
			system("CLS");
			display();
			printf("\n\nDo you want to change quantity of an item from cart? [y/n]:");
			scanf("%s",&ch2);
			if(ch2=='y'||ch2=='Y')
			{
				printf("Enter the Product ID to change its quantity:");
				scanf("%d",&del);
				rem(del);
				goto lable;
			}
			int choose,bank;
			char card[12],otp[6];
			printf("\nPayment Options:\n\t1> Online payment \n\t2> Cash on delivery \nChoose your payment method:");
			scanf("%d",&choose);
			switch(choose)
			{
				case 1:
					system("CLS");
					printf("\n\n1> State Bank of India \n2> Bank of Baroda \n3> Punjab National Bank \n4> Bank of India \n5> Canara Bank \n6> Union Bank of India \n7> IDBI Bank \n8> Indian Bank \n9> Central Bank of India \n10> Syndicate Bank \n11> Axis Bank \nChoose the Bank for Payment:");
					scanf("%d",&bank);
					printf("\nEnter your Debit Card Number:");
					scanf("%s",card);
					while(strlen(card)!=12)
					{
						printf("Incorrect Debit card number!!");
						printf("\nRe-Enter the Debit card Number:");
						scanf("%s",card);
					}
					printf("Enter the sent OTP:");
					scanf("%s",otp);
					printf("Processing");
					for(i=0;i<3;i++)
					{
						printf(".");
						Sleep(1000);
					}
					printf("\nTransaction Done. You oreder will arrive in 1-2 Weeks");
					break;
				case 2:
					printf("You have choosen Cash on delivery. Your order will arrive in 1- 2 Weeks");
					break;
				default:
					printf("Choice a Valid Payment option");
			}
			printf("\nAddress:%s",temp->address);
			printf("\nPincode:%ld",temp->pincode);
		}
		printf("\n\nExit? [y/n]:");
		scanf("%s",&ch);
	}while(ch=='n'||ch=='N');
	printf("\n\n------------------- Thank you. Visit again -----------------------------");
	return 0;
}
