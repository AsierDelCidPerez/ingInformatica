#! /bin/bash

# Author: Asier Del Cid Pérez (Introducción al Software)
# Version: 1.0
# Description: Programa para organizar ficheros

cowsay "Bienvenido a mi script de limpieza. ¡Vamos a conocernos! ¿Cómo te llamas?"
read -p "Introduce tu nombre porfa: " name

clear
cowsay "Un placer conocerte " $name ". Mi intención es ayudarte con tu labor de limpieza. Para ello eliga una de las siguientes opciones:\n1) Descargar ficheros a ordenar\n2) Ordenar ficheros\n"

echo "1) Descargar ficheros a ordenar"
echo "2) Ordenar ficheros"
echo "3) Realizar cuestionario"
desbloqueado=false
hashPocoSecreto="4a70e2f046e14d1a0099f12a63aac35d"



if [[ -f ./.key.hash && $(cat ./.key.hash | base64 -d) == $hashPocoSecreto ]]
then
	desbloqueado=true
	echo "4) Imprimir frase de la suerte"
else
	echo "4) [Opción bloqueada, realiza el cuestionario primero]"
fi

read -p "Elige una opción(1/2/3/4): " opt

if [[ $opt -eq 1 ]]
then
	rm -rf ./desorganizado
	echo "Este comando depende de git. ¿Desea instalarlo y/n?"
	read -p "¿Instalar (y/n)?: " op
	if [$op -eq y];
	then
		sudo apt install git
		sudo apt update
	fi

	git clone https://github.com/AsierDelCidPerez/scriptISw.git
	cp -r ./scriptISw ./desorganizado
	clear
	echo "[+] Ficheros correctamente instalados."
	cd ./desorganizado

elif [[ $opt -eq 2 ]]
then
	
	if [[ -d ./desorganizado ]]
	then
		mkdir ./organizado
		cd ./organizado
		mkdir ./musica
		mkdir ./imagenes
		mkdir ./texto
		mv ../desorganizado/*.mp3 ./musica
		mv ../desorganizado/*.txt ./texto
		mv ../desorganizado/*.jpg ./imagenes
		cd ..
		rmdir ./desorganizado
	else
		echo "[-] Instale primero la carpeta que contiene los archivos vistos en clase."
	fi
elif [[ $opt -eq 3 ]]
then
	echo "[*] A continuación vas a realizar un cuestionario. Si aciertas las cinco preguntas desbloquearás mágicamente la opción bloqueada"
	cuestionario=0
	read -p "¿Estás listo?(y/n): " listo
       	if [[ listo -eq y ]]
	then
		clear
		echo "Empezamos con una fácil... A la siguiente convención de diseño para nombrar variables: miNombreDeVariable, se le denomina:"
		echo "1) Snake-case"
		echo "2) Camel-case"
		echo "3) Ni-idea-case"
		echo "4) Ninguna opción anterior es correcta"
		read -p "Eliga una opción :): (1/2/3/4): " miOpc
		if [[ $miOpc -eq 2 ]]
		then
			cuestionario=$cuestionario+1
		fi
		clear
		echo "¿Cuál de los siguientes NO es un lenguaje de programación?"
		echo "1) C"
		echo "2) C"
		echo "3) C"
		echo "4) HTML"
		echo "PISTA: HTML no es un lenguaje de programación :)"
		read -p "Eliga una opción :): (1/2/3/4): " miOpc
		if [[ miOpc -eq 4 ]]
		then 
			cuestionario=$cuestionario+1
		fi
		clear
		echo "¿Has oído hablar de Dennis Ritchie? Es el creador de _______"
		echo "1) C"
		echo "2) C++"
		echo "3) Java"
		echo "4) Python"
		read -p "Eliga una opción :): (1/2/3/4): " miOpc
		if [[ miOpc -eq 1 ]]
		then
			cuestionario=$cuestionario+1
		fi
		clear
		echo "Vamos a ir poniendo las cosas más difíciles con un tema trepidántemente 'apuntado' como dificil. ¿Qué imprimirá el siguiente código C?"
		echo ""
		echo "#include <stidio.h>"
		echo ""
		echo "int main(void){"
		echo "	int miNum = 5;"
		echo "	int * ptr = &miNum;"
		echo "	*ptr = 7;"
		echo "	printf(\"%d\", miNum);"
		echo "}"
		echo ""
		echo "1) 5"
		echo "2) 7"
		echo "3) 6"
		echo "4) Ninguna de las anteriores es correcta"
		read -p "Eliga una opción :): (1/2/3/4): " miOpc
		if [[ miOpc -eq 2 ]]
		then
			cuestionario=$cuestionario+1
		fi
		clear
		echo "[BOSS Final] ¿Has oído hablar de las fuentes del Nilo? Pues resulta que diferentes fuentes reciben agua de otras fuentes, pero la característica de las fuentes del Nilo, es que todas ellas reciben fuente de una fuente común: la fuente universal. Dadas las relaciones a->b (donde a da agua a b) se pide saber la estructura de datos que minimice el gasto en memoria. Por ejemplo c recibe agua de a si a -> b y b -> c. Se asegura que no hay ciclos."
		echo "1) un array o vector (unidimensional)"
		echo "2) Una matriz (para representar el grafo) o array bidimensional"
		echo "3) Un diccionario o map"
		echo "4) Un multiconjunto o multiset"

# Se puede inicializar un array v en tamaño n (cantidad de fuentes que hay) con -1 de manera que v[b] = a de esta manera por las características del problema se debe hallar el a tal que v[a] = -1

		read -p "Eliga una opción :): (1/2/3/4): " miOpc
		if [[ miOpc -eq 1 ]]
		then
			cuestionario=$cuestionario+1
		fi
		if [[ $cuestionario -eq 5 ]]
		then
			echo "[+] Has desbloqueado la opción secreta."
			echo $hashPocoSecreto | base64 > .key.hash
		else
			echo "[-] No has desbloqueado la opción secreta. Try again :)"

		fi
	fi

elif [[ $opt -eq 4 ]]
then
	if $desbloqueado
	then
		fortune
	else
		echo "[-] No puedes acceder a esta opción"
	fi
else
	echo "[-] No te entendí, lo siento"
fi
