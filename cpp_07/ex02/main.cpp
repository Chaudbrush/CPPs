#include "Array.hpp"
#include "Complex.cpp"

#define MAX_VAL 750

int main(int, char**)
{
    srand(time(NULL));
    // Testing Int
    std::cout << "--- Testing Int ---" << std::endl;  
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        for (int i = 0; i < MAX_VAL; i++) {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++) {
            if (mirror[i] != numbers[i]) {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try {
            std::cout << "trying to access index '-2'" << std::endl;
            numbers[-2] = 0;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        try {
            std::cout << "trying to access index 'MAX_VAL'" << std::endl;        
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++) {
            numbers[i] = rand();
        }
        delete [] mirror;
    }

    // Testing Float
    std::cout << "\n--- Testing Float ---" << std::endl;
    {
        Array<float> numbers(MAX_VAL);
        float* mirror = new float[MAX_VAL];
        for (int i = 0; i < MAX_VAL; i++) {
            const float value = rand() * 0.5;
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<float> tmp = numbers;
            Array<float> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++) {
//            std::cout << std::fixed << std::setprecision(3) << mirror[i] << ", " << numbers[i] << std::endl;
            if (mirror[i] != numbers[i]) {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try {
            std::cout << "trying to access index '-2'" << std::endl;
            numbers[-2] = 0;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        try {
            std::cout << "trying to access index 'MAX_VAL'" << std::endl;
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++) {
            numbers[i] = rand();
        }
        delete [] mirror;  
    }


    {
        int size = 5;
        Array<int> numbers(size);
        int* mirror = new int[size];
        for (int i = 0; i < size; i++) {
            numbers[i] = i;
            mirror[i] = i;
        }
        for (int i = 0; i < size; i++) {
            std::cout << numbers[i] << ", " << mirror[i] << std::endl;
        }
        // SCOPE
        {
            std::cout << "\n--- Inside Scope ---" << std::endl;
            Array<int> test(numbers);
            for (int i = 0; i < size; i++) {
                test[i] = i * 2;
                std::cout << numbers[i] << ", " << test[i] << std::endl;
            }
            Array<int> copy2;

            copy2 = test;
        }
        delete[] mirror;
    }
    std::cout << "\n--- Testing Complex ---" << std::endl;
    {
        int size = 5;
        Array<Complex> numbers(size);
        (void)numbers;
        Complex* mirror = new Complex[size];
        (void)mirror;
        for (int i = 0; i < size; i++) {
            numbers[i].setX(i);
            numbers[i].setY(i * 2);
            mirror[i].setX(i);
            mirror[i].setY(i * 2);
        }
        for (int i = 0; i < size; i++) {
            std::cout << numbers[i] << " || " << mirror[i] << std::endl;
        }
        // SCOPE
        {
            std::cout << "\n--- Inside Scope ---" << std::endl;
            Array<Complex> test(numbers);
            for (int i = 0; i < size; i++) {
                test[i].setX(numbers[i].getX() * 2);
                test[i].setY(numbers[i].getY() * 2);
                std::cout << numbers[i] << " || " << test[i] << std::endl;
            }
            Array<Complex> copy2;

            copy2 = test;
        }
        delete[] mirror;
    }
    return 0;
}