#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* left, * right;
};

//Удаление
Node* Deletenode(Node* node, int x)
{
	bool ok = false;
	if (node == NULL)
		return node;
	if (x == node->info)
	{
		//Если оба пустые
		if (node->right == NULL && node->left == NULL)
		{
			Node* temp = NULL;
			node = temp;
			delete node;
		}
		else
		{
			//Если оба не пустые
			if (node->right != NULL && node->left != NULL)
			{
				//buf - текущий элемент, temp - указатель на него
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
				//Если левый не пустой
				if (node->left != NULL)
				{
					Node* temp = node;
					node = node->left;
					delete temp;
				}
				//Если правый не пустой
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

//Вставка элемента
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

//Обход дерева в префиксной форме
void pre_print(Node* node) {
	if (node != NULL) {
		cout << node->info << " ";
		pre_print(node->left);
		pre_print(node->right);
	}
}

//Обход дерева в инфиксной форме
void inf_print(Node* node) {
	if (node != NULL) {
		inf_print(node->left);
		cout << node->info << " ";
		inf_print(node->right);
	}
}

//Обход дерева в постфиксной форме
void post_print(Node* node) {
	if (node != NULL) {
		post_print(node->left);
		post_print(node->right);
		cout << node->info << " ";
	}
}

//Поиск элемента в дереве
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
	cout << "Элементы, которые будут добавляться: ";
	for (int i = 0; i < 10; i++)
	{
		mas[i] = rand() % 10 + 1;
		cout << mas[i] << " ";
		list = addnode(mas[i], list);
	}
	cout << endl;
	cout << endl;

	cout << "Обход дерева в постфиксной форме: ";
	post_print(list);
	cout << endl;
	cout << endl;

	cout << "Обход дерева в инфиксной форме: ";
	inf_print(list);
	cout << endl;
	cout << endl;

	cout << "Обход дерева в префиксной форме: ";
	pre_print(list);
	cout << endl;
	cout << endl;

	if (find(list, 7))
		cout << "Элемент '7' есть" << endl;
	else
		cout << "Элемента '7' нет" << endl;

	cout << endl;
	list = Deletenode(list, 5);
	cout << "Обход дерева в префиксной форме: ";
	pre_print(list);
	cout << endl;
	cout << endl;



	system("pause");
	return 0;
}