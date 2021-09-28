#include <iostream>
#include <windows.h> //windows ������� include

using namespace std;

char Input();
void Process(char Key);
void Render();

bool bGmaeState = true;


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
}

void Render()
{
	system("cls"); //�ܼ�â clear
	cout << "�׸���." << endl;
}