#pragma once
#include "Product.h"

class Shop
{
	friend Shop operator+(const int a, const Shop& s);
private:
	int size;
	int max_size;
	Product* products;

	void createMemory(int _maxSize);
	void clearMemory();
public:
	// Конструктори
	Shop();
	/*explicit*/ Shop(int _max_size);
	Shop(const Shop& other);
	~Shop();

	//Геттери + сеттер
	int getMaxSize() const;
	int getSize() const;
	void setMaxSize(int _maxSize);

	//Ввід + вивід
	void read(istream& is);
	void read(string path);
	void print(ostream& os) const;

	//Додати продукт
	void addProduct(const Product& p);
	void changePrice();

	//Перевантажені оператори
	Shop& operator=(const Shop& other);
	Shop operator+(const Shop& other) const;
	Shop& operator+=(const Shop& other);
	Shop& operator*=(const Shop& other);

	// зроблено на швидкоруч, забути і змінити за можливости

	// Я не знаю чому, але воно не хоче працювати правильно
	// (якісь конфлікти з Shop operator+(const Shop& other))
	
	Shop operator+(int a) const;

	// Логічні оператори
	bool operator<(const Shop& other);
	bool operator==(const Shop& other);
	bool operator>(const Shop& other);
	bool operator!=(const Shop& other);

	// Оператори << та >>
};