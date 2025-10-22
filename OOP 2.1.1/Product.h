#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Date.h"

//#include <string>
using namespace std;


class Product
{
	// тільки "cin >> p": friend void operator >>(istream& is, Product& p);
 
	// Нижній дозволяє ланцюжком cin >> a >> b;
	friend istream& operator >>(istream& is, Product& p);
	friend ostream& operator <<(ostream& os, const Product& p);
private:
	string name;
	double price;
	string manufacturer;
	Date product_date;

public:

	// Конструктори
	Product();
	Product(string _name, double _price, string _manufacturer, Date _productDate) :
		name(_name),
		price(_price),
		manufacturer(_manufacturer),
		product_date(_productDate)
	{
		//cout << "Product(string _name, double _price, string _manufacturer, Date _productDate)" << endl;
	};
	Product(const Product& other);

	// Ввід + вивід
	void print() const;
	void print(ostream& os) const;
	void print_short(ostream& os) const;
	void read(istream& os);

	//Геттери
	string get_name() const;
	double get_price() const;
	string get_manufacturer() const;
	Date get_productDate() const;

	//Сеттери
	void set_name(string _name);
	void set_price(double _price);
	void set_manufacturer(string _manufacturer);
	void set_productDate(Date _productDate);

	// Інші
	void change_discont(double _percent);
	bool is_dateCorrect() const;
	double priceSale(int _percent = 0);

	//++
	void operator++();
	void operator++(int a);
	
};