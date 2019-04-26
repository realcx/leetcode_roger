#include <vector>

class VectorUtil {
public:
    VectorUtil();
    ~VectorUtil();

public:
    template<typename T>
    static void print_vector1d(const std::vector<T>& v) {
        if (v.size() == 0) {
            std::cout << "vector size is 0" << std::endl;
            return;
        }

        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "" << std::endl;
    }

    template<typename T>
    static void print_vector2d(const std::vector<std::vector<T>>& v)
    {
        if (v.size() == 0) {
            std::cout << "vector row size is 0" << std::endl;
            return;
        }

        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v.size(); j++) {
                std::cout << v[i][j] << " ";
            }
            std::cout << "" << std::endl;
        }
    }
};