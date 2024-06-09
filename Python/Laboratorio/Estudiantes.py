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
import sys

def askData():
    try:
        f = open("ESTUDIANTES.dat", "x")
        print("Creando archivo 'ESTUDIANTES.dat'...")
        pass
    except:
        f = open("ESTUDIANTES.dat", "a")
        option = "s"
        while (option == "s"):
            cedula = str(input("Ingrese la cedula: "))
            nombre = str(input("Ingrese el nombre: "))
            fecha = str(input("Ingrese la fecha de nacimiento, usar formato DD/MM/AA: "))
            sexo = str(input("Ingrese el sexo (M/F): "))
            promedio = float(input("Ingrese el promedio: "))
            f.write(f"{cedula} {nombre} {fecha} {sexo} {promedio}\n")
            option = str(input("Desea ingresar otro estudiante? (S/N): ").lower())
        print("\nVolviendo al menu...\n")
    f.close()
    main()

def create_report(promedio1,promedio2):
    try:
        f = open("ESTUDIANTES.dat", "r")
    except FileNotFoundError:
        print("\nNO HAY ESTUDIANTES REGISTRADOS, REGRESANDO AL MENU...\n.")
        return
    
    r = open("REPORTE.txt", "w")
    line = f.readline()
    while line:
        student_data = line.split(" ")
        if (float(student_data[4]) > promedio1) and (float(student_data[4]) < promedio2):
            r.write(f"{student_data[0]} {student_data[1]} {student_data[3]} {student_data[4]}\n")
        line = f.readline()
    r.close()
    print_file_contents("REPORTE.txt")
    f.close()
    main()

def print_file_contents(filename):
    with open(filename, 'r') as file:
        for line in file:
            print(line, end='')

def main():
    print("BIENVENIDO AL SISTEMA DE INGRESO DE DATOS, POR FAVOR INGRESAR SU ACCION DESEADA")
    option = int(input("1. INGRESAR DATOS\n2. IMPRIMIR REPORTE\n3. SALIR\n"))

    if (option == 1):
        askData()
    if (option == 2):
        promedio1 = int(input("Ingrese minimo del promedio: "))
        promedio2 = int(input("Ingrese maximo del promedio: "))
        create_report(promedio1,promedio2)
    if (option == 3):
        print("\nGRACIAS POR UTILIZAR NUESTRO SISTEMA\n")
        sys.exit()
    
    else:
        print("\nACCION NO VALIDA, VOLVIENDO AL MENU\n")
        main()

if __name__ == "__main__":
    main()