#EJERCICIOS PSEUDO-CODIGO A PYTHON JOSE ANDRES PEREIRA
ejercicio = int(input("Escoja el ejercicio que desea ver: 1=Longitud de la palabra, 2=Cadena n, n-1, n-2..., 3=Calculadora: "))

if ejercicio == 1:
    #1. Logitud de la palabra
    def longitud(palabra):
        return len(palabra)
    palabra = str(input("Ingrese una palabra: "))
    print("La longitud de la palabra es: ", longitud(palabra))

elif ejercicio == 2:
    #2. Cadena n, n-1, n-2...
    def cadena_n(numero):
        while numero > 0:
            for i in range(numero, 0, -1):
                print(i)
            numero -= 1
            
    numero = int(input("Ingrese un numero: "))
    (cadena_n(numero))

elif ejercicio == 3:
    #3. Calculadora
    def calculadora(num1, num2, operacion):
        if operacion == "+":
            return num1 + num2
        elif operacion == "-":
            return num1 - num2
        elif operacion == "*":
            return num1 * num2
        else:
            return "Operacion no valida"

    num1 = float(input("Ingrese el primer numero: "))
    num2 = float(input("Ingrese el segundo numero: "))
    operacion = input("Ingrese la operacion(+=Suma -=Resta *=Multiplicación): ")
    print("El resultado es: ", calculadora(num1, num2, operacion))
