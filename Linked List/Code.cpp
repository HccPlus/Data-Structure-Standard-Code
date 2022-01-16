//这是一个标准链表结构，可供《数据结构》课程的初学者进行参考。
// 
//该链表存储的数据为int型。实际应用中可能有多种或多个类型，在此处以int型为例。
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//作者e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//该结构目前具有增、删、改、查等功能，
//具体功能介绍见LinkedList类中各个函数前的注释

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
		system("pause");
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
	int push_front(int dat)
	{

		//申请动态内存
		node* p = new node;

		//为新建结点的dat变量赋值
		p->dat = dat;

		//使新建结点的next指针指向原head指针
		p->next = head;

		//使原head指针指向新建结点
		head = p;

		//若为首个结点，tail指针指向该结点
		if (!tail) tail = p;

		//结点数+1
		num++;

		return 0;

	}

	//在链表头部移除结点
	int pop_front()
	{

		//如果head不为空指针
		if (head)
		{
			//使head指针指向下一结点并删除原head结点
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

		//如果移除节点后head指针为空
		if (!head)
		{
			//将尾指针置空
			tail = NULL;
		}

		num--;

		return 0;
	}

	//在链表结尾添加结点
	int push_back(int dat)
	{
		//新建结点并赋值
		node* p = new node;
		p->dat = dat;

		//如果链表不空
		if (tail)
		{

			//将尾结点的next指针只向新结点
			tail->next = p;

			//将尾结点指向新结点
			tail = p;

		}

		//如果链表为空
		else
		{

			//将头、尾结点都指向新结点
			head = p;
			tail = p;

		}

		num++;

		return 0;

	}

	//在链表结尾移除结点
	int pop_back()
	{

		//如果链表不空
		if (head)
		{

			//若链表只有一个结点
			if (num == 1)
			{
				//删除该结点并将head, tail结点置空
				delete head;
				head = NULL;
				tail = NULL;
			}

			//若链表有一个以上的结点
			else
			{

				//新建指针
				node* p = head;

				//循环使p指针指向倒数第二个结点
				while (p->next)
				{
					if (p->next == tail) break;
					p = p->next;
				}

				//删除尾结点
				delete tail;

				//将尾结点指向之前的倒数第二个结点
				tail = p;

				//将新的尾结点的next指针置空
				tail->next = NULL;

			}

		}

		//若链表为空
		else
		{
			//运行错误
			error();
		}

		num--;

		return 0;
	}

	//返回指定序号结点数据
	int get_node(int sen)
	{

		//如果序号大于链表结点数
		if (sen >= num)
		{
			//运行出错
			error();
		}

		//新建指针
		node* p = head;

		//循环是指针指向目标节点
		for (int i = 0; i < sen; i++)
		{
			p = p->next;
		}

		//返回该结点数据
		return p->dat;

	}

	//编辑指定序号的结点数据
	int edit_node(int sen, int dat)
	{

		//如果序号大于等于链表结点数
		if (sen >= num)
		{
			//运行出错
			error();
		}

		//新建指针
		node* p = head;

		//循环使指针指向待修改结点
		for (int i = 0; i < sen; i++)
		{
			p = p->next;
		}

		//修改该结点的数据
		p->dat = dat;

		return 0;
	}

	//返回输入的数据在链表中的位置（若不存在则返回-1）
	int inq(int dat)
	{

		//新建指针
		node* p = head;

		//新建返回值
		int ret = -1;

		//循环遍历链表查找是否存在该数据
		for (int i = 0; i < num; i++)
		{
			//如果该结点数据与输入数据相同
			if (p->dat == dat)
			{
				ret = i;
				break;
			}
		}

		return ret;
	}

	//返回链表结点数
	int size()
	{
		return num;
	}

	//顺序输出链表
	int print()
	{
		node* p = head;
		for (int i = 0; i < num; i++)
		{
			cout << p->dat << ' ';
			p = p->next;
		}
		cout << endl;
		return 0;
	}

};

int main()
{
	LinkedList list;
	return 0;
}
