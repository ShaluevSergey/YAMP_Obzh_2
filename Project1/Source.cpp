#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* left, * right;
};

//��������
Node* Deletenode(Node* node, int x)
{
	bool ok = false;
	if (node == NULL)
		return node;
	if (x == node->info)
	{
		//���� ��� ������
		if (node->right == NULL && node->left == NULL)
		{
			Node* temp = NULL;
			node = temp;
			delete node;
		}
		else
		{
			//���� ��� �� ������
			if (node->right != NULL && node->left != NULL)
			{
				//buf - ������� �������, temp - ��������� �� ����
				Node* buf = node->right, * temp = node;
				if (buf->left != NULL)
				{
					temp = buf;
					buf = buf->left;
					ok = true;
				}
				while (buf->left != NULL)
				{
					buf = buf->left;
					temp = temp->left;
				}
				node->info = buf->info;
				if (ok)
					temp->left = buf->right;
				else
					temp->right = buf->right;
				delete buf;
			}
			else
			{
				//���� ����� �� ������
				if (node->left != NULL)
				{
					Node* temp = node;
					node = node->left;
					delete temp;
				}
				//���� ������ �� ������
				else
				{
					Node* temp = node;
					node = node->right;
					delete temp;
				}
			}
		}
	}
	else if (x < node->info)
		node->left = Deletenode(node->left, x);
	else
		node->right = Deletenode(node->right, x);
	return node;
}

//������� ��������
Node* addnode(int x, Node* node) {
	if (node == NULL) {
		node = new Node;
		node->info = x;
		node->left = NULL;
		node->right = NULL;
	}
	else if (x < node->info)
		node->left = addnode(x, node->left);
	else
		node->right = addnode(x, node->right);
	return(node);
}

//����� ������ � ���������� �����
void pre_print(Node* node) {
	if (node != NULL) {
		cout << node->info << " ";
		pre_print(node->left);
		pre_print(node->right);
	}
}

//����� ������ � ��������� �����
void inf_print(Node* node) {
	if (node != NULL) {
		inf_print(node->left);
		cout << node->info << " ";
		inf_print(node->right);
	}
}

//����� ������ � ����������� �����
void post_print(Node* node) {
	if (node != NULL) {
		post_print(node->left);
		post_print(node->right);
		cout << node->info << " ";
	}
}

//����� �������� � ������
Node* find(Node* node, float d)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->info == d)
	{
		return node;
	}

	if (d < node->info)
	{
		if (node->left != NULL)
			return find(node->left, d);
		else
		{
			return NULL;
		}
	}
	else
	{
		if (node->right)
			return find(node->right, d);
		else
		{
			return NULL;
		}
	}
}

int main()
{
	setlocale(0, "");
	Node* list = NULL, * list1 = NULL;
	int mas[10];
	cout << "��������, ������� ����� �����������: ";
	for (int i = 0; i < 10; i++)
	{
		mas[i] = rand() % 10 + 1;
		cout << mas[i] << " ";
		list = addnode(mas[i], list);
	}
	cout << endl;
	cout << endl;

	cout << "����� ������ � ����������� �����: ";
	post_print(list);
	cout << endl;
	cout << endl;

	cout << "����� ������ � ��������� �����: ";
	inf_print(list);
	cout << endl;
	cout << endl;

	cout << "����� ������ � ���������� �����: ";
	pre_print(list);
	cout << endl;
	cout << endl;

	if (find(list, 7))
		cout << "������� '7' ����" << endl;
	else
		cout << "�������� '7' ���" << endl;

	cout << endl;
	list = Deletenode(list, 5);
	cout << "����� ������ � ���������� �����: ";
	pre_print(list);
	cout << endl;
	cout << endl;



	system("pause");
	return 0;
}