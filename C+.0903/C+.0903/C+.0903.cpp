#include <iostream>
#include <fstream>
using namespace std;
//友元函数
class FTest{
	int m_a;
	int m_b;
public:
	FTest() :
		m_a(0),
		m_b(0){

	}

	FTest(int a, int b) :
		m_a(a),
		m_b(b){

	}
	void setNum(int a, int b);

	friend ostream & operator << (ostream & os, FTest & data);//友元函数，friend为关键字
	friend istream & operator >> (istream & is, FTest & data);
	friend class FTest2;
};

class FTest2{
public:
	FTest2(){
		FTest ft(2, 3);
		cout << ft.m_a << endl;
	}
};

void FTest::setNum(int a, int b){
	m_a = a;
	m_b = b;
}

ostream & operator << (ostream & os,FTest & data){
	os << data.m_a << ' ' << data.m_b;
	return os;
}

istream & operator >> (istream & is, FTest & data){
	is >> data.m_a >> data.m_b;
	return is;
}

class A{
	class B{
		int a;
		int b;
	}a;
	int b;
};


int main(){

	FTest ft;
	ifstream is("1.txt");


	is >> ft;
	cout << ft << endl;
	is.close();

	system("pause");
	return 0; 
}