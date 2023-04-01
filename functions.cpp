#include "myhead.h"
//读取某个地区文件夹中的所有类型的人的信息
vector<Person*> get_file_list(string region)
{
	vector<Person*> list;
	string filename = "files/" + region + "/Out_Worker.csv";
	fstream file;
	string temp;
	file.open(filename, ios::in);
	
	getline(file, temp);//去掉标题行
	while(getline(file,temp))
	{
		for(int i=0;i<temp.length();i++)
		{
			if (temp[i] == ',')
				temp[i] = ' ';
		}
		stringstream ss(temp);
		Person* p;
		p = new Out_Worker;
		p->set(ss);
		list.push_back(p);
	}
	file.close();

	filename = "files/" + region + "/Out_Student.csv";
	file.open(filename, ios::in);
	getline(file, temp);
	while (getline(file, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == ',')
				temp[i] = ' ';
		}
		stringstream ss(temp);
		Person* p;
		p = new Out_Student;
		p->set(ss);
		list.push_back(p);
	}
	file.close();


	filename = "files/" + region + "/Here_Student.csv";
	file.open(filename, ios::in);
	getline(file, temp);
	while (getline(file, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == ',')
				temp[i] = ' ';
		}
		stringstream ss(temp);
		Person* p;
		p = new Here_Student;
		p->set(ss);
		list.push_back(p);
	}
	file.close();

	filename = "files/" + region + "/Here_Worker.csv";
	file.open(filename, ios::in);
	getline(file, temp);
	while (getline(file, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == ',')
				temp[i] = ' ';
		}
		stringstream ss(temp);
		Person* p;
		p = new Here_Worker;
		p->set(ss);
		list.push_back(p);
	}
	file.close();

	return  list;
}

//这个函数用于程序运行结束的时候统一更新一遍外部文件，然后删除内存。
void save_file_list(string region,vector<Person*>& list)
{
	string filename = "files/" + region + "/Out_Worker.csv";
	fstream file;
	file.open(filename, ios::out);
	file << "姓名" << "," << "性别" << "," << "年龄" << "," << "电话号码" << "," << "工作单位" << "," << "离开时间"
		<< "," << "现住址" << "," << "现住址编号" << endl;
	file.close();
	for(int i=0;i<list.size();i++)
	{
		if(list[i]->get_type()=="Out_Worker")
		{
			list[i]->save_to_file(filename);
		}
	}

	filename = "files/" + region + "/Out_Student.csv";
	file.open(filename, ios::out);
	file << "姓名" << "," << "性别" << "," << "年龄" << "," << "电话号码" << "," << "学校" << "," << "离开时间"
		<< "," << "现住址" << "," << "现住址编号" << endl;
	file.close();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Out_Student")
		{
			list[i]->save_to_file(filename);
		}
	}


	filename = "files/" + region + "/Here_Student.csv";
	file.open(filename, ios::out);
	file << "姓名" << "," << "性别" << "," << "年龄" << "," << "电话号码" << "," << "学校" << "," << "到来时间"
		<< "," << "原住址" << "," << "原住址编号" << endl;
	file.close();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Here_Student")
		{
			list[i]->save_to_file(filename);
		}
	}

	filename = "files/" + region + "/Here_Worker.csv";
	file.open(filename, ios::out);
	file << "姓名" << "," << "性别" << "," << "年龄" << "," << "电话号码" << "," << "工作单位" << "," << "到来时间"
		<< "," << "原住址" << "," << "原住址编号" << endl;
	file.close();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Here_Worker")
		{
			list[i]->save_to_file(filename);
		}
	}

	/*for(int i=0;i<list.size();i++)
	{
		delete list[i];
		list[i]= nullptr;
	}
	list.clear();*/
}

