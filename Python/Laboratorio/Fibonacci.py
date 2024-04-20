#Valor mas cercano del numero dado en la serie de Fibonacci de manera recursiva

def fibo(n,serie=[0,1]):
    if serie[-1] >= n:
        return serie[:-1]
    else:
        serie.append(serie[-1] + serie[-2])
        return fibo(n,serie)

def main():
    n = int(input("Ingrese numero limite de la serie: "))
    print(fibo(n))

if __name__ == "__main__" :
    main()