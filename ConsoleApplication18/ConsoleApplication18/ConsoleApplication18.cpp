#include<iostream>
#include<string>
using namespace std;

class BathPage{
public:
	void hheader() {
		cout << "首页、公开课、登陆、注册..（gomggongtoubuu)" << endl;
	}
	void footer() {
		cout << "底部信息、版权信息、联系方式..（gomggongtoubuu)" << endl;
	}
	void left() {
		cout << "左侧信息、导航栏、分类信息..（gomggongtoubuu)" << endl;
	}
	void right() {
		cout << "右侧信息、广告栏、推荐信息..（gomggongtoubuu)" << endl;
	}
};
class Java :public BathPage 
{
public:
	void content(){
		cout << "Java课程页面信息（gomggongtoubuu)" << endl;
	}
};
class c :public BathPage
{
public:
	void content() {
		cout << "C课程页面信息（gomggongtoubuu)" << endl;
	}
};

void test01() {
	Java j;
	j.hheader();
	j.footer();
	j.left();
	j.right();
	j.content();
	c cl;
	cl.hheader();
	cl.footer();
	cl.left();
	cl.right();
	cl.content();
}

int main() {
	test01();
	return 0;
}