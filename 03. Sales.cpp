#include <iostream>
#include <string>
#include <sstream>
#include <map>

class Sale {
private:
	std::string town;
	std::string product;
	double price = 0.0;
	double quantity = 0.0;
public:
	void input(std::istream& istr);
	const std::string& getTown(void) const { return town; }
	const std::string& getProduct(void) const { return product; }
	const double getPrice(void) const { return price; }
	const double getQuantity(void) const { return quantity; }
	const double totalPrice(void) const { return price * quantity; }
};

void Sale::input(std::istream& istr) {
	istr >> town >> product >> price >> quantity;
}

int main() {
	Sale* sales = NULL;
	size_t numberOfSales = 0;
	std::cin >> numberOfSales;

	typedef std::map<std::string, double> myMap;
	sales = new Sale[numberOfSales];
	for (size_t i = 0; i < numberOfSales; i++)
	{
		sales[i].input(std::cin);
	}
	myMap totalSales;
	for (size_t i = 0; i < numberOfSales; i++)
	{
		Sale& currSale = sales[i];
		totalSales[currSale.getTown()] += currSale.totalPrice();
	}

	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	for (myMap::iterator it = totalSales.begin(); it != totalSales.end(); it++)
	{
		std::cout << it->first << " -> " << it->second << std::endl;
	} 

	delete[] sales;
	return 0;
}