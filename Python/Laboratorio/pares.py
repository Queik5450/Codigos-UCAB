#Programa que reciba digitos pares de un numero y los sume de manera recursiva sin usar manejo de listas

def suma_digitos_pares(k):
    if k == 0:
        return 0
    else:
        digito = k % 10
        if digito % 2 == 0:
            return digito + suma_digitos_pares(k // 10)
        else:
            return suma_digitos_pares(k // 10)

def main():
    numero1 =int(input("Ingresar el numero a evaluar\n"))
    print(f"La suma de los dígitos pares de {numero1} es: {suma_digitos_pares(numero1)}")

if __name__ == "__main__" :
    main()