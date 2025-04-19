// Includes
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <list>
#include <deque>

using namespace std;
// Constants
const int NUM_ELEMENTS = 1000000;

// Functions declarations
void ProfileBackInsertVector(vector<int>& vec);
void ProfileRandomAccessVector(vector<int>& vec);
void ProfileBackInsertList(list<int>& lis);
void ProfileFrontInsertList(list<int>& lis);
void ProfileRandomAccessDeque(deque<int>& deq);
void ProfileBackInsertDeque(deque<int>& deq);
void ProfileFrontInsertDeque(deque<int>& deq);

// Functions Definitions
int main()
{
    vector<int> vec;
    ProfileBackInsertVector(vec);
    // TODO: Profile RandomAccessVector
    ProfileRandomAccessVector(vec);

    // TODO: Create list
    list<int> lis;
    // TODO: ProfileBackInsertList
    // TODO: ProfileFrontInsertList
    ProfileBackInsertList(lis);
    ProfileFrontInsertList(lis);

    // TODO: Create deque
    // TODO: ProfileBackInsertDeque
    // TODO: ProfileFrontInsertDeque
    // TODO: ProfileRandomAccessDeque
    deque<int> deq;
    ProfileRandomAccessDeque(deq);
    ProfileBackInsertDeque(deq);
    ProfileFrontInsertDeque(deq);

    return 0;
}

void ProfileBackInsertVector(vector<int>& vec)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = std::chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the back for std::vector: " << duration.count() << " ms\n";
}
void ProfileRandomAccessVector(vector<int>& vec)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, NUM_ELEMENTS - 1);
    int result = vec[distrib(gen)];
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::vector: " << duration.count() << " ms\n";
}
void ProfileBackInsertList(list<int>& lis)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);
    lis.insert(lis.end(), distrib(gen));
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::list: " << duration.count() << " ms\n";
}
void ProfileFrontInsertList(list<int>& lis)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);
    lis.insert(lis.begin(), distrib(gen));
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::list: " << duration.count() << " ms\n";
}
void ProfileRandomAccessDeque(deque<int>& deq)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, NUM_ELEMENTS - 1);
    int result = deq[distrib(gen)];
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::deque: " << duration.count() << " ms\n";
}
void ProfileBackInsertDeque(deque<int>& deq)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);
    deq.insert(deq.end(), distrib(gen));
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::deque: " << duration.count() << " ms\n";
}
void ProfileFrontInsertDeque(deque<int>& deq)
{
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    /*for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.at(i);
    }*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);
    deq.insert(deq.begin(), distrib(gen));
    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    //chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>((end - start)/NUM_ELEMENTS);
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to access a element for std::deque: " << duration.count() << " ms\n";
}