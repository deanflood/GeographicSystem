#include "City.h"
#include "BinarySearchTree.h"
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>

using namespace std;

int main() {

	City city1 = City("Dublin", 1500000, 15.5, make_pair("53.3498", "6.2603"));
	City city2 = City("Washington DC", 8600000, 15.5, make_pair("38.9072", "77.0369"));
	City city3 = City("New York", 2200000, 18, make_pair("40.7128", "74.0059"));
	City city4 = City("San Francisco", 3500000, 15.5, make_pair("37.7749", "122.4194"));
	City city5 = City("Las Vegas", 3100000, 15.5, make_pair("36.1699", "115.1398"));
	City city6 = City("Belfast", 1700000, 15.5, make_pair("54.5973", "5.9301"));
	City city7 = City("Mexico City", 1700000, 15.5, make_pair("19.4326", "99.1332"));
	City city8 = City("Texas", 1700000, 15.5, make_pair("90.7326", "99.1332"));
	City city9 = City("Vancouver", 1700000, 15.5, make_pair("23.4326", "99.1332"));
	City city10 = City("Las Angles", 1700000, 15.5, make_pair("9.4326", "9.1332"));

	BinarySearchTree tree = BinarySearchTree();

	tree.add(city1);
	tree.add(city2);
	tree.add(city3);
	tree.add(city4);
	tree.add(city5);
	tree.add(city6);
	tree.add(city7);
	tree.add(city8);
	tree.add(city9);
	tree.add(city10);

	//Start Time for Add by City
	boost::timer::cpu_timer addByCityTimer;

	for (int i = 0; i < 100; i++) {

		addByCityTimer.resume();

		tree.add(city1);
		tree.add(city2);
		tree.add(city3);
		tree.add(city4);
		tree.add(city5);
		tree.add(city6);
		tree.add(city7);
		tree.add(city8);
		tree.add(city9);
		tree.add(city10);

		addByCityTimer.stop();

		tree.deleteNode("Dublin");
		tree.deleteNode("Washington DC");
		tree.deleteNode("New York");
		tree.deleteNode("San Francisco");
		tree.deleteNode("Las Vegas");
		tree.deleteNode("Belfast");
		tree.deleteNode("Mexico City");
		tree.deleteNode("Texas");
		tree.deleteNode("Vancouver");
		tree.deleteNode("Las Angles");

	}

	//Output timer
	boost::timer::cpu_times addByCiyElapsed = addByCityTimer.elapsed();
	cout << endl << "Add Times" << endl << "CPU Time: " << (addByCiyElapsed.user + addByCiyElapsed.system) / 1e9 << " seconds" << endl
		<< "Wall Time: " << addByCiyElapsed.wall / 1e9 << " seconds"
		<< endl;

	//Start Time for search by City
	boost::timer::cpu_timer nameTimer;

	for (int i = 0; i < 500; i++) {
		tree.searchTree("Dublin");
		tree.searchTree("Washington DC");
		tree.searchTree("New York");
		tree.searchTree("San Francisco");
		tree.searchTree("Las Vegas");
		tree.searchTree("Belfast");
		tree.searchTree("Mexico City");
		tree.searchTree("Texas");
		tree.searchTree("Vancouver");
		tree.searchTree("Las Angles");
	}

	//Output timer
	boost::timer::cpu_times nameElapsed = nameTimer.elapsed();
	cout << endl << "Search by Name" << endl << "CPU Time: " << (nameElapsed.user + nameElapsed.system) / 1e9 << " seconds" << endl
				<< "Wall Time: " << nameElapsed.wall / 1e9 << " seconds"
				<< endl;

	//Start Time for search by Coordinates
	boost::timer::cpu_timer coordinateTimer;

	for (int i = 0; i < 500; i++) {
		tree.searchTree(make_pair("53.3498", "6.2603"));
		tree.searchTree(make_pair("38.9072", "77.0369"));
		tree.searchTree(make_pair("40.7128", "74.0059"));
		tree.searchTree(make_pair("37.7749", "122.4194"));
		tree.searchTree(make_pair("36.1699", "115.1398"));
		tree.searchTree(make_pair("54.5973", "5.9301"));
		tree.searchTree(make_pair("19.4326", "99.1332"));
		tree.searchTree(make_pair("90.7326", "99.1332"));
		tree.searchTree(make_pair("23.4326", "99.1332"));
		tree.searchTree(make_pair("9.4326", "9.1332"));
	}

	//Output timer
	boost::timer::cpu_times coorElapsed = coordinateTimer.elapsed();
	cout << endl << "Search by Coordinates" << endl << "CPU Time: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds" << endl
		<< "Wall Time: " << coorElapsed.wall / 1e9 << " seconds"
		<< endl;

	//Start Time Coordinates
	boost::timer::cpu_timer heightTimer;

	for (int i = 0; i < 5000; i++) {
		tree.height();
	}
	boost::timer::cpu_times heightElapsed = heightTimer.elapsed();
	cout << endl << "Height Times" << endl << "CPU Time: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds" << endl
		<< "Wall Time: " << coorElapsed.wall / 1e9 << " seconds"
		<< endl;

	cout << endl << "Near By Cities Example" << endl;
	cout << "Cities near ('37.7749', '125.4194')" << endl;

	tree.add(city1);
	tree.add(city2);
	tree.add(city3);
	tree.add(city4);
	tree.add(city5);
	tree.add(city6);
	tree.add(city7);
	tree.add(city8);
	tree.add(city9);
	tree.add(city10);

	tree.nearByCities({ "37.7749", "125.4194" }, 1000);

	system("pause");
	return 1;
}