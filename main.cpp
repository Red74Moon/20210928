#include <iostream>
#include <windows.h> //windows ������� include

using namespace std;

//���� �����ڰ� �ϴ� ��
char Input();
void Process(char Key);
void Render();

//�����ڰ� �����ϴ� Process
void CustomProcess(char Key);

//�����ڰ� �����ϴ� Render
void CustomRender();

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
	CustomProcess(Key);
}

void Render()
{
	system("cls"); //�ܼ�â clear
	cout << "�׸���." << endl;

	CustomRender();
}

void CustomProcess(char Key)
{
	if (Key == 'G' || Key == 'g') 
	{
		Gold++;
	}
}

void CustomRender()
{
	cout << "Gold = " << Gold << endl;
}
