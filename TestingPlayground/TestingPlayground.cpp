#include <iostream>

class Base1
{
public:
	virtual int GetX() = 0;
};

class Derived1 : public Base1
{
public:
	Derived1(int _x)
	{
		x = _x;
	}

	int GetX()
	{
		return x;
	}

private:
	int x;
};







class Base2
{
public:
	Base1* base1;

	Base2()
	{ 
		base1 = nullptr;
	}

	~Base2()
	{
		delete base1;
	}

	virtual int GetY() = 0;
	int DefaultGetY()
	{
		return base1->GetX();
	}
};

class Derived2 : public Base2
{
public:
	Derived2() : Base2() 
	{
		base1 = new Derived1(10);
	}


	int GetY()
	{
		return DefaultGetY();
	}
};





class Base3
{
public:
	Derived2* d2 = new Derived2();

	int doYaThang()
	{
		return d2->GetY();
	}

	void deletePtr()
	{
		delete d2->base1;
	}
};






int main()
{
	Base3 b = Base3();
	for (int i = 0; i < 10; i++)
	{
		std::cout << b.doYaThang() << std::endl;
	}
		/*b.deletePtr();
	std::cout << b.doYaThang() << std::endl;*/
	return 0;
}