#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //windows ������� include

using namespace std;

//���� �����ڰ� �ϴ� ��
char Input();
bool Process(char Key);
void Draw();
void Initialize();
void Terminate();

void CustomInitialze();
void CustomTerminate();
bool CustomProcess(char Key);
void CustomDraw();

//�����ڰ� �����ϴ� Process
//void KeyOnPress(char Key);
//�����ڰ� �����ϴ� Render
//void PostRender();\
//�迭 �ʱ�ȭ
//void ArrayInitialize();
//void ArrayDisplay();
//void ArrayShuffle();

bool ProcessBingo(char Key);


void InitializeBingoPlayMap();

//�迭 ����
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
	//�ܼ� �ܼ� �Է�
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
	//�����(������)�� �����ϴ� Process
//	KeyOnPress(Key);

	return CustomProcess(Key);
}

void Draw()
{
	//system("cls"); //�ܼ�â clear
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
	//�����ǿ��� ã�� ĭ�� ��ŷ�Ѵ�.
	for (int i = 0; i < 9; i++)
	{
		if (BingoPlayMap[i] == Key - 48)
		{
			BingoPlayMap[i] = 'X';
			cout << "�����" << endl;
			break;
		}
	}

	//���� �������� Ȯ���Ѵ�.
	for (int i = 0; i <= 6; i = i + 3)
	{
		if (BingoPlayMap[i + 0] == 'X' &&
			BingoPlayMap[i + 1] == 'X' &&
			BingoPlayMap[i + 2] == 'X') {
			cout << "����" << endl;
			return false;
		}
	}

	//���� �������� Ȯ���Ѵ�.
	for (int i = 0; i <= 2; i++)
	{
		if (BingoPlayMap[i + 0] == 'X' &&
			BingoPlayMap[i + 3] == 'X' &&
			BingoPlayMap[i + 6] == 'X') {
			cout << "����" << endl;
			return false;
		}
	}

	//�밢�� �������� Ȯ���Ѵ�.
	if (BingoPlayMap[0] == 'X' &&
		BingoPlayMap[4] == 'X' &&
		BingoPlayMap[8] == 'X') {
		cout << "����" << endl;
		return false;
	}
	else if (BingoPlayMap[2] == 'X' &&
			 BingoPlayMap[4] == 'X' &&
			 BingoPlayMap[6] == 'X') {
			 cout << "����" << endl;
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