#include "myhead.h"

//设置字体的大小颜色等等
void setfont(double size)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0 ;
	cfi.dwFontSize.Y = size;  //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //字体粗细 
	wcscpy_s(cfi.FaceName, L"楷体");//改字体
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	//下面的暂时没用，在做双缓冲机制中会用到
	/*
	 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consoleCurrentFont;
	GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
	*/
}

void move(int index_now, int index_new)
{
	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//下面是自己移动的时候计算的区域
	short cut_up = 38 * index_now;
	short cut_bottom = 38 * index_now + 38;
	short pa_y = index_new * 38;
	SMALL_RECT CutScr = { 0, cut_up, 40, cut_bottom }; //裁剪区域与目标区域的集合行成剪切区域
	COORD pos = {0 , pa_y };     //起点坐标，与裁剪区域长宽构成的区域再与目标区域的集合为粘贴区
	//定义填充字符的各个参数及属性

	SetConsoleTextAttribute(hOut, 0xF0);
	CONSOLE_SCREEN_BUFFER_INFO Intsrc;
	GetConsoleScreenBufferInfo(hOut, &Intsrc);
	CHAR_INFO chFill = { ' ',  Intsrc.wAttributes }; //定义剪切区域填充字符
	ScrollConsoleScreenBuffer(hOut, &CutScr, NULL, pos, &chFill); //移动文本
}

void main_map()
{
	setfont(1);
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);//最大化
	SetConsoleTitleA("疫情防控流动人员管理系统");//改窗体名
	system("color 0b");//改前景后景颜色
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
	//获取窗口句柄，设置窗口默认最大化
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
		case 72://向上
			{
			int index_new = index_now == 0 ? 0 : index_now - 1;
			move(index_now, index_new);
			index_now = index_new;
			break;
			}
		case 80://向下
			{
			int index_new = index_now == 7 ? 7 : index_now + 1;
			move(index_now, index_new);
			index_now = index_new;
			}
		}
	}
	return index_now;

}