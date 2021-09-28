#include <iostream>
#include <cstdlib>
#include <ctime>
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

//�迭 �ʱ�ȭ
//void ArrayInitialize();
//void ArrayDisplay();
//void ArrayShuffle();

//�迭 ����
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
	//�ܼ� �ܼ� �Է�
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
	//�����(������)�� �����ϴ� Process
	KeyOnPress(Key);

	CustomProcess();
}

void Render()
{
	system("cls"); //�ܼ�â clear
	cout << "�׸���." << endl;

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
//	//���� ���� (shuffle)
//	for (int i = 0; i < 9; i++)
//	{
//		// �迭���� �������� �ڸ�1
//		int R = rand() % 9;
//		// �迭���� �������� �ڸ�2
//		int R2 = rand() % 9;
//
//		// �迭 �ڸ� ����
//		int Temp = BingoPlayMap[R];
//		BingoPlayMap[R] = BingoPlayMap[R2];
//		BingoPlayMap[R2] = Temp;
//	}
//}

void Initialize()
{
	//�ʱ�ȭ
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

	//���� ���� (shuffle)
	for (int i = 0; i < 100; i++)
	{
		// rand
		int Index1 = rand() % 9;
		int Index2 = rand() % 9;

		// �迭 �ڸ� ����
		int Temp = BingoPlayMap[Index1];
		BingoPlayMap[Index1] = BingoPlayMap[Index2];
		BingoPlayMap[Index2] = Temp;
	}
}
