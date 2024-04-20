#Calcular factorial con recursividad

def factorial(x):
    if x==0:
        return 1
    return x*factorial(x-1)

def main():
    x=int(input("Numero del factorial: "))
    print(factorial(x))

if __name__ == "__main__" :
    main()