//分文件版本


/*头文件区*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "shengming.h" 

/*宏定义区*/ 
#define  ADMIN_password "123456" /*管理员登录密码*/

int main()
{
	int flag1=1,flag2=1,flag3=1;/* flag是判断条件,flag为 1 时为真，为 0 时为假 */
	char choice1,choice2,choice3;
	FILE *p1,*p2,*p3;
	
	if((p1=fopen("library.txt","r"))==NULL)/*p1是图书管理系统的书籍信息文件指针*/
	{
		p1=fopen("library.txt","w");
		fclose(p1);
	 } 
	 if((p2=fopen("infomember.txt","r"))==NULL)/*p2是图书管理系统的会员个人信息文件指针*/
	 {
	 	p2=fopen("infomember.txt","w");
	 	fclose(p2);
	 }
	 if((p3=fopen("memberbook.txt","r"))==NULL)/*p3是图书管理系统的会员书籍信息文件指针*/
	 {
	 	p3=fopen("memberbook.txt","w");
	 	fclose(p3);
	 }
	 
	 while(flag1)
	 {
	 	system("cls");
	 	menu1();/*调出主菜单 */ 
	 	puts("");
	 	printf("请您选择（1-3）：");
		choice1=getch();
		while(choice1!='1'&&choice1!='2'&&choice1!='3') choice1=getch(); 
		printf("%c",choice1);
		fflush(stdin);//清除缓冲区
		
		if(choice1=='1')//管理员 
		{
			if(compare_password (ADMIN_password))
			{	//密码正确 
				printf("\n\n\t\t\t\t  --输入密码正确!--\n\n\t\t\t\t==正在进入管理员界面==\n");
				clock_delay(); 
				while(flag2)
				{
					system("cls");
					menu3();
					puts("");
					printf("请您选择(0-B(大小写均可)):");
					
					char c; c=choice3=getch();
					
					while(c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5'&&c!='6'&&c!='7'&&c!='8'&&c!='9'&&c!='0'&& c!='A'&&c!='a' && c!='B'&&c!='b' && c!='C'&&c!='c' )
							c=choice3=getch();
					printf("%c\n",choice3); 
					switch(choice3)
					{
						case '1':display_book();break;//显示所有图书信息 
						case '2':add_book();	break;
						case '3':delete_book();	break;
						case '4':modify_book();	break;
						case '5':search_book();	break;
						case '6'://借书 
								{
									char account[20];
									printf("请输入借书人的账号：");
									gets(account);
									borrow_book(account);
									break;
								}
						case '7':/*还书*/
								{
									char account[20];
									printf("请输入借书人的账号：");
									gets(account);
									return_book(account);
									break;
								}
						case '8':display_memberbook(); break;//借出？？？ 
						case '9':member_log_up();	break;//注册用户 
						case 'a':				
						case 'A':delect_member();	break;//注销用户
						case 'b':
						case 'B':search_member(); break;//查找用户
						case '0':flag2=0;printf("\n\t\t\t正在退出管理员界面...");
								clock_delay(); break;
						default:break;
					}
				}
			}
			else
			{
				puts("\n\n\t\t\t\t --输入密码错误！--\n");
				clock_delay();
			}
			flag2=1;//恢复原场 
		} 
		 
		else if(choice1=='2')//会员登录 (完成)
		{
			int flag=0;
			char account1[20],account_choice;//account1: 账号 
			system("cls");
			password_circle();
			fflush(stdin);
			gets(account1);//
			flag=member_log_in(account1);/*账户登录函数*/ 
			if(flag==2)//账号未注册，注册该账号了之后再次登录 
			{
				system("cls");
				password_circle();
				fflush(stdin);
				gets(account1);
				flag=member_log_in(account1);/*账户登录函数*/	
			} 
			if(flag==1)//密码正确 
			{
	    		while(flag2&&flag3)
				{
		    		system("cls");
					menu2();//！！！！！！！！！！！！！！！！！！！！！ 
		    		printf("\n");
		    		//作选择 
		    		printf("请您选择(1-8):");
		    		choice2=getch();
		    		while(choice2!='1'&&choice2!='2'&&choice2!='3'&&choice2!='4'&&choice2!='5'&&choice2!='6'&&choice2!='7'&&choice2!='8')
		  				choice2=getch();
		  			printf("%c",choice2);
		
		   			switch(choice2)
		    		{
		    			case '1':search_book(); break;//查找图书信息 
		    			case '2':user_account(account1);  break;//我的资料
		    			case '3':display_book();   break;//展示所有图书信息 
		    			case '4':flag2=0;//退出用户界面
							     printf("\n\n\t\t\t正在退出用户界面...");
		       		       	  	 clock_delay();
								 break;
						default:break;/*虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上*/
		    		}
				}
			} 	
			flag2=1,flag3=1;
		}
		
		else if(choice1=='3')//退出 
		{
			flag1=0; 
		}
		 
		
		
	 	//system("pause");//调试 
	 }
	 
	 fflush(stdin);
	 system("cls");
	 puts("你已经安全退出系统！（按任意键关闭界面） 欢迎再次使用");
	 getch();//从控制台读取一个字符，但不显示在 屏幕 上
	 
	 return 0;
}
