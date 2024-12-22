import sys

args = sys.argv()

for i in args:
    print(i)

with open('archivo.txt', 'r') as archivo:
    lineas = archivo.readlines()
    for linea in lineas:
        print(linea.strip())