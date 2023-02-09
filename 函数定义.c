//分文件版本

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "shengming.h"

/*宏定义区*/ 
#define  ADMIN_password "123456" /*管理员登录密码*/
//#define infomember.txt infomember_demo.txt 
//#define library.txt library_demo.txt
//#define memberbook.txt memberbook_demo.txt
void delect_member()
{
	fflush(stdin);
	system("cls");
	while(1)
	{
		printf("请输入您要删除的用户的id:");
		char search[20];
		gets(search);
		fflush(stdin);
		FILE* p1;
		MEMBER member[100];
		int number=0;
		p1=fopen("infomember.txt","r");
		while(!feof(p1))
		{
			fscanf(p1,"%s %s %s %s %s",member[number].ID,member[number].password,member[number].password_key,member[number].name,member[number].sex);
			number++;
		}
		fclose(p1);
		fflush(stdin);
		
		int n;
		for(n=0;n<number;n++)
		{
			if(strcmp(search,member[n].ID)==0)
			break;
		}
		if(n>=number)
		{
			printf("系统内没有拥有该id的用户！");
			system("pause");
			break; 
		}
		else
		{
			int i;
			for(i=n;i<number-1;i++)
			{
				member[i]=member[i+1];
			}
			number--;
		}
		char choice;
		printf("是否保存该条修改？(y/n)");
		choice=getch();
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N') choice=getch();
		printf("%c\n",choice);
		
		if(choice=='n'||choice=='N')
		{
			printf("该次修改保存失败！"); 
		 } 
		 else
		 {
		 	p1=fopen("infomember.txt","w");
		 	int i;
		 	for(i=0;i<number;i++)
		 	{
		 		fprintf(p1,"%s %s %s %s %s",member[number].ID,member[number].password,member[number].password_key,member[number].name,member[number].sex);
			}
			fclose(p1);
			printf("修改保存成功！\n");
		 }
		 
		 printf("是否再次删除用户？(y/n)");
		 choice=getch();
		 while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!=
		 'N') choice=getch();
		 printf("%c\n",choice);
		 
		 if(choice=='n'||choice=='N')
			break; 
		 else
			continue;	
	}
	
	
}


