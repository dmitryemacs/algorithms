#include <iostream>
#include <thread>

namespace { 
    int x = 0;
    void __attribute__((noinline)) use(int c) { asm(""); }

    void race() {
	//going up
	for(int i = 0; i < 100000; ++i) {
	    x += 1;
	    use(x);
	}

	//going down
	for(int i = 0; i < 100000; ++i) {
	    x -= 1;
	    use(x);
	}
    }
}

int main() {
    std::thread t1{race};
    std::thread t2{race};
    t1.join();
    t2.join();
    std::cout << x << std::endl;
}
