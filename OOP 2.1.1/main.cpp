#include "Product.h"
#include <fstream>
#include "Shop1.h"

// Варіант 1
int main()
{
	ifstream is("AllProducts1.txt");
	ifstream is2("AllProducts2.txt");
	Shop1 shop1;
	Shop1 shop2;
	shop1.read(is);
	shop2.read(is2);
	is.close();
	is2.close();
	cout << "Shop1 readed from first file: " << endl << endl;;
	shop1.print(cout);
	cout << endl;
	cout << "Shop2 readed from second file: " << endl << endl;
	shop2.print(cout);
	Shop1 shop3;
	cout << endl;
	Shop1 shop3_f = shop3.add_FoodProducts_to_shop(shop1);
	Shop1 shop3_ff = shop3_f.add_FoodProducts_to_shop(shop2);
	cout << "Shop3 only food products with days < 7: " << endl << endl;
	ofstream os("Result1.txt");
	shop3_ff.print(cout);
	os << "Shop3 only food products with days < 7: " << endl << endl;
	shop3_ff.print(os);
	os.close();
	cout << endl;
	cout << "Shop2 before changing: " << endl << endl;
	shop2.print(cout);
	cout << endl;
	shop2.set_new_price_for_nofood(50, 200);
	cout << "Shop2 after changing new_price in range(look at strings for manufacturer +_range): " << endl << endl;
	ofstream os1("Result2.txt");
	shop2.print(cout);
	os1 << "Shop2 after changing new_price in range (look at strings for manufacturer +_range): " << endl << endl;
	shop2.print(os1);
	os1.close();
	cout << endl;
	ofstream os2("Result1_2.txt");
	os2 << "Shop3 all_new_prices for products: " << endl;
	os2 << shop3_ff.all_new_prices() << endl;
	cout << "Shop3 all_new_prices for products: " << endl;
	cout << shop3_ff.all_new_prices() << endl;


}


