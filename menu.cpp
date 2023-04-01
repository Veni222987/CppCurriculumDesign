#include "myhead.h"

//��������Ĵ�С��ɫ�ȵ�
void setfont(double size)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0 ;
	cfi.dwFontSize.Y = size;  //���������С
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //�����ϸ 
	wcscpy_s(cfi.FaceName, L"����");//������
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	//�������ʱû�ã�����˫��������л��õ�
	/*
	 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consoleCurrentFont;
	GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
	*/
}

void move(int index_now, int index_new)
{
	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//�������Լ��ƶ���ʱ����������
	short cut_up = 38 * index_now;
	short cut_bottom = 38 * index_now + 38;
	short pa_y = index_new * 38;
	SMALL_RECT CutScr = { 0, cut_up, 40, cut_bottom }; //�ü�������Ŀ������ļ����гɼ�������
	COORD pos = {0 , pa_y };     //������꣬��ü����򳤿��ɵ���������Ŀ������ļ���Ϊճ����
	//��������ַ��ĸ�������������

	SetConsoleTextAttribute(hOut, 0xF0);
	CONSOLE_SCREEN_BUFFER_INFO Intsrc;
	GetConsoleScreenBufferInfo(hOut, &Intsrc);
	CHAR_INFO chFill = { ' ',  Intsrc.wAttributes }; //���������������ַ�
	ScrollConsoleScreenBuffer(hOut, &CutScr, NULL, pos, &chFill); //�ƶ��ı�
}

void main_map()
{
	setfont(1);
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);//���
	SetConsoleTitleA("�������������Ա����ϵͳ");//�Ĵ�����
	system("color 0b");//��ǰ������ɫ
	fstream map_picture;
	map_picture.open("files/map.txt");
	char c;
	while (!map_picture.eof())
	{
		c = map_picture.get();
		cout << c;
	}
	map_picture.close();
	
}

int menu()
{
	//��ȡ���ھ�������ô���Ĭ�����
	system("color F0");
	setfont(2);
	HWND hwnd = GetForegroundWindow();
	fstream menu_picture;
	char c;
	menu_picture.open("files/appendex.txt", ios::in);
	while (!menu_picture.eof())
	{
		c = menu_picture.get();
		cout << c;
	}
	menu_picture.close();

	int index_now = 0;

	while (1)
	{
		int a = _getch();
		if(a==13)
			break;
		switch (a)
		{
		case 72://����
			{
			int index_new = index_now == 0 ? 0 : index_now - 1;
			move(index_now, index_new);
			index_now = index_new;
			break;
			}
		case 80://����
			{
			int index_new = index_now == 7 ? 7 : index_now + 1;
			move(index_now, index_new);
			index_now = index_new;
			}
		}
	}
	return index_now;

}