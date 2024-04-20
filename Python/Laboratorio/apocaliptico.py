def apocaliptico(numero, apocalipsis):
    findelmundo=numero%10
    if  findelmundo==6:
        apocalipsis=apocalipsis+1

        if apocalipsis==3:
            return True
        else:
            return apocaliptico(numero // 10, apocalipsis)
    elif numero==0:
        return False
        
    else:
        apocalipsis=0
        return apocaliptico(numero // 10, apocalipsis)
        
def main ():
    numero=int(input("Por favor introduzca su posible numero apocaliptico\n"))
    apocalipsis=0
    if apocaliptico(numero, apocalipsis):
        print(f"{numero} es un número apocalíptico.")
    else:
        print(f"{numero} no es un número apocalíptico.")
if __name__ == "__main__" :
    main()