#include <iostream>
#include <windows.h> //windows ������� include

using namespace std;

//���� �����ڰ� �ϴ� ��
char Input();
void Process(char Key);
void Render();

//�����ڰ� �����ϴ� Process
void KeyOnPress(char Key);

//�����ڰ� �����ϴ� Render
void PostRender();

bool bGmaeState = true;

int Gold = 0;

int main()
{ 
	// -- Game Engine�� �ϴ� ��<Game Loop Pattern>--
	// 
	// ������� �Է��� �޴´�. (Input)
	// ��ü�� ��ġ(���а��)�Ѵ�. (Process) 
	// �׸��� �׸���.(����������� ���� ��´�.) (Render)
	// 
	//
	while (bGmaeState)
	{ 
		char Key = Input();
		Process(Key);
		Render();
	}
	return 0;
}

char Input()
{
	//�ܼ� �ܼ� �Է�
	char Key;

	cin >> Key;

	return Key;
}

void Process(char Key)
{
	if (Key == 'q' || Key == 'Q')
	{
		bGmaeState = false;
	}
	//�����(������)�� �����ϴ� Process
	KeyOnPress(Key);
}

void Render()
{
	system("cls"); //�ܼ�â clear
	cout << "�׸���." << endl;

	PostRender();
}

void KeyOnPress(char Key)
{
	if (Key == 'G' || Key == 'g') 
	{
		Gold++;
	}
}

void PostRender()
{
	cout << "Gold = " << Gold << endl;
}
