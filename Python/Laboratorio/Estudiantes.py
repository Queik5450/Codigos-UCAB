"""
Elaborar un programa en Python cree un archivo de texto donde se almacenen
la cédula, nombre, fecha de nacimiento, sexo (M/F) y promedio de notas, de los
estudiantes de la UCAB, para ello
Pedir los datos por pantalla y almacenarlos en el archivo, llamado
ESTUDIANTES.DAT
A partir de los datos almacenados en el archivo ESTUDIANTES.DAT
elaborar un reporte (archivo de salida, llamado REPORTE.TXT) que
contenga la cédula, nombre, sexo y promedio de nota en un rango dado.
"""

def askData():
    try:
        f = open("ESTUDIANTES.dat", "x")
        pass
    except:
        f = open("ESTUDIANTES.dat", "r+")
        option = "s"
        while (option == "s"):
            cedula = str(input("Ingrese la cedula: "))
            nombre = str(input("Ingrese el nombre: "))
            fecha = str(input("Ingrese la fecha de nacimiento, usar formato DD/MM/AA: "))
            sexo = str(input("Ingrese el sexo (M/F): "))
            promedio = float(input("Ingrese el promedio: "))
            f.write(f"{cedula} {nombre} {fecha} {sexo} {promedio}\n")
            option = str(input("Desea ingresar otro estudiante? (S/N): ").lower())
    f.close()
    main()

def print_report(promedio1,promedio2):
    try:
        r = open("REPORTE.txt", "x")
        pass
    except:
        f = open("ESTUDIANTES.dat", "r")
        r = open("REPORTE.txt", "r+")
        while (EOFError == False):
            line = f.readline().split(" ")
            if (line(4) > promedio1) and (line(4) < promedio2):
                r.write(f"{line(0)} {line(1)} {line(3)} {line(4)}\n")
    r.close()
    main()

def main():
    print("BIENVENIDO AL SISTEMA DE INGRESO DE DATOS, POR FAVOR INGRESAR SU ACCION DESEADA")
    option = int(input("1. INGRESAR DATOS\n2. IMPRIMIR REPORTE\n3. SALIR\n"))

    if (option == 1):
        askData()
    if (option == 2):
        promedio1 = int(input("Ingrese minimo del promedio: "))
        promedio2 = int(input("Ingrese maximo del promedio: "))
        print_report(promedio1,promedio2)
    if (option == 3):
        print("GRACIAS POR UTILIZAR NUESTRO SISTEMA")
    
    else:
        print("ACCION NO VALIDA")
        main()

if __name__ == "__main__":
    main()