#pragma once
#include "Product.h"
class NoFoodProduct : public Product
{
private:
	double power;
	double volume;
public:
	NoFoodProduct(string _name = "", double price = 0.0, string _manofacture = "", Date _product_date = Date(1, 1, 1970), double _power = 0.0, double _volume = 0.0);
	NoFoodProduct* clone() const override;
	double get_power() const;
	double get_volume() const;
	char get_type() const override;

	void set_power(double _power);
	void set_volume(double _volume);

	void print(ostream& os) const;
	void read(istream& is);

	bool isBig() const;
	double new_price() const override;

};

