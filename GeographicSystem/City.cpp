#include "City.h"

City::City()
{
}

City::City(string name, int population, double averageTemperature, pair<string, string> coordinates)
{
	City::name = name;
	City::population = population;
	City::averageTemperature = averageTemperature;
	City::coordinates = coordinates;
}

bool City::operator<(City & city)
{
	return name.compare(city.name) < 0 ;
}

bool City::operator>(City & city)
{
	return name.compare(city.name) > 0;
}

ostream & operator<<(ostream & stream, City & city)
{
	stream
		<< "City: " << city.name << endl;
		//<< "\nPopulation: " << city.population 
		//<< "\nAverage Temp: " << city.averageTemperature
		//<< "\nCoordinates: " << city.coordinates.first << ", " << city.coordinates.second << endl;
	return stream;
}
