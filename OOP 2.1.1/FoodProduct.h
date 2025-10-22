#pragma once
#include "Product.h"
class FoodProduct : public Product
{
private:
	int days;
public:
	FoodProduct(string _name = "", double _price = 0.0, string _manofacture = "", Date _product_date = Date(1, 1, 1970), int _days = 0);
	void print(ostream& os) const;
};