void search_member()
{
	fflush(stdin);
	system("cls");
	while(1)
	{
		printf("请输入您要查找的用户的id:");
		char search[20];
		gets(search);
		fflush(stdin);
		FILE* p1;
		p1=fopen("infomember.txt","r");
		MEMBER member[100];
		
		int number=0;
		while(!feof(p1))
		{
			fscanf(p1,"%s %s %s %s %s\n",member[number].ID,member[number].password,
				member[number].password_key,member[number].name,member[number].sex);
				
			number++;
		}
		int n;
		for(n=0;n<number;n++)
		{
			if(strcmp(search,member[n].ID)==0)
				break;
		}

		if(n>=number)
		{
			printf("系统中没有拥有该id的用户！\n");
			system("pause");
			break;
		}
		else
		{
			//输出信息 	
		    printf("\n");
			printf("|---------------------------用户信息-------------------------|\n");
    		printf("|姓名        性别      ID              密码                  |\n");
    		printf("|%-12s%-10s%-16s%-22s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
   			printf("|                                                            |\n");
    		printf("|----------------------------图书借阅信息--------------------|\n");
      		printf("|编号  书名        作者      出版社          类别    单价    |\n");
      		
      		FILE* p3;
      		p3=fopen("memberbook.txt","r");
			int booknumber=0;
			BOOKGRASP bookgrasp[100];
			while(!feof(p3))
			{
				fscanf(p3,"%s %s %s %s %s %f %s\n",
						bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
						bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
				booknumber++;
			}
			fclose(p3);
			if(bookgrasp[0].price<=1e-8)
			{
				printf("当前图书馆未有任何借书信息\n");
				system("pause");
			}
      		else
      		{
	      		int i=0; 
	      		while(i<booknumber)
	       		{
	        		if(strcmp(bookgrasp[i].account,search)==0)
	        		{
						printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[i].number,
						bookgrasp[i].name,bookgrasp[i].author,bookgrasp[i].press,
						bookgrasp[i].category,bookgrasp[i].price);
					}
	        		i++;
	      		}
			}
    					
			
		}

		printf("\n是否继续查找用户(y/n):");
		fflush(stdin);
		char choice;
		choice=getch();
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N') choice=getch();
		putchar(choice);
		puts("");
		
		if(choice=='y'||choice=='Y') continue;
		else break; 
		
	}
	
	
}



int user_account(char account[20])
{
	FILE *p2,*p3;
	int n,number,booknumber,flag=0,i,flag2=1,count=0;
	int flag3=0,flag4=0,flag5=0;//修改名字，性别，密匙 
	char new_password[20],key[30],choice;
	char new_name[20],new_sex[20];
	MEMBER member[100];
	BOOKGRASP bookgrasp[100];
	system("cls");
	
	p2=fopen("infomember.txt","r");	
	number=0;	
	while(!feof(p2))
	{
		
		number++;
	}
	fclose(p2);
	
	p3=fopen("memberbook.txt","r");
			booknumber=0;
			while(!feof(p3))
			{
				fscanf(p3,"%s %s %s %s %s %f %s\n",
						bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
						bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
				booknumber++;
			}
			fclose(p3);
			if(bookgrasp[0].price<=1e-8)
			{
				printf("当前图书馆未有任何借书信息");
				flag=0;
				printf("\n\n按任意键返回!\n");
   				getch();
			}
			else{ 		
				for(n=0;n<number;n++)
					if(strcmp(member[n].ID,account)==0)
					{
						i=0;
						printf("\n");
						printf("|---------------------------个人信息-------------------------|\n");
    					printf("|姓名        性别      ID              密码                  |\n");
    					printf("|%-12s%-10s%-16s%-22s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
    					printf("|                                                            |\n");
    					printf("|----------------------------图书借阅信息--------------------|\n");
      					printf("|编号  书名        作者      出版社          类别    单价    |\n");
      		
      					while(i<booknumber)
       				 	{
        					if(strcmp(bookgrasp[i].account,account)==0)
        					{
							printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[i].number,
									bookgrasp[i].name,bookgrasp[i].author,bookgrasp[i].press,
									bookgrasp[i].category,bookgrasp[i].price);
							count++;
							}
        					i++;
        				}
        				if(strcmp(member[n].sex,"male")==0) 
       				 	printf("\n%s先生，您当前借阅的书籍共有%d本。",member[n].name,count);
        				else if(strcmp(member[n].sex,"female")==0)
        				printf("\n%s女士，您当前借阅的书籍共有%d本。",member[n].name,count);
        				else
						printf("\n%s，您当前借阅的书籍共有%d本。",member[n].name,count); 
        				
						if(bookgrasp[0].price<=1e-8) 
       				 	printf("\n而图书馆内共有0本书籍正在被借阅。\n");
       				 	else
       				 	printf("\n而图书馆内共有%d本书籍正在被借阅。\n",booknumber);
        			//*******修改资料********	
        				//修改密码 
						printf("\nPS:是否需要修改密码(y/n):");
						fflush(stdin);
						choice=getch();
						while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   					choice=getch();
						printf("%c",choice);
						printf("\n");
						if(choice=='Y'||choice=='y')
						{
							printf("\n请输入修改密码的密钥(user_key):");
							fflush(stdin);
							gets(key);
							if(strcmp(member[n].password_key,key)==0)
							{
								printf("请输入新密码：");
								fflush(stdin);
								gets(new_password);
								strcpy(member[n].password,new_password);
								flag=1;
								p2=fopen("infomember.txt","w");
            					for(n=0;n<number;n++)
            					fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
										member[n].password_key,member[n].name,member[n].sex);
           						fclose(p2);
           					}
           					else
           						printf("\n输入密钥错误!"); 
						}
						else
							flag=0; 
							
						//修改名字
						 printf("\nPS:是否需要修改名字(y/n):");
						fflush(stdin);
						choice=getch();
						while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   					choice=getch();
						printf("%c",choice);
						printf("\n");
						if(choice=='Y'||choice=='y')
						{
								printf("请输入新名字：");
								fflush(stdin);
								gets(new_name);
								strcpy(member[n].name,new_name);
								flag3=1;
								p2=fopen("infomember.txt","w");
            					for(n=0;n<number;n++)
            					fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
										member[n].password_key,member[n].name,member[n].sex);
           						fclose(p2);
           					
						}
						else
							flag3=0; 
						//修改性别
						 printf("\nPS:是否需要修改性别(y/n):");
						fflush(stdin);
						choice=getch();
						while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   					choice=getch();
						printf("%c",choice);
						printf("\n");
						if(choice=='Y'||choice=='y')
						{
								printf("请输入新性别：");
								fflush(stdin);
								gets(new_sex);
								strcpy(member[n].sex,new_sex);
								flag4=1;
								p2=fopen("infomember.txt","w");
            					for(n=0;n<number;n++)
            					fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
										member[n].password_key,member[n].name,member[n].sex);
           						fclose(p2);
           					
						}
						else
							flag4=0;  
						
    				}
    					
    			}		 
   	if(flag==1||flag3==1||flag4==1)
   		{
		    if(flag==1)printf("\n密码修改成功！"); 
		    if(flag3==1) printf("\n名字修改成功！");
		    if(flag4==1) printf("\n性别修改成功！");
		    printf("\n按任意键返回!\n");
   			getch();
		    return 1;
		}
    else
	{
   		return 0;
	}
}

