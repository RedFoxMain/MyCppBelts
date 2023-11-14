#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
    cout << "Send '" << message << "' to e-mail "  << email << endl;
}

// абстрактный класс
class INotifier{
public:
	virtual void Notify(const string& message){}
};

// SmsNotifier
class SmsNotifier: public INotifier{
public:
	SmsNotifier(string phone): phone_(phone){
	}
	
	void Notify(const string& message){
		SendSms(phone_, message);
	}
	
private:
	string phone_;
};

// EmailNotifier
class EmailNotifier: public INotifier{
public:
	EmailNotifier(string address): address_(address){
	}
	void Notify(const string& message){
		SendEmail(address_, message);
	}
	
private:
	string address_;
};

// Notify method
void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
}

int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
  return 0;
}
