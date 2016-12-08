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
	cout << "请输入考生人数:";
	StuInformation* myExamApplitionSystem = new StuInformation();
	
	cout << "请选择您要进行的操作（1为插入,2为删除，3为查找，4为修改，5为统计，0为取消操作）:";
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
		cout << "请选择您要进行的操作（1为插入,2为删除，3为查找，4为修改，5为统计，0为取消操作）:";
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
	cout << "请输入你要插入的考生的位置：";
	cin >> position;
	p->insert(position);
}

void delFunc(StuInformation* p) {
	string examNum;
	cout << "请输入你要删除的考生的考号";
	cin >> examNum;
	p->deleteNode(examNum);
}


void searchFunc(StuInformation* p) {
	string examNum;
	cout << "请输入你要查找的考生的考号：";
	cin >> examNum;
	cout << "考号    姓名     性别      年龄        报考类别" << endl;
	p->showNode(examNum);
}


void modifyFunc(StuInformation* p) {
	string examNum;
	cout << "请输入你要修改的考生的考号：";
	cin >> examNum;
	p->modifyNode(examNum);
}