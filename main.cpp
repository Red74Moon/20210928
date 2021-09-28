#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //windows 헤더파일 include

using namespace std;

//엔진 개발자가 하는 일
char Input();
void Process(char Key);
void Render();

//개발자가 구현하는 Process
void KeyOnPress(char Key);

//개발자가 구현하는 Render
void PostRender();

//배열 초기화
//void ArrayInitialize();
//void ArrayDisplay();
//void ArrayShuffle();

//배열 선언
int BingoPlayMap[9];

void Initialize();
void Terminate();

void CustomInitialze();
void CustomTerminate();
void CustomProcess();
void ProcessBingo();
void CustomDraw();

void InitializeBingoPlayMap();

bool bGameState = true;

int Gold = 0;

int main()
{

	Initialize();

	while (bGameState)
	{ 
		//ArrayInitialize();
		//ArrayShuffle();
		//ArrayDisplay();

		char Key = Input();
		
		Process(Key);

		Render();

	}
	Terminate();
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
		bGameState = false;
	}
	//사용자(개발자)가 구현하는 Process
	KeyOnPress(Key);

	CustomProcess();
}

void Render()
{
	system("cls"); //콘솔창 clear
	cout << "그린다." << endl;

	//PostRender();
	CustomDraw();
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

//void ArrayInitialize()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		BingoPlayMap[i] = i + 1;
//	}
//}
//
//void ArrayDisplay()
//{
//	for (int i = 0; i < 9; i++)
//	{	
//		cout << BingoPlayMap[i] << "\t";
//	}
//	cout << endl;
//}
//
//void ArrayShuffle()
//{
//	// srand(time(NULL));
//
//	//숫자 섞기 (shuffle)
//	for (int i = 0; i < 9; i++)
//	{
//		// 배열에서 가져오는 자리1
//		int R = rand() % 9;
//		// 배열에서 가져오는 자리2
//		int R2 = rand() % 9;
//
//		// 배열 자리 섞음
//		int Temp = BingoPlayMap[R];
//		BingoPlayMap[R] = BingoPlayMap[R2];
//		BingoPlayMap[R2] = Temp;
//	}
//}

void Initialize()
{
	//초기화
	CustomInitialze();
}

void Terminate()
{
	CustomTerminate();
}

void CustomInitialze()
{
	InitializeBingoPlayMap();
}

void CustomTerminate()
{
}

void CustomProcess()
{
	ProcessBingo();
}

void ProcessBingo()
{
}

void CustomDraw()
{
}

void InitializeBingoPlayMap()
{
	for (int i = 0; i < 9; i++)
	{
		BingoPlayMap[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	//숫자 섞기 (shuffle)
	for (int i = 0; i < 100; i++)
	{
		// rand
		int Index1 = rand() % 9;
		int Index2 = rand() % 9;

		// 배열 자리 섞음
		int Temp = BingoPlayMap[Index1];
		BingoPlayMap[Index1] = BingoPlayMap[Index2];
		BingoPlayMap[Index2] = Temp;
	}
}
