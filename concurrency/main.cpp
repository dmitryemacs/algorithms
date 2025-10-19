#include <iostream>
#include <vector>
#include <thread>

int main(void) {
    
    std::thread t([]() {
	std::cout << "Spawned id: " << std::this_thread::get_id() << std::endl;
    });

    std::cout << "Parent id: " << std::this_thread::get_id() << std::endl;
    t.join();
    return 0;
}