void display_memberbook()/*查看所有图书借阅信息函数*/
{
	FILE *p3;
	BOOKGRASP bookgrasp[100];
	int booknumber,n;
	system("cls");
	
	p3=fopen("memberbook.txt","r");
	booknumber=0;
	while(!feof(p3))
	{
		fscanf(p3,"%s %s %s %s %s %f %s\n",
				bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
				bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
		booknumber++;
	}
	if(bookgrasp[0].price==0.0)
		printf("当前没有借阅信息");
	else{ 
	printf("当前共有%d位会员借阅书籍。",booknumber);
	printf("\n");
   	printf("|---------------------------借阅图书信息-----------------------------------|\n");
   	printf("|编号  书名        作者      出版社          类别    单价    借阅ID        |\n");
   	printf("|                                                                          |\n");
    for(n=0;n<booknumber;n++)		
       	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-14s|\n",bookgrasp[n].number,
				bookgrasp[n].name,bookgrasp[n].author,bookgrasp[n].press,
				bookgrasp[n].category,bookgrasp[n].price,bookgrasp[n].account); 
	} 
	printf("\n\n输入任意键返回...");
	fflush(stdin);
	getch(); 
} 

int check_repeat_ID(char *id_account)/*查重函数*/ 
{
	FILE *p2;
	MEMBER member[100];
	int flag1=0,flag2=1,n,number;
	
    p2=fopen("infomember.txt","r");
   	number=0;
    while(!feof(p2))
    {
        fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
       	number++;
    }
    fclose(p2);
	for(n=0;n<number;n++)
    	if(strcmp(member[n].ID,id_account)==0)
    	{
    	    flag1=1;
			break;
		}
		if(flag1)
		{
			return 1;
   		}
   		else{
            return 0;
		}
}

void password_circle()/*画框函数*/ 
{
	system("cls");
	printf("\n\n\n\t\t\t***================================*** \n");
	printf("\t\t\t                                   \n");
	printf("\t\t\t   账户 (account):");
}

int member_log_in(char account[15])/*会员登录函数*/
{
	FILE *p2;
	MEMBER member[100];
	char choice1,choice2;
	int flag1=0,flag2=1,n,k=3;
	int number;
	
    p2=fopen("infomember.txt","r");
   	number=0;
    while(!feof(p2))
    {
        fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
       	number++;
    }
    fclose(p2);
	for(n=0;n<number;n++)
    	if(strcmp(member[n].ID,account)==0)
    	{
    	    flag1=1;
			break;
		}
		if(flag1)
		{
			while(flag2)
			{
				if(compare_password(member[n].password))/* 调用会员密码比对函数 */ 
				{ 
					printf("\n\n\n\t\t\t   核对正确！正在进入会员界面...");
					clock_delay();
      	       	 	return 1;
				}
				else{
					--k;/*密码输入次数count*/ 
					if(k!=0)
					{
						printf("\n\n\n\t\t\t   您的密码输入有误!还有%d次机会重新输入密码！",k);
						printf("\n\t\t\t   您是否要继续输入密码(y/n):");
						fflush(stdin);
						choice1=getch();
						while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
      	    				choice1=getch();
      					printf("%c",choice1);
						printf("\n");
						if(choice1=='Y'||choice1=='y')
							flag2=1;
						else
							return 0;
					}
					else{
						printf("\n\n\t\t\t   您输入次数已用完！按任意键退出...");
						fflush(stdin);
   						getch(); 
              	 		return 0;
					}	
				}		
			}
			flag2=1;
   		}
   		else{
   			printf("\n\n\n\t\t\t  该ID还未注册,是否需要注册会员(y/n):");
			choice2=getch();
			while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
      	    	choice2=getch();
      	    printf("%c",choice2);
      	    printf("\n");
      	    if(choice2=='Y'||choice2=='y')
			{
				member_log_up();
				return 2; 
			}
			else
				return 0; 
		}
}

