#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

using namespace std;

// Define the maximum number of threads and resources
const int MAX_RESOURCES = 20;
const int MAX_THREADS = 10;


// Define a mutex and a condition variable to protect the resources
mutex mtx;
condition_variable cv;

// Define the number of available resources
int available_resources = MAX_RESOURCES;

// Define a queue of waiting threads
queue<int> waiting_threads;

// Define a function that simulates a thread using a resource
void use_resource(int thread_id) {
    while (true) {
        // Acquire the mutex
        unique_lock<mutex> lck(mtx);

        // Wait for a resource to become available
        while (available_resources == 0) {
            // Add the thread ID to the queue of waiting threads
            waiting_threads.push(thread_id);
            cout << "Thread " << thread_id << " is waiting for a resource." << endl;
            cv.wait(lck);
        }

        // Use a resource
        available_resources--;
        cout << "Thread " << thread_id << " is using a resource. Remaining resources: " << available_resources << endl;

        // Release the mutex
        lck.unlock();

        // Simulate some work being done
        this_thread::sleep_for(chrono::seconds(1));

        // Acquire the mutex
        lck.lock();

        // Release a resource
        available_resources++;
        cout << "Thread " << thread_id << " has released a resource. Remaining resources: " << available_resources << endl;

        // Notify a waiting thread that a resource has become available
        if (!waiting_threads.empty()) {
            int next_thread = waiting_threads.front();
            waiting_threads.pop();
            cv.notify_one();
            cout << "Thread " << next_thread << " has been notified." << endl;
        }

        // Release the mutex
        lck.unlock();

        // Simulate some more work being done
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    // Create an array of threads
    thread threads[MAX_THREADS];

    // Start the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        threads[i] = thread(use_resource, i);
    }

    // Create a pool of waiting threads
    while (true) {
        // Acquire the mutex
        unique_lock<mutex> lck(mtx); // the mutex is automatically released when lck goes out of scope

        // Print the number of waiting threads and their IDs
        if (!waiting_threads.empty()) {
            cout << "Number of waiting threads: " << waiting_threads.size() << endl;
            cout << "Waiting threads: ";
            queue<int> temp_queue = waiting_threads;
            while (!temp_queue.empty()) {
                cout << temp_queue.front() << " ";
                temp_queue.pop();
            }
            cout << endl;
        }

        // Release the mutex
        lck.unlock();

        // Simulate some work being done
        this_thread::sleep_for(chrono::seconds(5));
    }

    // Join the threads (this code will never be reached)
    for (int i = 0; i < MAX_THREADS; i++) {
        threads[i].join();
    }

    return 0;
}
