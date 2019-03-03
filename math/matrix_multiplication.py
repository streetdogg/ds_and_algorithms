#!/usr/bin/python3

def matrix_multiplication(a, b, size):
    c = []
    for i in range(size):
        c.append([])

    for k in range(size):
        for i in range(size):
            res = 0
            for j in range(size):
                res += a[i][j]*b[j][k]

            c[i].append(res)

    return c

def main():
    a = [[10, 20, 30],
         [49, 59, 69],
         [79, 87, 96]]

    b = [[1, 0, 0],
         [0, 1, 0],
         [0, 0, 1]]

    c = matrix_multiplication(a, b, 3)
    print(c)

if __name__ == "__main__":
    main()