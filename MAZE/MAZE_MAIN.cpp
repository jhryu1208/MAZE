#include <iostream>
#include <conio.h>
using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
*/
struct _tagPoint
{
	int x;
	int y;
};

// typedef : 타입을 재정의하는 기능
// _tagPoint의 변수타입명을 POINT로도 명시가능하게 해준다.
// 다시말해, POINT로 자료형을 선언해도 _tagPoint를 선언한 것과 같은 취급.
typedef _tagPoint	POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) //널문자가 들어갈 여백을 하나 늘려준다
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
			if (pPlayerPos->x == j && pPlayerPos->y == i) // →방향은 x축에 해당하며 열구역에 해당한다. ↑방향은 y축에 해당하며 행구역에 해당한다.
				cout << "☆";
			else if (Maze[i][j] == '0')
				cout << "■"; // 특수문자 2byte
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "♥";
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0) // 위로갈수록 i(행)가 작아진다. 따라서, y-1은 위로감을 의미
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
		{
			// 위에 벽이없다면 위로 이동
			--(pPlayerPos->y);
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20) // 아래로 갈수록 i(행)가 커진다. 따라서, y+1은 아래로 감을 의미
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
		{
			// 아래에 벽이없다면 아래로 이동
			++(pPlayerPos->y);
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0) // 왼쪽으로갈수록 j(열)가 작아진다. 따라서, x-1은 왼쪽으로 감을 의미
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
		{
			// 왼쪽에 벽이없다면 왼쪽으로 이동
			--(pPlayerPos->x);
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20) // 오른쪽으로갈수록 j(열)가 커진다. 따라서, x+1은 오른쪽으로 감을 의미
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0')
		{
			// 오른쪽에 벽이없다면 오른쪽으로 이동
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
|                Main 함수                |
|||||||||||||||||||||||||||||||||||||||||||
*/

int main()
{
	// 20 x 20 미로를 만든다.
	char strMaze[21][21] = {};
	
	POINT tPlayerPos = {};
	POINT tStartPos = {};
	POINT tEndPos = {};

	// 미로를 *초기*설정한다.
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (1)
	{
		system("cls"); // 연속적 출력을 위해서
		// 미로를 출력한다.
		Output(strMaze, &tPlayerPos);

		// 도착지에 도착
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "도착!" << endl;
			break; // while구문 탈출 = 미로종료
		}

		cout << " w : 위	s : 아래	a : 왼쪽	d : 오른쪽	q: 종료 :";
		
		// 종료
		char cInput = _getch(); // _getch() : 입력 버퍼를 사용하지 않음, 화면에 키의 입력을 보여주지 않음
		if (cInput == 'q' || cInput == 'Q')
			break;

		// Move 함수
		MovePlayer(strMaze, &tPlayerPos, cInput);
	}

	return 0;
}