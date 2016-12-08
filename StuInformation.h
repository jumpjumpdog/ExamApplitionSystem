#pragma once
#ifndef STUINFORMATION
#define STUINFORMATION

#include"string"
#include"iostream"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

typedef string ElemType_1;
typedef int ElemType_2;

struct stuData {
	ElemType_1 examNum;
	ElemType_1 name;
	ElemType_1 gender;
	ElemType_2 age;
	ElemType_1 type;
};

struct stuInfor {

	stuData data;
	stuInfor *next;
	static int i ;
   
	stuInfor();
	stuInfor(const string & _examNum, const string & _name, bool _gender, int _age, const string &_type);
	stuInfor(const stuInfor* pStuInfor);
	~stuInfor();
	

};











class StuInformation
{
public:
	stuInfor* root;
	int numTotal;

	StuInformation();
	~StuInformation();
	void insert(int);
	stuInfor* search(int);
	stuInfor* search( string&);
	void deleteNode( string&);
	void outPut(bool);
	void outPut();
	void showNode(string &);
	void modifyNode(string &);
	void sort(bool);                       //ÅÅÐòº¯Êý
	void clearList();
	int getListSize();
	bool isEmptyList();
};

#endif 