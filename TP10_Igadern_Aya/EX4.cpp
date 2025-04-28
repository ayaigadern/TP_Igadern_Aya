#include <array>
#include <iostream>
#include <cstddef> 

// Matrix class
template<typename T, std::size_t M, std::size_t N>
class Matrix {
private:
    std::array<T, M * N> matrix; 

public:
    // Constructor: Initialize everything to 0
    Matrix() {
        matrix.fill(T{});
    }

    // Set value at (row, col)
    void set(std::size_t row, std::size_t col, T value) {
        matrix[row * N + col] = value;
    }

    // Get value at (row, col)
    T get(std::size_t row, std::size_t col) const {
        return matrix[row * N + col];
    }

    // Add two matrices
    Matrix<T, M, N> add(const Matrix<T, M, N>& other) const {
        Matrix<T, M, N> result;
        for (std::size_t i = 0; i < M; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                result.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return result;
    }
};

// Specialization for incompatible matrices
template<typename T, std::size_t M1, std::size_t N1, std::size_t M2, std::size_t N2>
Matrix<T, M1, N1> add_incompatible(const Matrix<T, M1, N1>&, const Matrix<T, M2, N2>&) {
    static_assert(M1 == M2 && N1 == N2, "Erreur : dimensions incompatibles pour l'addition de matrices !");
    return Matrix<T, M1, N1>{};
}

int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);
    auto m3 = m1.add(m2);
    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl; // Affiche 6 8
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl; // Affiche 10 12
    Matrix<int, 2, 3> m4; // Incompatible
    // m1.add(m4); // Erreur de compilation (static_assert)
    return 0;
    }
