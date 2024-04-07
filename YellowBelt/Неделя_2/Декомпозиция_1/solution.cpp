#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

enum class QueryType{
        NewBus,
        BusesForStop,
        StopsForBus,
        AllBuses
};

struct Query{
        QueryType type;
        std::string bus;
        std::string stop;
        std::vector<std::string> stops;
};

std::istream &operator>>(std::istream &is, Query &q){
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

        switch (q.type){
        case QueryType::NewBus:
                is >> q.bus;
                is.ignore(1);
                q.stops.clear();
                while (is.peek() != '\n'){
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

struct BusesForStopResponse{
        // Наполните полями эту структуру
        std::string stop;
        std::map<std::string, std::vector<std::string>> busses_for_stops;
};

std::ostream &operator<<(std::ostream &os, const BusesForStopResponse &r){
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
        std::string bus;
        std::map<std::string, std::vector<std::string>> stops_for_busses;
};

std::ostream &operator<<(std::ostream &os, const StopsForBusResponse &r){
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
        std::map<std::string, std::vector<std::string>> all_busses;
};

std::ostream &operator<<(std::ostream &os, const AllBusesResponse &r){
        // Реализуйте эту функцию
        for (const auto [bus, stops] : r.all_busses){
        	os << bus << ": ";
            for (const auto stop : stops){
            	os << stop << " ";
            }
            os << std::endl;
        }
        return os;
}

class BusManager{
  private:
        std::map<std::string, std::vector<std::string>> bus_stops;
        std::map<std::string, std::vector<std::string>> stops_bus;

  public:
        void AddBus(const std::string &bus, const std::vector<std::string> &stops){
            // Реализуйте этот метод
        	if (!stops.empty()){
            	bus_stops[bus] = stops;
                stops_bus = bus_stops;
            }else{
            	std::cout << "Stops empty!";
            }
        }

        BusesForStopResponse GetBusesForStop(const std::string &stop) const{
                // Реализуйте этот метод
                BusesForStopResponse db;
                db.stop = stop;
                db.busses_for_stops = stops_bus;
                return db;
        }

        StopsForBusResponse GetStopsForBus(const std::string &bus) const{
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
                        std::cout << "No buses!";
                }
                return allBus;
        }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main(){
        int query_count;
        Query q;

        std::cin >> query_count;

        BusManager bm;
        for (int i = 0; i < query_count; ++i){
                std::cin >> q;
                switch (q.type){
                case QueryType::NewBus:
                        bm.AddBus(q.bus, q.stops);
                        break;
                case QueryType::BusesForStop:
                        std::cout << bm.GetBusesForStop(q.stop) << std::endl;
                        break;
                case QueryType::StopsForBus:
                        std::cout << bm.GetStopsForBus(q.bus) << std::endl;
                        break;
                case QueryType::AllBuses:
                        std::cout << bm.GetAllBuses() << std::endl;
                        break;
                }
        }

        return 0;
}