#pragma once
#include "Product.h"
class FoodProduct : public Product
{
private:
	int days;
public:
	FoodProduct(string _name = "", double _price = 0.0, string _manofacture = "", Date _product_date = Date(1, 1, 1970), int _days = 0);
	FoodProduct* clone() const override;
	int get_days() const;
	void set_days(int _days);

	char get_type() const override;

	void print(ostream& os) const;
	void read(istream& is);

	double new_price() const override;
};

