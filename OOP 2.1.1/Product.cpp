#include "Product.h"

Product::Product()
{
	this->name = "noname";
	this->price = 0;
	this->manufacturer = "noname";
	this->product_date = Date();
}

Product::Product(const Product& other)
{
	this->name = other.name;
	this->price = other.price;
	this->manufacturer = other.manufacturer;
	this->product_date = other.product_date;
}

void Product::print() const
{
	cout << this->name << " * "
		<< this->price << " * "
		<< this->manufacturer << " * ";
	this->product_date.print(cout);
}

// Без virtual в реалізації
//void Product::print() const
//{
//}

void Product::print(ostream& os) const
{
	os << this->name << " "
		<< this->price << " "
		<< this->manufacturer << " ";
	this->product_date.print(os);
}

void Product::print_short(ostream& os) const
{
	os << this->name << " "
		<< this->price;
}

void Product::read(istream& os)
{
	//cout << "Enter name: ";
	os >> this->name;
	//cout << "Enter price: ";
	os >> this->price;
	//cout << "Enter: manufacturer: ";
	os >> this->manufacturer;
	//cout << "Enter date: ";
	/*os >> this->product_date.day >> this->product_date.month >> this->product_date.year;*/
	string s;
	os >> s;
	this->product_date.read(s);
}

string Product::get_name() const
{
	return this->name;
}

double Product::get_price() const
{
	return this->price;
}

string Product::get_manufacturer() const
{
	return this->manufacturer;
}

Date Product::get_productDate() const
{
	return this->product_date;
}

char Product::get_type() const
{
	return 'p';
}

void Product::set_name(string _name)
{
	this->name = _name;
}

void Product::set_price(double _price)
{
	this->price = _price;
}

void Product::set_manufacturer(string _manufacturer)
{
	this->manufacturer = _manufacturer;
}

void Product::set_productDate(Date _productDate)
{
	this->product_date = _productDate;
}

void Product::change_discont(double _percent)
{
	this->price = this->price - this->price * _percent;
}

bool Product::is_dateCorrect() const
{
	if (this->product_date.year < 1 ||
		this->product_date.month < 1 ||
		this->product_date.month > 12 ||
		this->product_date.day < 1)
	{
		return false;
	}

	int days_inMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((this->product_date.month == 2) &&
		((this->product_date.year % 400 == 0) ||
			((this->product_date.year % 4 == 0) && (this->product_date.year % 100 != 0))) // перевірка чи рік високосний щоб 
		)																				// змінити кількість днів у лютому
	{
		days_inMonth[2] = 29;
	}

	return this->product_date.day <= days_inMonth[this->product_date.month];
}

double Product::priceSale(int _percent)
{
	return this->price - (double)this->price * _percent / 100;
}

istream& operator >>(istream& is, Product& p)
{
	p.read(is);
	return is;
}

ostream& operator <<(ostream& os, const Product& p)
{
	p.print(os);
	return os;
}

void Product::operator++() {
	this->price = this->price * (1 + 0.01);
}

void Product::operator++(int a) {
	this->price = this->price * (1 + 0.01);
}

Product* Product::clone() const
{
	/*cout << "Cloning Product " << this << endl;*/
	return new Product(*this);
}

double Product::new_price() const
{
	return this->price;
}
