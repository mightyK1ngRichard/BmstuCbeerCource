#pragma once
#include <iostream>
enum type_figure {
	type_point = 1,
	type_segment,
	type_triangle,
	type_rectangle
};

class point{
public:
	point();
	point(const int&, const int&);
	point(const point&);
	void AddPoint(const int&, const int&);
	~point() = default;
//private:
	int _x;
	int _y;
};
point::point() : _x(0), _y(0) {}
point::point(const int& x, const int& y) : _x(x), _y(y){}
point::point(const point& p) : _x(p._x), _y(p._y) {}
inline void point::AddPoint(const int& x, const int& y) {
	_x = x;
	_y = y;
}

class figure {
public:
	figure();
	~figure() = default;
	void Print() const;
	void Creat();
private:
	type_figure _type;
	point* _coordinate;
};
figure::figure() : _coordinate(nullptr), _type(type_point) {}
void figure::Print() const {
	switch (_type)
	{
	case type_point:
		std::cout << "A(" << _coordinate[0]._x << ',' << _coordinate[0]._y << ')' << std::endl;
		break;
	case type_segment:
		std::cout << "A(" << _coordinate[0]._x << ',' << _coordinate[0]._y << ')' << std::endl;
		std::cout << "B(" << _coordinate[1]._x << ',' << _coordinate[1]._y << ')' << std::endl;
		break;
	case type_triangle:
		std::cout << "A(" << _coordinate[0]._x << ',' << _coordinate[0]._y << ')' << std::endl;
		std::cout << "B(" << _coordinate[1]._x << ',' << _coordinate[1]._y << ')' << std::endl;
		std::cout << "C(" << _coordinate[2]._x << ',' << _coordinate[2]._y << ')' << std::endl;
		break;
	case type_rectangle:
		std::cout << "A(" << _coordinate[0]._x << ',' << _coordinate[0]._y << ')' << std::endl;
		std::cout << "B(" << _coordinate[1]._x << ',' << _coordinate[1]._y << ')' << std::endl;
		std::cout << "C(" << _coordinate[2]._x << ',' << _coordinate[2]._y << ')' << std::endl;
		std::cout << "D(" << _coordinate[3]._x << ',' << _coordinate[3]._y << ')' << std::endl;
		break;
	default:
		break;
	}
}
void figure::Creat() {
	std::cout << "| 1: точка \n";
	std::cout << "| 2: отрезок \n";
	std::cout << "| 3: треугольник \n";
	std::cout << "| 4: прямоугольник \n";
	size_t reply;
	std::cout << "| Выберите тип фигуры: ";
	std::cin >> reply;
	switch (reply)
	{
	case 1:
		_type = type_point;
		_coordinate = new point[1];
		std::cout << "| координата x = ";
		std::cin >> _coordinate[0]._x;
		std::cout << "| координата y = ";
		std::cin >> _coordinate[0]._y;
		break;
	case 2:
		_type = type_segment;
		_coordinate = new point[2];
		for (size_t i = 0; i < 2; ++i) {
			std::cout << "| координата x = ";
			std::cin >> _coordinate[i]._x;
			std::cout << "| координата y = ";
			std::cin >> _coordinate[i]._y;
		}
		break;
	case 3:
		_type = type_triangle;
		_coordinate = new point[3];
		for (size_t i = 0; i < 3; ++i) {
			std::cout << "| координата x = ";
			std::cin >> _coordinate[i]._x;
			std::cout << "| координата y = ";
			std::cin >> _coordinate[i]._y;
		}
		break;
	case 4:
		_type = type_rectangle;
		_coordinate = new point[4];
		for (size_t i = 0; i < 4; ++i) {
			std::cout << "| координата x = ";
			std::cin >> _coordinate[i]._x;
			std::cout << "| координата y = ";
			std::cin >> _coordinate[i]._y;
		}
		break;
	default:
		std::cout << "| Error! " << std::endl;
		break;
	}
}
