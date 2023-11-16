#include <iostream>
#include <sstream>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }
  
  void SetLine(int line) { line = line; }
  void SetFile(string file) { filename = file; }
  
  void Log(const string& message);

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
  int line;
  string filename;
};

void Logger::Log(const string& message){
	if(log_line && log_file){
		os << filename << ": " << line << " " << message << '\n';
	}
	else if(log_line){
		os << "Line: " << line << '\n';
	}
	else if(log_file){
		os << filename << '\n';
	}
	else{
		os << message << '\n';
	}
	
}

#define LOG(logger, message) \
logger.SetLine(__LINE__); \
logger.SetFile(__FILE__); \
logger.Log(message);


int main(int argc, char *argv[])
{
	ostringstream os;
	Logger log(os);
	log.SetLogLine(true);
	log.SetLogFile(true);
	LOG(log, "hello");
	cout << os.str();
}