void member_log_up()
{
	char choice1,choice2;
	int flag=1; 
	FILE *p2;
	MEMBER member;
	
	while(1)
	{
		system("cls");
		fflush(stdin);
	
		printf("输入您想注册的ID名:");
		gets(member.ID);
		
		if(check_repeat_ID(member.ID))
		{	
			printf("该ID已被注册！请重新注册^_^\n");
			printf("按任意键重新注册\n\n");
			getch();
			flag=1; 
		}
		else{
			flag=0;
			printf("输入您的密码(不要告知他人):");
			gets(member.password);
			
			printf("输入找回密码的密钥(以免忘记账户或密码不能登陆！):"); 
			gets(member.password_key); 
			
			printf("输入您的姓名:");
			gets(member.name);
	
			printf("输入您的性别(男士输入male,女士输入female):");
			char temp[20];
			gets(temp);
			while(strcmp(temp,"male")!=0&&strcmp(temp,"female")!=0)
			{
				printf("输入您的性别(男士输入male,女士输入female):");
				gets(temp);
			 } 
			 strcpy(member.sex,temp);
				
			strcpy(member.sex,temp);
	
			printf("是否保存这次注册信息(y/n):");
    		choice1=getch();
    		while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
      	    	choice1=getch();
      	    printf("%c",choice1);
 			printf("\n");
   	 	if(choice1=='Y'||choice1=='y')
    	{
        	p2=fopen("infomember.txt","a");
	    	fprintf(p2,"%s %s %s %s %s\n",member.ID,member.password,
					member.password_key,member.name,member.sex);
	    	fclose(p2);
			printf("\n您的账户已注册成功！\n");
    	}
    	else
    	{
       		printf("\n您的注册信息未保存!\n");
    	}
    	printf("\n是否继续注册会员(y/n):");
        choice2=getch();
        while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
      	    choice2=getch();
      	printf("%c",choice2);
      	printf("\n");
    	}
     	if(choice2=='Y'||choice2=='y'||flag==1)
        	continue;
      	else
       	 	break;
	}
}

void borrow_book(char account[20])
{
	FILE *p1,*p3;
	BOOKINFO bookinfo[100];
	char search[30],choice;
	int flag=1,n;
	int booknumber1;
	system("cls");

    while(flag)
    {
      	printf("输入要借阅的书本名:");
      	gets(search);
      	p1=fopen("library.txt","r");
      	booknumber1=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber1].number,bookinfo[booknumber1].name,bookinfo[booknumber1].author,
				bookinfo[booknumber1].press,bookinfo[booknumber1].category,
				&bookinfo[booknumber1].price,&bookinfo[booknumber1].quantity,&bookinfo[booknumber1].time);
        	booknumber1++;
        }
      	fclose(p1);
	
      	if(bookinfo[0].quantity==0)
        {
        	printf("\n书库中没有任何信息!\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber1;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
					bookinfo[n].quantity--;
					bookinfo[n].time++;
					
					p3=fopen("memberbook.txt","a");  /*借书以a追加的方式，在文件中增加一本书*/ 
					fprintf(p1,"%s %s %s %s %s %f %s\n",
							bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
							bookinfo[n].category,bookinfo[n].price,account);
					fclose(p3); 
					break;
				}
            }
        if(n>=booknumber1)
           printf("\n没有查找该书的任何信息!\n");
        else
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber1;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
					bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n借书成功!\n");
        }
   		printf("\n是否继续借书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
    }
}

