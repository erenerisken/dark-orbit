//
// Created by Eren Erişken on 3/20/22.
//

#ifndef DARK_ORBIT_ROTATIONMATRIX_H
#define DARK_ORBIT_ROTATIONMATRIX_H

#include <array>
#include <cmath>

#include "Utilities.h"
#include "Vector3.h"

/**
 * 4x4 matrix of 32 bit float values
 */
typedef std::array<std::array<float, 4>, 4> matrix_t;

/**
 * 3D rotation matrix (4x4) for transforming spheres around origin
 */
class RotationMatrix {
private:
     matrix_t matrix;

public:
    /**
     * Constructs a rotation matrix instance from given float values
     * @param m primitive matrix type for constructing the rotation matrix
     */
    explicit RotationMatrix(const matrix_t &m);

    /**
     * Calculates and returns transpose of the matrix
     * @return A new rotation matrix instance containing transpose of this matrix
     */
    [[nodiscard]] RotationMatrix transpose() const;

    /**
     * Calculates a rotation matrix around x axis for given angle
     * @param theta angle of rotation in radians
     * @return A new rotation matrix for a rotation of theta radians around x axis
     */
    static RotationMatrix rotateX(float theta);
    /**
     * Calculates and returns a rotation matrix around given axis for given angle
     * @param axis axis of rotation (not necessarily a unit ve
     * @param degrees angle of rotation in degrees
     * @return A new rotation matrix for a rotation of degrees amount
     */
    static RotationMatrix aroundAxis(const Vector3& axis, float degrees);

    /**
     * Calculates and returns product of this matrix and the given matrix
     * @param rhs right hand side of the product
     * @return A new matrix M = this x rhs
     */
    RotationMatrix operator*(const RotationMatrix& rhs) const;
    /**
     * Calculates and returns product of this matrix and the given vector
     * @param v right hand side of the product
     * @return A new Vector3 u = this x v
     */
    Vector3 operator*(const Vector3& v) const;
};


#endif //DARK_ORBIT_ROTATIONMATRIX_H
