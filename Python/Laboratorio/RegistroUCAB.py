"""
Usando archivos de texto (secuenciales), crear las siguientes estructuras de
archivos, para el registro de los empleados de la UCAB:
Departamentos (CodigoDpto, NombreDpto) y
Empleados (Céeula, Nombre, Sexo, CodigoDpto, Sueldo)
o Para el Sexo use los valores “M” y “F”
o Para los CódigosDpto use valores enteros

Para ello, elabore los programas en Python que :
1.Reciba por pantalla los codigos y nombres de los departamentos y los almacene
en un archivo llamado DEPARTAMENTOS
2. Reciba por pantalla la cédula, el nombre, el sexo, el código del departamento y
el sueldo de cada uno de los Empleados y los almacene en un archivo llamado
EMPLEADOS. El programa debe permitir ingresar varios empleados hasta que
el usuario decida no ingresar más. No solicitar con antelación la cantidad de
empleados a almacenar.
3. A partir de los archivos creados , DEPARTAMENTOS y EMPLEADOS, generar
un listado (archivo de salida tipo TEXTO) llamado REPORTE que contenga por
Depatamento los Empleados que tienen un sueldo en un rango dado..

El archivo de salida (al que llamaremos Reporte.TXT) debe mostrar el titulo
“Empleados por departamento con sueldo entre xxxx a yyyyy Bs.“ y luego para cada
Departamento mostrar su Código y su Nombre y debajo debe mostrar la cédula,
nombre , sexo y sueldo de los empleados. Este ejercicio deben
hacerlo luego usando los archivos de entrada en formato Binario.
"""

import datetime
import sys

time = datetime.datetime.now()
simplified_hour = time.strftime('%H:%M')
date = datetime.datetime.now().date()

def departments_data():
    try:
        d=open("DEPARTAMENTOS.bin","x")
        print("\nCREANDO ARCHIVO 'DEPARTAMENTOS'...\n")
        print("\nARCHIVO 'DEPARTAMENTOS' CREADO, VOLVIENDO AL MENU\n")
        pass
    except:
        d=open("DEPARTAMENTOS.bin","a")
        option = "s"
        while (option == "s"):
            dep_number = int(input("INGRESE NUMERO DE DEPARTAMENTO: "))
            dep_name = str(input(f"INGRESE NOMBRE DEL DEPARTAMENTO {dep_number}:"))
            d.write(f"{dep_number} {dep_name}\n")
            option=str(input("QUIERE INGRESAR OTRO DEPARTAMENTO?(S/N): ").lower())
        print ("\nVOLVIENDO AL MENU...\n")
    d.close()
    main()

def employee_data():
    try:
        e=open("EMPLEADOS.bin", "x")
        print("\nCREANDO ARCHIVO 'EMPLEADOS'...\n")
        print("\nARCHIVO 'EMPLEADOS' CREADO, VOLVIENDO AL MENU\n")
        pass
    except:
        e = open("EMPLEADOS.bin", "a")
        option = "s"
        while (option == "s"):
            cedula = str(input("INGRESE LA CEDULA DEL EMPLEADO: "))
            name = str(input("INGRESE EL NOMBRE DEL EMPLEADO: "))
            sex = str(input(f"INGRESE EL SEXO DEL EMPLEADO '{name}'(M/F): "))
            employee_number = int(input(f"INGRESE EL NUMERO DE DEPARTAMENTO DEL EMPLEADO '{name}': "))
            salary = float(input(f"INGRESE EL SUELDO DEL EMPLEADO '{name}': "))
            e.write(f"{cedula} {name} {sex} {employee_number} {salary} \n")
            option=str(input("QUIERE INGRESAR OTRO EMPLEADO?(S/N): ").lower())
        print ("\nVOLVIENDO AL MENU...\n")
    e.close()
    main()

def create_report():
    try:
        d = open("DEPARTAMENTOS.bin", "r")
        e = open("EMPLEADOS.bin", "r")

    except FileNotFoundError:
        print("\nNO EXISTE EL ARCHIVO 'DEPARTAMENTOS' O 'EMPLEADOS', CREELOS E INTENTE DE NUEVO\n")
        main()
    
    r = open("REPORTE.TXT", "w")
    r.write("\n")
    
    salary_range_start = float(input("INGRESE SUELDO MINIMO DEL RANGO: "))
    salary_range_end = float(input("INGRESE SUELDO MAXIMO DEL RANGO: "))
    department_check = int(input("INGRESE NUMERO DEL DEPARTAMENTO: "))
    
    r.write(f"UCAB                                                                               FECHA: {date}\n")
    r.write(f"                                                                                   HORA: {simplified_hour}\n")
    r.write(f"          EMPLEADOS POR DEPARTAMENTO CON UN SUELDO ENTRE {salary_range_start} Y {salary_range_end} Bs.\n\n")
    r.write(" DEPARTAMENTO  \t      CEDULA \t      NOMBRE \t       SEXO \t       SUELDO  \n")
    r.write("************** \t     ********\t     ********\t      ******\t      ******** \n")
    departments = d.readlines()
    employees = e.readlines()
    
    for department in departments:
        department_data = department.split()
        department_number = department_data[0]
        department_name = department_data[1]
        for employee in employees:
            employee_data = employee.split()
            employee_salary = float(employee_data[4])
                
            if (int(employee_data[3]) == int(department_number)) and (int(employee_data[3]) == department_check) and (salary_range_start <= employee_salary <= salary_range_end):
                employee_cedula = employee_data[0]
                employee_name = employee_data[1]
                employee_sex = employee_data[2]
                r.write(f"{department_number}-{department_name}          {employee_cedula}         {employee_name}            {employee_sex}              {employee_salary}\n")

    d.close()
    e.close()
    r.close()
    print_report()

    option = str(input("\nQUIERE VOLVER AL MENU?(S/N): ").lower())
    if (option == "s"):
        print("\nREGRESANDO AL MENU...\n")
        main()
    else:
        print("\n\nCERRANDO PROGRAMA...\n\n")
        sys.exit()

def print_report():
    try:
        r = open("REPORTE.TXT", "r")
        report_content = r.read()
        print(report_content)
    except FileNotFoundError:
        print("\nEL ARCHIVO 'REPORTE.TXT' NO EXISTE\n")
    r.close()

def main():
    print("==========================================================")
    print("BIENVENIDO AL SISTEMA DE REGISTRO DE EMPLEADOS DE LA UCAB")
    print("==========================================================")
    option=int(input("1.INGRESAR DATOS DEPARTAMENTOS\n2.INGRESAR EMPLEADOS\n3.IMPRIMIR REPORTE DE EMPLEADOS SEGUN SU SUELDO\n4.SALIR\n"))
    
    if (option == 1):
        departments_data()
    if (option == 2):
        employee_data()
    if (option == 3):
        create_report()
    if (option == 4):
        print("\nGRACIAS POR USAR NUESTRO SISTEMA\n")
        sys.exit()
    else:
        print("OPCION INVALIDA, VOLVIENDO AL MENU")
        main()

if __name__ == "__main__":
    main()