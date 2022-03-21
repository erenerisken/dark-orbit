//
// Created by Eren Erişken on 3/20/22.
//

#ifndef DARK_ORBIT_ROTATIONMATRIX_H
#define DARK_ORBIT_ROTATIONMATRIX_H

#include <array>
#include <cmath>

#include "Utilities.h"
#include "Vector3.h"

typedef std::array<std::array<float, 4>, 4> matrix_t;

class RotationMatrix {
private:
     matrix_t matrix;

public:
    explicit RotationMatrix(matrix_t m);

    [[nodiscard]] RotationMatrix transpose() const;

    static RotationMatrix rotateX(float theta);
    static RotationMatrix aroundAxis(const Vector3& axis, float degrees);

    RotationMatrix operator*(const RotationMatrix& rhs) const;
    Vector3 operator*(const Vector3& v) const;
};


#endif //DARK_ORBIT_ROTATIONMATRIX_H
