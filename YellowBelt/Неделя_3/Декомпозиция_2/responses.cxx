#include "responses.h"

std::ostream &operator<<(std::ostream &os, const BusesForStopResponse &r)
{
	// Реализуйте эту функцию
	if(r.busses_for_stops.empty()){
		os << "No stop!";
	}
	for (const auto [bus, stops] : r.busses_for_stops)
	{
		if(find(stops.begin(), stops.end(), r.stop) != stops.end()){
			os << bus;
		}
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const StopsForBusResponse &r)
{
	// Реализуйте эту функцию
	if (r.stops_for_busses.count(r.bus) > 0)
	{
		os << r.bus << ": ";
		for (const auto stop : r.stops_for_busses.at(r.bus))
		{
			os << stop << " ";
		}
	}
	else
	{
		os << "No bus!";
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const AllBusesResponse &r)
{
	// Реализуйте эту функцию
	for (const auto [bus, stops] : r.all_busses)
	{
		os << bus << ": ";
		for (const auto stop : stops)
		{
			os << stop << " ";
		}
		os << std::endl;
	}
	return os;
}