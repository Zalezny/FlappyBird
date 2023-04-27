#include <barrier>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <semaphore>

void worker(std::barrier<>& b) {
    std::stringstream ss;

    ss << "Watek stworzony " << std::this_thread::get_id() << std::endl;
    std::cout << ss.str() << std::flush;
    ss.str("");

    b.arrive_and_wait();

    ss << "Watek stworzony " << std::this_thread::get_id() << std::endl;
    std::cout << ss.str() << std::flush;
}

void zad1() {
    const int numThreads = 10;
    std::barrier b(numThreads);
    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        threads[i] = std::thread(worker, std::ref(b));
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void printLetter(std::binary_semaphore& sem1, std::binary_semaphore& sem2, char letter) {
    while (true) {
        sem1.acquire();

        std::cout << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        sem2.release();
    }
}

void zad2() {
    std::binary_semaphore a{ 1 };
    std::binary_semaphore b{ 0 };
    std::binary_semaphore c{ 0 };

    const int numThreads = 3;
    std::thread threads[numThreads];

    threads[0] = std::thread(printLetter, std::ref(a), std::ref(b), 'A');
    threads[1] = std::thread(printLetter, std::ref(b), std::ref(c), 'B');
    threads[2] = std::thread(printLetter, std::ref(c), std::ref(a), 'C');

    for (auto& thread : threads) {
        thread.join();
    }
}

void print_a(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_a.acquire();

        std::cout << 'A' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        sem_b.release();
    }
}

void print_b(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_b.acquire();

        std::cout << 'B' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        sem_a.release();
        sem_c.release();
    }
}

void print_c(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_c.acquire();

        std::cout << 'C' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        sem_a.release();
    }
}

void zad3() {
    std::counting_semaphore<3> sem_a{ 0 };
    std::counting_semaphore<3> sem_b{ 0 };
    std::counting_semaphore<3> sem_c{ 1 };

    std::thread threads[3];

    threads[0] = std::thread(print_a, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));
    threads[1] = std::thread(print_b, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));
    threads[2] = std::thread(print_c, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));

    for (auto& thread : threads) {
        thread.join();
    }
}


int main() {
    //zad1();
    //zad2();
    zad3();
}