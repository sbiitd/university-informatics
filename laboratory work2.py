def input_set():
    size = int(input("Введите размер множества: "))
    
    print("Введите элементы множества:")
    elements = []
    for i in range(size):
        element = int(input())
        elements.append(element)
        
    elements = sorted(set(elements))
    return elements

def find_common_greater_than_t(setA, setB, t):
    result = []
    
    for elem in setA:
        if elem > t and elem in setB:
            result.append(elem)
    
    return result

def main():
    A = []
    B = []
    
    t = int(input("Введите значение t: "))
    
    A = input_set()
    B = input_set()
    
    common = find_common_greater_than_t(A, B, t)
    
    if not common:
        print(f"Нет общих элементов больше {t}")
    else:
        print(f"Общие элементы больше {t}: ", end="")
        for elem in common:
            print(elem, end=" ")
        print()

if __name__ == "__main__":
    main()