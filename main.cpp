#include <iostream>
#include <windows.h> //windows 헤더파일 include

using namespace std;

void Input();
void Process();
void Render();

bool bGmaeState = true;

char Key;

int main()
{ 
	// -- Game Engine이 하는 일 --
	// 
	// 사용자의 입력을 받는다. (Input)
	// 물체를 배치(수학계산)한다. (Process) 
	// 그림을 그린다.(가상공간에서 사진 찍는다.) (Render)
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
	system("cls"); //콘솔창 clear
	cout << "그린다." << endl;
}
