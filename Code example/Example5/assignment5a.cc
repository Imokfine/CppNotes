/**
 * @file assignment5a.cc
 * @brief Code for 5614 assignment 5 Part 1.
 * @author Xueni Fu
 * @version 2.0
 * @date 2023-05-20
 */

#include <vector>
#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <algorithm>
#include <thread>
#include <future>


 // You can use this global to make it easy to switch
//const auto policy = std::launch::async;
const auto policy = std::launch::deferred;   


int main(void)
{
    const int n{ 50'000'000 };
    std::atomic<double> dot_prod{ 0 };  // I used atomic to prevent reordering of code around the timings
    std::random_device rd{};
    std::default_random_engine eng{ rd() };
    // Note using std::ref to wrap engine in a referece_wrapper. See Assignment doc
    auto ui = std::bind(std::normal_distribution<>{}, std::ref(eng));

    std::vector<double> v1(n);
    std::vector<double> v2(n);
    std::generate(std::begin(v1), std::end(v1), ui);
    std::generate(std::begin(v2), std::end(v2), ui);


    auto hardware_threads = std::thread::hardware_concurrency();
    std::cout << "Num hardware threads = " << hardware_threads << '\n';
    unsigned available_threads = 3;

    auto partial_dot = [](auto it, auto it2, auto it3) {return std::inner_product(it, it2, it3, 0.0); };

    // --------------------------------Serial version-------------------------------------------------------

    auto start = std::chrono::steady_clock::now();
    dot_prod = std::inner_product(std::begin(v1), std::end(v1), std::begin(v2), 0.0);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Dot product (serial). Answer = " << dot_prod << "\nElapsed time : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n\n";


    // ------------------------------ task based --------------------------------------------------------
    start = std::chrono::steady_clock::now();

    // Add code to do spawn three async tasks here. You can use the lamda expression partial_dot from above 
    int len = v1.size() / available_threads; // the length of vector on each thread

    auto h1 = std::async(policy, partial_dot, std::begin(v1), std::begin(v1) + len, std::begin(v2));
    auto h2 = std::async(policy, partial_dot, std::begin(v1) + len, std::begin(v1) + len * 2, std::begin(v2) + len);
    auto h3 = std::async(policy, partial_dot, std::begin(v1) + len * 2, std::end(v1), std::begin(v2) + len * 2);

    dot_prod = h1.get() + h2.get() + h3.get();

    end = std::chrono::steady_clock::now();
    std::cout << "Dot product parallel async: dot_prod = " << dot_prod << "\nElapsed time : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n\n";

    // ------------------------------ packaged_tasks --------------------------------------------------------


    start = std::chrono::steady_clock::now();

    //
    // Add code to do spawn three threads to run three packaged tasks here. You can use the lamda expression partial_dot from above
    // You will need to create the packaged tasks and then move each one into a thread
    //

    std::packaged_task<double(std::vector<double>::iterator, std::vector<double>::iterator,
        std::vector<double>::iterator)> ptask1{ partial_dot };
    std::packaged_task<double(std::vector<double>::iterator, std::vector<double>::iterator,
        std::vector<double>::iterator)> ptask2{ partial_dot };
    std::packaged_task<double(std::vector<double>::iterator, std::vector<double>::iterator,
        std::vector<double>::iterator)> ptask3{ partial_dot };

    auto f1 = ptask1.get_future();
    auto f2 = ptask2.get_future();
    auto f3 = ptask3.get_future();

    std::thread t1{ std::move(ptask1), std::begin(v1), std::begin(v1) + len, std::begin(v2) };
    std::thread t2{ std::move(ptask2), std::begin(v1) + len, std::begin(v1) + len * 2, std::begin(v2) + len };
    std::thread t3{ std::move(ptask3), std::begin(v1) + len * 2, std::end(v1), std::begin(v2) + len * 2 };

    auto dp = f1.get() + f2.get() + f3.get();

    end = std::chrono::steady_clock::now();
    std::cout << "Dot Product parallel threads & packaged task  = " << dp << "\nElapsed time : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n\n";

    // --------------------------------------packaged tasks-------------------------------------

    
    return 0;
}

