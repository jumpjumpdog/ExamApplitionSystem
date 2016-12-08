#include "StuInformation.h"

int stuInfor::i = 0;

stuInfor::stuInfor() {
	next = nullptr;
}

stuInfor::stuInfor(const string & _examNum, const string & _name, bool _gender, int _age, const string &_type) {
	this->data.examNum = _examNum;
	this->data.name = _name;
	this->data.gender = _gender;
	this->data.age = _age;
	this->data.type = _type;
	this->next = nullptr;
}

stuInfor::stuInfor(const stuInfor* pStuInfor) {                        //�ڵ�Ŀ������캯��
	this->data.examNum = pStuInfor->data.examNum;
	this->data.name = pStuInfor->data.name;
	this->data.gender = pStuInfor->data.gender;
	this->data.age = pStuInfor->data.age;
	this->data.type = pStuInfor->data.type;
	this->next = pStuInfor->next;
}


stuInfor::~stuInfor() {

}
StuInformation::StuInformation()
{
	stuInfor* last,*tempNode;
	last = root = new stuInfor();

	cin >> numTotal;
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������!" << endl;
	 
	for (int i = 0; i <numTotal; i++) {
		tempNode = new stuInfor();
		if ( NULL == tempNode)
		{
			cerr << "lack memory!";
			exit(1);
		}
		cin >> tempNode->data.examNum >> tempNode->data.name >> tempNode->data.gender >> tempNode->data.age >> tempNode->data.type;
		last->next = tempNode;
		last = tempNode;                                                     //rootΪ����ͷ�ڵ㣬���ڲ���
	}
}

StuInformation::~StuInformation()
{
}


void StuInformation::insert(int pos){
	int i = 0;
	stuInfor* current;

	auto newNode = new stuInfor();
	if (nullptr == newNode){
		cerr << "lack memory!";
		exit(1);
	}
	cout << "���������뿼���Ŀ��ţ��������Ա������Լ��������";
	cin >> newNode->data.examNum >> newNode->data.name >> newNode->data.gender >> newNode->data.age >> newNode->data.type;

	current = search(pos - 1);
	if (current) {
		newNode->next = current->next;
		current->next = newNode;
		numTotal++;
		outPut();
		return;
	}
	else
		delete newNode;
	return;
}


stuInfor* StuInformation::search(int pos) {
	if (pos < 0 || pos > numTotal)
	{
		cout << "out of range!" << endl;
		return NULL;
	}
	else {
		stuInfor* current;
		current = root;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
		return current;
	}
	
	
}

stuInfor* StuInformation::search( string & p) {
	stuInfor* current = root;
	if (!root)
		return NULL;
	while (current->next)
	{
		if (p == current->next->data.examNum)
			return current;
		else
			current = current->next;
	}
	return NULL;
}


void StuInformation::deleteNode( string& p) {
	stuInfor* current,*tempNode;
	current = search(p);
	if (!current) {
		cout << "No Such Student!" << endl;
  }
	else {
		cout << "��Ҫɾ���Ŀ�������Ϣ�ǣ�" << endl;
		showNode(p);
		tempNode = current->next;
 		current->next = current->next->next;
		delete tempNode;
		numTotal--;
	}
}


void StuInformation::modifyNode(string& q) {
	stuInfor* p = search(q);
	p = p->next;
	showNode(q);
	cout << "��������Ҫ�޸ĵĿ�������Ϣ��" << endl;
	cin >> p->data.examNum >> p->data.name >> p->data.gender >> p->data.age >> p->data.type;
}




void StuInformation::sort(bool mark) {                      //��������mark=1 ����mark=0 ����
	stuData* a = new stuData[numTotal + 1];
	stuInfor* p = root->next;
	for (int i = 1; i <= numTotal; i++)
	{
		a[i] = p->data;
		p = p->next;
	}
           
	int k;
	for (int i = 1; i < numTotal; i++) {
		k = i;
		for (int j = i+1; j <= numTotal; j++)
		{
			if (1 == mark&&a[k].examNum > a[j].examNum)
				k = j;
			else if (0 == mark&&a[k].examNum < a[j].examNum)
				k = j;
		}
		if (k != i)
		{
			stuData temp;
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	
	k = 1;
	p = root;
	while (NULL != p->next) {
		p->next->data = a[k++];
		p = p->next;
	}
}



void StuInformation::outPut(bool mark) {                    //mark=1 �������  mark=0 �������
	auto current = root;
	cout << "����    ����     �Ա�      ����        �������" << endl;
	sort(mark);
	while (current->next) {
		cout << current->next->data.examNum << "  " << current->next->data.name <<"  "<< current->next->data.gender << "  " << current->next->data.age << "  " << current->next->data.type << endl;
		current = current->next;
	}
}

void StuInformation::outPut() {
	auto current = root;
	cout << "����    ����     �Ա�      ����        �������" << endl;
	while (current->next) {
		cout << current->next->data.examNum << "  " << current->next->data.name << "  " << current->next->data.gender << "  " << current->next->data.age << "  " << current->next->data.type << endl;
		current = current->next;
	}
}

void StuInformation::showNode(string & q) {               //���ָ���ڵ������
	stuInfor* p = search(q);
	p = p->next;
	cout << "����    ����     �Ա�      ����        �������" << endl;
	cout << p->data.examNum << " " << p->data.name << " " << p->data.gender << " " << p->data.age << " " << p->data.type << endl;
}

void StuInformation::clearList() {                          //����������渽��ͷ�ڵ�
	stuInfor*temp, *pRoot;
	
	temp = root->next;
	while (temp) {
		pRoot = temp->next;
		delete(temp);
		temp = pRoot;
	}
	root->next = NULL;
}
 
int StuInformation::getListSize() {                        //�õ�������
	return numTotal;
}

bool StuInformation::isEmptyList() {                          //�ж������Ƿ�Ϊ��
	return numTotal;
}