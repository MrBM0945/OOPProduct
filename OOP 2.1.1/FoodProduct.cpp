#include "FoodProduct.h"

FoodProduct::FoodProduct(string _name, double price, string _manofacture, Date _product_date, int _days): 
	Product(_name, price, _manofacture, _product_date), days(_days)
{
}

void FoodProduct::print(ostream& os) const{
	Product::print(os);
	os << " " << this->days;
}

void FoodProduct::read(istream& is) {
	Product::read(is);
	is >> this->days;
};