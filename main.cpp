#include <iostream>
#include <windows.h> //windows ������� include

using namespace std;

void Input();
void Process();
void Render();

bool bGmaeState = true;

char Key;

int main()
{ 
	// -- Game Engine�� �ϴ� �� --
	// 
	// ������� �Է��� �޴´�. (Input)
	// ��ü�� ��ġ(���а��)�Ѵ�. (Process) 
	// �׸��� �׸���.(����������� ���� ��´�.) (Render)
	// 
	//
	while (bGmaeState)
	{ 
		Input();
		Process();
		Render();
	}

	return 0;
}

void Input()
{
	cin >> Key;
}

void Process()
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
