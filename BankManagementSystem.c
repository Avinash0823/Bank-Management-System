#include<stdio.h>
#include<stdlib.h> #include<string.h> #include<windows.h> #include<math.h> 
void create();
void update(); void transaction(); void visit();
void delete(); void view_rec(); void close();
int fin_exit; struct date{ int d,m,y;

};
struct details{
char name[60]; int acc_no,age; char address[60];
long long int aadhar_no; long long int phone; char mail[40];
char acc_type[10]; float amt;
struct date aod; struct date depo; struct date draw;
}add,upd,check,rem,tran;
 
float ci (float t,float p,float r){ float CI; CI=p*pow((1+r/100),t); return(CI);
}
int main()
{	int select;


system("color 3");
printf("\n\n\t\t\t==============	<<<	ACCOUNT MANAGEMENT BANKING SYSTEM >>> ===============");
printf("\n\n\n\t\t\t===============<<< WELCOME TO THE MAIN MENU>>> ===============");
printf("\n\n\t\t[1]To Create new account"); printf("\n\t\t[2]To Do transactions");
printf("\n\t\t[3]View current status quo of existing account"); printf("\n\t\t[4]Update account info of existing account"); printf("\n\t\t[5]Delete an existing account"); printf("\n\t\t[6]Access customer's list");
printf("\n\t\t[7]Exit the software");

printf("\n\n\n\n\n\t\tEnter your choice:"); scanf("%d",&select);
switch(select)
{
case 1:create();// break;
case 2:transaction();// break;
case 3:visit();// break;
case 4:update();// break;
case 5:delete();// break;
case 6:view_rec();//
 
break;
case 7:close();// break; system("cls");
}

return 0;
}


void create()

