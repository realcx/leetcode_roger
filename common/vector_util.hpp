#include <iostream>
#include <vector>

using namespace std;


class VectorUtil {
public:
    VectorUtil() = default;
    ~VectorUtil() = default;

public:
    template<typename T>
    static void print_vector1d(const vector<T>& v) {
        if (v.size() == 0) {
            cout << "vector size is 0" << endl;
            return;
        }

        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << "" << endl;
    }

    template<typename T>
    static void print_vector2d(const vector<vector<T>>& v) {
        if (v.size() == 0) {
            cout << "vector row size is 0" << endl;
            return;
        }

        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "" << endl;
        }
    }

    template<typename T>
    static void print_vector3d(const vector<vector<vector<T>>>& v) {
        if (v.size() == 0) {
            cout << "vector row size is 0" << endl;
            return;
        }

        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v[0].size(); j++) {
                for (size_t p = 0; p < v[0][0].size(); p++) {
                    cout << v[i][j][p] << " ";
                }
                cout << "" << endl;
            }
            cout << "" << endl;
        }
    }
};