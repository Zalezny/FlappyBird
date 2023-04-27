#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

const int NUM_REPEATS = 3;
const int NUM_SEMAPHORES = 3;

void print_C(std::counting_semaphore<3>& sem_C, std::counting_semaphore<3>& sem_A) {
    for (int i = 0; i < NUM_REPEATS; ++i) {
        sem_C.acquire();

        cout << 'C' << flush;
        this_thread::sleep_for(chrono::seconds(1));

        sem_A.release();
    }
}

void print_A(std::counting_semaphore<3>& sem_A, std::counting_semaphore<3>& sem_B) {
    for (int i = 0; i < NUM_REPEATS; ++i) {
        sem_A.acquire();

        cout << 'A' << flush;
        this_thread::sleep_for(chrono::seconds(1));

        sem_B.release();
    }
}

void print_B(std::counting_semaphore<3>& sem_B, std::counting_semaphore<3>& sem_C) {
    for (int i = 0; i < NUM_REPEATS; ++i) {
        sem_B.acquire();

        cout << 'B' << flush;
        this_thread::sleep_for(chrono::seconds(1));

        sem_C.release();
    }
}

int main() {
    counting_semaphore<3> sem_C{ 1 };
    counting_semaphore<3> sem_A{ 0 };
    counting_semaphore<3> sem_B{ 0 };

    thread threads[NUM_SEMAPHORES];

    threads[0] = thread(print_C, ref(sem_C), ref(sem_A));
    threads[1] = thread(print_A, ref(sem_A), ref(sem_B));
    threads[2] = thread(print_B, ref(sem_B), ref(sem_C));

    for (auto& thread : threads) {
        thread.join();
    }

    cout << endl;
}