#pragma warning(disable:4996)
#include<iostream>
#include<conio.h>
#include<queue>
#include<stack>
#include<random>
#include<time.h>
using namespace std;
//================���������� ������� � ������� ������=====================
//========================================================================
int queue1[1000];//�������
int indexLastElement = 0;// ������ ���������� ��������
int* ptrInd = &indexLastElement; // ���������
//== ������� ���������� �������� � ������� ==
void addElementInFirstQueue(int* ind)
{
	int element;
	cout << "Enter your element" << endl;
	cin >> element;
	queue1[*ind] = element;
	*ind++;
}
//== ������� �������� �������� �� ������� ==
void deleteElementFromFirstQueue(int* ind)
{
	for (int i = 0; i < *ind - 1; i++)
	{
		queue1[i] = queue1[i + 1];
	}
	queue1[*ind - 1] = 0;
	*ind--;
}


//== ���������� ������� � ������� ������

struct queue2
{
	int data;
	queue2* next;
};

queue2	*head,    // ��������� �� ������ �������
*current, // ��������� �� �������� �������
*last;    // ��������� �� ����� �������
int n;
// �������� ������� � ������� page 339
void add()
{
	current = new queue2;
	cin >> current->data;
	current->next = NULL;
	if (last == NULL)
		head = current;
	else
		last->next = current;
	last = current;
}
// Getdel
void getdel()
{
	int save; // ���������� ��� ���������� ��������� ��������
	current = head;
	save = current->data;
	head = current->next;
	if (head == NULL)
		last = NULL;
	delete current;
}

// ���������� � ������� ���� ������

struct Stack
{
	int data();
	Stack* next;

};

Stack	*head1,
*head2,
*current;





/*
void search(stack<int> s, queue<int> q, int a[]){

}

void deletion (stack<int> s, queue<int> q, int a[]){

}

void addition(stack<int> s, queue<int> q, int a[]){

}

void init(){
srand(time(NULL));
int rnd;
queue<int> q;
stack<int> s;
int a[100];
for (int i = 0; i < 20; i++){
rnd = rand() % 99;
q.push(rnd);
s.push(rnd);
a[i] = rnd;
cout << q.back() << "	" << s.top() << "	" << a[i] << endl;
}
addition(s, q, a);
}

int main(){
cout << "restart the program?" << endl;
label1:
init();
if (getch() == 121){
goto label1;
}
}