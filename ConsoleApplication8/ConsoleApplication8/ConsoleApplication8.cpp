
#include<iostream>
using namespace std;
class Point {
public:
	void setX(int x) { this->x = x; }
	int getX() { return x; }
	void setY(int y) { this->y = y; }
	int getY() { return y; }
private:
	int x;
	int y;
};

// 修改：Cycle→Circle
class Circle {
public:
	void setR(int r) { this->r = r; }
	int getR() { return r; }
	void setCenter(Point center) { this->center = center; }
	Point getCenter() { return center; }
private:
	int r;
	Point center;
};

// 判断点和圆位置
void isInCircle(Circle& c, Point& p) {
	int dx = c.getCenter().getX() - p.getX();
	int dy = c.getCenter().getY() - p.getY();
	int distance = dx * dx + dy * dy;
	int rDistance = c.getR() * c.getR();
	if (distance < rDistance) cout << "点在圆内" << endl;
	else if (distance == rDistance) cout << "点在圆上" << endl;
	else cout << "点在圆外" << endl;
}

// 立方体类
class Cube {
public:
	void setl(int l) { m_length = l; }
	int getLgenth() { return m_length; }
	void setw(int w) { m_width = w; }
	int getWidth() { return m_width; }
	void seth(int h) { m_height = h; }
	int getHeight() { return m_height; }
	int calculateS() { return 2 * (m_length * m_width + m_length * m_height + m_width * m_height); }
	int calculateV() { return m_length * m_width * m_height; }
private:
	int m_length, m_width, m_height;
};

int main() {
	Cube c;
	c.setl(3); c.setw(4); c.seth(5);
	cout << "长:" << c.getLgenth() << endl;
	cout << "宽:" << c.getWidth() << endl;
	cout << "高:" << c.getHeight() << endl;
	cout << "表面积:" << c.calculateS() << endl;
	cout << "体积:" << c.calculateV() << endl;

	Circle c1;
	c1.setR(5);
	Point p1;
	p1.setX(3); p1.setY(4);
	c1.setCenter(p1);
	Point p2;
	p2.setX(5); p2.setY(5);
	isInCircle(c1, p1);
	return 0;
}