void return_book(char account[20])
{
	FILE *p1,*p3;
	BOOKINFO bookinfo[100];
	BOOKGRASP bookgrasp[100];
	char search[30],choice;
	int flag=1,flag2=0,n,i,k,j,t=0;
	int booknumber,booknumber2;
	system("cls");
	
    while(flag)
    {
    	flag2=0;
    	fflush(stdin);
      	p1=fopen("library.txt","r");
      	booknumber=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        	booknumber++;
        }
      	fclose(p1);
      	
    	p3=fopen("memberbook.txt","r");
		booknumber2=0;
		while(!feof(p3))
		{
			fscanf(p3,"%s %s %s %s %s %f %s\n",
					bookgrasp[booknumber2].number,bookgrasp[booknumber2].name,bookgrasp[booknumber2].author,bookgrasp[booknumber2].press,
					bookgrasp[booknumber2].category,&bookgrasp[booknumber2].price,bookgrasp[booknumber2].account);
			booknumber2++;
		}
		fclose(p3);				
      	
		printf("您所借阅的所有图书信息如下:\n"); 
        printf("|----------------------------图书借阅信息--------------------|\n");
      	printf("|编号  书名        作者      出版社          类别    单价    |\n");
        while(t<booknumber2)
       	{
        	if(strcmp(bookgrasp[t].account,account)==0)
        	{
				printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[t].number,
						bookgrasp[t].name,bookgrasp[t].author,bookgrasp[t].press,
						bookgrasp[t].category,bookgrasp[t].price);
			}
        	t++;
        }
      	
      	printf("\n输入要归还的书本名:");
      	gets(search);
      	if(bookinfo[0].quantity==0)
        {
        	printf("\n书库中没有任何信息!\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
						bookinfo[n].quantity++;

						if(bookgrasp[0].price==0)
							printf("\n您没有借书信息。");
						else{
						for(k=0;k<booknumber2;k++)
							if(!strcmp(bookgrasp[k].account,account)&&!strcmp(bookgrasp[k].name,search))
							{
								flag2=1;
								for(i=k;i<booknumber2-1;i++)
               						bookgrasp[i]=bookgrasp[i+1];
               					booknumber2--;
               					break;
               				}
               			
						p3=fopen("memberbook.txt","w");
						for(j=0;j<booknumber2;j++)
						{
							fprintf(p3,"%s %s %s %s %s %f %s\n",
								bookgrasp[j].number,bookgrasp[j].name,bookgrasp[j].author,bookgrasp[j].press,
								bookgrasp[j].category,bookgrasp[j].price,bookgrasp[j].account);
						}
						fclose(p3);
						}
						break;
					}
				} 
        if(n==booknumber||flag2==0)
        	printf("您并没有这条借阅信息!\n"); 
        if(n<booknumber&&flag2==1)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
				bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1); 
            printf("\n还书成功！");
        }
        else
        	printf("\n还书失败！");
        
		fflush(stdin);	
   		printf("\n是否继续还书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
	}
}

void search_book()/*根据图书名称显示图书的信息*/
{
	int flag=1,flag1=1;
	char select;
    char name_compare[30]="";/*name_compare用来存放要查询的书名*/
   	char number_compare[30]=""; /*number_compare用来存放要查询的书籍编号*/
   	char author_compare[30]="";/*author_compare用来存放要查询的作者姓名*/
	char search[30]="";/*search是比对数组,将需要查找的数组读进比对数组*/
	char compare[30]="";/*compare是比对数组,将书库中的数组读进比对数组*/
    int n=0;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber=0;

    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);

	while(flag)
    {
		system("cls");
    	while(flag1)
		{
			system("cls");
			fflush(stdin);
			printf("您想通过\n\n1.<-图书编号->\n\n2.<-书名->\n\n3.<-作者名->\n\n哪种方式查询图书:");
    		select=getch();
    		printf("%c",select);
			printf("\n\n请您输入查找信息:");		
			switch(select)
			{
				case '1':gets(number_compare);strcpy(search,number_compare);flag1=0;break;
				case '2':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
				case '3':gets(author_compare);strcpy(search,author_compare);flag1=0;break;
				default :
					printf("\n不要输入菜单之外的数字~按任意键继续！");
					fflush(stdin);
            	    getch(); 
			}
		}

	flag1=1;
    if(bookinfo[0].quantity==0)
    {
    	
      	printf("书库中没有任何信息!\n\n");
      	printf("按任意键回到主菜单!\n\n");
      	getch();
      	break;
    }
    else
    {
     	for(n=0;n<booknumber;n++)
      	{
      		switch(select)
      		{
      			case '1':strcpy(compare,bookinfo[n].number);break;
      			case '2':strcpy(compare,bookinfo[n].name);break;
      			case '3':strcpy(compare,bookinfo[n].author);break;
			}
        	if(strcmp(compare,search)==0)
          	{
         		printf("|---------------------------------图书信息---------------------------------|\n");
      			printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      			printf("|                                                                          |\n");
    			printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
       			break;
			}
       	}
   			if(n>=booknumber)
       		printf("\n没有查找符合您要求的书籍!\n");
       		
      		printf("\n\n是否继续查询(y/n):");
      		choice=getch();
     		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    	choice=getch();
      		printf("%c",choice);
      		printf("\n");
      		if(choice=='Y'||choice=='y')
       			flag=1;
      		else
      			flag=0;
       		
       }
	}
}