{
int select,v=0,a=0,d=0; FILE *ptr;
ptr=fopen("crec.dat","a+"); do{
system("cls");
printf("\t\t\t==============<<<ADDRECORD>>>==========
=====");
printf("\nCreate a user account number:\n"); scanf("%d",&check.acc_no);
while(fscanf(ptr,"%d %s %d/%d/%d %d %s %ld %ld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if (check.acc_no==add.acc_no)
{printf("Account no. already in use!"); create();}
}
}while(select==1); add.acc_no=check.acc_no;
printf("\nEnter the name:\n");
 
scanf("%s",add.name);
printf("\nEnter today's date(dd/mm/yyyy):\n"); scanf("%d/%d/%d",&add.depo.d,&add.depo.m,&add.depo.y); printf("\nEnter the date of birth(dd/mm/yyyy):\n"); scanf("%d/%d/%d",&add.aod.d,&add.aod.m,&add.aod.y); printf("\nEnter the age:\n");
scanf("%d",&add.age); printf("\nEnter the address:\n"); scanf("%s",add.address);
do{
printf("\nEnter the Aadhar number --<!!should not be more or less than 12 digits!!>--:\n");
scanf("%lld",&add.aadhar_no);
if(add.aadhar_no>100000000000&&add.aadhar_no<=999999999999
)
{
a++;
}
else
{
printf("Invalid	input!!!!	.\nPlease	enter	correct	Aadhar number\n");
}
}while(a==0); do{
printf("\nEnter the phone number --<!!should not be more or less than 10 digits!!>--: \n");
scanf("%lld",&add.phone);
if(add.phone>1000000000 && add.phone<=9999999999)
{ v++;}
else
{printf("Invalid	input!!!!.\nPlease	enter	correct	phone number\n");}
}while(v==0);
printf("\nEnter your Email-ID:\n"); scanf("%s",add.mail);
 
do{
printf("\nEnter the amount to deposit---------<<!!!Please enter a minimum amount of Rs:3000!!!>>	\nRs:");
scanf("%f",&add.amt); if(add.amt>3000){ d++;} else
{
printf("\nBalance is insufficient!!!.\nPlease enter	a minimum amount of Rs:3000");
}
}while(d==0);
printf("\nType	of
account:\n\t#saving\n\t#current\n\t#fixed\n\n\t(**INPUT FORMAT**)\n\nfor	example:\nif	your	choice	is	'#fixed',enter fixed\n\n\tEnter your choice:");
scanf("%s",add.acc_type);
fprintf(ptr,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);

fclose(ptr);
printf("\nAccount created successfully!"); do{
printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&fin_exit);
system("cls"); if (fin_exit==1)
main();
else if(fin_exit==0) close();
else
{
printf("\nInvalid!\a"); printf("\nPlease try again!!!!\a\a");
 
}
}while(fin_exit<0||fin_exit>1);
}
void transaction(void)
{		int select,test=0; FILE *old,*newrec;
old=fopen("crec.dat","r"); newrec=fopen("new_crec.dat","w");

printf("Enter the account no. of the customer:\n"); scanf("%d",&tran.acc_no);
while (fscanf(old,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{

if(add.acc_no==tran.acc_no)
{		test=1; if(strcmpi(add.acc_type,"fixed")==0)
{
printf("\a\a\a\n\nYOU	CANNOT	DEPOSIT	OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
main();
}
printf("\n\nDo	you	want to\n1.Deposit\n2.Withdraw\n3.check balance\n\nEnter your choice--
<1 for deposit, 2 for withdraw and 3 for balance>--:\n"); scanf("%d",&select);
if (select==1)
{
printf("Enter the amount you want to deposit:\nRs: "); scanf("%f",&tran.amt);
add.amt+=tran.amt;
 
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s
%s	%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
printf("\n\nDeposited successfully!");
}
else if(select==2)
{
printf("Enter the amount you want to withdraw:\nRs: "); scanf("%f",&tran.amt);
add.amt-=tran.amt;
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s
%s	%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
printf("\n\nWithdrawn successfully!");
}
else if(select==3)
{
printf("the	remaining	balance	in	the	account	is
:%f",add.amt);
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s
%s	%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
}

}
else
{
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a
 
dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
}
}
fclose(old); fclose(newrec); remove("crec.dat");
rename("new_crec.dat","crec.dat"); if(test!=1)
{
printf("\n\nRecord not found!!"); do{
printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&fin_exit); system("cls");
if (fin_exit==0) transaction();
else if (fin_exit==1) main();
else if (fin_exit==2) close();
else
{
printf("\nInvalid!"); }
}while(fin_exit<0||fin_exit>2);
}
else
{
do{
printf("\nEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&fin_exit);
system("cls"); if (fin_exit==1)
main();
else if (fin_exit==0) close();
 
else
printf("\n\nInvalid!!!\a\a"); printf("\nPlease try again!!\a\a");
}while(fin_exit<0||fin_exit>1);
}

}
void visit(void)
{
FILE *ptr; int test=0; int select; int n;
float time;
float intrate,rate=6.5; ptr=fopen("crec.dat","r");
printf("Do you want to check by"); printf("\n[1].Account no");
printf("\n[2].Name");
printf("\n[3].E-mail ID"); printf("\n\nEnter your choice:");

scanf("%d",&select); if (select==1)
{		printf("Enter the account number:\n"); scanf("%d",&check.acc_no);

while (fscanf(ptr,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if(add.acc_no==check.acc_no)
{		system("cls"); test=1;
 

printf("\t\t========<<<ACCOUNTINFORMATION>>>=======
====\t\t");
printf("\nUser Account number.:%d",add.acc_no); printf("\nName of the user:%s",add.name);
printf("\nDate	of	birth	:%d/%d/%d ",add.aod.d,add.aod.m,add.aod.y);
printf("\nAge:%d",add.age); printf("\nAddress:%s",add.address); printf("\n aadhar_No:%lld",add.aadhar_no); printf("\nPhone number:%lld",add.phone); printf("\n E-mail-ID:%s",add.mail);
printf("\nType Of Account:%s",add.acc_type); printf("\nAmount deposited:Rs: %.2f",add.amt); printf("\nDate	Of
Deposit:%d/%d/%d\n\n",add.depo.d,add.depo.m,add.depo.y); if(strcmpi(add.acc_type,"fixed")==0)
{
printf("Enter the time period (max 10 ys) you want your amount to be fixed deposited :\n");
scanf("%d",&n); switch(n)
{
case 1:
time=1; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+1); break;
case 2:
time=2; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+2); break;
 
case 3:
time=3; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+3); break;
case 4:
time=4; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+4); break;
case 5:
time=5; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+5); break;
case 6:
time=6; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+6); break;
case 7:
time=7; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+7); break;
case 8: time=8;
 
intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+8); break;
case 9:
time=9; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+9); break;
case 10:
time=10; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+10); break;
}
}

else if(strcmpi(add.acc_type,"saving")==0)
{
time=(1.0/12.0); rate=8;
intrate=ci(time,add.amt,rate);
printf("\n\nYou	will	get	Rs:.%.2f	as	compounded dividend %d of every month",intrate,add.depo.m);
}
else if(strcmpi(add.acc_type,"current")==0)
{printf("\n\nYou will get no interest\a\a");}
}
}
}
 
else if (select==2)
{		printf("Enter the name:\n"); scanf("%s",&check.name);
while (fscanf(ptr,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if(strcmpi(add.name,check.name)==0)
{		system("cls"); test=1;
printf("\t\t========<<<ACCOUNT
INFORMATION>>>===========\t\t");
printf("\nUser Account number.:%d",add.acc_no); printf("\nName of the user:%s",add.name);
printf("\nDate	of	birth	:%d/%d/%d ",add.aod.d,add.aod.m,add.aod.y);
printf("\nAge:%d",add.age); printf("\nAddress:%s",add.address); printf("\n aadhar_No:%lld",add.aadhar_no); printf("\nPhone number:%lld",add.phone); printf("\n E-mail-ID:%s",add.mail);
printf("\nType Of Account:%s",add.acc_type); printf("\nAmount deposited:Rs: %.2f",add.amt); printf("\nDate	Of
Deposit:%d/%d/%d\n\n",add.depo.d,add.depo.m,add.depo.y); if(strcmpi(add.acc_type,"fixed")==0)
{
printf("Enter the time period (max 10 ys) you want your amount to be fixed deposited :\n");
scanf("%d",&n); switch(n)
{
case 1:
time=1; intrate=ci(time,add.amt,rate);
 
printf("\n\nYou will get Rs:%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+1); break;
case 2:
time=2; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+2); break;
case 3:
time=3; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+3); break;
case 4:
time=4; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+4); break;
case 5:
time=5; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+5); break;
case 6:
time=6; intrate=ci(time,add.amt,rate);
 
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+6); break;
case 7:
time=7; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+7); break;
case 8:
time=8; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+8); break;
case 9:
time=9; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+9); break;
case 10:
time=10; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+10); break;
}
}
else if(strcmpi(add.acc_type,"saving")==0)
{
 
time=(1.0/12.0); rate=8;
intrate=ci(time,add.amt,rate);
printf("\n\nYou	will	get	Rs:.%.2f	as	compounded dividend %d of every month",intrate,add.depo.m);
}
else if(strcmpi(add.acc_type,"current")==0)
{printf("\n\nYou will get no interest\a\a");}
}
}
}
else if(select==3)
{
printf("Enter E-Mail-ID:\n"); scanf("%s",check.mail);
while (fscanf(ptr,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if(strcmpi(add.mail,check.mail)==0)
{		system("cls"); test=1;
printf("\t\t========<<<ACCOUNT
INFORMATION>>>===========\t\t");
printf("\nUser Account number.:%d",add.acc_no); printf("\nName of the user:%s",add.name);
printf("\nDate	of	birth	:%d/%d/%d ",add.aod.d,add.aod.m,add.aod.y);
printf("\nAge:%d",add.age); printf("\nAddress:%s",add.address); printf("\n aadhar_No:%lld",add.aadhar_no); printf("\nPhone number:%lld",add.phone); printf("\n E-mail-ID:%s",add.mail);
printf("\nType Of Account:%s",add.acc_type); printf("\nAmount deposited:Rs: %.2f",add.amt);
 
printf("\nDate	Of
Deposit:%d/%d/%d\n\n",add.depo.d,add.depo.m,add.depo.y); if(strcmpi(add.acc_type,"fixed")==0)
{	/*135*/
printf("Enter the time period (max 10 ys) you want your amount to be fixed deposited :\n");
scanf("%d",&n); switch(n)
{
case 1:
time=1; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+1); break;
case 2:
time=2; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+2); break;
case 3:
time=3; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+3); break;
case 4:
time=4; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+4); break;
 
case 5:
time=5; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+5); break;
case 6:
time=6; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+6); break;
case 7:
time=7; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+7); break;
case 8:
time=8; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+8); break;
case 9:
time=9; intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+9); break;
case 10: time=10;
 
