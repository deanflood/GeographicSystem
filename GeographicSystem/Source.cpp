#include "City.h"
#include "BinarySearchTree.h"
using namespace std;

int main() {
	City city1 = City("Dublin", 1500000, 15.5, make_pair("53.3498", "6.2603"));
	City city2 = City("Washington DC", 8600000, 15.5, make_pair("38.9072", "77.0369"));
	City city3 = City("New York", 2200000, 18, make_pair("40.7128", "74.0059"));
	City city4 = City("San Francisco", 3500000, 15.5, make_pair("37.7749", "122.4194"));
	City city5 = City("Las Vegas", 3100000, 15.5, make_pair("36.1699","115.1398"));
	City city6 = City("Belfast", 1700000, 15.5, make_pair("54.5973", "5.9301"));
	City city7 = City("Mexico City", 1700000, 15.5, make_pair("19.4326", "99.1332"));

	BinarySearchTree tree = BinarySearchTree();

	tree.add(city1);
	tree.add(city2);
	tree.add(city3);
	tree.add(city4);
	tree.add(city5);
	tree.add(city6);
	tree.add(city7);

	//tree.nearByCities(make_pair("37.7749", "122.4194"), 1000);

	tree.deleteNode("Washington DC");

	tree.printInOrder();
	cout << endl;
  
	system("pause");
	return 1;
}