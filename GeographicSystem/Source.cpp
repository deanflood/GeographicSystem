#include "City.h"
#include "BinarySearchTree.h"
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>

using namespace std;

void randomCityGenerator(BinarySearchTree &tree) {
	string latitude = "";
	string longitude = "";
	double averageTemperature = 15;
	int population = 100;
	string cityName;
	for (int i = 0; i < 2500; i++) {
		latitude = to_string(i);
		longitude = to_string(i);
		cityName = "City " + i;
		tree.add(City(cityName, population, averageTemperature, { latitude, longitude }));
	}
}

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


	//Start Time Coordinates
	boost::timer::cpu_timer coordinateTimer;

	for (int i = 0; i < 100; i++) {

		coordinateTimer.resume();

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

		coordinateTimer.stop();

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
	boost::timer::cpu_times coorElapsed = coordinateTimer.elapsed();
	std::cout << endl << "COOR CPU TIME: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds"
		<< " WALLCLOCK TIME: " << coorElapsed.wall / 1e9 << " seconds"
		<< std::endl;

	////Start Time
	//boost::timer::cpu_timer nameTimer;

	//for (int i = 0; i < 500; i++) {
	//	tree.searchTree("Dublin");
	//	tree.searchTree("Washington DC");
	//	tree.searchTree("New York");
	//	tree.searchTree("San Francisco");
	//	tree.searchTree("Las Vegas");
	//	tree.searchTree("Belfast");
	//	tree.searchTree("Mexico City");
	//	tree.searchTree("Texas");
	//	tree.searchTree("Vancouver");
	//	tree.searchTree("Las Angles");
	//}

	////Output timer
	//boost::timer::cpu_times nameElapsed = nameTimer.elapsed();
	//std::cout	<< endl << "CITY CPU TIME: " << (nameElapsed.user + nameElapsed.system) / 1e9 << " seconds"
	//			<< " WALLCLOCK TIME: " << nameElapsed.wall / 1e9 << " seconds"
	//			<< std::endl;

	////Start Time Coordinates
	//boost::timer::cpu_timer coordinateTimer;

	//for (int i = 0; i < 500; i++) {
	//	tree.searchTree(make_pair("53.3498", "6.2603"));
	//	tree.searchTree(make_pair("38.9072", "77.0369"));
	//	tree.searchTree(make_pair("40.7128", "74.0059"));
	//	tree.searchTree(make_pair("37.7749", "122.4194"));
	//	tree.searchTree(make_pair("36.1699", "115.1398"));
	//	tree.searchTree(make_pair("54.5973", "5.9301"));
	//	tree.searchTree(make_pair("19.4326", "99.1332"));
	//	tree.searchTree(make_pair("90.7326", "99.1332"));
	//	tree.searchTree(make_pair("23.4326", "99.1332"));
	//	tree.searchTree(make_pair("9.4326", "9.1332"));
	//}

	////Output timer
	//boost::timer::cpu_times coorElapsed = coordinateTimer.elapsed();
	//std::cout << "COOR CPU TIME: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds"
	//	<< " WALLCLOCK TIME: " << coorElapsed.wall / 1e9 << " seconds"
	//	<< std::endl;

	//Start Time Coordinates
	/*randomCityGenerator(tree);

	boost::timer::cpu_timer addTimer;
	tree.height();
	boost::timer::cpu_times coorElapsed = addTimer.elapsed();
	std::cout << " CPU TIME: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds"
		<< " WALLCLOCK TIME: " << coorElapsed.wall / 1e9 << " seconds"
		<< std::endl;
*/
	system("pause");
	return 1;
}