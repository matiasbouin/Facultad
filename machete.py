'''
Estructura While
'''
continuar = input("Desea ingresar un hogar? SI/NO: ").upper()
while continuar != "SI" and continuar != "NO": #Checkear condicion con while
    print("Usted ingresó:", continuar)
    continuar = input("Ingrese una opción válida. Desea ingresar un hogar? SI/NO: ").upper() 
while continuar == "SI": #While principal
    contador_de_personas = 0
    suma_edades = 0
    personas_en_hogar = int(input("Indique cuantas personas viven en el hogar: "))
    while contador_de_personas < personas_en_hogar:
        edad = int(input("Ingrese la edad del integrante: "))
        suma_edades += edad
        if edad < 18:
            menores_a_18_anios += 1
        contador_de_personas += 1
    promedio = suma_edades / personas_en_hogar
    if promedio > promedio_familia_mas_longeva:
        promedio_familia_mas_longeva = promedio
    print("")
    continuar = input("Desea ingresar un hogar? SI/NO:").upper() #Volver a pedir condicion al final del While

'''
Ordenar items en array
'''
array = [3, 4, 5, 1, 3, 6, 10]
for i in range(len(array)):
    for j in range(i+1, len(array)): #Importante
        if array[i] > array[j]:
            aux = array[i] #Para no perder el valor i
            array[i] = array[j]
            array[j] = aux
        print(array)

'''

'''