//往列表中输入个人信息，最新的信息储存在容器里。
void input_information(string region,vector<Person*>& list)
{
	char a;
	entrance:
	cout << "请选择你需要登记的人员类型" << endl
		<< "1、本地就业人员" << endl
		<< "2、外地就业人员" << endl
		<< "3、本地学生" << endl
		<< "4、外地学生" << endl;

	cin >> a;

	switch (a)
	{
	case '1':
		{
			Person* hw = new Here_Worker;
			string file_name = "files/" + region + "/Out_Worker.csv";
			cout << "请依次输入以下信息：" << endl <<
				"姓名  性别  年龄  电话号码  工作单位  何时到本地  从何地来  原住址编号" << endl;
			hw->set(cin);
			hw->save_to_file(file_name);
			list.push_back(hw);
			break;
		}
	case '2':
		{
			Person* ow=new Out_Worker;
			string file_name = "files/" + region + "/Out_Worker.csv";
			cout << "请依次输入以下信息：" << endl <<
				"姓名  性别  年龄  电话号码  工作单位  离开时间  现住址  现住址编号" << endl;
			ow->set(cin);
			ow->save_to_file(file_name);
			list.push_back(ow);
			break;
		}
	case '3':
		{
		Person* hs = new Here_Student;
		string file_name = "files/" + region + "/Out_Student.csv";
		cout << "请依次输入以下信息：" << endl <<
			"姓名  性别  年龄  电话号码  学校  何时到本地  原住址  原住址编号" << endl;
		hs->set(cin);
		hs->save_to_file(file_name);
		list.push_back(hs);
		break;
		}
	case '4':
		{
			Person* os = new Out_Student;
			string file_name = "files/" + region + "/Out_Student.csv";
			cout << "请依次输入以下信息：" << endl <<
				"姓名  性别  年龄  电话号码  学校  离开时间  现住址  现住址编号" << endl;
			os->set(cin);
			os->save_to_file(file_name);
			list.push_back(os);
			break;
		}
	default:
		{
			cout << "输入错误，请重新输入." << endl;
			goto entrance;
		}
	}
}

//查找某个名字所对应的信息，如果找到了就返回索引值，否则返回-1.
int find_name(vector<Person*>list, string name)
{
	for(int i=0;i<list.size();i++)
	{
		if (list[i]->get_name() == name)
			return i;
	}
	return -1;
}

//要做的是把指向的这个人的index操作，使之在list里面是变化的，最后再考虑导出
void move_in(int i,vector<Person*>&list)
{
	if(list[i]->bool_here())
	{
		cout << "此人已经居住在本地" << endl;
	}
	else
	{
		cout << "请问您的身份是？1、学生； 2、就业者" << endl;
		int num;
		Person* p= nullptr;
		cin >> num;
		if (num == 1)
			 p = new Here_Student(*(Out_Student*)list[i]);
		else if (num == 2)
			 p = new Here_Worker(*(Out_Worker*)list[i]);

		cout << "请输入你从哪里回来，以及该地的编号" << endl;
		string address;
		int address_num;
		cin >> address >> address_num;

		((Here_Population*)p)->set_address_from_info(address, address_num);

		//delete list[i];
		list[i] = p;
		//p = nullptr;
		//list.erase(list.begin()+i, list.begin()+i+1);
	}
}

void move_out (int i,vector<Person*>& list)
{
	if(!list[i]->bool_here())
	{
		cout << "此人已经迁出到外地" << endl;
	}
	else
	{
		cout << "请问您的身份是？1、学生； 2、就业者" << endl;
		int num;
		Person* p= nullptr;
		cin >> num;
		if (num == 1)
			p = new Out_Student(*(Here_Student*)list[i]);
		else if (num == 2)
			p = new Out_Worker(*(Here_Worker*)list[i]);
		cout << "请输出您需要外出的地点，以及该地的地址编号" << endl;
		string address;
		int address_num;
		cin >> address >> address_num;
		((Out_Population*)p)->set_address_now_info(address, address_num);

		//delete list[i];
		list[i] = p;
		//p = nullptr;
		//list.erase(list.begin() + i, list.begin() + i + 1);
	}
}

void sent_message(string name,vector<Person*> list)
{
	for(int i=0;i<list.size();i++)
	{
		if(list[i]->get_name()==name)
		{
			//短信内容以后再改
			list[i]->phone.put_message("根据疫情防控指挥部显示，您在14天内曾到过中高风险地区，\n请您尽快就近参加核酸检测，感谢您的配合。");
		}
	}
}

void sort_by_age(vector<Person*>& list)
{
	Person* temp= nullptr;
	int max = 0,index=0;
	for(int i=0;i<list.size()-1;i++)
	{
		max = list[i]->get_age();
		index = i;
		for(int j=i+1;j<list.size();j++)
		{
			if(list[j]->get_age()>max)
			{
				index = j;
				max = list[j]->get_age();
			}
		}
		//交换
		temp = list[i];
		list[i] = list[index];
		list[index] = temp;
		temp = nullptr;
	}
	show_all(list);
}

