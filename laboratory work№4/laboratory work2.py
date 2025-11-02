def input_set():
    result = set()
    size = int(input("Введите размер множества: "))
    
    print("Введите элементы множества:")
    for i in range(size):
        element = int(input())
        result.add(element)
    
    return result

def find_common_greater_than_t(setA, setB, t):
    result = set()
    
    # Используем генератор для эффективного поиска элементов > t
    for elem in setA:
        if elem > t and elem in setB:
            result.add(elem)
    
    return result

def main():
    t = int(input("Введите значение t: "))
    
    A = input_set()
    B = input_set()
    
    common = find_common_greater_than_t(A, B, t)
    
    if not common:
        print(f"Нет общих элементов больше {t}")
    else:
        print(f"Общие элементы больше {t}: ", end="")
        # Выводим элементы через пробел
        print(' '.join(map(str, sorted(common))))

if __name__ == "__main__":
    main()