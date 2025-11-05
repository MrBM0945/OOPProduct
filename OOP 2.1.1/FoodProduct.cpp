#include "FoodProduct.h"

FoodProduct::FoodProduct(string _name, double price, string _manofacture, Date _product_date, int _days): 
	Product(_name, price, _manofacture, _product_date), days(_days)
{
}

FoodProduct* FoodProduct::clone() const
{
	/*cout << "FoodProduct Product " << this << endl;*/
	return new FoodProduct(*this);
}

int FoodProduct::get_days() const
{
	return this->days;
}

void FoodProduct::set_days(int _days)
{
	this->days = _days;
}

char FoodProduct::get_type() const
{
	return 'f';
}

void FoodProduct::print(ostream& os) const{
	Product::print(os);
	os << " " << this->days;
}

void FoodProduct::read(istream& is) {
	Product::read(is);
	is >> this->days;
};