import random
import math
import sys


class Vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def normalized(self):
        magnitude = math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)
        return Vector(self.x / magnitude, self.y / magnitude, self.z / magnitude)


def perpendicular_vector(v):
    a, b = random.random(), random.random()
    if v.z != 0:
        x, y, z = v.x, v.y, v.z
    elif v.y != 0:
        x, y, z = v.x, v.z, v.y
    elif v.x != 0:
        x, y, z = v.y, v.z, v.x
    else:
        raise ValueError('zero-vector')

    c = (- x * a - y * b) / z

    if v.z != 0:
        return Vector(a, b, c)
    elif v.y != 0:
        return Vector(a, c, b)
    elif v.x != 0:
        return Vector(b, c, a)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: generator <number_of_spheres>")
        exit(0)
    n_spheres = int(sys.argv[1])
    for i in range(n_spheres):
        r = random.randrange(1, 1000000)
        theta = round(random.uniform(-math.pi, math.pi), 3)
        phi = round(random.uniform(0.01, math.pi), 3)
        w = random.randrange(-360, 360)
        vx = r * math.cos(theta) * math.sin(phi)
        vy = r * math.sin(theta) * math.sin(phi)
        vz = r * math.cos(phi)
        u = perpendicular_vector(Vector(vx, vy, vz)).normalized()
        print(f"{r} {theta} {phi} {w} {u.x} {u.y} {u.z}")
