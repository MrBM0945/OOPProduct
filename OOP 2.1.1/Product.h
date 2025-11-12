#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Date.h"
using namespace std;


class Product
{
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
	virtual ~Product() = default;

	// Ввід + вивід
	virtual void print() const; // віртуальність в дочірньому зберігається
	virtual void print(ostream& os) const;
	void print_short(ostream& os) const;
	virtual void read(istream& os);

	//Геттери
	string get_name() const;
	double get_price() const;
	string get_manufacturer() const;
	Date get_productDate() const;
	virtual char get_type() const;

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

	virtual Product* clone() const;

	virtual double new_price() const;
};