void display_book()/*显示全部图书信息*/
{
    FILE *p1;
    int n;
    BOOKINFO bookinfo[100];
    int booknumber=0;
    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);
    printf("当前图书馆内有%d目书籍\n\n",booknumber);
    if(bookinfo[0].quantity==0)
    {
      	printf("\n没有任何图书信息!\n\n");
    }
    else
    {
      	n=0;
      	printf("|---------------------------------图书信息---------------------------------|\n");
      	printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      	printf("|                                                                          |\n");
      	while(n<booknumber)
        {
        	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
        	n++;
        }
      }
    printf("\n\n按任意键返回上一级菜单!\n");
   	getch();
}

void modify_book()/*修改图书信息*/
{
	
	int flag1=1,flag2;
	char change,choice;
	char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
   	char press[30];/*出版社*/
	char category[20];/*类别*/ 
    int  quantity;/*藏书量*/
    float price;/*单价*/
	
	char search[20];
	BOOKINFO bookinfo[100];
	int booknumber;
	
	while(1)
	{
		flag2=0;
		system("cls");
		fflush(stdin);
		FILE* p1;
		p1=fopen("library.txt","r");
		booknumber=0;
		while(!feof(p1))
		{
			fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
			booknumber++;
		}
		fclose(p1);
		
		if(bookinfo[0].quantity==0)
		{
			printf("书库中么有仍何书目！\n");
			printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
		}
		else//非空 
		{
			printf("输入要修改信息的书本名：");
			gets(search);
			int n;
			for(n=0;n<booknumber;n++)
			{
				if(strcmp(search,bookinfo[n].name)==0)
				break;
			 } 
			printf("\n");
			printf("|---------------------------------图书信息---------------------------------|\n");
      		printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      		printf("|                                                                          |\n");
    		printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                   bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            
			while(flag1)
			{
				
				printf("\n1.书籍编号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n6.书籍单价\n7.藏书量\n\n您想要修改的是:");
				change=getch();
				while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5'&&change!='6'&&change!='7')
  					change=getch();
  				printf("%c",change);
  				
          		printf("\n请输入新的字条:");
          		fflush(stdin);	
           		switch(change)
           		{
           			case '1':gets(number);flag1=0;flag2=check_repeat_book(number);
           						if(!flag2) strcpy(bookinfo[n].number,number);break;
           			case '2':gets(name);strcpy(bookinfo[n].name,name);flag1=0;break;
           			case '3':gets(author);strcpy(bookinfo[n].author,author);flag1=0;break;
            		case '4':gets(press);strcpy(bookinfo[n].press,press);flag1=0;break;
            		case '5':gets(category);strcpy(bookinfo[n].category,category);flag1=0;break;
            		case '6':scanf("%f",&price);bookinfo[n].price=price;flag1=0;break;
           			case '7':scanf("%d",&quantity);bookinfo[n].quantity=quantity;flag1=0;break;
           			default:break;	
				}
			}
			flag1=1;
			
			if(n>=booknumber)
			{
				printf("\n没有查找该书的任何信息!");
			}
			else if(!flag2)
			{//写入 
				p1=fopen("library.txt","w");
				for(n=0;n<booknumber;n++)
				fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
					bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            	fclose(p1);
            	printf("\n修改成功!");
			}
			 else
        	printf("您想修改的图书信息与馆内信息重复。"); 
   		
		   printf("\n是否继续进行修改(y/n):");
        	choice=getch();
        	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
			printf("%c",choice);
      		printf("\n");
        	if(choice=='Y'||choice=='y')
            	continue;
        	else
            	break;
			         	   
		}
		
			
	}
}

