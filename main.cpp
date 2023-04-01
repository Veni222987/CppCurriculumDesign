#include "myhead.h"
#include "Out_Worker.h"
#include "Out_Student.h"
#include "Here_Worker.h"
#include "Here_Student.h"
using namespace cv;
int main()
{

	//opencv产生txt文件
	const char character[] = "@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`  .  ";

	const char* img_path = "./files/map_picture.jpg";    
	const char* txt_path = "./files/mapt.txt";  

	Mat img = imread(img_path);
	Mat gray_img;
	cvtColor(img, gray_img, COLOR_RGB2GRAY);   //灰度矩阵

	//转灰度图截图以及测试
	/*imshow("灰度图", gray_img);
	waitKey(0);*/

	//转化
	string str;
	for (int y = 0; y < gray_img.rows; y++)
	{
		for (int x = 0; x < gray_img.cols; x++)
		{
			int grayVal = (int)gray_img.at<uchar>(y, x);    //获取坐标像素点的灰度值。（强制类型转换是为了避免负值）
			int index = 69.0 / 255.0 * grayVal;             //根据灰度值选取字符
			str += character[index];
		}
		str += "\r\n";
	}

	//写入文本文件中
	ofstream outStream;
	outStream.open(txt_path);
	outStream << str << endl;
	outStream.close();




	//展示封面地图
	vector<Person*> Operating_list;
	char alphabet;
	string region;

	map_entrance:
	main_map();
	//输入操作选项
	cin >> alphabet;
	switch (alphabet)
	{
	case 'A': case 'a':
	{
		region = "guangzhou";
		Operating_list = get_file_list("guangzhou");
		break;
	}
	case 'B': case 'b':
	{
		region = "shenzhen";
		Operating_list = get_file_list("shenzhen");
		break;
	}
	case'C':case 'c':
	{
		region = "zhuhai";
		Operating_list = get_file_list("zhuhai");
		break;
	}
	case 'D':case 'd':
	{
		region = "shantou";
		Operating_list = get_file_list("shantou");
		break;
	}
	case 'E':case 'e':
	{
		region = "foshan";
		Operating_list = get_file_list("foshan");
		break;
	}
	case 'F':case 'f':
	{
		region = "shaoguan";
		Operating_list = get_file_list("shaoguan");
		break;
	}
	case 'G':case 'g':
	{
		region = "zhanjiang";
		Operating_list = get_file_list("zhanjiang");
		break;
	}
	case 'H':case 'h':
	{
		region = "zhaoqing";
		Operating_list = get_file_list("zhaoqing");
		break;
	}
	case 'J':case 'j':
	{
		region = "jiangmen";
		Operating_list = get_file_list("jiangmen");
		break;
	}
	case 'K':case 'k':
	{
		region = "maoming";
		Operating_list = get_file_list("maoming");
		break;
	}
	case 'L':case 'l':
	{
		region = "huizhou";
		Operating_list = get_file_list("huizhou");
		break;
	}
	case 'M':case 'm':
	{
		region = "meizhou";
		Operating_list = get_file_list("meizhou");
		break;
	}
	case 'N':case 'n':
	{
		region = "shanwei";
		Operating_list = get_file_list("shanwei");
		break;
	}
	case 'P':case 'p':
	{
		region = "heyuan";
		Operating_list = get_file_list("heyuan");
		break;
	}
	case 'Q':case 'q':
	{
		region = "yangjiang";
		Operating_list = get_file_list("yangjiang");
		break;
	}
	case 'R':case 'r':
	{
		region = "qingyuan";
		Operating_list = get_file_list("qingyuan");
		break;
	}
	case 'S':case 's':
	{
		region = "dongguan";
		Operating_list = get_file_list("dongguan");
		break;
	}
	case 'T':case 't':
	{
		region = "zhongshan";
		Operating_list = get_file_list("zhongshan");
		break;
	}
	case 'U':case 'u':
	{
		region = "chaozhou";
		Operating_list = get_file_list("chaozhou");
		break;
	}
	case 'V':case 'v':
	{
		region = "jieyang";
		Operating_list = get_file_list("jieyang");
		break;
	}
	case 'W':case 'w':
	{
		region = "yunfu";
		Operating_list = get_file_list("yunfu");
		break;
	}
	default:
	{
		system("cls");
		setfont(20);
		cout << "无效的指令，请重新输入" << endl;
		Sleep(3000);
		goto map_entrance;
	}
	}
	
	
	//实际上选完了rigion之后就是选完了需要操作的文件空间了，所以之后不需要再分类了

	//下面是实现菜单栏的操作

	system("cls");
	while(1)
	{
		setfont(1);
		int number=menu();
		system("cls");
		setfont(20);
		switch (number)
		{
		case 0:
			{
			input_information(region,Operating_list);
			break;
			}
		case 1:
			{
				entrance:
				cout << "请输入您需要查找的名字：" << endl;
				string name;
				cin >> name;
				int index=find_name(Operating_list, name);
				if(index!=-1)
				{
					entrance_find_name:
					cout << "请选择你需要进行的操作:" << endl<<
						"1、外出人员返乡登记"<<endl<<
						"2、本地人员外出登记"<<endl<<
						"3、短信通知核酸检测"<<endl<<
						"4、悄悄地看看他的手机信箱"<<endl;
					char num = 0;
					cin >> num;
					switch (num)
					{
					case '1':
						{
							move_in(index,Operating_list);
							cout << "手续已经办理完成" << endl;
							break;
						}
					case '2':
						{
							move_out(index, Operating_list);
							cout << "手续已经办理完成" << endl;
							break;
						}
					case '3':
						{
							sent_message(Operating_list[index]->get_name(), Operating_list);
							break;
						}
					case '4':
						{
							Operating_list[index]->phone.show_messages();
							break;
						}
						default:
						{
							cout << "无效的指令，请重新输入" << endl;
							goto entrance_find_name;
						}
					}
				}
				else
				{
					cout << "查无此人，请重新输入" << endl;
					goto entrance;
				}
				break;
			}
		case 2:
			{
				entrance_sort:
				cout << "请选择您需要排序的指标" << endl
				<<"1、姓名拼音字母排序"<<endl
				<<"2、年龄降序排序"<<endl;
			char a = 0;
			cin >> a;
			if (a == '1')
				sort_by_name(Operating_list);
			else if(a=='2')
			{
				sort_by_age(Operating_list);
			}
			else
			{
				cout << "无效的指令，请重新输入" << endl;
				goto entrance_sort;
			}
				break;
			}
		case 3:
			{
			cout << "请输入您需要统计的地区的编号" << endl;
			int a = 0;
			cin >> a;
			cout<<"本地列表中在该地的人数："<<statistics_in_region(Operating_list, a) << endl;
			break;
			}
		case 4:
			{
				show_all(Operating_list);
				break;
			}
		case 5:
			{entrance_5:
				cout << "请选择你需要筛选的类型：" << endl
				<< "1、本地学生" << endl
				<< "2、本地就业者" << endl
				<< "3、外地学生" << endl
				<< "4、外地就业者" << endl;
			char a;
			string type;
			cin >> a;
			switch (a)
			{
			case '1':type = "Here_Student"; break;
			case '2':type = "Here_Worker"; break;
			case '3':type = "Out_Student"; break;
			case '4':type = "Out_Worker"; break;
				default:
					{
					cout << "无效指令，请重新输入" << endl;
					system("cls");
						goto entrance_5;
					}
			}
			show_type(type, Operating_list);
			break;
			}
		case 6:
			{
			get_risky_Person(Operating_list);
			break;
			}
		case 7:
			{
			suansuan(Operating_list,region);
			break;
			}
		}
		bool_continue:
		cout << "请问您需要继续操作吗？（Y/N）" << endl;
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			system("cls");
			continue;
		}
		else if(c=='N'||c=='n')
			break;
		else
		{
			cout << "无效的指令，请重新输入。" << endl;
			goto bool_continue;
		}
	}
	save_file_list(region, Operating_list);
	system("pause");
	return 0;
}