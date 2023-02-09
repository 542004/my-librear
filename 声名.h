#ifndef _MYSELF_HEAD_
#define _MYSELF_HEAD_

     /*结构体声明区*/
typedef struct bookinfo/*系统图书信息 */ 
{
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/ 
    char category[20]; /*类别*/ 
    float price;/*单价*/ 
    int  quantity;/*馆藏量*/
 	int  time;/*借书次数*/ 
}BOOKINFO;

typedef struct bookgrasp/*会员借出的书籍信息*/ 
{
	char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/ 
    char category[20]; /*类别*/ 
    float price;/*单价*/ 
 	char account[30];/*借书者ID*/
}BOOKGRASP;

typedef struct member/*会员个人信息 */ 
{ 
	char name[30];
	char ID[20];
	char password[30];
	char sex[15];	
	char password_key[30];
}MEMBER; 


#endif 



/*************   函数声名   **************/
/*菜单函数区*/
void menu1();
void menu2();
void menu3();


/*工具函数区*/
int compare_password(char password[20]);/*密码比对函数 */  
void clock_delay(); /*时间延时函数*/ 


/*会员信息系统层级函数区*/
int user_account(char account[20]);/*个人账户信息*/ //我的资料，修改资料，已借图书 
void search_book();/*根据图书名称显示图书的信息*/


/*管理员信息系统层级函数区*/

//用户管理
void member_log_up();/*用户注册函数*/
void delect_member();/*用户注销函数*/
void search_member();/*用户查找函数*/
int user_account(char account[20]);/*个人账户信息*/ /*用户修改资料函数*/

//图书管理
void add_book();/*输入新进的图书信息*/
int check_repeat_book(char number[30]);/*查重书籍编号*/
void delete_book();/*根据图书名称对图书信息进行删除*/
void search_book();/*根据图书名称显示图书的信息*/
void modify_book();/*修改图书信息*/
void display_book();/*显示全部图书信息*/
void show_member(char account[20]);

//借书管理 
void borrow_book(char account[20]);/*借书*/
void return_book(char account[20]);/*还书*/
