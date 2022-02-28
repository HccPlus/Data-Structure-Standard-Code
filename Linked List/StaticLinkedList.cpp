//这是一个标准静态链表结构，可供《数据结构》课程的初学者进行参考。
// 
//该链表存储的数据为int型。实际应用中可能有多种或多个类型，在此处以int型为例。
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//作者e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//该结构目前具有输入链表、打印链表的功能，
//具体功能介绍见StaticLinkedList类中各个函数前的注释

////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

class StaticLinkedList
{

private:

	struct node
	{
		int dat;
		int next;
		bool storaged;
		node()
		{
			dat = 0;
			next = -1;
			storaged = false;
		}
	};

	//静态链表（数组）的头节点指针
	node* head;

	//静态链表的结点数
	int num;

	//是否完成输入
	bool readed;

public:

	StaticLinkedList()
	{

		//输入静态链表的长度
		cin >> num;

		//初始化静态链表
		head = new node[num];
		for (int i = 0; i < num; i++)
		{
			head[i].dat = 0;
			head[i].next = -1;
		}

		readed = false;

	}

	//用顺序数列创建一个静态链表(输入-1时停止)
	int in()
	{

		//存储输入值的变量
		int next = 0;

		//存储链表有效结点数的变量
		int sum = 0;

		//循环输入
		while (next != -1)
		{
			int dat = 0;
			node& nd = head[next];
			cin >> dat;
			cin >> next;
			nd.dat = dat;
			nd.next = next;
		}

		readed = true;
		return 0;
	}

	//从头顺序打印链表
	int print()
	{
		int i = 0;
		while (i != -1)
		{
			cout << head[i].dat << ' ';
			i = head[i].next;
		}
		cout << endl;
		return 0;
	}

};

int main()
{
	StaticLinkedList list;
	list.in();
	list.print();
	return 0;
}