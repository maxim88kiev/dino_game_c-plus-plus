#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "dino.h"

using namespace std;
//
//void Input() {
//	if(_kbhit())
//	{
//		switch (_getch()){
//			case 72:
//				cout << "up" <<endl;
//				break;
//			case 80:
//				cout << "down" <<endl;
//				break;
//		}
//	}
//}
//
//void Logic() {
//	Sleep(500);
//	cout << "Logic" <<endl;
//}
//
//void Draw() {
//	cout << "Draw" <<endl;
//}
//
//bool stop = false;
//
//void Run()
//{
//	while(!stop)
//	{
//		Input();
//		Logic();
//		Draw();
//	}
//}


int main() {

	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);

	Dino dino;

	/*for (int i = 29; i > 15; i--) {
		cout << i << endl;
	}*/

	dino.Run();
	system("pause");
	return 0;
}