'''
Programa que almacena la cédula, el nombre, las calificaciones obtenidas 
en los tres parciales de 20% c/u, la nota de los laboratorios (10%) y 
la nota del proyecto final (30%) y luego muestre en pantalla los nombres de los 
estudiantes cuyo promedio individual supera el por promedio total del grupo.
'''
def calificationsAppend(student_number, students, califications):
    for i in range(1,student_number+1):
        student_name = str(input(f"Nombre de estudiante {i}: "))
        students.append(student_name)
        
        partials_total:float = 0
        for j in range (1,4):
            partials=float(input(f"Nota de estudiante {i} de parcial {j}: "))
            partials_total = partials_total + (partials * 0.2)
        califications.append(partials_total)

        laboratory = float(input("Nota de laboratorio: "))
        laboratory = laboratory * 0.1
        califications.append(laboratory)

        finalProject = float(input("Nota del proyecto final: "))
        finalProject = finalProject * 0.3
        califications.append(finalProject)

def average(student_number, students, califications):
    total_average = sum(califications) / len(califications)
    for i in range(student_number):
        individual_grades = califications[i*3:i*3+3]
        individual_average = sum(individual_grades) / len(individual_grades)
        if individual_average > total_average:
            print(f"Los estudiantes que tienen una nota mas alta del promedio son: {students[i]}")

def main():
    students=[]
    califications=[]
    student_number = int(input("Ingrese cantidad de estudiantes a evaluar: "))
    calificationsAppend(student_number, students, califications)
    average(student_number, students, califications)

if __name__ == "__main__":
    main()