void delete_book()/*根据图书名称对图书信息进行删除*/
{
	char choice;
	BOOKINFO bookinfo[100];
	char search[20];
	FILE* p1;
	int booknumber;
	system("cls");
	while(1)
	{
		p1=fopen("library.txt","r");//要在while里面 
		fflush(stdin);
		printf("请输入删除的书本名称：");
		gets(search);
		booknumber=0;
		
		//读出
		while(!feof(p1))
		{
			fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        	booknumber++;//
		 } 
		 fclose(p1);//勿忘 
		 if(bookinfo[0].quantity==0)
		 {
		 	printf("书库中没有任何信息!\n\n");
		 	system("pause");
		 	break;
		 }
		 else
		 {
		 	//定位到第几个 
		 	int i;
		 	for(i=0;i<booknumber;i++)
		 		if(strcmp(bookinfo[i].name,search)==0) break;
		 		
		 	if(i>=booknumber) printf("\n没有查找该书的任何信息！\n");
			 else
			 {
			 	printf("\n是否确认需要删除该条书目(Y/N):");
           		choice=getch();
             	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    		choice=getch();
      	    	putchar(choice);
      	    	puts("");
      	    	
      	    	if(choice=='y'||choice=='Y')
      	    	{
      	    		int j;
      	    		for(j=i;j<booknumber;j++)
      	    		{
      	    			bookinfo[j]=bookinfo[j+1];
					}
					  booknumber--;
					p1=fopen("library.txt","w");
					int i;
					for(i=0;i<booknumber;i++)
					{
						fprintf(p1,"%s %s %s %s %s %f %d %d\n",bookinfo[i].number,bookinfo[i].name,bookinfo[i].author,
						bookinfo[i].press,bookinfo[i].category,bookinfo[i].price,bookinfo[i].quantity,bookinfo[i].time);
					}
					fclose(p1);
					printf("删除成功！\n");
				}
				else
				{
					printf("该书目没有被删除！\n");
				}
			  } 
		 }
		 //判断要不要继续删除
		 printf("是否继续删除书目(y/n):");
		 choice=getch();
		 while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N') choice=getch();
		 putchar(choice);
		 puts("");
		 if(choice=='y'||choice=='Y') continue;
		 else break; 
	}
}
int check_repeat_book(char number[30])/*查重书籍编号*/
{
	BOOKINFO bookinfo[100];
	FILE* p1;
	p1=fopen("library.txt","r");
	int i=0;//计数 
	while(!feof(p1))
	{
		fscanf(p1,"%s %s %s %s %s %f %d %d\n",
			bookinfo[i].number,bookinfo[i].name,bookinfo[i].author,
			bookinfo[i].press,bookinfo[i].category,
			&bookinfo[i].price,&bookinfo[i].quantity,&bookinfo[i].time);
		i++;
	}
	fclose(p1);
	//遍历比对
	int flag=0;//判断是否重复 
	int j;
	for(j=0;j<i;j++)
	{
		if(strcmp(bookinfo[j].number,number)==0)
		{
			flag=1;
			break;
		}
	 } 
	 if(flag) return 1;
	 else return 0;
	
}
void add_book()/*输入新进的图书信息*/
{
	system("cls");
	
	char choice;//判断y/n 
	int flag=0;//判断是否添加数目
	FILE* p1;
	BOOKINFO newbook;
	
	//需要循环
	while(1)
	{
		char choice;
		flag=0;
		fflush(stdin);
		printf("请输入图书编号：");
		gets(newbook.number);
		if(check_repeat_book(newbook.number))//重复 
		{
			flag=1;
			printf("该图书编号已被使用！");
			system("pause");
		}
		else
		{
			fflush(stdin); 
			printf("请输入书名:");
			gets(newbook.name);
		
			printf("请输入作者:");
			gets(newbook.author);
		
			printf("请输入出版社:");
			gets(newbook.press);
			
			printf("请输入类别(文学/科学/理学/工学/等):");
			gets(newbook.category);
		
			printf("请输入价格:");
			scanf("%f",&newbook.price);
		
			printf("请输入馆藏量:");
			scanf("%d",&newbook.quantity);
		
			printf("请输入借阅次数(新书输入0):");
			scanf("%d",&newbook.time); 
			fflush(stdin);
			printf("是否保存该条书目(y/n):");
			
			
			choice=getch();
			while(choice!='y'&&choice!='Y'&&choice!='N'&&choice!='n') choice=getch();
			putchar(choice);
			
			if(choice=='y'||choice=='Y')
			{
				//写入文件
				p1=fopen("library.txt","a");
				fprintf(p1,"%s %s %s %s %s %f %d %d\n",newbook.number,newbook.name,newbook.author,newbook.press,
					newbook.category,newbook.price,newbook.quantity,newbook.time);
				fclose(p1);
				printf("\n该条书目已添加到library.txt文件中!\n");
			}
				else
	        {
	       		printf("\n本条书目未保存!\n");
	        }
	        
	        printf("\n\n是否继续添加书目(y/n):");
	        choice=getch();
	        while(choice!='y'&&choice!='Y'&& choice!='n'&&choice!='N')
	        	choice=getch();
	        	
	        putchar(choice);
	        puts("");
			
		}
		
		if(choice=='y'||choice=='Y'||flag==1)
		{
			continue;
		}
		else
		{
			break;
		 } 
		
	}
	return;
}

