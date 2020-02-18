def create_array(rango):
    estudios = []
    for i in range(rango):
        i = float(input("Ingrese un valor de 1 a 1.5"))
        while 1 > i or i > 1.5:
            print("Por favor, ingrese un valor valido")
            i = float(input("Ingrese un valor de 1 a 1.5"))
        estudios.append(i)
    print(estudios)
    return estudios

def mayor_calidad(estudios):
    mayor = estudios[0]
    for i in estudios:
        if i > mayor:
            mayor = i
    return mayor

def promedio_mayores_125(estudios):
    promedio = 0
    contador = 0
    for i in estudios:
        if i > 1.25:
            promedio += i
            contador += 1
    return promedio/contador

def main():
    print(" ")
    estudios = create_array(50)
    print(" ")
    mayor = mayor_calidad(estudios)
    promedio = promedio_mayores_125(estudios)
    print("El estudio de mayor calidad es de", mayor)
    print("")
    print("El promedio de los mayores a 1.25 es de", promedio)

main()

# ORDERNAR ITEMS EN ARRAY
array = [3, 4, 5, 1, 3, 6, 10]
for i in range(len(array)):
    for j in range(i+1, len(array)):
        if array[i] > array[j]:
            aux = array[i] #Para no perder el valor i
            array[i] = array[j]
            array[j] = aux
        print(array)
print("#" * 10)
print(array)