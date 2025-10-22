#include "Product.h"
#include <fstream>
#include "Shop.h"

void test1();
void readArray(Product* arr, int n, istream& is);
void printArray(const Product* arr, int n, ostream& os);

int main()
{
	Shop shop1;
	Shop shop2;
	shop1.read("AllProducts.txt");
	shop2.read("AllProducts2.txt");
	cout << "Shop 1: " << endl;
	shop1.print(cout);
	cout << endl;
	cout << "Shop 2: " << endl;
	shop2.print(cout);
	cout << endl;
	cout << "Shop1 + product with price = 300" << endl;
	Shop shop3 = shop1 + 300;
	shop3.print(cout);
}

void test1()
{
	Product a; // конструктор за замовчуванням тому що нема користувацьких
	a.print();
	cout << endl;
	Product b("table", 3000, "EpicentrK", Date(3, 9, 2025));
	b.print();
	b.change_discont(0.1);
	b.print();

	Product c = a;
	c.set_name("group C");
	c.set_price(10000);


	cout << endl;
	cout << "product a" << endl;
	a.print();
	cout << endl;
	cout << "product c" << endl;
	c.print();
	cout << endl;

	b = c;

	cout << "produtc b" << endl;
	b.print();
}

void readArray(Product* arr, int n, istream& is)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i].read(is);
	}
}

void printArray(const Product* arr, int n, ostream& os)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i].print(os);
		os << endl;
	}
}

void test2() {
	cout << "lol";
	// не працює, я не розумію чому
	/*shop5 = shop1 + 300;*/
	/*shop5 = 300 + shop1;*/
	/*cout << "Shop 4: " << endl;
	shop4.addProduct(Product("table", 3000, "Epicentr", Date(3, 9, 2025)));
	shop4.print(cout);
	cout << endl;
	shop1 += shop2 += shop3;
	cout << "after shop1 += shop2 += shop3: " << endl;
	cout << "Shop1: " << endl;
	shop1.print(cout);
	cout << endl;
	cout << "Shop2: " << endl;
	shop2.print(cout);
	cout << endl;
	cout << "Shop3: " << endl;
	shop3.print(cout);
	cout << endl;
	cout << (shop2 != shop1) << endl;
	Shop shopa;
	Shop shopb;
	cout << (shopa != shopb) << endl;
	cout << (shop2 > shop1) << endl;*/
	Shop shop1;
	Shop shop2;
	Shop shop3;
	shop1.read("AllProducts.txt");
	//shop2.read("AllProducts2.txt");
	/*shop3 = shop1;*/
	cout << "Shop1: " << endl;
	shop1.print(cout);
	cout << endl;
	shop1.changePrice();
	cout << endl;
	shop1.print(cout);
	//cout << "Shop2: " << endl;
	//shop2.print(cout);
	//cout << endl;
	//cout << "Shop3: " << endl;
	//shop3.print(cout);
	//cout << endl;

	/*Shop shop4 = shop1 + shop2;*/
	cout << (shop1 > shop2) << endl;
	/*Shop shop5 = shop1 + 300;*/
	Shop shop4 = shop1 + 300;
	shop4.print(cout);
	/*shop5.print(cout);*/


	return;
};
