"""
Elabore un programa en Python, que tome un archivo y determine si es una
imagen de tipo JPG. Sabiendo que un archivo JPG tiene sus dos primeros byte con
los valores FF D8.
"""

def is_jpg(file):
    with open(file, 'rb') as f:
        bytes_iniciales = f.read(2)
        return bytes_iniciales == b'\xFF\xD8'

def main():
    file = input("Ingrese la ruta del archivo: ")
    if is_jpg(file):
        print("El archivo es una imagen de tipo JPG.")
    else:
        print("El archivo no es una imagen de tipo JPG.")

if __name__ == "__main__":
    main()