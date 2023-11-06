#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType{
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query{
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream &operator>>(istream &is, Query &q){
	// Реализуйте эту функцию
	string type;
	is >> type;
	map<string, QueryType> types = {
		{"NEW_BUS", QueryType::NewBus},
		{"BUSES_FOR_STOP", QueryType::BusesForStop},
		{"STOPS_FOR_BUS", QueryType::StopsForBus},
		{"ALL_BUSES", QueryType::AllBuses}};
	q.type = types[type];
	is.ignore(1);
	
	switch (q.type){
	case QueryType::NewBus:
		is >> q.bus;
		is.ignore(1);
		q.stops.clear();
		while (is.peek() != '\n')
		{
			string stop;
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

struct BusesForStopResponse{
	// Наполните полями эту структуру
	string stop;
	map<string, vector<string>> busses_for_stops;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r){
	// Реализуйте эту функцию
	bool found = false;
	for(const auto [bus, stops]: r.busses_for_stops){
		for(const auto st: stops){
			if(st == r.stop){
				os << bus << " ";
				found = true;
			}
		}
	}
	if(!found){
		os << "No stop!";
	}
	return os;
	
}

struct StopsForBusResponse{
	// Наполните полями эту структуру
	string bus;
	map<string, vector<string>> stops_for_busses;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
	// Реализуйте эту функцию
	if(r.stops_for_busses.count(r.bus)>0){
		os << r.bus << ": ";
		for(const auto [bus, stops]: r.stops_for_busses){
			if(r.bus == bus){
				for(const auto stop: stops){
					os << stop << " ";
				}
			}
		}
	}else{
		os << "No bus!";
	}
	return os;
}

struct AllBusesResponse{
	// Наполните полями эту структуру
	map<string, vector<string>> all_busses;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r){
	// Реализуйте эту функцию
	for (const auto [bus, stops] : r.all_busses){
		os << bus << ": ";
		for (const auto stop : stops)
		{
			os << stop << " ";
		}
		os << endl;
	}
	return os;
}

class BusManager{
  private:
	map<string, vector<string>> bus_stops;
	map<string, vector<string>> stops_bus;

  public:
	void AddBus(const string &bus, const vector<string> &stops){
		// Реализуйте этот метод
		if (!stops.empty())
		{
			bus_stops[bus] = stops;
			stops_bus = bus_stops;
		}else{
			cout << "Stops empty!";
		}
	}

	BusesForStopResponse GetBusesForStop(const string &stop) const{
		// Реализуйте этот метод
		BusesForStopResponse db;
		db.stop = stop;
		db.busses_for_stops = stops_bus;
		return db;
	}

	StopsForBusResponse GetStopsForBus(const string &bus) const{
		// Реализуйте этот метод
		StopsForBusResponse stopsForBus;
		
		stopsForBus.bus = bus;
		stopsForBus.stops_for_busses = stops_bus;
		return stopsForBus;
	}

	AllBusesResponse GetAllBuses() const{
		// Реализуйте этот метод
		AllBusesResponse allBus;
		if(!bus_stops.empty()){
			allBus.all_busses = stops_bus;
		}else{
			cout << "No buses!";
		}
		return allBus;
	}
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main(){
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i){
		cin >> q;
		switch (q.type){
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
