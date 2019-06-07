#include <iostream>
#include <cmath>
#include <algorithm>

void abssort(float *x, unsigned N)
{
    std::sort(x,
            x + N,
            [](float a, float b) { 
                //return std::abs(a) < std::abs(b); 
                if (std::abs(a) < std::abs(b))
                    return true;
                else 
                    return false;
                });
}

int main()
{
    float array_f[] {-2.3, 7.9, 5.8, -0.3, 4.1, -9.9, 8.1};
    
    int size = sizeof(array_f) / sizeof (float);

    abssort(array_f, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << array_f[i] << " ";
    }
    std::cout << std::endl;

    std::cout << [] (float f) { return std::abs(f); } (-3.5) << std::endl;
    std::cout << [] (float f) -> int { return std::abs(f); } (-3.5) << std::endl;

    auto lambda = [] () -> int { return val * 100; };

    return 0;
}