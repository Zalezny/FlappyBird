#include <iostream>
#include <future>
#include <string>

int square(int x)
{
    return x * x;
}

int cube(int x)
{
    return x * x * x;
}

void zad1() {
    std::future<int> squareAsync = std::async(std::launch::async, square, 5);
    std::future<int> cubeAsync = std::async(std::launch::async, cube, 5);
    std::cout << "Suma obu: " << squareAsync.get() + cubeAsync.get() << std::endl;
}

int calculateProduct(int a, int b) {
    return a * b;
}

void zad2() {
    std::packaged_task<int(int, int)> task(calculateProduct);
    std::future<int> futureObj = task.get_future();
    std::async(std::launch::async, std::move(task), 8, 9);
    std::cout << "Wartosc calculateProduct: " << futureObj.get() << std::endl;
}

std::string getName() {
    std::string name;
    std::cout << "Podaj imie: ";
    std::cin >> name;
    return name;
}

int getAge() {
    int age;
    std::cout << "Podaj wiek: ";
    std::cin >> age;
    return age;
}

std::string getAddress() {
    std::string address;
    std::cout << "Podaj adres: ";
    std::cin.ignore(); 
    std::getline(std::cin, address);
    return address;
}

void zad3() {

    std::promise<std::string> name_promise;
    std::promise<int> age_promise;
    std::promise<std::string> address_promise;

    std::future<std::string> name_future = name_promise.get_future();
    std::future<int> age_future = age_promise.get_future();
    std::future<std::string> address_future = address_promise.get_future();

    std::async(std::launch::async, [&name_promise]() {
        name_promise.set_value(std::move(getName()));
        });
    std::async(std::launch::async, [&age_promise]() {
        age_promise.set_value(getAge());
        });
    std::async(std::launch::async, [&address_promise]() {
        address_promise.set_value(std::move(getAddress()));
        });
   
    std::cout << "Name: " << name_future.get() << std::endl;
    std::cout << "Age: " << age_future.get() << std::endl;
    std::cout << "Address: " << address_future.get() << std::endl;
}

int main()
{
    std::cout << "ZAD1" << std::endl;
    zad1();
    std::cout << "ZAD2" << std::endl;
    zad2();
    std::cout << "ZAD3" << std::endl;
    zad3();
}