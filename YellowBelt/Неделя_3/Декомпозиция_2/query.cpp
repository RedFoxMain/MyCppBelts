#include "query.h"

std::istream &operator>>(std::istream &is, Query &q)
{
	// Реализуйте эту функцию
	std::string type;
	is >> type;
	std::map<std::string, QueryType> types = {
		{"NEW_BUS", QueryType::NewBus},
		{"BUSES_FOR_STOP", QueryType::BusesForStop},
		{"STOPS_FOR_BUS", QueryType::StopsForBus},
		{"ALL_BUSES", QueryType::AllBuses}};
	q.type = types[type];
	is.ignore(1);

	switch (q.type)
	{
	case QueryType::NewBus:
		is >> q.bus;
		is.ignore(1);
		q.stops.clear();
		while (is.peek() != '\n')
		{
			std::string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
		break;
	case QueryType::BusesForStop:
		is >> q.stop;
		break;
	case QueryType::StopsForBus:
		is >> q.bus;
		break;
	case QueryType::AllBuses:
		break;
	}
	return is;
}
