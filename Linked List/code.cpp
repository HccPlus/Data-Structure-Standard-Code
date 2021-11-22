//这是一个标准链表结构，可供《数据结构》课程的初学者进行参考。
// 
//该链表存储的数据为int型。实际应用中可能有多种或多个类型，在此处以int型为例。
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//作者e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//该结构目前并未完成，如需更多信息请等待后续更新
//
//该文件仅给出了链表前端添加、删除结点的函数。

////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

//链表结点结构
struct node
{

	//链表的存储数据
	int dat;

	//链表结点的next指针
	node* next;

	//链表结点的构造函数
	node()
	{
		dat = 0;
		next = NULL;
	}

};

//对链表进行增删改查的操作类
class LinkedList
{

private:
	
	//链表的头指针
	node* head;

	//（可选）链表的尾指针
	node* tail;

	//（可选）链表的结点数
	int num;

	//（没有尾指针时）找到链表的尾结点
	node* get_tail()
	{
		node* p = head;
		node* temp = p;

		//循环使p指向NULL  temp指向尾结点
		//若链表为空，不执行该段语句
		while (p)
		{
			p = temp->next;
			if (p)
			{
				temp = p;
			}
		}
		
		//返回尾结点指针
		return temp;
	}

	//提示运行错误
	int error()
	{
		cout << "运行出错！" << endl;
		return 0;
	}

public:

	LinkedList()
	{
		head = NULL;
		tail = NULL;
		num = 0;
	}

	~LinkedList()
	{

		//定义变量指向待删除结点
		node* p = head;
		node* temp = p;

		//循环删除结点
		//若链表为空，不执行该段语句
		while (p)
		{
			temp = p->next;
			delete p;
			p = temp;
		}

	}

	//在链表头部添加结点
	int front_push(int dat)
	{

		//申请动态内存
		node* p = new node;

		//为新建结点的dat变量赋值
		p->dat = dat;

		//使新建结点的next指针指向原head指针
		p->next = head;

		//使原head指针指向新建结点
		head = p;

		//结点数+1
		num++;

		return 0;

	}

	//在链表头部移除结点
	int front_pop()
	{
		
		//如果head不为空指针
		if (head)
		{
			//使head结点指向下一结点并删除原head结点
			node* p = head;
			head = head->next;
			delete p;
			p = NULL;
		}

		//若head为空
		else
		{
			//显示错误报告
			error();
		}

		return 0;
	}


};

int main()
{
	LinkedList list;
	return 0;
}
