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

// Algorithm O(n)
int max_subarray_sum_n(const vector<int>& arr) 
{
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (size_t i = 1; i < arr.size(); i++) 
    {
        current_sum = current_sum > 0 ? current_sum + arr[i] : arr[i];
        if (current_sum > max_sum) 
        {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) {
        cerr << "Error reading input. Please provide exactly 2 inputs. (<random_seed>, <input_size>)" << endl;
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    vector<int> array = generate_random_array(seed, size);

    // Run the algorithm and measure running time using gprof
    cout << "Max subarray sum O(n): " << max_subarray_sum_n(array) << endl;

    return 0;
}
