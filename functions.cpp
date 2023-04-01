#include "myhead.h"
//��ȡĳ�������ļ����е��������͵��˵���Ϣ
vector<Person*> get_file_list(string region)
{
	vector<Person*> list;
	string filename = "files/" + region + "/Out_Worker.csv";
	fstream file;
	string temp;
	file.open(filename, ios::in);
	
	getline(file, temp);//ȥ��������
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

//����������ڳ������н�����ʱ��ͳһ����һ���ⲿ�ļ���Ȼ��ɾ���ڴ档
void save_file_list(string region,vector<Person*>& list)
{
	string filename = "files/" + region + "/Out_Worker.csv";
	fstream file;
	file.open(filename, ios::out);
	file << "����" << "," << "�Ա�" << "," << "����" << "," << "�绰����" << "," << "������λ" << "," << "�뿪ʱ��"
		<< "," << "��סַ" << "," << "��סַ���" << endl;
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
	file << "����" << "," << "�Ա�" << "," << "����" << "," << "�绰����" << "," << "ѧУ" << "," << "�뿪ʱ��"
		<< "," << "��סַ" << "," << "��סַ���" << endl;
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
	file << "����" << "," << "�Ա�" << "," << "����" << "," << "�绰����" << "," << "ѧУ" << "," << "����ʱ��"
		<< "," << "ԭסַ" << "," << "ԭסַ���" << endl;
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
	file << "����" << "," << "�Ա�" << "," << "����" << "," << "�绰����" << "," << "������λ" << "," << "����ʱ��"
		<< "," << "ԭסַ" << "," << "ԭסַ���" << endl;
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

//���б������������Ϣ�����µ���Ϣ�����������
void input_information(string region,vector<Person*>& list)
{
	char a;
	entrance:
	cout << "��ѡ������Ҫ�Ǽǵ���Ա����" << endl
		<< "1�����ؾ�ҵ��Ա" << endl
		<< "2����ؾ�ҵ��Ա" << endl
		<< "3������ѧ��" << endl
		<< "4�����ѧ��" << endl;

	cin >> a;

	switch (a)
	{
	case '1':
		{
			Person* hw = new Here_Worker;
			string file_name = "files/" + region + "/Out_Worker.csv";
			cout << "����������������Ϣ��" << endl <<
				"����  �Ա�  ����  �绰����  ������λ  ��ʱ������  �Ӻε���  ԭסַ���" << endl;
			hw->set(cin);
			hw->save_to_file(file_name);
			list.push_back(hw);
			break;
		}
	case '2':
		{
			Person* ow=new Out_Worker;
			string file_name = "files/" + region + "/Out_Worker.csv";
			cout << "����������������Ϣ��" << endl <<
				"����  �Ա�  ����  �绰����  ������λ  �뿪ʱ��  ��סַ  ��סַ���" << endl;
			ow->set(cin);
			ow->save_to_file(file_name);
			list.push_back(ow);
			break;
		}
	case '3':
		{
		Person* hs = new Here_Student;
		string file_name = "files/" + region + "/Out_Student.csv";
		cout << "����������������Ϣ��" << endl <<
			"����  �Ա�  ����  �绰����  ѧУ  ��ʱ������  ԭסַ  ԭסַ���" << endl;
		hs->set(cin);
		hs->save_to_file(file_name);
		list.push_back(hs);
		break;
		}
	case '4':
		{
			Person* os = new Out_Student;
			string file_name = "files/" + region + "/Out_Student.csv";
			cout << "����������������Ϣ��" << endl <<
				"����  �Ա�  ����  �绰����  ѧУ  �뿪ʱ��  ��סַ  ��סַ���" << endl;
			os->set(cin);
			os->save_to_file(file_name);
			list.push_back(os);
			break;
		}
	default:
		{
			cout << "�����������������." << endl;
			goto entrance;
		}
	}
}

//����ĳ����������Ӧ����Ϣ������ҵ��˾ͷ�������ֵ�����򷵻�-1.
int find_name(vector<Person*>list, string name)
{
	for(int i=0;i<list.size();i++)
	{
		if (list[i]->get_name() == name)
			return i;
	}
	return -1;
}

//Ҫ�����ǰ�ָ�������˵�index������ʹ֮��list�����Ǳ仯�ģ�����ٿ��ǵ���
void move_in(int i,vector<Person*>&list)
{
	if(list[i]->bool_here())
	{
		cout << "�����Ѿ���ס�ڱ���" << endl;
	}
	else
	{
		cout << "������������ǣ�1��ѧ���� 2����ҵ��" << endl;
		int num;
		Person* p= nullptr;
		cin >> num;
		if (num == 1)
			 p = new Here_Student(*(Out_Student*)list[i]);
		else if (num == 2)
			 p = new Here_Worker(*(Out_Worker*)list[i]);

		cout << "�������������������Լ��õصı��" << endl;
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
		cout << "�����Ѿ�Ǩ�������" << endl;
	}
	else
	{
		cout << "������������ǣ�1��ѧ���� 2����ҵ��" << endl;
		int num;
		Person* p= nullptr;
		cin >> num;
		if (num == 1)
			p = new Out_Student(*(Here_Student*)list[i]);
		else if (num == 2)
			p = new Out_Worker(*(Here_Worker*)list[i]);
		cout << "���������Ҫ����ĵص㣬�Լ��õصĵ�ַ���" << endl;
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
			//���������Ժ��ٸ�
			list[i]->phone.put_message("�����������ָ�Ӳ���ʾ������14�����������и߷��յ�����\n��������ͽ��μӺ����⣬��л������ϡ�");
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
		//����
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

//ֻͳ����صģ���ͳ�Ʊ��صģ�����ɸѡ����ɸ�����ص�
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
	cout << "�������ǣ�" << num << endl;
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
	cout << "�������ǣ�" << num << endl;
}

void show_type(string type,vector<Person*> list)
{
	cout.setf(ios::left);
	if(type=="Here_Worker")
		cout<<setw(8)<<"����"<<setw(6)<<"�Ա�"<<setw(6)<<"����"<<setw(12)<<  "�绰����"
	<<setw(20)<<"������λ"<<setw(12)<<"��ʱ����"<<setw(20) << "ԭסַ"
	<<setw(6)<<"ԭסַ���" << endl;
	else if(type=="Here_Student")
		cout << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "ѧУ" << setw(12) << "��ʱ����" << setw(20) << "ԭסַ"
		<< setw(6) << "ԭסַ���" << endl;
	else if(type=="Out_Worker")
		cout << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "������λ" << setw(12) << "�뿪ʱ��" << setw(20) << "��סַ"
		<< setw(6) << "��סַ���" << endl;
	else if(type=="Out_Student")
		cout << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "ѧУ" << setw(12) << "�뿪ʱ��" << setw(20) << "��סַ"
		<< setw(6) << "��סַ���" << endl;
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
	cout << "���ؾ�ҵ��Ա:"<<endl
	<< setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "������λ" << setw(12) << "��ʱ����" << setw(20) << "ԭסַ"
		<< setw(6) << "ԭסַ���" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for(int i=0;i<list.size();i++)
	{
		if(list[i]->get_type()=="Here_Worker")
			list[i]->show();
	}

	SetConsoleTextAttribute(hOut, 0xF1);
	cout <<endl<< "��ؾ�ҵ��Ա:" << endl<<setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "������λ" << setw(12) << "�뿪ʱ��" << setw(20) << "��סַ"
		<< setw(6) << "��סַ���" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Out_Worker")
			list[i]->show();
	}
	SetConsoleTextAttribute(hOut, 0xF1);
	cout << endl << "����ѧ��:" << endl << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "ѧУ" << setw(12) << "��ʱ����" << setw(20) << "ԭסַ"
		<< setw(6) << "ԭסַ���" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Here_Student")
			list[i]->show();
	}
	SetConsoleTextAttribute(hOut, 0xF1);
	cout << endl << "���ѧ��:" << endl << setw(8) << "����" << setw(6) << "�Ա�" << setw(6) << "����" << setw(12) << "�绰����"
		<< setw(20) << "ѧУ" << setw(12) << "�뿪ʱ��" << setw(20) << "��סַ"
		<< setw(6) << "��סַ���" << endl;
	SetConsoleTextAttribute(hOut, 0xF0);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->get_type() == "Out_Student")
			list[i]->show();
	}

	cout << endl << "��������" << list.size() << endl << endl;
}

void  get_risky_Person(vector<Person*> list)
{
	vector<string> temp;
	cout << "������ĳ���и߷��յ����ĵ������" << endl;
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
			list[i]->phone.put_message("�¹ڷ����������ָ�Ӳ��칫��������:������������Ͼ����ֿ�չȫԱ�����⡣\n�������յ�����Ϣ��72Сʱ��δ�������⣬�뾡��ǰ���ͽ���ʱ������(��ҽ�ƻ���)���к����⡣\n����ǰ������������������ø��˷����� ������Ҫ��������Ա�Ӵ���������Ⱥ�ۼ�����л������ϡ�");
	}
	cout << endl << "�����ѷ��͡�" << endl;
}