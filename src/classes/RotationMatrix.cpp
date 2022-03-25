//
// Created by Eren Erişken on 3/20/22.
//

#include "RotationMatrix.h"

RotationMatrix::RotationMatrix(const matrix_t &m): matrix(m) {}

RotationMatrix RotationMatrix::rotateX(float theta) {
    float sinTheta = std::sin(theta);
    float cosTheta = std::cos(theta);
    matrix_t m = {{
                          {{1, 0,        0,         0}},
                          {{0, cosTheta, -sinTheta, 0}},
                          {{0, sinTheta, cosTheta,  0}},
                          {{0, 0,        0,         1}},
                  }};

    return RotationMatrix(m);
}

RotationMatrix RotationMatrix::transpose() const {
    matrix_t m;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m[i][j] = matrix[j][i];
        }
    }

    return RotationMatrix(m);
}

RotationMatrix RotationMatrix::operator*(const RotationMatrix &rhs) const {
    matrix_t m;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            float sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += matrix[i][k] * rhs.matrix[k][j];
            }
            m[i][j] = sum;
        }
    }

    return RotationMatrix(m);
}

RotationMatrix RotationMatrix::aroundAxis(const Vector3 &axis, float degrees) {
    Vector3 u = axis.normalized();

    Vector3 v;
    float ux = std::abs(u.getX());
    float uy = std::abs(u.getY());
    float uz = std::abs(u.getZ());

    if (ux < uy && ux < uz) {
        v.setX(0);
        v.setY(-u.getZ());
        v.setZ(u.getY());
    } else if (uy < ux && uy < uz) {
        v.setX(-u.getZ());
        v.setY(0);
        v.setZ(u.getX());
    } else {
        v.setX(-u.getY());
        v.setY(u.getX());
        v.setZ(0);
    }

    v = v.normalized();
    Vector3 w = (u * v).normalized();

    matrix_t orthonormal = {{
                          {{u.getX(), u.getY(), u.getZ(), 0}},
                          {{v.getX(), v.getY(), v.getZ(), 0}},
                          {{w.getX(), w.getY(), w.getZ(), 0}},
                          {{0,        0,        0,        1}},
    }};
    RotationMatrix m(orthonormal);
    RotationMatrix mInverse = m.transpose();
    RotationMatrix rotationX = RotationMatrix::rotateX(Utilities::degreesToRadians(degrees));

    return mInverse * rotationX * m;
}

Vector3 RotationMatrix::operator*(const Vector3 &v) const {
    std::array<float, 4> rhs = {v.getX(), v.getY(), v.getZ(), 1};
    std::array<float, 4> result = {0, 0, 0, 0};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += matrix[i][j] * rhs[j];
        }
    }

    return {result[0], result[1], result[2]};
}
