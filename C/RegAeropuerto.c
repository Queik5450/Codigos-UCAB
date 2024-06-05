/*
Se tienen datos sobre el tráfico aéreo de todos los vuelos salientes del 
aeropuerto de Budapest, considerando los siguientes campos, 
respectivamente:
• Nombre de la aerolínea que opera el vuelo.
• Destino del vuelo (nombre de una ciudad).
• Número de pasajeros transportados por el vuelo.
Los datos mencionados, siguiendo el anterior formato, son los siguientes:
Alitalia Roma 180
Alitalia Pisa 82
Germanwings Munich 96
Germanwings Frankfurt 163
NorwegianAir Bergen 202
Wizzair London 184
Wizzair Frankfurt 83
Wizzair Lisbon 198
Se desea que usted cree estructuras de datos apropiadas para guardar los datos 
dados y, posterior a ello, hacer uso de funciones para realizar cada uno de los 
siguientes requerimientos. La salida de resultados por consola debe contener 
exactamente 4 líneas, donde la línea i en la salida es la solución al requerimiento i.
Requerimientos:
1. ¿Cuántos vuelos hay hacia "Frankfurt"?
2. ¿Qué vuelo tiene más pasajeros?
3. Encuentra el primer vuelo con menos de 100 pasajeros.
4. Nombra la aerolínea con el mayor número total de pasajeros. 
*/

#include <stdio.h>
#include <string.h>

struct data
{
    char company[20];
    char city[20];
    int passengers;
};

int countFlightsToCity(struct data flights[], int numFlights, char city[])
{
    int count = 0;
    for (int i = 0; i < numFlights; i++)
    {
        if (strcmp(flights[i].city, city) == 0)
        {
            count++;
        }
    }
    return count;
}

struct data findFlightWithMostPassengers(struct data flights[], int numFlights)
{
    struct data maxPassengersFlight = flights[0];
    for (int i = 1; i < numFlights; i++)
    {
        if (flights[i].passengers > maxPassengersFlight.passengers)
        {
            maxPassengersFlight = flights[i];
        }
    }
    return maxPassengersFlight;
}

struct data findFirstFlightWithLessThan100Passengers(struct data flights[], int numFlights)
{
    struct data firstFlight;
    for (int i = 0; i < numFlights; i++)
    {
        if (flights[i].passengers < 100)
        {
            firstFlight = flights[i];
            break;
        }
    }
    return firstFlight;
}

char* findAirlineWithMostPassengers(struct data flights[], int numFlights)
{
    char* airlineWithMostPassengers = flights[0].company;
    int maxPassengers = flights[0].passengers;
    for (int i = 1; i < numFlights; i++)
    {
        if (flights[i].passengers > maxPassengers)
        {
            airlineWithMostPassengers = flights[i].company;
            maxPassengers = flights[i].passengers;
        }
    }
    return airlineWithMostPassengers;
}

int main()
{
    struct data flights[] = {
        {"Alitalia", "Roma", 180},
        {"Alitalia", "Pisa", 82},
        {"Germanwings", "Munich", 96},
        {"Germanwings", "Frankfurt", 163},
        {"NorwegianAir", "Bergen", 202},
        {"Wizzair", "London", 184},
        {"Wizzair", "Frankfurt", 83},
        {"Wizzair", "Lisbon", 198}
    };
    int numFlights = sizeof(flights) / sizeof(flights[0]);

    // 1. ¿Cuántos vuelos hay hacia "Frankfurt"?
    char city[] = "Frankfurt";
    int numFlightsToFrankfurt = countFlightsToCity(flights, numFlights, city);
    printf("1. Hay %d vuelos hacia Frankfurt.\n", numFlightsToFrankfurt);

    // 2. ¿Qué vuelo tiene más pasajeros?
    struct data flightWithMostPassengers = findFlightWithMostPassengers(flights, numFlights);
    printf("2. El vuelo con mas pasajeros es operado por %s hacia %s con %d pasajeros.\n", flightWithMostPassengers.company, flightWithMostPassengers.city, flightWithMostPassengers.passengers);

    // 3. Encuentra el primer vuelo con menos de 100 pasajeros.
    struct data firstFlightWithLessThan100Passengers = findFirstFlightWithLessThan100Passengers(flights, numFlights);
    printf("3. El primer vuelo con menos de 100 pasajeros es operado por %s hacia %s con %d pasajeros.\n", firstFlightWithLessThan100Passengers.company, firstFlightWithLessThan100Passengers.city, firstFlightWithLessThan100Passengers.passengers);

    // 4. Nombra la aerolínea con el mayor número total de pasajeros.
    char* airlineWithMostPassengers = findAirlineWithMostPassengers(flights, numFlights);
    printf("4. La aerolinea con el mayor numero total de pasajeros es %s.\n", airlineWithMostPassengers);

    return 0;
}