void sort_by_name(vector<Person*>& list)
{
	Person* temp= nullptr;
	string min_name;
	int min_index;
	for(int i=0;i<list.size()-1;i++)
	{
		min_name = list[i]->get_name();
		min_index = i;
		for(int j=i+1;j<list.size();j++)
		{
			if(list[j]->get_name()<min_name)
			{
				min_name = list[j]->get_name();
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
		temp = nullptr;
	}
	show_all(list);
}

//只统计外地的，不统计本地的，后面筛选可以筛出本地的
int statistics_in_region(vector<Person*> list,int address_num)
{
	int num = 0;
	for(int i=0;i<list.size();i++)
	{
		if(((Out_Population*)list[i])->get_address_num()==address_num&&list[i]->bool_here()==false)
		{
			list[i]->show();
			num++;
		}
	}
	return num;
}

void show_here(vector<Person*> list)
{
	int num=0;
	for(int i=0;i<list.size();i++)
	{
		if(list[i]->bool_here())
		{
			list[i]->show();
			num++;
		}
	}
	cout << "总人数是：" << num << endl;
}

void show_not_here(vector<Person*> list)
{
	int num = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (!list[i]->bool_here())
		{
			list[i]->show();
			num++;
		}
	}
	cout << "总人数是：" << num << endl;
}

void show_type(string type,vector<Person*> list)
{
	cout.setf(ios::left);
	if(type=="Here_Worker")
		cout<<setw(8)<<"姓名"<<setw(6)<<"性别"<<setw(6)<<"年龄"<<setw(12)<<  "电话号码"
	<<setw(20)<<"工作单位"<<setw(12)<<"何时返回"<<setw(20) << "原住址"
	<<setw(6)<<"原住址编号" << endl;
	else if(type=="Here_Student")
		cout << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "学校" << setw(12) << "何时返回" << setw(20) << "原住址"
		<< setw(6) << "原住址编号" << endl;
	else if(type=="Out_Worker")
		cout << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "工作单位" << setw(12) << "离开时间" << setw(20) << "现住址"
		<< setw(6) << "现住址编号" << endl;
	else if(type=="Out_Student")
		cout << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "学校" << setw(12) << "离开时间" << setw(20) << "现住址"
		<< setw(6) << "现住址编号" << endl;
	for(int i=0;i<list.size();i++)
	{
		if (list[i]->get_type() == type)
			list[i]->show();
	}
}

void show_all(vector<Person*>list)
{
	cout.setf(ios::left);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 0xF1);
	cout << "本地就业人员:"<<endl
	<< setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "工作单位" << setw(12) << "何时返回" << setw(20) << "原住址"
		<< setw(6) << "原住址编号" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for(int i=0;i<list.size();i++)
	{
		if(list[i]->get_type()=="Here_Worker")
			list[i]->show();
	}

	SetConsoleTextAttribute(hOut, 0xF1);
	cout <<endl<< "外地就业人员:" << endl<<setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "工作单位" << setw(12) << "离开时间" << setw(20) << "现住址"
		<< setw(6) << "现住址编号" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Out_Worker")
			list[i]->show();
	}
	SetConsoleTextAttribute(hOut, 0xF1);
	cout << endl << "本地学生:" << endl << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "学校" << setw(12) << "何时返回" << setw(20) << "原住址"
		<< setw(6) << "原住址编号" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Here_Student")
			list[i]->show();
	}
	SetConsoleTextAttribute(hOut, 0xF1);
	cout << endl << "外地学生:" << endl << setw(8) << "姓名" << setw(6) << "性别" << setw(6) << "年龄" << setw(12) << "电话号码"
		<< setw(20) << "学校" << setw(12) << "离开时间" << setw(20) << "现住址"
		<< setw(6) << "现住址编号" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Out_Student")
			list[i]->show();
	}

	cout << endl << "总人数：" << list.size() << endl << endl;
}

void  get_risky_Person(vector<Person*> list)
{
	vector<string> temp;
	cout << "请输入某个中高风险地区的地区编号" << endl;
	int num;
	cin >> num;
	for(int i=0;i<list.size();i++)
	{
		if (num == list[i]->get_address_num())
			list[i]->show();
	}
}

void suansuan(vector<Person*>list,string region)
{
	for(int i=0;i<list.size();i++)
	{
		if (list[i]->bool_here())
			list[i]->phone.put_message("新冠肺炎疫情防控指挥部办公室提醒您:疫情防控形势严峻，现开展全员核酸检测。\n如您在收到该信息近72小时内未做核酸检测，请尽快前往就近临时采样点(或医疗机构)进行核酸检测。\n请您前往做核酸检测过程中做好个人防护， 尽量不要与其他人员接触，避免人群聚集。感谢您的配合。");
	}
	cout << endl << "短信已发送。" << endl;
}