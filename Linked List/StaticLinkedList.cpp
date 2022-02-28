//����һ����׼��̬����ṹ���ɹ������ݽṹ���γ̵ĳ�ѧ�߽��вο���
// 
//������洢������Ϊint�͡�ʵ��Ӧ���п����ж��ֻ������ͣ��ڴ˴���int��Ϊ����
//
//from: https://github.com/HccPlus/Data-Structure-Standard-Code
//
//����e-mail: vct233@163.com

////////////////////////////////////////////////////////////////

//�ýṹĿǰ��������������ӡ����Ĺ��ܣ�
//���幦�ܽ��ܼ�StaticLinkedList���и�������ǰ��ע��

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

	//��̬�������飩��ͷ�ڵ�ָ��
	node* head;

	//��̬����Ľ����
	int num;

	//�Ƿ��������
	bool readed;

public:

	StaticLinkedList()
	{

		//���뾲̬����ĳ���
		cin >> num;

		//��ʼ����̬����
		head = new node[num];
		for (int i = 0; i < num; i++)
		{
			head[i].dat = 0;
			head[i].next = -1;
		}

		readed = false;

	}

	//��˳�����д���һ����̬����(����-1ʱֹͣ)
	int in()
	{

		//�洢����ֵ�ı���
		int next = 0;

		//�洢������Ч������ı���
		int sum = 0;

		//ѭ������
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

	//��ͷ˳���ӡ����
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