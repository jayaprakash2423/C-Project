#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
 struct menu
{
char *item;
int cost;
}z[100];
int menu(struct menu z[100]);
void user1();
void cust();
void cart(struct menu z[100]);
void admin();
void records();
void magic(struct menu z[100]);
void totalearn();
int earnings=0,bill=0;
void main()
{
    FILE *f3;
    f3=fopen("billing.txt","w");
    fclose(f3);
    magic(z);

}
void magic(struct menu z[100])
{  
    int input1;
    int bill=0;
    z[3].item="Veg biryani";
    z[3].cost=100;
    z[1].item="Chicken Biryani";
    z[1].cost=150;
    z[2].item="Chicken curry";
    z[2].cost=90;
    z[8].item="bread salad";
    z[8].cost=50;
    z[4].item="mushroom curry";
    z[4].cost=85;
    z[5].item="chicken noodles";
    z[5].cost=80;
    z[6].item="parota";
    z[6].cost=30;
    z[7].item="munchuria";
    z[7].cost=100;
    z[0].item="Meals";
    z[0].cost=75;
    z[9].item="Shawarma Veg";
    z[9].cost=65;
    z[10].item="Shawarma non-veg";
    z[10].cost=90;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\tWELCOME TO DIGITALISED HOTEL\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t1. ADMINISTRATOR\n");
    printf("\t\t\t2. CUSTOMER\n");
    printf("\t\t\t3. ABOUT US\n");
    printf("\t\t\t4. EXIT\n");
    printf("Enter the input to choose: (from 1 to 4) \n");
    scanf("%d",&input1);
    if(input1==1)

    {
        user1();
    }
       
    else if(input1==2)
    {
        cust();
    }
    else if(input1==3)
    {
        printf("\n\nHello!Dear customer welcome to our C hotel,\nIt is completly digitalised hotel, you can access our menu at any time on our platform,you can check your bill any time, and the types of dishes available on that day .\n\n\n©CPROJECT\n\n");
        magic(z);
    }
    else if(input1==4)
    {

        printf("\n\n\nThank you for visiting our hotel.\nCome again....\n\n");
        
    }
    else
    {
        printf("Enter a proper input!\n");
       magic(z);
    }
}
void user1()
{
    char a[10]="mk",b[10]="mk",user[30],word[30];
    int V1,V2,i;
 printf("Enter the username : \n");
        scanf("%s",user);
        printf("Enter the password : \n");
        scanf("%s",word);
        V1=strcmp(user,a);
V2=strcmp(word,b);

        if(V1==0&&V2==0)
        {
system("clear");
             admin();
            
        }
        else
        {
        printf("INVALID USERNAME OR PASSWORD\n");
          magic(z);
       }
}
void admin()
{
    int input2,n,i=1,k=11,r1;
    printf("Enter the input : (from 1 to 4) \n");
    printf("1. DAILY LIST\n");
    printf("2. RECORDS\n");
    printf("3. TOTAL EARNINGS\n");
    printf("4. EXIT\n");
    scanf("%d",&input2);
    if (input2==1)
    {
   n=menu(z);
   admin();
    }
else if (input2==2)
    records();
    else if (input2==4)
    magic(z);
    else if (input2==3)
    totalearn();
    else
    {
    printf("Enter a valid input");
    magic(z);
    }
}
int menu (struct menu z[100])
{

int i;
system("clear");
printf("\t\t\t\t\tWELCOME\n\n");
printf("\t\tToday MENU\t\t\t\t\t\t\t\t%s\n\n",__DATE__);
for(i=0;i<=10;i++)
printf("%2d. %s -----%d\n",i+1,z[i].item,z[i].cost);
printf("\n");
}
void cart(struct menu z[100])
{
int a,b,j;
FILE *f2;
menu(z);
printf("Enter the serial no. of the required item in the above menu\n");
scanf("%d",&a);
printf("Enter the no of plates required\n");
scanf("%d",&b);
printf("\n MY CART\n");
f2=fopen("billing.txt","a");
printf("%s (%d * %d)---%d\n",z[a-1].item,z[a-1].cost,b,b*z[a-1].cost);
fprintf(f2,"%s  %d         %d\n",z[a-1].item,b,b*z[a-1].cost);
fclose(f2);
bill+=b*z[a-1].cost;
printf("Any Other Items Reqiured press 1 else press 2\n");
scanf("%d",&j);
if(j==1)
cart(z);
else if(j>1)
cust();
}
void cust()
{
    int n,i;
    char ch;
    FILE *fog,*f1;
    printf("1. MENU\n");
    printf("2. CART\n");
    printf("3. BILLING\n");
    printf("4. EXIT\n");
    scanf("%d",&n);
    if (n==1)

    {
    i=menu(z);
    cust();
    }
else if (n==2)
{
cart(z);
}

else if(n==3)
{
    char name[100],phone[11];
    fog=fopen("report.txt","a");
    printf("Your bill is %d\n",bill);
    earnings+=bill;
    printf("Enter your name without space : \n");
    scanf("%s",name);
    fprintf(fog,"Name : %s\t",name);
    printf("Enter your phone number : \n");
    scanf("%s",phone);
    fprintf(fog,"phone number : %s\t",phone);
    fprintf(fog,"Bill is : %d\t\n",bill);
    fclose(fog);
    system("clear");
printf("\t\t\tBILL\t\t\t\t\t\t%s\n\n\n",__DATE__);
printf("Name     quantity  price \n");
f1=fopen("billing.txt","r");
while((ch=fgetc(f1))!=EOF)
{
printf("%c",ch);
}
fclose(f1);
    printf("Thak you for shopping visit again\n\n");
    printf("Press any digit to goto to home ");
    scanf("%d",&i);
    magic(z);
}
else if (n==4)
{
    magic(z);
}
else
{
    printf("Enter a valid input");
}
}
void records()
{
    int i;
    system("clear");
    char ch;
    FILE *fp;
    fp=fopen("report.txt","r");
    if (fp==NULL)
    {
    printf("No records to display\n");
    printf("Press 1 to go to previous menu");
    scanf("%d",&i);
    if (i==1)
    {
    admin();
    }
    }
    else
    {
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    printf("\n\n");
    admin();

}
}
void totalearn()
{
    int n,k;
printf("Total earnings are : %d\n\n",earnings);
printf("press 1 to go to previous menu");
scanf("%d",&n);
if (n==1)
{
admin();
}
}
