#include "City.h"
#include "BinarySearchTree.h"
using namespace std;

int main() {
	City city1 = City("Dublin", 1500000, 15.5, make_pair("53.3498 N", "6.2603 W"));
	City city2 = City("London", 8600000, 15.5, make_pair("51.5074 N", "0.1278 W"));
	City city3 = City("Paris", 2200000, 18, make_pair("48.8566 N", "2.3522 E"));
	City city4 = City("Berlin", 3500000, 15.5, make_pair("52.5200 N", "13.4050 E"));
	City city5 = City("Madrid", 3100000, 15.5, make_pair("40.4168 N"," 3.7038 W"));
	City city6 = City("Budapest", 1700000, 15.5, make_pair("47.4979 N", "19.0402 E"));
	City city7 = City("Budapest", 1700000, 15.5, make_pair("47.4979 N", "19.0402 E"));

	BinarySearchTree tree = BinarySearchTree();

	tree.add(city1);
	tree.add(city2);
	tree.add(city3);
	tree.add(city4);
	tree.add(city5);
	tree.add(city6);
	tree.add(city7);

	tree.printInOrder();

	string dub = "Dublin";
	cout << "\n**********\n";
	tree.searchTree("London");
	tree.searchTree("Londonk");

	pair<string, string> p = make_pair("47.4979 N", "19.0402 E");
	cout << "HEIGHT" << tree.height() << endl << endl;

	tree.prettyPrint();


	string cityCheck = "Dublin";
	system("pause");
	return 1;
}