#include <iostream>
#include <conio.h>
using namespace std;

/*
0 : ��
1 : ��
2 : ������
3 : ������
*/
struct _tagPoint
{
	int x;
	int y;
};

// typedef : Ÿ���� �������ϴ� ���
// _tagPoint�� ����Ÿ�Ը��� POINT�ε� ��ð����ϰ� ���ش�.
// �ٽø���, POINT�� �ڷ����� �����ص� _tagPoint�� ������ �Ͱ� ���� ���.
typedef _tagPoint	POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) //�ι��ڰ� �� ������ �ϳ� �÷��ش�
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 20;
	pEndPos->y = 20;
	
	*pPlayerPos = *pStartPos;

	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111100000000");
	strcpy_s(Maze[2],  "00100010000111111100");
	strcpy_s(Maze[3],  "01100010000000000100");
	strcpy_s(Maze[4],  "01000011110001111100");
	strcpy_s(Maze[5],  "01000000001111000000");
	strcpy_s(Maze[6],  "01100000001000000000");
	strcpy_s(Maze[7],  "01000000001111111000");
	strcpy_s(Maze[8],  "00001110000000001000");
	strcpy_s(Maze[9],  "01111011111111111000");
	strcpy_s(Maze[10], "01000000000000000000");
	strcpy_s(Maze[11], "01111100111111100000");
	strcpy_s(Maze[12], "00000111100000111110");
	strcpy_s(Maze[13], "01111100000000000010");
	strcpy_s(Maze[14], "01000000001111111110");
	strcpy_s(Maze[15], "01111110011000000000");
	strcpy_s(Maze[16], "00000010010000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");
}

void Output(char Maze[21][21], PPOINT pPlayerPos) 
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (pPlayerPos->x == j && pPlayerPos->y == i) // ������� x�࿡ �ش��ϸ� �������� �ش��Ѵ�. ������� y�࿡ �ش��ϸ� �౸���� �ش��Ѵ�.
				cout << "��";
			else if (Maze[i][j] == '0')
				cout << "��"; // Ư������ 2byte
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "��";
			else if (Maze[i][j] == '3')
				cout << "��";
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0) // ���ΰ����� i(��)�� �۾�����. ����, y-1�� ���ΰ��� �ǹ�
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
		{
			// ���� ���̾��ٸ� ���� �̵�
			--(pPlayerPos->y);
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20) // �Ʒ��� ������ i(��)�� Ŀ����. ����, y+1�� �Ʒ��� ���� �ǹ�
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
		{
			// �Ʒ��� ���̾��ٸ� �Ʒ��� �̵�
			++(pPlayerPos->y);
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0) // �������ΰ����� j(��)�� �۾�����. ����, x-1�� �������� ���� �ǹ�
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
		{
			// ���ʿ� ���̾��ٸ� �������� �̵�
			--(pPlayerPos->x);
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20) // ���������ΰ����� j(��)�� Ŀ����. ����, x+1�� ���������� ���� �ǹ�
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0')
		{
			// �����ʿ� ���̾��ٸ� ���������� �̵�
			++(pPlayerPos->x);
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

/*
|||||||||||||||||||||||||||||||||||||||||||
|                Main �Լ�                |
|||||||||||||||||||||||||||||||||||||||||||
*/

int main()
{
	// 20 x 20 �̷θ� �����.
	char strMaze[21][21] = {};
	
	POINT tPlayerPos = {};
	POINT tStartPos = {};
	POINT tEndPos = {};

	// �̷θ� *�ʱ�*�����Ѵ�.
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (1)
	{
		system("cls"); // ������ ����� ���ؼ�
		// �̷θ� ����Ѵ�.
		Output(strMaze, &tPlayerPos);

		// �������� ����
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "����!" << endl;
			break; // while���� Ż�� = �̷�����
		}

		cout << " w : ��	s : �Ʒ�	a : ����	d : ������	q: ���� :";
		
		// ����
		char cInput = _getch(); // _getch() : �Է� ���۸� ������� ����, ȭ�鿡 Ű�� �Է��� �������� ����
		if (cInput == 'q' || cInput == 'Q')
			break;

		// Move �Լ�
		MovePlayer(strMaze, &tPlayerPos, cInput);
	}

	return 0;
}