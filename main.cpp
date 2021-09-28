#include <iostream>
#include <windows.h> //windows 헤더파일 include

using namespace std;

//엔진 개발자가 하는 일
char Input();
void Process(char Key);
void Render();

//개발자가 구현하는 Process
void CustomProcess(char Key);

//개발자가 구현하는 Render
void CustomRender();

bool bGmaeState = true;

int Gold = 0;

int main()
{ 
	// -- Game Engine이 하는 일<Game Loop Pattern>--
	// 
	// 사용자의 입력을 받는다. (Input)
	// 물체를 배치(수학계산)한다. (Process) 
	// 그림을 그린다.(가상공간에서 사진 찍는다.) (Render)
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
	//단순 콘솔 입력
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
	//사용자(개발자)가 구현하는 Process
	CustomProcess(Key);
}

void Render()
{
	system("cls"); //콘솔창 clear
	cout << "그린다." << endl;

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
