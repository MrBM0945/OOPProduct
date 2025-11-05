#include "Shop1.h"
#include "FoodProduct.h"
#include "NoFoodProduct.h"

void Shop1::createMemory(int _maxSize) {
	this->max_size = _maxSize;
	this->products = new Product * [this->max_size];
	for (int i = 0; i < this->max_size; i++) {
		this->products[i] = nullptr;
	}
};

void Shop1::clearMemory() {

	if (this->products != nullptr) {
		// Пробую size замість max_size
		for (int i = 0; i < this->size; i++) {
			/*cout << "Index " << i << " ptr=" << products[i] << endl;*/
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

Shop1::Shop1(const Shop1& other)
{
		this->size = other.size;
		this->max_size = other.max_size;
		createMemory(this->max_size);
		for (int i = 0; i < this->size; i++)
			this->products[i] = other.products[i]->clone();

}

Shop1& Shop1::operator=(const Shop1& other) {
	if (this == &other)
		return *this;

	clearMemory();
	this->size = other.size;
	this->max_size = other.max_size;
	createMemory(this->max_size);
	for (int i = 0; i < this->size; i++)
		this->products[i] = other.products[i]->clone();

	return *this;
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
	this->clearMemory();
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
		case 'n':
			this->products[i] = new NoFoodProduct();
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
}

void Shop1::addProduct(const Product& p) {
	if (this->size >= this->max_size) {
		int otherMax = (this->max_size == 0 ? 1 : this->max_size * 2);
		Product** temp = new Product*[otherMax];
		for (int i = 0; i < this->size; i++) {
			temp[i] = this->products[i];
		}
		delete[] this->products;
		this->products = temp;
		this->max_size = otherMax;
	}
	this->products[this->size++] = p.clone();
}

void Shop1::segregate_products(Shop1& foodShop, Shop1& NoFoodShop)
{
	for (int i = 0; i < this->size; i++) {
		char type = this->products[i]->get_type();
		switch (type) {
		case 'f':
			foodShop.addProduct(*(this->products[i]));
			break;
		case 'n':
			NoFoodShop.addProduct(*(this->products[i]));
			break;
		}
	}
}

void Shop1::test_method()
{
	for (int i = 0; i < this->size; i++) {
		cout << *(this->products[i]);
		cout << endl;
		NoFoodProduct* prod = dynamic_cast<NoFoodProduct*>(this->products[i]);
		if (prod != nullptr) {
			cout << prod->isBig() << endl;
		}
		/*cout << "Type of object" << i + 1 << ": " << typeid(*(this->products[i])).name() << endl;*/
	}

}

