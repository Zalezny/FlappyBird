
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

class A {
private:
    int x;
public:
    A(int x) {
        this->x = x;
    }

    void kwadrat() {
        for (int i = 0; i < 10; i++) {
            std::cout << x * x << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        
    }
};

class B {
private:
    int x;
    int y;

public:
    B(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void pomnoz() {
        for (int i = 0; i < 10; i++) {
            std::cout << x * y << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        
    }
};

void zad1() {
    A a(5);
    B b(3, 4);

    std::thread t1(&A::kwadrat, &a);
    std::thread t2(&B::pomnoz, &b);

    t1.join();
    t2.join();
}

std::atomic<int> counterAtom(0);
int counter = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        counterAtom.fetch_add(1, std::memory_order_relaxed);
        counter++;
    }
}

void decrement() {
    for (int i = 0; i < 1000000; ++i) {
        counterAtom.fetch_sub(1, std::memory_order_relaxed);
        counter--;
    }
}

void zad2() {
    std::thread t1(increment);
    std::thread t2(decrement);

    t1.join();
    t2.join();

    std::cout << "atomowa: " << counterAtom << std::endl;
    std::cout << "licznik: " << counter << std::endl;
}

std::mutex mutex_;
std::condition_variable cond_var_producent, cond_var_konsument;
int produkt = 0;

void producent(int nr) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (produkt > 0) {
        cond_var_producent.wait(lock);
    }
    produkt = nr;
    std::cout << "Producent " << nr << " wyprodukowal produkt " << produkt << std::endl;
    cond_var_konsument.notify_one();
}

void konsument() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (produkt == 0) {
        cond_var_konsument.wait(lock);
    }
    std::cout << "Konsument skonsumowal produkt " << produkt << std::endl;
    produkt = 0;
    cond_var_producent.notify_one();
}

void zad3() {
    std::thread producenci[10];
    std::thread konsumenci[10];

    for (int i = 0; i < 10; ++i) {
        producenci[i] = std::thread(producent, i);
        konsumenci[i] = std::thread(konsument);
    }

    for (int i = 0; i < 10; ++i) {
        producenci[i].join();
        konsumenci[i].join();
    }
}

int main() {
    std::cout << "Zadanie 1" << std::endl;
    zad1();
    std::cout << "Zadanie 2" << std::endl;
    zad2();
    std::cout << "Zadanie 3" << std::endl;
    zad3();
    return 0;
}