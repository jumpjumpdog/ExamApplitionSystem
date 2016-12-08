#include"StuInformation.h"

typedef enum choice{
	cancel,insert, del,search,modify,statistic
};


void insertFunc(StuInformation*);
void delFunc(StuInformation*);
void searchFunc(StuInformation*);
void modifyFunc(StuInformation*);

int main() {

	choice mychoice;
	int temp=-1;
	cout << "�����뿼������:";
	StuInformation* myExamApplitionSystem = new StuInformation();
	
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ����,2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������:";
	cin >> temp;
	mychoice = (choice)temp;
	while (cancel!=mychoice) {
		switch (mychoice) {
        case insert:insertFunc(myExamApplitionSystem); break;
		case del:delFunc(myExamApplitionSystem); break;
		case search:searchFunc(myExamApplitionSystem); break;
		case modify:modifyFunc(myExamApplitionSystem); break;
		case statistic:break;
		}
		cout << "��ѡ����Ҫ���еĲ�����1Ϊ����,2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������:";
		cin >> temp;
		mychoice = (choice)temp;
	}

	/*myExamApplitionSystem->sort(1);

	myExamApplitionSystem->clearList();
	myExamApplitionSystem->outPut(true);*/
	return 0;
}

void insertFunc(StuInformation* p) {
	int position;
	cout << "��������Ҫ����Ŀ�����λ�ã�";
	cin >> position;
	p->insert(position);
}

void delFunc(StuInformation* p) {
	string examNum;
	cout << "��������Ҫɾ���Ŀ����Ŀ���";
	cin >> examNum;
	p->deleteNode(examNum);
}


void searchFunc(StuInformation* p) {
	string examNum;
	cout << "��������Ҫ���ҵĿ����Ŀ��ţ�";
	cin >> examNum;
	cout << "����    ����     �Ա�      ����        �������" << endl;
	p->showNode(examNum);
}


void modifyFunc(StuInformation* p) {
	string examNum;
	cout << "��������Ҫ�޸ĵĿ����Ŀ��ţ�";
	cin >> examNum;
	p->modifyNode(examNum);
}