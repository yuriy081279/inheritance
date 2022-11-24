#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		red=0x000000FF,
		green=0x0000FF00,
		blue=0x00FF0000,
		yellow=0x0000AAFF,
		white=0x00FFFFFF,
		grey=0x00AAAAAA,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,

	};
	class Shape // Абстрактная фигура
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 800)start_x = 800;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 500)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 30)line_width = 30;
			this->line_width = line_width;
		}
		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width,  Color color) :color(color) 
		{
			set_start_x
			(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}

	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 5)side = 5;
			if (side > 20)side = 20;
			this->side = side;
		}
		// constructors
		Square(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :Shape(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата: " << side << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double length;

	public:
		double get_width()const
		{
			return  width;
		}
		double get_length()const
		{
			return  length;
		}
		void set_width(double width)
		{
			if (width < 30)width = 30;
			if (width > 300)width = 300;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 20)length = 20;
			if (length > 200)length = 200;
			this->length = length;
		}
		Rectangle(double width, double length, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :Shape(start_x, start_y, line_width, color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle()
		{
		}
		double get_area()const override
		{
			return width * length;
		}
		double get_perimeter()const override
		{
			return (width + length) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/

			HWND hwnd = GetConsoleWindow(); //получаем окно консоли
			HDC hdc = GetDC(hwnd); // Получаем контекст устройства для окна консолиб то на чем рисуем

			//3) сщздаем карандаш - то чем рисуем

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);

			HBRUSH hBrush = CreateSolidBrush(color);
			// выбираем карандаш для рисования

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x+width, start_y+length);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc); //освобождаем контекст устройства
		}

		
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина прямоугольника: " << length << endl;
			cout << "Ширина прямоугольника: " << width << endl;
			Shape::info();
		}
	};

	class Circule :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius < 20)radius = 20;
			if (radius > 220)radius = 220;
			this->radius = radius;
		}
		Circule(double radius, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :
			Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circule() {}
		double get_area()const override
		{
			return M_PI * pow(radius, 2);

		}
		double get_perimeter()const override
		{
			return 2 * M_PI * radius;
		}
		void draw()const override
		{
			HWND hwnd=GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Radius:\t" << radius << endl;
			Shape::info();
		}
	};

	class Triangle : public Shape
	{

	public:
		Triangle(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color) {}
		virtual	double get_height()const = 0;
		void info()const
		{
			cout << "Height:\t" << get_height() << endl;
			Shape::info();
		}
	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:

        double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side > 300)side = 300;
			if (side < 20) side = 20;
			this->side = side;
		}
		EquilateralTriangle(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle(){}
		double get_height()const override
		{
			return 2 * get_area() / side;
		}
		double get_area()const override
		{
			return side * side * sqrt(3) / 4;
		}
		double get_perimeter()const override
		{
			return side * 3;
		}
		void draw()const override
		{
			HWND hmrzh = GetConsoleWindow();
			HDC hdc = GetDC(hmrzh);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vert[] =
			{
				{start_x, start_y + side},
				{start_x+side, start_y + side},
				{start_x+side/2, start_y + side-get_height()},

			};

			::Polygon(hdc, vert, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hmrzh, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Side:\t" << side << endl;
			Triangle::info();
		}
    };
	class IsTriangle :public Triangle
	{
		double side;
		double base;

	public:
		double get_side()const
		{
			return side;
		}
		double get_base()const
		{
			return base;
		}
		void set_side(double side)
		{
			if (side < 10)side = 10;
			if (side > 400)side = 400;
			this->side = side;
		}
		void set_base(double base)
		{
			if (base < 30)base = 30;
			if (base > 700)base = 700;
			this->base = base;
		}			
		IsTriangle(double side, double base, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			: Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
			set_base(base);
		}
        ~IsTriangle(){}
		double get_height()const override
		{
			return sqrt(pow(side, 2) - pow(base/2, 2));
		}
		double get_area()const override
		{
			return base/2 * sqrt(pow(side, 2) - pow(base/2, 2));
		}
		double get_perimeter()const override
		{
			return base + side * 2;
		}
		void draw()const override
		{
			HWND hmrzh = GetConsoleWindow();
			HDC hdc = GetDC(hmrzh);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT point[] =
			{
				{start_x, start_y+side},
				{start_x+base, start_y+side}, 
				{start_x+base/2, start_y+side/2}
			};
			::Polygon(hdc, point, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hmrzh, hdc);

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Side:\t" << side << endl;
			cout << "Base:\t" << base << endl;
			Triangle::info();
		}
	};

	class RiTriangle:Triangle
	{
		double katet1;		
		double katet2;

	public:
		double get_katet1()const
		{
			return katet1;
		}
		double get_katet2()const
		{
			return katet2;
		}
		
		void set_katet1(double katet1)
		{
			if (katet1 < 7)katet1 = 7;
			if (katet1 > 400)katet1 = 400;
			this->katet1 = katet1;
		}
		void set_katet2(double katet2)
		{
			if (katet2 < 7)katet2 = 7;
			if (katet2 > 400)katet2 = 400;
			this->katet2 = katet2;
		}
		
		RiTriangle(double katet1, double katet2, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_katet1(katet1);
			set_katet2(katet2);			
		}
		~RiTriangle(){}
		double get_height()const override
		{
			return (katet1 * katet2)/ sqrt(pow(katet1, 2) + pow(katet1, 2));
		}
		double get_area()const override
		{
			return (katet1*katet2)/2;
		}
		double get_perimeter()const override
		{
			return katet1 + katet2 + sqrt(pow(katet1,2) + pow(katet1, 2));
		}
		void draw()const override
		{
			HWND hmrzh = GetConsoleWindow();
			HDC hdc = GetDC(hmrzh);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT point[] =
			{
				{start_x, start_y + katet1},
				{start_x + katet2, start_y + katet1},
				{start_x, start_y}
			};
			::Polygon(hdc, point, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hmrzh, hdc);

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Katet1:\t" << katet1 << endl;
			cout << "Katet2:\t" << katet2 << endl;
			cout << "Gipotenuza:\t" << sqrt(pow(katet1, 2) + pow(katet1, 2)) << endl;
			Triangle::info();
		}
	};
}

	void main()
	{
		setlocale(LC_ALL, "");
		//Shape shape;
		//Geometry::Square square(8, 100, 100, 11, Geometry::Color::console_yellow);
		//square.info();

		Geometry::Rectangle rect(150, 70, 300, 100, 11, Geometry::Color::grey);
		rect.info();

		Geometry::Circule circ(40, 500, 100, 11, Geometry::Color::blue);
		circ.info();

		Geometry::EquilateralTriangle e_try(170, 350, 200, 8, Geometry::Color::green);
		e_try.info();

		Geometry::IsTriangle i_try(200, 300, 550, 170, 3, Geometry::Color::red);
		i_try.info();

		Geometry::RiTriangle r_try(300, 140, 235, 170, 3, Geometry::Color::blue);
		r_try.info();
	}
