#include <iostream>
#include <random>
#include <vector>

void rand(std::vector<int> &N) {
    std::random_device dev;
    std::mt19937 mt(dev());
    std::uniform_int_distribution<int> dis(1, 100);

    for(int i = 0; i < N.size(); i++) {
        N[i] = dis(mt);
    }
}

void sort_radix(std::vector<int> &N){
    int *a0 = new int[N.size()];
    int *a1 = new int[N.size()];
    
    for(int radix = 0; radix < 32; radix++) {
        int a0_size = 0;
        int a1_size = 0;
        for(int i = 0; i < N.size(); i++) {
            if((N[i] & (1 << radix)) == 0) {
                a0[a0_size++] = N[i];
            }
            else {
                a1[a1_size++] = N[i];
            }
        }

        for(int i = 0; i < a0_size; i++) {
            N[i] = a0[i];
        }
        for(int i = 0; i < a1_size; i++) {
            N[a0_size + i] = a1[i];
        }
    }

    delete[] a0;
    delete[] a1;
}

void print(std::vector<int> &N) {
    for(int i = 0; i < N.size(); i++) {
        std::cout << N[i] << " ";
    }
    std::cout << "\n";
}

int main(void) {
    std::vector<int> Vec(20);
    rand(Vec);
    std::cout << "Rand vector: ";
    print(Vec);
    std::cout << "Sort vector: ";
    sort_radix(Vec);
    print(Vec);
}