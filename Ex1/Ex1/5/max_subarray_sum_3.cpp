#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MIN -25
#define MAX 74

using namespace std;

// Function to generate a random array of numbers
vector<int> generate_random_array(int seed, int size) 
{
    srand(seed);
    vector<int> array(size);
    for (int i = 0; i < size; i++) 
    {
        array[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    return array;
}

// Algorithm O(n^3)
int max_subarray_sum_n3(const vector<int>& arr) 
{
    int max_sum = MIN * arr.size();
    for (size_t i = 0; i < arr.size(); i++) 
    {
        for (size_t j = i; j < arr.size(); j++) 
        {
            int current_sum = 0;
            for (size_t k = i; k <= j; k++) 
            {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) 
            {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        cerr << "Error reading input. Please provide exactly 2 inputs. (<random_seed>, <input_size>)" << endl;
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    vector<int> array = generate_random_array(seed, size);

    // Run the algorithm and measure running time using gprof
    cout << "Max subarray sum O(n^3): " << max_subarray_sum_n3(array) << endl;

    return 0;
}
