'''
Ingrease numeros enteros hasta que dicho numero sea negativo o cero y calcular:

a) Promedio de aquellos numeros impares y multiplos de 3
b) Porcentaje de numeros divisores de 4
c) Cantidad de numeros primos
'''

numero = int(input("Ingresalo bebe: "))
numeros = []

while numero > 0:
    
    numeros.append(numero)
    numero = int(input("Ingresalo bebe: "))

print("")
print(numeros)
print("")

#a
suma_a = 0
cantidad_a = 0

for i in range(len(numeros)):

    if numeros[i] % 2 != 0 and numeros[i] % 3 == 0:
        suma_a += numeros[i]
        cantidad_a += 1
    
promedio_a = suma_a / cantidad_a

print("")
print("El promedio de numeros impares multiplos de 3 es:", promedio_a)
print("")

#b
total = len(numeros)
suma_b = 0
cantidad_b = 0

for i in range(len(numeros)):

    if numeros[i] % 4 == 0:
        suma_b += numeros[i]
        cantidad_b += 1

porcentaje_b = (cantidad_b * 100) / total

print("")
print("El porcentaje de numeros divisores de 4 es:", porcentaje_b)
print("")

#c
primos = []

for i in range(len(numeros)):

    x = numeros[i]
    divisores = []

    for j in range(2, x):
        if numeros[i] % j == 0:
            divisores.append(j)

    if len(divisores) <= 1:
        primos.append(numeros[i])
    
print("")
print("La cantidad de numeros primos es:", len(primos))
print(primos)
print("")


    

















