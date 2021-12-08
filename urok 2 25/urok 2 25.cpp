#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <initializer_list>
#include <malloc.h>
using namespace std;
//class Point
//{
//private:
//	int X;
//	int Y;
//public:
//	Point()
//	{
//		X = 0;
//		Y = 0;
//	}
//	/*void SetValue(int x, int y)
//	{
//		X = x;
//		Y = y;
//	}*/
//	void Show()
//	{
//		cout << X << " " << Y << endl;
//	}
//	void operator()(int x, int y)
//	{
//		X = x;
//		Y = y;
//	}
//};
class SomeClass
{
	int some;
public:
	void* operator new(size_t size,const char* str = "New");
	void operator delete(void* ptr);
	void * operator new [](size_t fullsize, const  char* str = "New []");
	void operator delete [](void* ptr);
};
void* SomeClass::operator new(size_t size, const  char* str)
{
	cout << endl << str << endl;
	void* ptr = malloc(size);
	if (!ptr)
	{
		cout << "\nError memory new!!!!\n";
	}
	else 
	{
		cout << "\nMemory new-OK!!!!!\n";
	}
	return ptr;
}
class Rect 
{
	int Width, Height;
	char Symb;
	friend void friend_put(Rect* r, char s);
public:
	Rect(int wi, int hi, char si)
	{
		Width = wi;
		Height = hi;
		Symb=si;
	}
	void display() 
	{
		cout << endl << endl;
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
				cout << Symb << " ";
			cout << endl ;
		}
	}
};
void friend_put(Rect* r, char s)
{
	r->Symb = s;
}
void* SomeClass::operator new [](size_t fullsize, const  char* str)
{
	cout << "\n" << str << "\n";
	void* ptr= malloc(fullsize);
	if (!ptr)
	{
		cout << "\nError memory new[]!!!!\n";
	}
	else
	{
		cout << "\nMemory new[]-OK!!!!!\n";
	}
	return ptr;
}
void SomeClass::operator delete(void* ptr)
{
	free(ptr);
	cout << "\nDelete memory\n";
}
void SomeClass::operator delete [](void* ptr)
{
	free(ptr);
	cout << "\nDelete memory[]\n";
}
class line__;
class point_;
class point_ 
{
	float x, y;
public:
	point_(float xn = 0, float yn = 0)
	{
		x = xn;
		y = yn;
	}
	friend float uclon(point_, line__);
};
class line__
{
	float A,B,C;
public:
	line__(float a, float b, float c )
	{
		A = a;
		B = b;
		C = c;
	}
	friend float uclon(point_, line__);
};
float uclon(point_ p, line__ l) 
{
	return l.A * p.x + l.B * p.y + l.C;
}
class Point
{
	int x;
	int y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Show()
	{
		cout << "\n+++++++++++++++\n";
		cout << "x = " << x << "\ty = " << y;
		cout << "\n++++++++++++++++++\n";
	}
	Point& operator +(int d)
	{
		Point P(0, 0);
		P.x = x + d;
		P.y = y + d;
		return P;
	}
	int Getx() const
	{
		return x; 
	}
	int Gety() const
	{
		return y;
	}
	void Setx(int x) 
	{
		 this->x=x;
	}
	void Sety(int y)
	{
		this->y = y;
	}
};
Point& operator+(int d, Point& Z)
{
	Point P(0, 0);
	P.Setx( d+Z.Getx());
	P.Sety(d + Z.Gety());
	return P;
}

class Banana;
class Apple
{
public:
	void F_apple(Banana ob);
};
class Banana
{
	int x;
	int y;
public:
	Banana()
	{
		x = y = 777;
	}
	friend Apple;
};
void Apple::F_apple(Banana ob)
{
	cout << ob.x << endl;
	cout << ob.y << endl;
}
class Object
{
	char* str;
public:
	static int mun_obj;
	Object(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		cout << "Create " << str << endl;
		mun_obj++;
	}
	~Object()
	{
		delete str;
		mun_obj--;
	}
};
int Object::mun_obj = 0;
Object S1("First global Object.");
Object S2("Second global Object.");

void f(const char* str)
{
	Object s(str);
	cout << "Count of object - " << Object::mun_obj << ".\n";
	cout << "Worked Function f()" << ".\n";
}
class Prim
{
	int numb;
	static int stat;
public:
	Prim(int i)
	{
		numb = i;
	}
	static void func(int i, Prim* p = 0)
	{
		if (p)
		{
			p->numb = i;
		}
		else
		{
			stat = i;
		}
	}
	static void show()
	{
		cout << "stat = " << stat << endl;
	}
	void show2()
	{
		cout << "numb" << numb << endl;
	}
};
int Prim::stat = 8;
int main()
{
	setlocale(0, "rus");

	/*Banana b;
	Apple a;
	a.F_apple(b);*/

	/*Point P;
	P.Show();
	P(2, 3); 
	P.Show();
	int P1(2);
	cout << P1;*/

	//SomeClass *p = new SomeClass;
	//SomeClass *r = new SomeClass[5];
	//delete p;
	//delete[] r;

	/*Rect A(5, 3, 'A');
	Rect B(5, 3, 'B');
	A.display();
	B.display();
	friend_put(&A, 'a');
	friend_put(&B, 'b');
	A.display();
	B.display();*/

	//point_ P(16.0, 12.3);
	//line__ L(10.0, -42.3,24.0);
	//cout << "\nOtvet\n" << uclon(P, L) << endl;

	//Point A(3, 2);
	//A.Show();
	//Point B = A + 5;
	//B.Show();
	//Point C =  2 + A;
	//C.Show();

	//cout<< "Now, count of objects"<< Object::mun_obj<< ".\n";
	//Object M("Object in main().");
	//cout << "Now, count of objects"<< M.mun_obj<< ".\n";
	//f("Local object.");
	//cout<< "Before finish main" << M.mun_obj << ".\n";

	Prim::show();
	Prim::func(10);
	Prim obj(23);
	obj.show2();
	Prim::func(20,&obj);
	obj.show2();
	obj.func(27,&obj);
	obj.show2();
	return 0;
}