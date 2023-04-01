#include "myhead.h"
#include "Out_Worker.h"
#include "Out_Student.h"
#include "Here_Worker.h"
#include "Here_Student.h"
using namespace cv;
int main()
{

	//opencv����txt�ļ�
	const char character[] = "@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`  .  ";

	const char* img_path = "./files/map_picture.jpg";    
	const char* txt_path = "./files/mapt.txt";  

	Mat img = imread(img_path);
	Mat gray_img;
	cvtColor(img, gray_img, COLOR_RGB2GRAY);   //�ҶȾ���

	//ת�Ҷ�ͼ��ͼ�Լ�����
	/*imshow("�Ҷ�ͼ", gray_img);
	waitKey(0);*/

	//ת��
	string str;
	for (int y = 0; y < gray_img.rows; y++)
	{
		for (int x = 0; x < gray_img.cols; x++)
		{
			int grayVal = (int)gray_img.at<uchar>(y, x);    //��ȡ�������ص�ĻҶ�ֵ����ǿ������ת����Ϊ�˱��⸺ֵ��
			int index = 69.0 / 255.0 * grayVal;             //���ݻҶ�ֵѡȡ�ַ�
			str += character[index];
		}
		str += "\r\n";
	}

	//д���ı��ļ���
	ofstream outStream;
	outStream.open(txt_path);
	outStream << str << endl;
	outStream.close();




	//չʾ�����ͼ
	vector<Person*> Operating_list;
	char alphabet;
	string region;

	map_entrance:
	main_map();
	//�������ѡ��
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
		cout << "��Ч��ָ�����������" << endl;
		Sleep(3000);
		goto map_entrance;
	}
	}
	
	
	//ʵ����ѡ����rigion֮�����ѡ������Ҫ�������ļ��ռ��ˣ�����֮����Ҫ�ٷ�����

	//������ʵ�ֲ˵����Ĳ���

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
				cout << "����������Ҫ���ҵ����֣�" << endl;
				string name;
				cin >> name;
				int index=find_name(Operating_list, name);
				if(index!=-1)
				{
					entrance_find_name:
					cout << "��ѡ������Ҫ���еĲ���:" << endl<<
						"1�������Ա����Ǽ�"<<endl<<
						"2��������Ա����Ǽ�"<<endl<<
						"3������֪ͨ������"<<endl<<
						"4�����ĵؿ��������ֻ�����"<<endl;
					char num = 0;
					cin >> num;
					switch (num)
					{
					case '1':
						{
							move_in(index,Operating_list);
							cout << "�����Ѿ��������" << endl;
							break;
						}
					case '2':
						{
							move_out(index, Operating_list);
							cout << "�����Ѿ��������" << endl;
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
							cout << "��Ч��ָ�����������" << endl;
							goto entrance_find_name;
						}
					}
				}
				else
				{
					cout << "���޴��ˣ�����������" << endl;
					goto entrance;
				}
				break;
			}
		case 2:
			{
				entrance_sort:
				cout << "��ѡ������Ҫ�����ָ��" << endl
				<<"1������ƴ����ĸ����"<<endl
				<<"2�����併������"<<endl;
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
				cout << "��Ч��ָ�����������" << endl;
				goto entrance_sort;
			}
				break;
			}
		case 3:
			{
			cout << "����������Ҫͳ�Ƶĵ����ı��" << endl;
			int a = 0;
			cin >> a;
			cout<<"�����б����ڸõص�������"<<statistics_in_region(Operating_list, a) << endl;
			break;
			}
		case 4:
			{
				show_all(Operating_list);
				break;
			}
		case 5:
			{entrance_5:
				cout << "��ѡ������Ҫɸѡ�����ͣ�" << endl
				<< "1������ѧ��" << endl
				<< "2�����ؾ�ҵ��" << endl
				<< "3�����ѧ��" << endl
				<< "4����ؾ�ҵ��" << endl;
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
					cout << "��Чָ�����������" << endl;
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
		cout << "��������Ҫ���������𣿣�Y/N��" << endl;
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
			cout << "��Ч��ָ����������롣" << endl;
			goto bool_continue;
		}
	}
	save_file_list(region, Operating_list);
	system("pause");
	return 0;
}