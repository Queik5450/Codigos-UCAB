"""
Elabore un programa en Python, que tome un archivo y determine si es una
imagen de tipo PNG. Sabiendo que un archivo PNG tiene sus ocho primeros byte
con los valores 89- 50- 4E- 47 -0D- 0A- 1A- 0A
"""

def is_png(file):
    png_signature = [137, 80, 78, 71, 13, 10, 26, 10]

    """
    EXPLICACION: TODAS LAS IMAGENES .PNG TIENEN LOS MISMOS PRIMEROS 8 BYTES AL INICIO, QUE SON LOS
    INSERTADOS EN LA LISTA "png_signature", 137 ES LA CABEZA; 80,78 Y 71 SON LOS VALORES ASCII DE
    "P", "N" Y "G" RESPECTIVAMENTE; 13 Y 10 SON LOS VALORES ASCII DE "CR(CARRIAGE RETURN)" Y "LF(LINE FEED)",
    26 ES EL VALOR ASCII DE UN CARACTER DE CONTROL CONOCIDO COMO SUBSTITUTO.

    SABIENDO ESTO, SOLO SE DEBE REVISAR SI LOS PRIMEROS 8 BYTES COINCIDEN O NO 
    """
    
    with open(file, 'rb') as file:
        signature = file.read(8)
    
    return list(signature) == png_signature

def main():
    file = input("Ingrese la ruta del archivo: ")
    if is_png(file):
        print("Es una imagen de tipo PNG")
    else:
        print("NO ES una imagen de tipo PNG")

if __name__ == "__main__":
    main()