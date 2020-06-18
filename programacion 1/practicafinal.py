'''
3) Cargar un arreglo de 20 elementos reales con las temperaturas de varias ciudades. (Utilizar al menos 3 funciones).
a.       Mostrar el arreglo.
b.       Calcular el promedio de la temperatura.
c.       Mostrar la mayor y menor temperatura.
d.       Generar otro vector con las temperaturas mayores a 0.  Mostrarlo.
e.       Ordenar el primer arreglo.  Mostrarlo.

'''

def cargar_temperaturas():
    array_temperaturas = []

    for i in range(20):
        valor = int(input("Cargar temperatura"))
        array_temperaturas.append(valor)

    return array_temperaturas

def promedio(array_temperaturas):
    suma = 0

    for i in range(len(array_temperaturas)):
        suma += array_temperaturas[i]
    
    promedio = suma/len(array_temperaturas)
    
    return promedio

def mayor_y_menor(array_temperaturas):
    mayor = array_temperaturas[0]
    menor = mayor
    
    for i in range(len(array_temperaturas)):
        
        if array_temperaturas[i] < menor:
            menor = array_temperaturas[i]
        elif array_temperaturas[i] > mayor:
            mayor = array_temperaturas[i]
    
    return mayor, menor

def mayores_a_cero(array_temperaturas):
    array_mayores_a_cero = []

    for i in range(len(array_temperaturas)):
        if array_temperaturas[i] > 0:
            array_mayores_a_cero.append(array_temperaturas[i])

    return array_mayores_a_cero

def ordenar(array_temperaturas):
    for i in range(len(array_temperaturas)):
        for j in range(i+1, len(array_temperaturas)):
            
            if array_temperaturas[i] > array_temperaturas[j]:
                aux = array_temperaturas[i]
                array_temperaturas[i] = array_temperaturas[j]
                array_temperaturas[j] = aux
    
    return array_temperaturas  

def main_t():

    array_temperaturas = cargar_temperaturas()
    print("")
    print(array_temperaturas)
    print("")
    print(promedio(array_temperaturas))
    print("")
    print(mayor_y_menor(array_temperaturas))
    print("")
    print(mayores_a_cero(array_temperaturas))
    print("")
    print(ordenar(array_temperaturas))



main_t()


'''
En la AFA por un medio claro y justo le adjudicaron realizar un sistema para un nuevo campeonato de futbol.
El mismo debe permitir el ingreso de todos los equipos, nunca hay un numero exacto de equipos, pero si que son mas de 10
y menos de 20.
Por cada equipo se debe cargar: nombre, año de fundacion.
a.    Cargar los datos de todos los equipos. El ingreso concluye cuando el operador ingresa un vacio el nombre.
b.    Mostrar los datos cargados ordenados por año de fundacion ascendente.
c.    Cargar los resultados de los partidos jugados. Validando que el equipo esté cargado previamente,
que el resultado no se repita. Como esta carga se puede hacer en cualquier momento del torneo, no importa si estan todos
los partidos o solo algunos.
d.    Determinar quien va ganando el torneo
e.    Mostrar los 5 peores equipos
'''

#Creo mis arrays globales iniciales
equipos = []
fundaciones = []

#Defino mi funcion para añadir valores a mis arrays
def crear_equipos(min, max):
    print("Bienvenido a la creacion de equipos 2.0")
    
    #Al saber que son 10 equipos cómo mínimo, utilizo un for para solicitar sus nombres
    for i in range(0, min):
        nombre_equipo = input("Ingrese nombre del equipo: ")
        anio_fundacion = int(input("Ingrese año de fundacion del equipo: "))
        equipos.append(nombre_equipo)
        fundaciones.append(anio_fundacion)
        
    respuesta = input("Desea seguir agregando equipos?: s/n ")
    
    if respuesta == "s":
        nombre_equipo = input("Ingrese nombre del equipo: ")
        
        #Utilizo un while para que el usuario inserte el resto de los equipos a eleccion
        while nombre_equipo != "" and len(equipos) < max:
            anio_fundacion = int(input("Ingrese año de fundacion del equipo: "))
            equipos.append(nombre_equipo)
            fundaciones.append(anio_fundacion)
            nombre_equipo = input("Ingrese nombre del equipo: ")
    
    else:
        print("Ingreso de equipos terminado")

    return equipos, fundaciones

#Defino mi funcion para ordenar mis arrays segun sus valores // Logica para ordenar
def ordenar_equipos(equipos, fundaciones):
    for i in range(len(fundaciones)):
        for j in range(i+1, len(fundaciones)):
            if fundaciones[i] > fundaciones[j]: #Orden ascendente
                aux_1 = fundaciones[i]
                fundaciones[i] = fundaciones[j]
                fundaciones[j] = aux_1
                
                aux_2 = equipos[i]
                equipos[i] = equipos[j]
                equipos[j] = aux_2

    # print(equipos)
    # print(fundaciones)
    
    return equipos, fundaciones

#Defino mi funcion para crear mis array de resultados y equipos que jugaron
def cargar_resultados(equipos):
    equipos_que_jugaron = []
    puntos = []

    #Como el numero de partidos no está determinado, uso un while
    respuesta = input("Desea cargar un resultado? s/n")
    while respuesta == "s":
        
        equipo = input("Ingrese equipo: ")
        
        if equipo in equipos and equipo not in equipos_que_jugaron:
            puntaje = int(input("Ingrese puntaje:"))
            equipos_que_jugaron.append(equipo)
            puntos.append(puntaje)
        else:
            print("El equipo no se encuentra en los archivos o ya se cargó su puntaje")
        
        respuesta = input("Desea cargar un resultado? s/n")

    return equipos_que_jugaron, puntos

#Defino mi funcion para saber cuál de los equipos va ganando
def quien_gana(equipos_que_jugaron, puntos):
    mayor = puntos[0]
    equipo_ganador = equipos_que_jugaron[0]
    
    #Logica para saber el mayor item de un array
    for i in range(len(equipos_que_jugaron)):
        if puntos[i] > mayor:
            mayor = puntos[i]
            equipo_ganador = equipos_que_jugaron[i]
    
    print("El equipo que gana es:", equipo_ganador)

#Defino mi funcion para saber cuales son los 5 valores mas bajos de un array
def peores_equipos(equipos_que_jugaron, puntos):
    peores_equipos = []
    
    #Reutilizo mi funcion para ordenar los equipos
    equipos, puntos = ordenar_equipos(equipos_que_jugaron, puntos)
    
    #Selecciono y sumo a mi nueva array los valores
    for i in range(5):
        peores_equipos.append(equipos[i])
    
    print("Los peores equipos fueron:")
    print(peores_equipos)

#Defino mi funcion principal
def main():

    min = 10
    max = 20
    equipos, fundaciones = crear_equipos(min, max)

    print(ordenar_equipos(equipos, fundaciones))

    equipos_que_jugaron, puntos = cargar_resultados(equipos)

    quien_gana(equipos_que_jugaron, puntos)

    peores_equipos(equipos_que_jugaron, puntos)

main()







