def torres_hanoi(n, origen, destino, auxiliar):
    if n == 1:
        print(f"Mover disco 1 de {origen} a {destino}")
        return
    torres_hanoi(n-1, origen, auxiliar, destino)
    print(f"Mover disco {n} de {origen} a {destino}")
    torres_hanoi(n-1, auxiliar, destino, origen)

def main():
    n = int(input("Ingrese el número de discos: "))
    torres_hanoi(n, 'A', 'C', 'B')
    
if __name__ == "__main__" :
    main()