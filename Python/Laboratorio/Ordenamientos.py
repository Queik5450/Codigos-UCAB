"""
Dado un vector de N elementos, almacenados en forma aleatoria (desordenado), 
implementar en Python un programa que ordene el vector usando los siguientes 
métodos :
a) Inserción directa (Baraja)
b) Intercambio directo (Burbuja)
c) Selección directa
d) Ordenamiento recursivo (Quicksort)
e) Ordenamiento recursivo (Mergesort)

Implemente para ello un menú, en el cual se pueda seleccionar el tipo de método 
a utilizar y para cada caso pedir los elementos del vector a ordenar.

Para la prueba de los métodos Quicksoft y Mergesoft utilice un arreglo con un 
mínimo de 12 elementos y para los otros tres métodos utilice un arreglo con un 
mínimo de 8 elementos.

Para los métodos Quicksort y Mergesort muestre paso a paso cada cambio 
ocurrido en el arreglo hasta quedar totalmente ordenado.

Una vez ordenado el arreglo, implementar el métodos de búsqueda binaria 
recursiva para localizar un elemento cuyo valor sea dado por teclado..
"""

def insertionSort(elements):
    n=len(elements)
    for i in range(1, n):
        key = elements[i]
        j = i-1
        while j >= 0 and key < elements[j]:
            elements[j + 1] = elements[j]
            j -= 1
        elements[j + 1] = key
    return elements

def bubbleSort(bubble):
    n = len(bubble)
    for i in range(n):
        for j in range(0, n - i - 1):
            if bubble[j] > bubble[j + 1]:
                bubble[j], bubble[j + 1] = bubble[j + 1], bubble[j]
    return bubble

def selectionSort(selections):
    n = len(selections)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if selections[min_idx] > selections[j]:
                min_idx = j
        selections[i], selections[min_idx] = selections[min_idx], selections[i]
    return selections

def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])

    (array[i + 1], array[high]) = (array[high], array[i + 1])

    print(f"Partición realizada: {array[low:high+1]}, pivote={pivot}")

    return i + 1

def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)
    else:
        return array

def merge(array, left, middle, right):
    n1 = middle - left + 1
    n2 = right - middle

    L = [0] * (n1)
    R = [0] * (n2)

    for i in range(0, n1):
        L[i] = array[left + i]

    for j in range(0, n2):
        R[j] = array[middle + 1 + j]
            
    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        array[k] = L[i]
        i += 1
        k += 1
     
    while j < n2:
        array[k] = R[j]
        j += 1
        k += 1

    print(f"Arreglo ordenado hasta ahora: {array}")

def mergeSort(array, left, right):
    if left < right:
        middle = left+(right-left)//2
        mergeSort(array, left, middle)
        mergeSort(array, middle+1, right)
        merge(array, left, middle, right)
    else:
        return array
    
def recursiveBinarySearch(array, low, high, x):
    if high >= low:
        mid = (high + low) // 2

        if array[mid] == x:
            print(f"Elemento encontrado en el índice {mid}")
            return mid

        elif array[mid] > x:
            return recursiveBinarySearch(array, low, mid - 1, x)

        else:
            return recursiveBinarySearch(array, mid + 1, high, x)

    else:
        print("Elemento no encontrado")
        return -1

def main():

    array = []
    option = 1
    while option != 0:
        num = int(input("Ingrese numero nuevo para la lista(0 para dejar de ingresar numeros): "))
        option = num
        if option != 0:
            array.append(num)

    call = int(input("Escoja la forma con la que desea ordenar la lista (1. Insercion, 2. Burbuja, 3. Seleccion, 4. QuickSort, 5. MergeSort): "))

    if call == 1:
        print("La cadena ordenada con metodo de insercion se ve asi:")
        print(insertionSort(array))

    elif call == 2:
        print("La cadena ordenada con metodo burbuja se ve asi:")
        print(bubbleSort(array))

    elif call == 3:
        print("La cadena ordenada con metodo de seleccion se ve asi:")
        print(selectionSort(array))

    elif call == 4:
        print("La cadena ordenada con metodo QuickSort se ve asi:")
        quickSort(array, 0, len(array) - 1)
        print(array)

    elif call == 5:
        print("La cadena ordenada con metodo MergeSort se ve asi:")
        mergeSort(array, 0, len(array) - 1)
        print(array)

    search = str(input("Desear buscar un elemento en la lista ordenada? (S/N): ").lower())
    if (search == "s"):
        recursiveBinarySearch(array, 0, len(array)-1, int(input("Ingrese el numero a buscar: ")))
    else:
        print("Gracias por usar el programa")

if __name__ == "__main__":
    main()
