#include <iostream>
#include <vector>
#include "maxHeap.h"
#include "random_generator.h"

using namespace std;

// tests if the max estimated with the max heap is the actual max value of 
// the randomly generated numbers
bool testMax(vector<int> input, int maxValue){
    auto max = max_element(begin(input), end(input));
    return (maxValue == *max);
}

int main(int argc, char* argv[]){
    int m;
    random_generator rg;
    int newNumber = 0;
    vector<int> randNumbers;

    if (argc == 2){ 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
    else{
      cout << "maxHeap: [m]" << endl;
      cout << "[m]              number of the random numbers generated" << endl;
      cout << endl;
      return 1;
    }

    maxHeap * maxH = new maxHeap(m);


    // use heaps to store m random numbers to find and maintain the median value
    for (int i=0;i<m;++i){
        rg >> newNumber;
        newNumber %= 100;

        // keep randomly generated numbers in an stl vector for testing
        randNumbers.push_back(newNumber);

        // store randomly generated numbers in the heaps
        maxH->insertKey(newNumber);
    }


    // testing
    if (testMax(randNumbers, maxH->getMax())){
        cout << "The max was found successfully!" << endl;
        cout << "The max value is: " << maxH->getMax() << endl;
        cout << "The input array is: " << endl;
        for (auto i = randNumbers.begin(); i != randNumbers.end(); ++i)
            cout << *i << ", ";
        cout << endl;
    }
    else{
        cout << "Wrong max value." << endl;
    }

    delete maxH;

    return 0;
}