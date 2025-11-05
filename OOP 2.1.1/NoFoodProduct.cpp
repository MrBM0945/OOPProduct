#include "NoFoodProduct.h"

NoFoodProduct::NoFoodProduct(string _name, double price, string _manofacture, Date _product_date, double _power, double _volume):
    Product(_name, price, _manofacture, _product_date), power(_power), volume(_volume)
{
}

NoFoodProduct* NoFoodProduct::clone() const
{
    /*cout << "NoFoodProduct Product " << this << endl;*/
    return new NoFoodProduct(*this);
}

double NoFoodProduct::get_power() const
{
    return this->power;
}

double NoFoodProduct::get_volume() const
{
    return this->volume;
}

char NoFoodProduct::get_type() const
{
    return 'n';
}

void NoFoodProduct::set_power(double _power)
{
    this->power = _power;
}

void NoFoodProduct::set_volume(double _volume)
{
    this->volume = _volume;
}

void NoFoodProduct::print(ostream& os) const {
    Product::print(os);
    os << " " << this->power << " " << this->volume;
}

void NoFoodProduct::read(istream& is){
    Product::read(is);
    is >> this->power >> this->volume;
}

bool NoFoodProduct::isBig() const
{
    const double maxVolume = 100.0;
    // краще зробити клас, який матиме всі ці константи публічні
    return (this->volume > maxVolume);
}
