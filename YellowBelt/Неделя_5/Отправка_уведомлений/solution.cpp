#include <iostream>
#include <string>

void SendSms(const std::string &number, const std::string &message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string &email, const std::string &message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

// абстрактный класс
class INotifier{
public:
        virtual void Notify(const std::string &message){}
};

// SmsNotifier
class SmsNotifier: public INotifier{
public:
        SmsNotifier(std::string phone): _phone(phone){
        }

        void Notify(const std::string &message){
                SendSms(phone_, message);
        }

private:
        std::string phone_;
};

// EmailNotifier
class EmailNotifier: public INotifier{
public:
        EmailNotifier(std::string address): address_(address){
        }
        void Notify(const std::string &message){
                SendEmail(address_, message);
        }

private:
        std::string address_;
};

// Notify method
void Notify(INotifier &notifier, const std::string &message) {
        notifier.Notify(message);
}

int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
  return 0;
}