#include <iostream>
#include <condition_variable>
#include <vector>
#include <mutex>
#include <list>
#include <thread>
#include <functional>
#include <chrono>

struct ThreadPool {
public:
    ThreadPool(std::size_t threadPoolSize) {
        for (auto i = 0; i < threadPoolSize; ++i) {
            Threads.emplace_back([this] () {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> ug{Mutex};
                        Cv.wait(ug, [this] () { return !Queue.empty() || Stop; });
                        if (Stop && Queue.empty()) {
                            break;
                        }
                        task = std::move(Queue.front());
                        Queue.pop_front();
                    }
                    task();
                }
            });
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> ug{Mutex};
            Stop = true;

        }
        Cv.notify_all();

        for (auto& thread: Threads) {
            thread.join();
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> ug{Mutex};
            Queue.push_back(std::move(task));
        }
        Cv.notify_one();
    }

private:
    std::vector<std::thread> Threads;
    std::mutex Mutex;
    std::condition_variable Cv;
    std::list<std::function<void()>> Queue;
    bool Stop = false;
};

int main() {
    ThreadPool threadPool{2};
    for (auto i = 0; i < 5; ++i) {
        threadPool.enqueue([] () {
            std::cout << "start " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "end " << std::this_thread::get_id() << std::endl;
        });
    }
    return 0;
}
