В задаче «Декомпозиция программы» мы разбили монолитный код на набор функций и классов. Теперь мы сделаем ещё один шаг и разделим нашу программу на несколько файлов. В этой задаче вам нужно создать проект, состоящий из следующих файлов:
```
query.h, в него кладём:
enum class QueryType
struct Query
объявление istream& operator >> (istream& is, Query& q)
query.cpp, в него кладём
определение istream& operator >> (istream& is, Query& q);
responses.h:
struct BusesForStopResponse
ostream& operator << (ostream& os, const BusesForStopResponse& r)
struct StopsForBusResponse
ostream& operator << (ostream& os, const StopsForBusResponse& r)
struct AllBusesResponse
ostream& operator << (ostream& os, const AllBusesResponse& r)
responses.cpp: определения всего, что объявлено в responses.h
bus_manager.h: объявление класса BusManager
bus_manager.cpp: определения методов класса BusManager
main.cpp: функция main
```
