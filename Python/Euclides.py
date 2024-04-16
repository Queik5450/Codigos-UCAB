#Calcular MCD de dos numeros con algoritmos de Euclides de manera recursiva

def mcd(x,y):
    if y==0:
        return x
    else:
        return mcd(y,x%y)


x= int(input("Numero 1: "))
y= int(input("Numero 2: "))
print("El mcd es de: ",mcd(x,y))