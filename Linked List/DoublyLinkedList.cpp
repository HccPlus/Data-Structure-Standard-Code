//����һ����׼˫����ṹ���ɹ������ݽṹ���γ̵ĳ�ѧ�߽��вο���
// 
//������洢������Ϊint�͡�ʵ��Ӧ���п����ж��ֻ������ͣ��ڴ˴���int��Ϊ����
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//����e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//�ýṹĿǰ������ɾ�Ĳ�ȹ��ܣ�
//���幦�ܽ��ܼ�DoublyLinkedList���и�������ǰ��ע��

////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

//������ṹ
struct node
{

	//����Ĵ洢����
	int dat;

	//�������lastָ��
	node* last;

	//�������nextָ��
	node* next;

	//������Ĺ��캯��
	node()
	{
		dat = 0;
		last = NULL;
		next = NULL;
	}

};

class DoublyLinkedList
{

private:

	//�����ͷָ��
	node* head;

	//����ѡ�������βָ��
	node* tail;

	//����ѡ������Ľ����
	int num;

	//��û��βָ��ʱ���ҵ������β���
	node* get_tail()
	{
		node* p = head;
		node* temp = p;

		//ѭ��ʹpָ��NULL  tempָ��β���
		//������Ϊ�գ���ִ�иö����
		while (p)
		{
			p = temp->next;
			if (p)
			{
				temp = p;
			}
		}

		//����β���ָ��
		return temp;
	}

	//��ʾ���д���
	int error()
	{
		cout << "���г���" << endl;
		system("pause");
		return 0;
	}

public:

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		num = 0;
	}

	~DoublyLinkedList()
	{

		//�������ָ���ɾ�����
		node* p = head;
		node* temp = p;

		//ѭ��ɾ�����
		//������Ϊ�գ���ִ�иö����
		while (p)
		{
			temp = p->next;
			delete p;
			p = temp;
		}

	}

	//������ͷ����ӽ��
	int push_front(int dat)
	{

		//���붯̬�ڴ�
		node* p = new node;

		//Ϊ�½�����dat������ֵ
		p->dat = dat;

		//ʹ�½�����nextָ��ָ��ԭheadָ��
		p->next = head;

		//�������ͷ�����ͷ����lastָ��ָ���½��
		if (head) head->last = p;

		//ʹԭheadָ��ָ���½����
		head = p;

		//��Ϊ�׸���㣬tailָ��ָ��ý��
		if (!tail) tail = p;

		//�����+1
		num++;

		return 0;

	}

	//������ͷ���Ƴ����
	int pop_front()
	{

		//���head��Ϊ��ָ��
		if (head)
		{
			//ʹheadָ��ָ����һ��㲢ɾ��ԭhead���
			node* p = head;
			head = head->next;
			if (head) head->last = NULL;
			delete p;
			p = NULL;
		}

		//��headΪ��
		else
		{
			//��ʾ���󱨸�
			error();
		}

		//����Ƴ��ڵ��headָ��Ϊ��
		if (!head)
		{
			//��βָ���ÿ�
			tail = NULL;
		}

		--num;

		return 0;
	}

	//�������β��ӽ��
	int push_back(int dat)
	{

		//���붯̬�ڴ�
		node* p = new node;

		//Ϊ�½�����dat������ֵ
		p->dat = dat;

		//ʹ�½�����nextָ��ָ��ԭheadָ��
		p->last = tail;

		//�������ͷ�����ͷ����lastָ��ָ���½��
		if (tail) tail->next = p;

		//ʹԭheadָ��ָ���½����
		tail = p;

		//��Ϊ�׸���㣬tailָ��ָ��ý��
		if (!head) head = p;

		//�����+1
		num++;

		return 0;

	}

	//������β���Ƴ����
	int pop_back()
	{

		//���tail��Ϊ��ָ��
		if (tail)
		{
			//ʹtailָ��ָ����һ��㲢ɾ��ԭtail���
			node* p = tail;
			tail = tail->last;
			if (tail) tail->next = NULL;
			delete p;
			p = NULL;
		}

		//��tailΪ��
		else
		{
			//��ʾ���󱨸�
			error();
		}

		//����Ƴ��ڵ��tailָ��Ϊ��
		if (!tail)
		{
			//��βָ���ÿ�
			head = NULL;
		}

		--num;

		return 0;
	}

	//����ָ����Ž������
	int get_node(int sen)
	{

		//�����Ŵ�����������
		if (sen >= num)
		{
			//���г���
			error();
		}

		//�½�ָ��
		node* p = head;

		//ѭ����ָ��ָ��Ŀ��ڵ�
		for (int i = 0; i < sen; i++)
		{
			p = p->next;
		}

		//���ظý������
		return p->dat;

	}

	//�༭ָ����ŵĽ������
	int edit_node(int sen, int dat)
	{

		//�����Ŵ��ڵ�����������
		if (sen >= num)
		{
			//���г���
			error();
		}

		//�½�ָ��
		node* p = head;

		//ѭ��ʹָ��ָ����޸Ľ��
		for (int i = 0; i < sen; i++)
		{
			p = p->next;
		}

		//�޸ĸý�������
		p->dat = dat;

		return 0;
	}

	//��������������������е�λ�ã����������򷵻�-1��
	int inq(int dat)
	{

		//�½�ָ��
		node* p = head;

		//�½�����ֵ
		int ret = -1;

		//ѭ��������������Ƿ���ڸ�����
		for (int i = 0; i < num; i++)
		{

			//����ý������������������ͬ
			if (p->dat == dat)
			{
				ret = i;
				break;
			}

			//������һ�����
			p = p->next;

		}

		return ret;
	}

	//������������
	int size()
	{
		return num;
	}

	//˳���������
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

	//�����������
	int rev_print()
	{
		node* p = tail;
		for (int i = 0; i < num; i++)
		{
			cout << p->dat << ' ';
			p = p->last;
		}
		cout << endl;
		return 0;
	}

};

int main()
{
	DoublyLinkedList list;
	return 0;
}