int compare_password(char password[20])/*密码比对函数 */ 
{
	int len=0;//当前已经输入密码长度 
	char compare[20],c;
	fflush(stdin);
	printf("\n\t\t\t 密码(password):");
	//输入密码 
	while( (c=getch()) !=13)//\r是将光标移到该行首位
	{
		if(c==8&&len>0)
		{
			printf("\b \b");//清除*号和错符
			len--;
			continue;
		}
		if(c!=8)
		{
			compare[len++]=c;
			putchar('*');
		}
	}
		compare[len]='\0';//末尾结束 
	//比对密码 
		if(strcmp(password,compare)==0)
		{
			printf("\a");//响铃
			return 1; 
		}
		else
		{
			printf("\a");//响铃
			return 0;
		}
		
}

void menu1()
{
	system("color E9");
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t|  * - * - * hello world - LIST * - * - * |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   管理员登录                     |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   会员登录                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   退出系统                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
void menu2()
{
	system("color BC");
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -会-员-界-面- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   查找图书信息               | |\n");
    printf("\t\t\t| *  [2]   我的资料                   * |\n");
    printf("\t\t\t| |  [3]   展示馆内所有书目           | |\n");
    printf("\t\t\t| *  [4]   退出用户界面               * |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| | - * - * - * - * - * - * - * - * - | |\n");
	printf("\t\t\t *=====================================*\n");
}
void menu3()
{
	system("color E9");
	printf("\n\n");
	printf("\t\t\t *======================================*\n");
	printf("\t\t\t| | * - * - * 管-理-员-界-面 * - * - * | |\n");
	printf("\t\t\t| *                                    * |\n");
	printf("\t\t\t| *  [1]   显示所有图书信息            * |\n");
	printf("\t\t\t| |  [2]   添加图书                    | |\n");
	printf("\t\t\t| *  [3]   删减图书                    * |\n");
	printf("\t\t\t| |  [4]   修改图书信息                | |\n");
	printf("\t\t\t| *  [5]   查找图书信息                * |\n");
	printf("\t\t\t| |  [6]   借阅图书                    | |\n");
	printf("\t\t\t| *  [7]   归还图书                    * |\n");
	printf("\t\t\t| |  [8]   查看已借出图书              | |\n");
	printf("\t\t\t| *  [9]   会员注册                    * |\n");
	printf("\t\t\t| |  [a]   会员注销                    | |\n");
	printf("\t\t\t| |  [b]   会员查找                    | |\n");
	printf("\t\t\t| *  [0]   退出管理员界面              * |\n");
	printf("\t\t\t| | - * - * - * - * -- * - * - * - * - | |\n");
	printf("\t\t\t *======================================*\n");
}
void clock_delay()
{
	clock_t tm;
	tm=clock();
    while(clock()<tm+1000);
}

