def count_greater_than_t(arr, t):
    return sum(1 for x in arr if x > t)

def print_array(arr):
    print(' '.join(map(str, arr)))

def main():
    SIZE = 5
    A = [0] * SIZE
    B = [0] * SIZE

    t = int(input("Введите значение t: "))

    print(f"Введите {SIZE} элементов массива A:")
    for i in range(SIZE):
        A[i] = int(input())

    print(f"Введите {SIZE} элементов массива B:")
    for i in range(SIZE):
        B[i] = int(input())

    countA = count_greater_than_t(A, t)
    countB = count_greater_than_t(B, t)

    if countA < countB:
        print(f"Массив A имеет меньше элементов больше {t} ({countA}):")
        print_array(A)
        print(f"Массив B ({countB}):")
        print_array(B)
    else:
        print(f"Массив B имеет меньше элементов больше {t} ({countB}):")
        print_array(B)
        print(f"Массив A ({countA}):")
        print_array(A)

if __name__ == "__main__":
    main()