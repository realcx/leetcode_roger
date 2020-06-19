/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <climits>

#include "common/vector_util.hpp"

using namespace std;

/* 
1. Bubble Sort
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class BubbleSort {
public:
    template<typename T>
    vector<T> sort(const vector<T>& v_in) {
        const int size = v_in.size();
        vector<T> v_out(v_in);

        int tmp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (v_out[j] > v_out[j + 1]) {
                    tmp = v_out[j + 1];
                    v_out[j + 1] = v_out[j];
                    v_out[j] = tmp;
                }
            }
        }
        return v_out;
    }
};


/* 
2. Selection Sort
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class SelectionSort {
public:
    template<typename T>
    vector<T> sort(const vector<T>& v_in) {
        const int size = v_in.size();
        vector<T> v_out(v_in);

        int min_index;
        T tmp;
        for (int i = 0; i < size; i++) {
            min_index = i;
            for (int j = i + 1; j < size; j++) {
                if (v_out[j] < v_out[min_index]) {
                    min_index = j;
                }
            }
            tmp = v_out[min_index];
            v_out[min_index] = v_out[i];
            v_out[i] = tmp;
        }
        return v_out;
    }
};


/* 
3. Insertion Sort
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class InsertionSort {
public:
    template<typename T>
    vector<T> sort(const vector<T>& v_in) {
        if (v_in.size() <= 1) {
            return v_in;
        }

        vector<T> v_out;
        v_out.push_back(v_in[0]);
        for (int i = 1; i < v_in.size(); i++) {
            const int size = v_out.size();
            for (int j = 0; j < size; j++) {
                if (v_in[i] < v_out[j]) {
                    v_out.insert(v_out.begin() + j, v_in[i]);
                    break;
                }
                if (j == v_out.size() - 1) {
                    v_out.push_back(v_in[i]);
                }
            }
        }

        return v_out;
    }
};


/* 
4. Merge Sort
Time Complexity: O(nlog2n)
Space Complexity: O(n)
*/

class MergeSort {
public:
    template<typename T>
    vector<T> sort(const vector<T>& v_in) {
        const int size = v_in.size();
        if (size < 2) {
            return v_in;
        }
        const int middle = size / 2;

        vector<T> left_vect(v_in.begin(), v_in.begin() + middle);
        vector<T> right_vect(v_in.begin() + middle, v_in.end());
        return merge(sort(left_vect), sort(right_vect));
    }

    template<typename T>
    vector<T> merge(const vector<T>& v1, const vector<T>& v2) {
        vector<T> v_out;
        int i = 0;
        int j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) {
                v_out.push_back(v1[i++]);
            } else {
                v_out.push_back(v2[j++]);
            }
        }
        while (i < v1.size()) {
            v_out.push_back(v1[i++]);
        }
        while (j < v2.size()) {
            v_out.push_back(v2[j++]);
        }
        return v_out;
    }
};


/* 
5. Quick Sort
Time Complexity: O(nlog2n)
Space Complexity: O(nlog2n)
*/

class QuickSort {
public:
    template<typename T>
    vector<T> sort(const vector<T>& v_in) {
        vector<T> v_out;

        return v_out;
    }
};



int main() {
    vector<int> v1;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 101);
    }
    cout << "raw vector: " << endl;
    VectorUtil::print_vector1d(v1);
    cout << "bubble sort: "  << endl;
    VectorUtil::print_vector1d(BubbleSort().sort(v1));
    cout << "selection sort: " << endl;
    VectorUtil::print_vector1d(SelectionSort().sort(v1));
    cout << "insertion sort: " << endl;
    VectorUtil::print_vector1d(InsertionSort().sort(v1));
    cout << "merge sort: " << endl;
    VectorUtil::print_vector1d(MergeSort().sort(v1));
    // cout << "quick sort: " << endl;
    // VectorUtil::print_vector1d(QuickSort().sort(v1));
    return 0;
}
