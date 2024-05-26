'''
El arreglo tridimensional NOTAS contiene las notas enteras obtenidas en 5 
evaluaciones realizadas a cada uno de los 30 estudiantes que cursan cada una de 6 
asignaturas correspondientes al primer semestre de ingeniería informática en la 
UCAB-Guayana. Donde NOTAS [i,j,k] representa la nota obtenida en el parcial “k”, el 
estudiante “j” en la asignatura “i”. Hacer que el programa:
a) Almacene en arreglos los datos dados (nombre de las asignaturas, nombre de los 
estudiantes y notas).
b) Muestre el nombre de las materias en las que haya más del 50% de reprobados 
(se aprueba con un promedio >= 10).
c) Por asignatura, muestre el nombre de los estudiantes que reprobaron todos los 
parciales.
'''

def failedCheck(subjects_number, students_number, partials_number, grades):
    failed_subjects = []
    for i in range(subjects_number):
        failed = 0
        for j in range(students_number):
            average = sum(grades[i][j]) / partials_number
            if average < 10:
                failed += 1
        if failed > students_number / 2:
            failed_subjects.append(i)
    return failed_subjects

def failedPrint(subjects_number, students_number, partials_number, grades, subjects, students):
    failed_subjects = failedCheck(subjects_number, students_number, partials_number, grades)
    for i in failed_subjects:
        print(f"La materia de {subjects[i]} tiene mas del 50% de sus estudiantes reprobados.")

    for i in range(subjects_number):
        failed_students = []
        for j in range(students_number):
            failed = True
            for k in range(partials_number):
                grade = grades[i][j][k]
                if grade >= 10:
                    failed = False
                    break
            if failed:
                failed_students.append(students[j])
        print(f"Estudiantes que reprobaron todos los parciales en la materia {subjects[i]}:")
        for student in failed_students:
            print(student)

def main():
    subjects_number = int(input("Ingrese el número de asignaturas: "))
    students_number = int(input("Ingrese el número de estudiantes: "))
    partials_number = int(input("Ingrese el número de parciales: "))

    subjects = [input(f"Ingrese el nombre de la asignatura {i+1}: ") for i in range(subjects_number)]
    students = [input(f"Ingrese el nombre del estudiante {j+1}: ") for j in range(students_number)]
    grades = []
    failed_subjects = []

    for i in range(subjects_number):
        subject_grades = []
        for j in range(students_number):
            student_grades = []
            for k in range(partials_number):
                grade = int(input(f"Ingrese la nota del estudiante '{students[j]}' en la materia de '{subjects[i]}' en el parcial {k+1}: "))
                student_grades.append(grade)
            subject_grades.append(student_grades)
        grades.append(subject_grades)

    failedPrint(subjects_number, students_number, partials_number, grades, subjects, students)

if __name__ == "__main__":
    main()