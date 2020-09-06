#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double ftotal=0.0;
typedef struct Node
{
	int pass;
	char name[20];
	char address[100];
	long pincode;
	struct Node *addr;
}Node;
Node *start,*temp,*curr;
struct Cart
{
	int brnd[60];
	int ids,qty;
	long prices;
	float cgst,sgst;
	double total;
	struct Cart *addr;
}*front=NULL,*ptr,*cur;
void create(char name[],int pas,char ad[],int pin)
{
	temp=malloc(sizeof(struct Node));
	strcpy(temp->name,name);
	temp->pass=pas;
	strcpy(temp->address,ad);
	temp->pincode=pin;
	temp->addr=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(curr->addr!=NULL)
		{
			curr=curr->addr;
		}
		curr->addr=temp;
	}
}
void cart(int id,char brand[60],long price,int quant)
{
	ptr=malloc(sizeof(struct Cart));
	strcpy(ptr->brnd,brand);
	ptr->qty=quant;
	ptr->prices=price;
	ptr->ids=id;
	ptr->cgst=(9.0*(ptr->prices*ptr->qty))/100.0;
	ptr->sgst=ptr->cgst;
	ptr->total=(ptr->prices*ptr->qty);
	ftotal=ftotal+ptr->total;
	if(front==NULL || front->qty < quant)
	{
		ptr->addr=front;
		front=ptr;
	}
	else
	{
		cur=front;
		while(cur->addr!=NULL && cur->addr->qty > quant)
		{
			cur=cur->addr;
		}
		ptr->addr=cur->addr;
		cur->addr=ptr;
	}
}
void display()
{
	if(front==NULL)
	{
		printf("\n**** Why is your cart empty? Take a look at some exclusive offers ****\n");
	}
	else
	{
		printf("\nProduct ID \t Product name \t\t\t\t\t Price \t Quantity \tCgst(total) \tSgst(total) \tTotal");
		cur=front;
		while(cur!=NULL)
		{
			printf("\n-------------------------------------------------------------------------------------------------------------------------------");
			if(cur->ids <200 && cur->ids>100)
			{
				printf("\n%d\t\t %s \t\t\t\t\t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
			else if(cur->ids>200 && cur->ids<300)
			{
				printf("\n%d\t\t %s \t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
			else
			{
				printf("\n%d\t\t %s \t\t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
			cur=cur->addr;
		}
		printf("\n-------------------------------------------------------------------------------------------------------------------------------");
		printf("\nYour Grand total is: %.2lf",ftotal);
	}
}
void rem(int del)
{
	if(front==NULL)
	{
		printf("\n**** Why is your cart empty? Take a look at some exclusive offers ****\n");
	}
	else
	{
		cur=front;
		while(cur!=NULL && cur->ids != del)
		{
			ptr=cur;
			cur=cur->addr;
		}
		if(cur!=NULL)
		{
			ptr->addr=cur->addr;
			printf("\nThe item %d has been removed\n",cur->ids);
			ftotal=ftotal-cur->total;
			free(cur);	
		}
		else if(ptr->addr==NULL)
		{
			printf("\nThe item you want to remove is not available in your cart!!\n");
		}
		system("pause");
	}
}
void search(int id)
{
	if(front==NULL)
	{
		printf("\n**** Why is your cart empty? Take a look at some exclusive offers ****\n");
	}
	else
	{
		cur=front;
		while(cur!=NULL && cur->ids!=id)
		{
			cur=cur->addr;
		}
		if(cur!=NULL)
		{
			printf("\nProduct ID \t Product name \t\t\t\t\t Price \t Quantity \tCgst(total) \tSgst(total) \tTotal");
			printf("\n-------------------------------------------------------------------------------------------------------------------------------");
			if(cur->ids <200 && cur->ids>100)
			{
				printf("\n%d\t\t %s \t\t\t\t\t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
			else if(cur->ids>200 && cur->ids<300)
			{
				printf("\n%d\t\t %s \t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
			else
			{
				printf("\n%d\t\t %s \t\t%ld \t\t%d \t %.2f \t%.2f \t %.2lf",cur->ids,cur->brnd,cur->prices,cur->qty,cur->cgst,cur->sgst,cur->total);
			}
		}
		else
		{
			printf("Item Not Found!!!. Check the offer on your desired product ");
		}
	}
}
