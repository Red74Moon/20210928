#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //windows 헤더파일 include

using namespace std;

//엔진 개발자가 하는 일
char Input();
bool Process(char Key);
void Draw();
void Initialize();
void Terminate();

void CustomInitialze();
void CustomTerminate();
bool CustomProcess(char Key);
void CustomDraw();

//개발자가 구현하는 Process
//void KeyOnPress(char Key);
//개발자가 구현하는 Render
//void PostRender();


bool ProcessBingo(char Key);

void InitializeBingoPlayMap();

//배열 선언
int BingoPlayMap[9];

int Gold = 0;

int main()
{
	bool bGameState = true;

	Initialize();

	while (bGameState)
	{ 
		char Key = Input();
		
		bGameState = Process(Key);

		Draw();

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

bool Process(char Key)
{
	if (Key == 'q' || Key == 'Q')
	{
		return false;
	}
	//사용자(개발자)가 구현하는 Process
//	KeyOnPress(Key);

	return CustomProcess(Key);
}

void Draw()
{
	//system("cls"); //콘솔창 clear
	cout << endl << endl;

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
	for (int i = 0; i < 9; i++)
	{
		if ( i % 3 == 0 && i != 0 )
		{
			cout << "\n";
		}
		if (BingoPlayMap[i] > 9)
		{
			cout << (char)BingoPlayMap[i] << " ";
		}
		else
		{
			cout << BingoPlayMap[i] << " ";
		}
	}
}

bool CustomProcess(char Key)
{
	return ProcessBingo(Key);
}

bool ProcessBingo(char Key)
{
	//빙고판에서 찾은 칸에 마킹한다.
	for (int i = 0; i < 9; i++)
	{
		if (BingoPlayMap[i] == Key - 48)
		{
			BingoPlayMap[i] = 'X';
			CustomTerminate();
			cout << endl;
			break;
		}
	}

	//가로 빙고인지 확인한다.
	for (int i = 0; i <= 6; i = i + 3)
	{
		if (BingoPlayMap[i + 0] == 'X' &&
			BingoPlayMap[i + 1] == 'X' &&
			BingoPlayMap[i + 2] == 'X') {
			cout << endl << "[ 빙고 ]" << endl;
			return false;
		}
	}

	//세로 빙고인지 확인한다.
	for (int i = 0; i <= 2; i++)
	{
		if (BingoPlayMap[i + 0] == 'X' &&
			BingoPlayMap[i + 3] == 'X' &&
			BingoPlayMap[i + 6] == 'X') {
			cout << endl << "[ 빙고 ]" << endl;
			return false;
		}
	}

	//대각선 빙고인지 확인한다.
	if (BingoPlayMap[0] == 'X' &&
		BingoPlayMap[4] == 'X' &&
		BingoPlayMap[8] == 'X') {
		cout << endl << "[ 빙고 ]" << endl;
		return false;
	}
	else if (BingoPlayMap[2] == 'X' &&
			 BingoPlayMap[4] == 'X' &&
			 BingoPlayMap[6] == 'X') {
			 cout << endl << "[ 빙고 ]" << endl;
			 return false;
	}
	return true;
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