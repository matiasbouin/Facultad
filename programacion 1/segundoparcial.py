'''
SEGUNDO PARCIAL INTRODUCCION A LA PROGRAMACION
'''

#1
def crear_medicion():

    medicion = [0] * 30
    for i in range(len(medicion)):
        medicion[i] = float(input("Ingrese un grado de alcohol: "))
    
    return medicion

def promedio(medicion):
    
    suma = 0
    contador = 0
    for i in range(len(medicion)):
        suma += medicion[i]
        contador += 1
    
    promedio = suma/contador
    
    return promedio

def mediciones_superiores(medicion):
    
    mediciones_superiores = []
    for i in range(len(medicion)):
        if medicion[i] > 1.0:
            mediciones_superiores.append(medicion[i])
    
    return mediciones_superiores

def ordenar(mediciones_superiores):
    
    for i in range(len(mediciones_superiores)):
        for n in range(i+1, len(mediciones_superiores)):
            if mediciones_superiores[i] > mediciones_superiores[n]:
                aux = mediciones_superiores[i]
                mediciones_superiores[i] = mediciones_superiores[n]
                mediciones_superiores[n] = aux
    
    return mediciones_superiores

def otra_medicion(medicion, promedio):
    
    otra_medicion = [0] * 30
    for i in range(len(otra_medicion)):
        otra_medicion[i] = float(input("Ingrese un grado de alcohol: "))
    
    suma = 0
    contador = 0
    for i in range(len(otra_medicion)):
        suma += otra_medicion[i]
        contador += 1
    
    promedio2 = suma/contador

    if promedio2 > promedio:
        medicion_mas_responsable = "Primera medicion"
    elif promedio2 < promedio:
        medicion_mas_responsable = "Segunda medicion"
    else:
        medicion_mas_responsable = "Ambas tienen el mismo promedio"
   
    return medicion_mas_responsable

def main():
    print("####    BIENVENIDO A MEDICIONES DE ALCOHOL    ####")
    print("")
    print("Por favor, ingrese sus mediciones:")
    print("")
    
    medicion = crear_medicion()
    print("****    TERMINADO   ****")
    print("")
    print("Sus mediciones son:", medicion)
    print("")

    promedio_1 = promedio(medicion)
    print("El promedio de sus mediciones es:", promedio_1)
    print("")

    medicion_superior = mediciones_superiores(medicion)
    print("Las mediciones superiores a 1.0 son:", medicion_superior)
    print("")

    mediciones_ordenadas = ordenar(medicion_superior)
    print("Las mediciones superiores a 1.0 ordenadas, son:", mediciones_ordenadas)
    print("")

    print("A continuacion, ingrese su otra medicion para comparar promedios y responsabilidad:")
    print("")

    medicion_mas_responsable = otra_medicion(medicion, promedio_1)
    print("****    TERMINADO   ****")
    print("")
    print("La medicion mas responsable es:", medicion_mas_responsable)
    print("")

    print("****    PROGRAMA FINALIZADO    ****")

main()

#2
def creacion_de_registros(maximo):

    print("####    BIENVENIDO A CREACION DE REGISTROS    ####")
    print("Ingrese segun corresponda: ")
    
    numero_de_cliente = []
    kilowatts_consumidos = []
    corriente_maxima_detectada = []
    importe_de_la_factura = []

    contador = 0
    while contador < maximo:
        
        rta = input("Desea agregar un registro? s/n: ")
        while rta != "s" and rta != "n":
            print("Opcion invalida, seleccione segun corresponda: s/n")
            rta = input("Desea agregar un registro? s/n: ")
        
        if rta == "s":
            numero = int(input("Ingrese numero de cliente: "))
            kilowatts = input("Ingrese kilowatts_consumidos: ")
            corriente_maxima = int(input("Ingrese corriente maxima detectada: "))
            importe = int(input("Ingrese importe de la factura: "))
        
            numero_de_cliente.append(numero)
            kilowatts_consumidos.append(kilowatts)
            corriente_maxima_detectada.append(corriente_maxima)
            importe_de_la_factura.append(importe)

            print("")
            print("****    Registro creado    ****")
            print("")
            print("Numero de cliente:", numero)
            print("Kilowatts consumidos:", kilowatts)
            print("Corriente máxima detectada:", corriente_maxima)
            print("Importe de la factura:", importe)
            print("")

            contador += 1

        elif rta == "n":
            print("")
            print("****    TERMINADO    ****")
            contador = maximo + 1

        
        if contador == maximo:
            print("Llegaste al maximo de registros")
            print("****    TERMINADO    ****")
    
    return numero_de_cliente, kilowatts_consumidos, corriente_maxima_detectada, importe_de_la_factura

def comparar(numero_de_cliente, kilowatts_consumidos, corriente_maxima_detectada, importe_de_la_factura):
    valor = int(input("Ingrese un valor a comparar: "))
    print("****    COMPARACION TERMINADA    ****")
    print("")
    contador_2 = 1
    for i in range(len(corriente_maxima_detectada)):
        if corriente_maxima_detectada[i] > valor:
            print("    Registro numero", contador_2, "que supera el valor dado:")
            print("Numero de cliente:", numero_de_cliente[i])
            print("Kilowatts consumidos:", kilowatts_consumidos[i])
            print("Corriente máxima detectada:", corriente_maxima_detectada[i])
            print("Importe de la factura:", importe_de_la_factura[i])
            print("")
            contador_2 += 1

def main_2():
    numero_de_cliente, kilowatts_consumidos, corriente_maxima_detectada, importe_de_la_factura = creacion_de_registros(20)
    comparar(numero_de_cliente, kilowatts_consumidos, corriente_maxima_detectada, importe_de_la_factura)

main_2()