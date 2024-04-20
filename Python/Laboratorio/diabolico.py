#Programa que indique si un numero es diabolico o no(Tiene un numero impar de ceros en base 2)

def diabolico(numero, ceros=0):
    if numero > 0:
        print(numero % 2)
        if numero % 2 == 0:
            ceros += 1
        return diabolico(numero // 2, ceros)
    else:
        return ceros % 2 != 0, ceros

def main():
    numero=int (input("Por favor introducir numero a verificar: "))
    is_diabolico, ceros = diabolico(numero)
    if is_diabolico:
        print(f"{numero} es un número diabólico. Tiene {ceros} ceros")
    else:
        print(f"{numero} no es un número diabólico. Tiene {ceros} ceros")

if __name__ == "__main__":
    main()