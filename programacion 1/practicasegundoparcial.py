'''
Ejercicios 2do parcial intro a la programacion
'''

#1
def crear_vector(rango):
    print("SU lista de clientes sera de", rango, "clientes")
    clientes = [0] * rango
    for i in range(rango):
        clientes[i] = int(input("Ingrese edad del cliente: "))
        while clientes[i] < 18:
            clientes[i] = int(input("Ingrese edad del cliente, recuerde que debe ser mayor a 18 años: "))
    return clientes

def promedio(clientes):
    suma = 0
    for i in clientes:
        suma += i
    return suma/len(clientes)

def mayor(clientes):
    mayor = clientes[0]
    for i in clientes:
        if i > mayor:
            mayor = i
    return mayor

def edades_mayores_promedio(clientes, promedio):
    edades_mayores_promedio = []
    for i in clientes:
        if i > promedio:
            edades_mayores_promedio.append(i)
    return edades_mayores_promedio

def ordenar_vector(vector):
    vector_ordenado = vector[len(vector)//2 : ]
    vector_ordenado.sort()
    return vector_ordenado

def quitar_edad(vector):
    flag = True
    while flag:
        for i in vector:
            if i%2 == 0:
                vector.remove(i)
                flag = False
    return vector

def main():
    print("####    BIENVENIDO A CREACION DE CLIENTES    ####")
    print("Ingrese rango deseado")
    rango = int(input("Rango: "))
    clientes = crear_vector(rango)
    promedio_edad = promedio(clientes)
    mayor_edad = mayor(clientes)
    mayores_al_promedio = edades_mayores_promedio(clientes, promedio_edad)
    vector_ordenado = ordenar_vector(mayores_al_promedio)
    vector_sin_primer_edad_par = quitar_edad(clientes)
    print("####    TERMINADO    ####")
    print("")
    print("La edad promedio es:", promedio_edad)
    print("La mayor edad es:", mayor_edad)
    print("Las edades mayores al promedio son:", mayores_al_promedio)
    print("Este vector dividido y ordenado es:", vector_ordenado)
    print("El vector original sin primer edad par es:", vector_sin_primer_edad_par)

main()


#2
def main():
    tipos_de_ambientes = [1, 2, 3]
    precio_promedio_1, contador_1 = 0, 0
    precio_promedio_2, contador_2 = 0, 0
    precio_promedio_3, contador_3 = 0, 0
    mayor_precio = 0
    
    barrio = input("Ingrese el barrio: ").upper()
    
    while barrio != "FIN":
        tipo_de_ambiente = int(input("Ingrese tipo de ambiente segun corresponda (1-casa, 2- dep., 3-PH): "))
    
        while tipo_de_ambiente not in tipos_de_ambientes:
            print("ERROR: Tipo de ambiente invalido !!")
            tipo_de_ambiente = int(input("Ingrese tipo de ambiente segun corresponda (1-casa, 2- dep., 3-PH): "))
        
        cantidad_de_ambientes = input("Ingrese cantidad de ambientes: ")
        precio = int(input("Ingrese precio: "))
        
        if precio > mayor_precio:
            mayor_precio = precio
        
        if tipo_de_ambiente == tipos_de_ambientes[0]:
            precio_promedio_1 += precio
            contador_1 += 1
        elif tipo_de_ambiente == tipos_de_ambientes[1]:
            precio_promedio_2 += precio
            contador_2 += 1
        else:
            precio_promedio_3 += precio
            contador_3 += 1 
        
        barrio = input("Ingrese el barrio: ").upper()
    
    print("")
    print("####    TERMINADO    ####")
    print("")
    print("    Precio promedio por tipo de inmueble    ")
    print("Casa..........$", precio_promedio_1)
    print("Dep...........$", precio_promedio_2)
    print("PH............$", precio_promedio_3)
    print("")
    print("    Mayor precio detectado    ")
    print(mayor_precio)

main()


#3
def cargar_temperaturas(cantidad):
    print("####    BIENVENIDO A TEMPERATURAS    ####")
    print("")
    
    temperaturas = [0] * cantidad
    for i in range(len(temperaturas)):
        temperaturas[i] = float(input("Ingrese una temperatura: "))
    
    print("")
    print("####    TERMINADO    ####")
    print("")
    print("Tus temperaturas son: ", temperaturas)
    print("")
    return temperaturas
    

def promedio(temperaturas):
    suma = 0
    contador = 0
    
    for i in range(len(temperaturas)):
        suma += temperaturas[i]
        contador += 1
    
    print("Tu promedio es: ", suma/contador)
    print("")

def mayor_menor(temperaturas):
    mayor = temperaturas[0]
    menor = temperaturas[0]
    
    for i in range(len(temperaturas)):
        if temperaturas[i] > mayor:
            mayor = temperaturas[i]
        elif temperaturas[i] < menor:
            menor = temperaturas[i]
    
    print("La mayor temperatura es:", mayor)
    print("La menor temperatura es:", menor)
    print("")

def mayores_a_0(temperaturas):

    mayores_a_0 = []
    for i in range(len(temperaturas)):
            if temperaturas[i]> 0:
                mayores_a_0.append(temperaturas[i])
    print("Las temperaturas mayores a 0 son:", mayores_a_0)
    print("")

def ordenar(temperaturas):
    for i in range(len(temperaturas)):
        for n in range(i+1, len(temperaturas)):
            if temperaturas[i] > temperaturas[n]:
                aux = temperaturas[i]
                temperaturas[i] = temperaturas[n]
                temperaturas[n] = aux
    print(temperaturas)

def main():
    temperaturas = cargar_temperaturas(20)
    promedio(temperaturas)
    mayor_menor(temperaturas)
    mayores_a_0(temperaturas)
    ordenar(temperaturas)

main()
