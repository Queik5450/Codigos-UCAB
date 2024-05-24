#Dado N, un número impar, elaborar un algoritmo que genere un square mágico de orden N.

def magicSquare(size):
    square = [[0 for x in range(size)] for y in range(size)]
    n = 1
    i, j = 0, size//2
    while n <= size*size:
        square[i][j] = n
        n += 1
        newi, newj = (i-1) % size, (j+1) % size
        if square[newi][newj]:
            i += 1
        else:
            i, j = newi, newj
    return square

def main():
    size:int = 0
    while size%2 == 0:
        size=int(input("Ingrese dimension del cuadrado magico: "))
    for row in magicSquare(size):
        print(row)

if __name__ == "__main__":
    main()