//这是一个标准循环链表结构，可供《数据结构》课程的初学者进行参考。
// 
//该链表存储的数据为int型。实际应用中可能有多种或多个类型，在此处以int型为例。
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//作者e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//该结构目前具有增删改查等功能，
//具体功能介绍见CircularLinkedList类中各个函数前的注释

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

class CircularLinkedList
{

private:

	//链表的定位指针
	node* ptr;

	//（可选）链表的结点数
	int num;

	//提示运行错误
	int error()
	{
		cout << "运行出错！" << endl;
		system("pause");
		return 0;
	}

public:

	CircularLinkedList()
	{
		ptr = NULL;
		num = 0;
	}

	~CircularLinkedList()
	{

		//定义变量指向待删除结点
		node* p = ptr;
		node* temp = p;

		//循环删除结点
		//若链表为空，不执行该段语句
		for (int i = 0; i < num; i++)
		{
			temp = p->next;
			delete p;
			p = temp;
		}

	}

	//在链表定位处添加结点
	int push(int dat)
	{

		//申请动态内存
		node* p = new node;

		//为新建结点的dat变量赋值
		p->dat = dat;

		//使新结点的next指针指向定位结点的next指针
		if (ptr) p->next = ptr->next;

		//使定位结点的next指针指向新指针
		if (ptr) ptr->next = p;

		//若为首个结点，新结点的next指针指向自己
		else p->next = p;

		//使原ptr指针指向新建结点
		ptr = p;

		//结点数+1
		num++;

		return 0;

	}

	//在链表定位处后移除结点
	int pop()
	{

		//如果只有一个结点，删除ptr并将ptr置空
		if (ptr == ptr->next)
		{
			delete ptr;
			ptr = NULL;
		}

		//如果ptr不为空指针
		else if (ptr)
		{
			//删除下一结点
			node* p = ptr->next;
			ptr->next = p->next;
			delete p;
			p = NULL;
		}

		//若ptr为空
		else
		{
			//显示错误报告
			error();
		}

		--num;

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
		node* p = ptr->next;

		//循环使指针指向目标节点
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

		//如果序号大于链表结点数
		if (sen >= num)
		{
			//运行出错
			error();
		}

		//新建指针
		node* p = ptr->next;

		//循环使指针指向待修改节点
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
		node* p = ptr->next;

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

			//访问下一个结点
			p = p->next;

		}

		return ret;
	}

	//返回链表结点数
	int size()
	{
		return num;
	}

	//输出链表
	int print()
	{

		//如果链表为空，输出回车
		if (!ptr)
		{
			cout << endl;
			return 0;
		}

		node* p = ptr->next;
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
	CircularLinkedList list;
	return 0;
}