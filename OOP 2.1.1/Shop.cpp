#include "Shop.h"

void Shop::createMemory(int _maxSize)
{
	this->max_size = _maxSize;
	this->products = new Product[this->max_size];
}

void Shop::clearMemory()
{
	if (this->products)
	{
		delete[] this->products;
		this->size = 0;
		this->max_size = 0;
	}

}

Shop::Shop()
{
	this->size = 0;
	this->createMemory(5);
}

Shop::Shop(int _max_size)
{
	this->size = 0;
	this->createMemory(_max_size);
}

Shop::Shop(const Shop& other)
{
	if (this != &other)
	{
		this->size = other.size;
		createMemory(other.max_size);
		for (int i = 0; i < size; i++)
		{
			this->products[i] = other.products[i];
		}
	}
}

Shop::~Shop()
{
	this->clearMemory();

}

int Shop::getMaxSize() const
{
	return 0;
}

int Shop::getSize() const
{
	return 0;
}

// ןמהףלאעט םאה צטל לועמהמל
void Shop::setMaxSize(int _maxSize)
{
	if (this->max_size == _maxSize)
	{
		return;
	}

	if (this->max_size > _maxSize)
	{
		if (this->size > _maxSize)
		{
			Product* helper = new Product[_maxSize];
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
			Product* helper = new Product[_maxSize];
			for (int i = 0; i < size; ++i)
			{
				helper[i] = this->products[i];
			}
			clearMemory();
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
		Product* helper = new Product[_maxSize];
		for (int i = 0; i < size; i++)
		{
			helper[i] = this->products[i];
		}
		this->max_size = _maxSize;
		delete[] this->products;
		this->products = helper;
	}
}

void Shop::read(string path)
{
	ifstream is(path);
	this->clearMemory();
	is >> this->size;
	/*cout << is.is_open();*/
	this->createMemory(this->size);
	for (int i = 0; i < this->size; i++)
	{
		is >> products[i];
		//this->products[i].read(is);
		/*string name; double num;
		is >> name;
		this->products[i].set_name(name);
		is >> num;
		this->products[i].set_price(num);
		is >> name;
		this->products[i].set_manufacturer(name);

		is >> name;
		this->products[i].set_productDate(Date(name));*/
	}
	is.close();
}

void Shop::print(ostream& os) const
{
	for (int i = 0; i < this->size; i++)
	{
		this->products[i].print(os);
		os << endl;
	}
}

void Shop::addProduct(const Product& p)
{
	if (this->size >= this->max_size) {
		int newMax = (this->max_size == 0 ? 1 : this->max_size * 2);
		Product* temp = new Product[newMax];
		for (int i = 0; i < this->size; i++) {
			temp[i] = this->products[i];
		}
		delete[] this->products;
		this->products = temp;
		this->max_size = newMax;
	}
	this->products[this->size++] = p;
}

void Shop::changePrice()
{
	for (int i = 0; i < this->size; i++) {
		products[i]++;
	}
}

Shop& Shop::operator=(const Shop& other)
{
	// попробувати а = a; без if
	if(this != &other){
		this->clearMemory();
		this->size = other.size;
		this->createMemory(this->size);
		for (int i = 0; i < this->size; i++) {
			this->products[i] = other.products[i];
		}
	}
	return *this;
}

Shop& Shop::operator+=(const Shop& other)
{
	for (int i = 0; i < other.size; i++) {
		this->addProduct(other.products[i]);
	}
	return *this;
}

Shop& Shop::operator*=(const Shop& other) {
	*this = *this + other;
	return *this;
}

/*ТУТ НЕМАЄ БУТИ & !!!*/
Shop Shop::operator+(const Shop& other) const
{
	Shop result(this->size + other.size);
	result.size = result.max_size;
	for (int i = 0; i < this->size; i++) {
		result.products[i] = this->products[i];
		// по замовчуванню оператор =, бо в Products всі поля базових типів
	}
	for (int i = 0; i < other.size; i++) {
		result.products[i + this->size] = other.products[i];
	}
	return result;
}

Shop Shop::operator+(int a) const
{
	Shop result(*this);
	Product p;
	p.set_price(a);
	result.addProduct(p);
	return result;
}

Shop operator+(int a, const Shop& s )
{
	return s + a;
}

bool Shop::operator<(const Shop& other)
{
	// Я тут змінив <= на <, бо воно повертає і випадок оператора ==.
	if (this->size < other.size) {
		return true;
	}
	return false;
}

bool Shop::operator==(const Shop& other)
{
	if (this->size == other.size) {
		return true;
	}
	return false;
}

// Перевантажений оператор >
bool Shop::operator>(const Shop& other)
{
	if (!(*this < other || *this == other)) {
		return true;
	}
	return false;
}

bool Shop::operator!=(const Shop& other)
{
	return !(*this == other); // тут точно по об'єкту а !(this == &other) по вказівнику
	// погано
	//if (this->size == other.size) {
	//	return true;
	//}
	//return false;
}

// Віртуальний деструктор нада, коли треба клас має віртуальну функцію.
