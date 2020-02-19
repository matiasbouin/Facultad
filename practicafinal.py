'''
3) Cargar un arreglo de 20 elementos reales con las temperaturas de varias ciudades. (Utilizar al menos 3 funciones).
a.       Mostrar el arreglo.
b.       Calcular el promedio de la temperatura.
c.       Mostrar la mayor y menor temperatura.
d.       Generar otro vector con las temperaturas mayores a 0.  Mostrarlo.
e.       Ordenar el primer arreglo.  Mostrarlo.

'''
# def crear_temperaturas():
#     temperaturas = [0] * 20
#     for i in range(len(temperaturas)):
#         temperaturas[i] = float(input("Ingresa la temperatura: "))
    
#     return temperaturas


# def promedio(temperaturas):
#     suma = 0
#     contador = 0
#     for i in range(len(temperaturas)):
#         suma += temperaturas[i]
#         contador += 1
    
#     promedio = suma / contador

#     return promedio

# def mayor_menor(temperaturas):
#     mayor = temperaturas[0]
#     menor = temperaturas[0]

#     for i in range(len(temperaturas)):
#         if temperaturas[i] > mayor:
#             mayor = temperaturas[i]
#         elif temperaturas[i] < menor:
#             menor = temperaturas[i]
    
#     return mayor, menor

# def mayores_a_cero(temperaturas):
#     mayores_a_cero = []
#     for i in range(len(temperaturas)):
#         if temperaturas[i] > 0:
#             mayores_a_cero.append(temperaturas[i])
    
#     return mayores_a_cero

# def ordenar(temperaturas):
#     for i in range(len(temperaturas)):
#         for j in range(i+1, len(temperaturas)):
#             if temperaturas[j] < temperaturas[i]:
#                 aux = temperaturas[i]
#                 temperaturas[i] = temperaturas[j]
#                 temperaturas[j] = aux
    
#     return temperaturas


# def main():
#     temperaturas = crear_temperaturas()
#     promediobb = promedio(temperaturas)
#     print("El promedio es:", promediobb)
#     mayor, menor = mayor_menor(temperaturas)
#     print(mayor, menor)
#     mayores_cero = mayores_a_cero(temperaturas)
#     print(mayores_cero)
#     ordenada = ordenar(temperaturas)
#     print(ordenada)
# main()

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


equipos = []
fundaciones = []
def crear_equipos(min, max):
    print("Bienvenido a la creacion de equipos 2.0")
    
    for i in range(0, min):
        nombre_equipo = input("Ingrese nombre del equipo: ")
        anio_fundacion = int(input("Ingrese año de fundacion del equipo: "))
        equipos.append(nombre_equipo)
        fundaciones.append(anio_fundacion)
        
    respuesta = input("Desea seguir agregando equipos?: s/n ")
    
    if respuesta == "s":
        nombre_equipo = input("Ingrese nombre del equipo: ")
        
        while nombre_equipo != "" and len(equipos) < max:
            anio_fundacion = int(input("Ingrese año de fundacion del equipo: "))
            equipos.append(nombre_equipo)
            fundaciones.append(anio_fundacion)
            nombre_equipo = input("Ingrese nombre del equipo: ")
    
    else:
        print("Ingreso de equipos terminado")

    return equipos, fundaciones

def ordenar_equipos(equipos, fundaciones):
    for i in range(len(fundaciones)):
        for j in range(i+1, len(fundaciones)):
            if fundaciones[i] > fundaciones[j]:
                aux_1 = fundaciones[i]
                fundaciones[i] = fundaciones[j]
                fundaciones[j] = aux_1
                
                aux_2 = equipos[i]
                equipos[i] = equipos[j]
                equipos[j] = aux_2

    # print(equipos)
    # print(fundaciones)
    
    return equipos, fundaciones

def cargar_resultados(equipos):
    equipos_que_jugaron = []
    puntos = []
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

def quien_gana(equipos_que_jugaron, puntos):
    mayor = puntos[0]
    equipo_ganador = equipos_que_jugaron[0]
    
    for i in range(len(equipos_que_jugaron)):
        if puntos[i] > mayor:
            mayor = puntos[i]
            equipo_ganador = equipos_que_jugaron[i]
    
    print("El equipo que gana es:", equipo_ganador)

def peores_equipos(equipos_que_jugaron, puntos):
    peores_equipos = []
    
    equipos, puntos = ordenar_equipos(equipos_que_jugaron, puntos)
    
    for i in range(5):
        peores_equipos.append(equipos[i])
    
    print("Los peores equipos fueron:")
    print(peores_equipos)


def main():

    min = 10
    max = 20
    equipos, fundaciones = crear_equipos(min, max)

    print(ordenar_equipos(equipos, fundaciones))

    equipos_que_jugaron, puntos = cargar_resultados(equipos)

    quien_gana(equipos_que_jugaron, puntos)

    peores_equipos(equipos_que_jugaron, puntos)

main()







