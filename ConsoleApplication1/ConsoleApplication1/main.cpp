#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//set class Teacher and Cadre's son class T_C
class Teacher { //老师类
public:
	Teacher(string, int, char, string, long, string);
	void display();
protected:
	string name;
	int age;
	char sex;
	string address;
	long phonenum;
	string title;
};
Teacher::Teacher(string nam, int ag, char se, string add, long num, string tit) :name(nam), age(ag), sex(se), address(add), phonenum(num), title(tit) {}
void Teacher::display() {
	cout << endl << "name:" << setw(38) << setiosflags(ios::right) << name << endl;
	cout << "age:" << setw(38) << setiosflags(ios::right) << age << endl;
	cout << "sex:" << setw(38) << setiosflags(ios::right) << sex << endl;
	cout << "address:" << setw(38) << setiosflags(ios::right) << address << endl;
	cout << "phonenumber:" << setw(38) << setiosflags(ios::right) << phonenum << endl;
	cout << "title:" << setw(38) << setiosflags(ios::right) << title << endl;
}
class Cadre { //干部类
public:
	Cadre(string, int, char, string, long, string);
protected:
	string name;
	int age;
	char sex;
	string address;
	long phonenum;
	string post;
};
Cadre::Cadre(string s, int i, char c, string ss, long l, string sss) :name(s), age(i), sex(c), address(ss), phonenum(l), post(sss) {}
class Teacher_Cadre :public Teacher, public Cadre {
public:
	Teacher_Cadre(string nam, int ag, char se, string add, long num, string tit, string pos, int wag):
		Teacher(nam, ag,se,add,num,tit),Cadre(nam,ag,se,add,num,pos),wages(wag){}
	void show();
private:
	int wages;
}; 
void Teacher_Cadre::show() {
	Teacher::display();
	cout << "post:" << setw(38) << setiosflags(ios::right) << Cadre::post << endl;
	cout << "wages:" << setw(38) << setiosflags(ios::right) << wages << endl;
}

//运算符重载 Compare operator + (Compare x, Compare y);

//using template as max函数模板
template <typename Template_func>
Template_func max(Template_func a, Template_func b) {
	Template_func c = a > b ? a : b;
	return c;
}

//using class template as compare类模板
template <class Template_class>
class Compare
{
public:
	Compare(Template_class a, Template_class b) :x(a), y(b) {} //construct function
	Template_class max() {
		return x > y ? x : y;
	}Template_class min() {
		return x < y ? x : y;
	}
private:
	Template_class x, y;

}; // Compare <int> cmp(3.5, 11.34);

//struct of leader in vote
struct Leader {
	char name[10];
	int count;
};

//Hanoi tower
void hanoi(int n, char A, char B, char C) {
	if (n == 1)
		cout << "put " << n << " block from " << A << " to " << C << endl;
	else
	{
		hanoi(n - 1, A, C, B);
		cout << "put " << n << " block from " << A << " to " << C << endl;
		hanoi(n - 1, B, A, C);
	}

}

int main()
{
	//triangle B
	
	/*for (int i = 1; i < 9; i++) {
		cout << setw(9-i) << setfill(' ') << ' ' << setw(i*2-1) << setfill('B') << 'B' << endl;
	}*/
	
	
	//write in file
	/*
	ofstream outfile("D:/VScode/input.txt", ios::out|ios::app);
	if (!outfile) {
		cerr << "open error!" << endl;
		exit(0);
	}
	outfile << "the input content is my phonenumber: " << 15831535973 << endl;
	//outfile << "wrong answer" << endl;
	outfile.close();
	*/
	
	//派生类of老师和干部类进行输出
	//Teacher_Cadre tc("LiMing", 18, 'f', "Beijing 122street", 774221963, "professor", "master", 5000);
	//tc.show();

	//结构体：领导投票
	/*
	Leader leader[3] = { "wang",0,"muty",0,"zzn",0 };
	char vote[14];
	int i, j;
	for (i = 0; i < 10; i++) {
		cout << "name is :";
		cin >> vote;
		for (j = 0; j < 3; j++) {
			if (strcmp(vote, leader[j].name) == 0)
				leader[j].count++;
		}
	}cout << endl;
	for (i = 0; i < 3; i++) {
		cout << "the person whose name is " << setw(6) << leader[i].name << " got "
			<< setw(3) << leader[i].count << " votes totally!" << endl;
	}
	*/

	//hanoi tower
	/*
	void hanoi(int, char, char, char);
	char a = 'A', b = 'B',c = 'C';
	int n;
	cout << "print in n :" << endl;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	*/

	//调用通用函数模板↑template:max
	/*int x, y, z;
	cout << "write in a,b:" << endl;
	cin >> x >> y;
	z = max(x, y);
	cout << "max(a,b)=" << z << endl;*/
	/*float x, y, z;
	cout << "write in a,b:" << endl;
	cin >> x >> y;
	z = max(x, y);
	cout << "max(a,b)=" << setiosflags(ios::fixed) << setprecision(6) << z << endl;*/

	//足球队三对三比赛
	/*
	int x, y, z;
	for (x = 1; x < 4; x++) {
		for (y = 1; y < 4; y++) {
			if (x != y) {
				for (z = 1; z < 4; z++) {
					if (z != x && z != y) {
						if (x != 1 && z != 1 && z != 3) {
							cout << "x->" << char('a' - 1 + x) << endl;
							cout << "y->" << char('a' - 1 + y) << endl;
							cout << "z->" << char('a' - 1 + z) << endl;
						}
					}
				}
			}
		}
	}

	*/		

	//字母表后退四个数
	/*
	
	char c;
	do {
		cin >> c;
		if (c >= 'A'&& c <= 'Z' || c >= 'a' && c <= 'z')
		{
			c = c + 4;
			if (c > 'Z' && c <= 'Z'+4 || c > 'z' && c <= 'z'+4) //变换之后的基础上超出z的部分减去26
				c = c - 26;
		}
		cout << c;
	} while (c != '\n');
	cout << endl;
	
	*/

	//求素数using flag
	/*
	
	bool flag = true;
	for (int i = 101; i <= 200; i=i+2) {
		for (int j = 2; j <= int(sqrt(i)); j++) {
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag==true) cout << setw(5) << i << endl;
		flag = true;
	}

	*/		

	//斐波那契数列
	/*
	
	int f1 = 1, f2 = 1;
	long F = 0;
	for (int i = 1; i <= 40; i=i+2)
	{
		F = F + f1;
		F = F + f2;
		cout << setw(12) << f1;
		cout << setw(12) << f2;
		f1 = f1 + f2;
		f2 = f1 + f2;
		if ((i + 1) % 8 == 0) cout << endl;
	}cout << "F=" << F << endl;

	*/	

	//计算π
	/*

	int m;
	double n, t, pi;
	m = 1; n = t = 1;
	pi = 0;
	while (fabs(t) > 1e-7)
	{
		pi = pi + t;
		m = -m;
		n = n + 2;
		t = m / n;
		if(n<12) cout << "t=" << t << endl;
	}
	
	cout << "pi = " << setiosflags(ios::fixed) << setprecision(6) << pi * 4;

	*/

	//std::cout << "Hello World!\n";
}