//����һ����׼ѭ������ṹ���ɹ������ݽṹ���γ̵ĳ�ѧ�߽��вο���
// 
//������洢������Ϊint�͡�ʵ��Ӧ���п����ж��ֻ������ͣ��ڴ˴���int��Ϊ����
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//����e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//�ýṹĿǰ������ɾ�Ĳ�ȹ��ܣ�
//���幦�ܽ��ܼ�CircularLinkedList���и�������ǰ��ע��

////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

//������ṹ
struct node
{

	//����Ĵ洢����
	int dat;

	//�������nextָ��
	node* next;

	//������Ĺ��캯��
	node()
	{
		dat = 0;
		next = NULL;
	}

};

class CircularLinkedList
{

private:

	//����Ķ�λָ��
	node* ptr;

	//����ѡ������Ľ����
	int num;

	//��ʾ���д���
	int error()
	{
		cout << "���г���" << endl;
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

		//�������ָ���ɾ�����
		node* p = ptr;
		node* temp = p;

		//ѭ��ɾ�����
		//������Ϊ�գ���ִ�иö����
		for (int i = 0; i < num; i++)
		{
			temp = p->next;
			delete p;
			p = temp;
		}

	}

	//������λ����ӽ��
	int push(int dat)
	{

		//���붯̬�ڴ�
		node* p = new node;

		//Ϊ�½�����dat������ֵ
		p->dat = dat;

		//ʹ�½���nextָ��ָ��λ����nextָ��
		if (ptr) p->next = ptr->next;

		//ʹ��λ����nextָ��ָ����ָ��
		if (ptr) ptr->next = p;

		//��Ϊ�׸���㣬�½���nextָ��ָ���Լ�
		else p->next = p;

		//ʹԭptrָ��ָ���½����
		ptr = p;

		//�����+1
		num++;

		return 0;

	}

	//������λ�����Ƴ����
	int pop()
	{

		//���ֻ��һ����㣬ɾ��ptr����ptr�ÿ�
		if (ptr == ptr->next)
		{
			delete ptr;
			ptr = NULL;
		}

		//���ptr��Ϊ��ָ��
		else if (ptr)
		{
			//ɾ����һ���
			node* p = ptr->next;
			ptr->next = p->next;
			delete p;
			p = NULL;
		}

		//��ptrΪ��
		else
		{
			//��ʾ���󱨸�
			error();
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
		node* p = ptr->next;

		//ѭ��ʹָ��ָ��Ŀ��ڵ�
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

		//�����Ŵ�����������
		if (sen >= num)
		{
			//���г���
			error();
		}

		//�½�ָ��
		node* p = ptr->next;

		//ѭ��ʹָ��ָ����޸Ľڵ�
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
		node* p = ptr->next;

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

	//�������
	int print()
	{

		//�������Ϊ�գ�����س�
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