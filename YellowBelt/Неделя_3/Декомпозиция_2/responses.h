#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

struct BusesForStopResponse{
        std::string stop;
        std::map<std::string, std::vector<std::string>> busses_for_stops;
};
std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);


struct StopsForBusResponse{
        std::string bus;
        std::map<std::string, std::vector<std::string>> stops_for_busses;
};
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);


struct AllBusesResponse{
        std::map<std::string, std::vector<std::string>> all_busses;
};
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);