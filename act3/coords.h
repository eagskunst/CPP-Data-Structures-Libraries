COORD getCoord(){
	COORD xy;
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO p;
	GetConsoleScreenBufferInfo(hcon, &p);
	xy = p.dwCursorPosition;
	return xy;
}

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
 	dwPos.X = x;
 	dwPos.Y = y;
 	SetConsoleCursorPosition(hcon,dwPos);
}