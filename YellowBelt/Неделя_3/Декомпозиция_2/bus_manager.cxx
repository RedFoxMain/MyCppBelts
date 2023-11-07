#include "bus_manager.h"

void BusManager::AddBus(const std::string &bus, const std::vector<std::string> &stops)
{
	if (!stops.empty())
	{
		bus_stops[bus] = stops;
		stops_bus = bus_stops;
	}
	else
	{
		std::cout << "Stops empty!";
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const
{
	BusesForStopResponse db;
	db.stop = stop;
	db.busses_for_stops = stops_bus;
	return db;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string &bus) const
{
	StopsForBusResponse stopsForBus;

	stopsForBus.bus = bus;
	stopsForBus.stops_for_busses = stops_bus;
	return stopsForBus;
}

AllBusesResponse BusManager::GetAllBuses() const
{
	AllBusesResponse allBus;
	if (!bus_stops.empty())
	{
		allBus.all_busses = stops_bus;
	}
	else
	{
		std::cout << "No buses!";
	}
	return allBus;
}