#pragma once
#include "Product.h"

class Shop1
{
private:
	int size;
	int max_size;
	Product** products;

	void createMemory(int _maxSize);
	void clearMemory();
public:
	Shop1();
	Shop1(int _max_size);
	Shop1(const Shop1& other);
	Shop1& operator=(const Shop1& other);
	~Shop1();

	//Геттери + сеттер
	int getMaxSize() const;
	int getSize() const;
	void setMaxSize(int _maxSize);

	//Ввід + вивід
	void read(istream& is);
	void read(string path);
	void print(ostream& os) const;

	//Інши методи
	void addProduct(const Product& p);
	void segregate_products(Shop1& foodShop, Shop1& NoFoodShop);
	void test_method();
};

// НЕ продовольчий клас