intrate=ci(time,add.amt,rate);
printf("\n\nYou will get Rs:.%.2f as compounded
dividend	anually	on
%d/%d/%d",intrate,add.depo.d,add.depo.m,add.depo.y+10); break;
}
}

else if(strcmpi(add.acc_type,"saving")==0)
{
time=(1.0/12.0); rate=8;
intrate=ci(time,add.amt,rate);
printf("\n\nYou	will	get	Rs:.%.2f	as	compounded dividend %d of every month",intrate,add.depo.m);
}
else if(strcmpi(add.acc_type,"current")==0)
{printf("\n\nYou will get no interest\a\a");}
}
}
}


fclose(ptr); if(test!=1)
{	system("cls");
printf("\nRecord not found!!\a\a\a"); do{
printf("\n\a\aEnter 0 to terminate 0 program : "); scanf("%d",&fin_exit);
system("cls");
if (fin_exit==1) main();
else if (fin_exit==2) close();
else if(fin_exit==0) visit();
 
else
{


}
 


system("cls"); printf("\nInvalid!\a");
 

}
else
{
 
}while(fin_exit<0||fin_exit>2);
 
do{
printf("\nEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&fin_exit);
system("cls"); if (fin_exit==1)
main();
else if(fin_exit==0) close();
else
printf("\n\nInvalid!!!\a\a"); printf("\nPlease try again!!\a\a");
}while(fin_exit<0||fin_exit>1);
}
}
void update(void)
{
int select,test=0; FILE *old,*newrec;
old=fopen("crec.dat","r"); newrec=fopen("new_crec.dat","w");
printf("\nEnter the account no. of the customer whose info you want to change:\n");
scanf("%d",&upd.acc_no);
while(fscanf(old,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a
 
dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if (add.acc_no==upd.acc_no)
{	test=1;
printf("\nWhich	information	do	you	want	to
change?\n1.Address\n2.Phone\n3.E-mail\n\nEnter your choice(1 for address, 2 for phone and 3 for E-mail):\n");
scanf("%d",&select); system("cls"); if(select==1)
{printf("Enter the new address:\n"); scanf("%s",upd.address);
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,upd.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
system("cls"); printf("Changes saved!");
}
else if(select==2)
{/*24*/
printf("Enter the new phone number:\n"); scanf("%lld",&upd.phone);
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,upd.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
system("cls"); printf("Changes saved!");
}
else if(select==3)
{
printf("Enter the new E-mail:\n"); scanf("%s",upd.mail);
 
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,upd.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
system("cls"); printf("Changes saved!");
}
}
else
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);
}
fclose(old); fclose(newrec); remove("crec.dat");
rename("new_crec.dat","crec.dat");

if(test!=1)
{	system("cls");
printf("\nRecord not found!!\a\a\a");

do {
printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&fin_exit); system("cls");
if (fin_exit==1)
main();
else if (fin_exit==2) close();
else if(fin_exit==0) update();
 
else
{printf("\nInvalid!\a"); printf("\nPlease try again!!!\a\a");}
}while(fin_exit<0||fin_exit>2);
}
 
else {
do{
 


printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&fin_exit);
system("cls"); if (fin_exit==1)
main();
else if(fin_exit==0) close();
else printf("\n\nInvalid!!!\a\a");
printf("\nPlease try again!!\a\a");
 
}while(fin_exit<0||fin_exit>1);
}
}
void delete(void)
{
FILE *old,*newrec; old=fopen("crec.dat","r");
newrec=fopen("new_crec.dat","w"); int test=0;
printf("Enter the account no. of the customer you want to delete:"); scanf("%d",&rem.acc_no);
while (fscanf(old,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
if(add.acc_no!=rem.acc_no)
fprintf(newrec,"%d %s %d/%d/%d %d %s %lld %lld %s %s
%f
 
%d/%d/%d\n",add.acc_no,add.name,add.aod.d,add.aod.m,add.aod.y,a dd.age,add.address,add.aadhar_no,add.phone,add.mail,add.acc_type,a dd.amt,add.depo.d,add.depo.m,add.depo.y);

else
{test++;
printf("\nRecord deleted successfully!\n");
}
}
fclose(old); fclose(newrec); remove("crec.dat");
rename("new_crec.dat","crec.dat"); if(test==0)
{
printf("\nRecord not found!!\a\a\a"); do{
printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&fin_exit);

if (fin_exit==1) main();
else if (fin_exit==2) close();
else if(fin_exit==0) delete();
else
{printf("\nInvalid!\a");}
}while(fin_exit<0||fin_exit>2);
}
else do
{printf("\nEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&fin_exit);
system("cls"); if (fin_exit==1)
 
main();
else if(fin_exit==0) close();
else printf("\n\nInvalid!!!\a\a");
printf("\nPlease try again!!\a\a");
}while(fin_exit<0||fin_exit>1);

}//
void view_rec()
{
FILE *view; view=fopen("crec.dat","r"); int test=0;
char user[15],password[15]="qwerty"; printf("\n\n\t\tEnter the Admin password to login:"); scanf("%s",user);
if(strcmp(user,password)==0)
{
printf("\n\nPassword Match!\nLOADING.	\n");
printf("=======<<<::::ACCESS GRANTED:::>>>=======");
system("cls");
}
else{
printf("\t\t Wrong password\n"); do{
printf("Enter 0 to terminate program:"); scanf("%d",fin_exit);
if(fin_exit==1)
{
main();
}
else if(fin_exit==2)
{
close();
}
else if(fin_exit==0)
 
{ view_rec();}

else
{printf("\n\nInvalid!!!\a\a"); printf("\nPlease try again!!\a\a");}
}while(fin_exit<0||fin_exit>2);
}
printf("\nACC.	NO.\tNAME\tE-MAIL- ID\t\tADDRESS\t\tPHONE\n");
while(fscanf(view,"%d %s %d/%d/%d %d %s %lld %lld %s %s %f
%d/%d/%d\n",&add.acc_no,add.name,&add.aod.d,&add.aod.m,&add
.aod.y,&add.age,add.address,&add.aadhar_no,&add.phone,add.mail,a dd.acc_type,&add.amt,&add.depo.d,&add.depo.m,&add.depo.y)!=EO F)
{
printf("\n%d\t\t%s\t%s\t\t%s\t%lld",add.acc_no,add.name,add.mail,ad d.address,add.phone);
test++;
}

fclose(view); if (test==0)
{	system("cls");
printf("\nNO RECORDS!!\n");} do{
printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to
 
exit:");
 
scanf("%d",&fin_exit); system("cls");
if (fin_exit==1) main();
else if(fin_exit==0) close();
 
else
{
 
printf("\nInvalid!\a"); printf("\nPlease try again!!!\a\a");
}
}while(fin_exit<0||fin_exit>1);
}
void close(void)
{
printf("\n\n\n\nThis Bank management system program is brought to you by GROUP 1!");
printf("\nTHANK YOU!");
}
