//NECESITAS EL ARCHIVO DEL MISMO NOMBRE QUE ESTA EN LA CARPETA "PLANTILLAS"
#include "PlantillaListaEnlazada.h"

int main()
{
    Node *listp = NULL;

    listp = insert(listp, new_item("Jose Andres", 7));
    listp = insert(listp, new_item("Juan David", 8));
    listp = insert(listp, new_item("Daniel Carreno", 9));
    listp = insert(listp, new_item("Julio Solorzano", 10));
    printf(listp);
    listp, del_item("Juan David");
    printf(listp);

    return 0;
}