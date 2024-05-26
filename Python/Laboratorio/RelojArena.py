#Elaborar un programa en Python que imprima una matriz con forma de reloj de arena

def print_hourglass(dimention):
    matrix = [[0] * dimention for _ in range(dimention)]
    num = 0
    start = 0
    end = dimention - 1

    while start <= end:
        for i in range(start, end + 1):
            matrix[start][i] = num
            matrix[end][i] = num
        num += 1
        start += 1
        end -= 1

    for row in matrix:
        for num in row:
            print(f"{num:3}", end=" ")
        print()

def main():
    dimention = 0
    while dimention%2 == 0:
        dimention = int(input("Ingrese dimension del reloj de arena: "))
    print_hourglass(dimention)

if __name__ == "__main__":
    main()