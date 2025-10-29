#include "Shop1.h"
#include "FoodProduct.h"

void Shop1::createMemory(int _maxSize) {
	this->max_size = _maxSize;
	this->products = new Product * [this->max_size];
	for (int i = 0; i < this->max_size; i++) {
		this->products[i] = nullptr;
	}
};

void Shop1::clearMemory() {

	if (this->products != nullptr) {
		for (int i = 0; i < this->max_size; i++) {
			if (this->products[i] != nullptr) {
				delete this->products[i];
			}
		}
		delete[] products;
		this->products = nullptr;
	}
};

Shop1::Shop1() {
	this->size = 0;
	createMemory(5);
}

Shop1::Shop1(int _max_size) {
	this->size = 0;
	createMemory(_max_size);
}

Shop1::~Shop1()
{
	clearMemory();
}

int Shop1::getMaxSize() const {
	return this->max_size;
};
int Shop1::getSize() const {
	return this->size;
};

void Shop1::setMaxSize(int _maxSize) {

	if (this->max_size == _maxSize)
	{
		return;
	}

	if (this->max_size > _maxSize)
	{
		if (this->size > _maxSize)
		{
			Product** helper = new Product*[_maxSize];
			for (int i = 0; i < _maxSize; ++i)
			{
				helper[i] = this->products[i];
			}
			this->size = _maxSize;
			this->max_size = _maxSize;

			delete[] this->products;

			this->products = helper;
		}
		else
		{
			Product** helper = new Product*[_maxSize];
			for (int i = 0; i < size; ++i)
			{
				helper[i] = this->products[i];
			}
			this->size = _maxSize;
			this->max_size = _maxSize;

			delete[] this->products;

			this->products = helper;
			createMemory(_maxSize);
			for (int i = 0; i < size; i++)
			{
				this->products[i] = helper[i];
			}
			delete[] helper;
		}
	}
	else
	{
		Product** helper = new Product*[_maxSize];
		for (int i = 0; i < size; i++)
		{
			helper[i] = this->products[i];
		}
		this->max_size = _maxSize;
		delete[] this->products;
		this->products = helper;
	}
};

void Shop1::read(istream& is) {
	is >> this->size;
	this->createMemory(this->size);
	for (int i = 0; i < this->size; i++)
	{
		char mark;
		is >> mark;
		switch (mark) {
		case 'p':
			this->products[i] = new Product();
			break;
		case 'f':
			this->products[i] = new FoodProduct();
			break;
		default:
			this->products[i] = new Product();
			break;
		}
		is >> *(products[i]);
	}
};

void Shop1::print(ostream& os) const {
	for (int i = 0; i < this->size; i++) {
		os << *(this->products[i]);
		os << endl;
	}
};