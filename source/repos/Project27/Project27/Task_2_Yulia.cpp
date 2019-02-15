#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>



union All_values
{
	int integer;
	short int shinteger;
	long int linteger;
	unsigned int uinteger;
	float ffloat;
	double ddouble;
	bool bbool;
	char cchar;
};
class Any_type
{
private:
	bool integer_type;
	bool short_integer_type;
	bool long_integer_type;
	bool unsigned_int_type;
	bool float_type;
	bool double_type;
	bool bool_type;
	bool char_type;
	All_values store;

public:
	Any_type()
	{
		integer_type=false;
		short_integer_type=false;
		long_integer_type=false;
		unsigned_int_type=false;
		float_type=false;
		double_type=false;
		bool_type=false;
		char_type=false;
	}
	template<typename T>
	Any_type(T val)
	{
		if (typeid(int) == typeid(T))
		{
			store.integer = val;
			integer_type = true;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = false;
			double_type = false;
			bool_type = false;
			char_type = false;
		}
		if (typeid(short int) == typeid(T))
		{
			store.shinteger = val;
			integer_type = false;
			short_integer_type = true;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = false;
			double_type = false;
			bool_type = false;
			char_type = false;
		}
		if (typeid(bool) == typeid(T))
		{
			store.bbool = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = false;
			double_type = false;
			bool_type = true;
			char_type = false;
		}
		if (typeid(char) == typeid(T))
		{
			store.cchar = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = false;
			double_type = false;
			bool_type = false;
			char_type = true;
		}
		if (typeid(long int) == typeid(T))
		{
			store.linteger = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = true;
			unsigned_int_type = false;
			float_type = false;
			double_type = false;
			bool_type = false;
			char_type = false;
		}
		if (typeid(unsigned int) == typeid(T))
		{
			store.uinteger = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = true;
			float_type = false;
			double_type = false;
			bool_type = false;
			char_type = false;
		}
		if (typeid(float) == typeid(T))
		{
			store.ffloat = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = true;
			double_type = false;
			bool_type = false;
			char_type = false;
		}
		if (typeid(double) == typeid(T))
		{
			store.ddouble = val;
			integer_type = false;
			short_integer_type = false;
			long_integer_type = false;
			unsigned_int_type = false;
			float_type = false;
			double_type = true;
			bool_type = false;
			char_type = false;
		}
	}
	int ToInt()
	{
		if (integer_type == true)
		{
			return store.integer;
		}
		else 
		{
			throw "You can lose your data while convertion";
		}
	}
	void getType()
	{
		if (integer_type == true)
			std::cout << "The type of value is integer\n";
		if (short_integer_type == true)
			std::cout << "The type of value is short integer\n";
		if (long_integer_type == true)
			std::cout << "The type of value is long integer\n";
		if (unsigned_int_type == true)
			std::cout << "The type of value is unsigned integer\n";
		if (float_type == true)
			std::cout << "The type of value is float\n";
		if (double_type == true)
			std::cout << "The type of value is double\n";
		if (bool_type == true)
			std::cout << "The type of value is bool\n";
		if (char_type == true)
			std::cout << "The type of value is char\n";
		
	}
	~Any_type() {}
	void operator =(const Any_type& any)
	{
		this->integer_type = any.integer_type;
		this->short_integer_type = any.short_integer_type;
		this->long_integer_type = any.long_integer_type;
		this->unsigned_int_type = any.unsigned_int_type;
		this->float_type = any.float_type;
		this->double_type = any.double_type;
		this->char_type = any.char_type;
		this->bool_type = any.bool_type;
		this->store = any.store;
	}

};
void Swap(Any_type &a, Any_type &b)
{
	Any_type ggg = a;
	a = b;
	b = ggg;
}

int main()
{
	Any_type value_1 = 888888;
	Any_type value_2 = 3.14;
	Any_type value_3 = false;
	Any_type value_4 = 'd';
	value_1.getType();
	value_2.getType();
	value_3.getType();
	value_4.getType();
	

	try
	{
		int b = value_3.ToInt();
		std::cout << b;
	}
	catch (const char* msg)
	{
		std::cout << msg << "\n";
	}
	system("pause");
	return 0;
}