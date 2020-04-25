Proposito
    En esta carpeta se encuentra el programa que hice para gnerar los test cases, el programa se encuentra escrito en GO
Archivos
    main.go: codigo fuente del programa escrito en GO
    go.mod: Es el archivo de modulo de GO, en realidad esta ahi por constumbre y por que si no lo pong VSCODE se queja. normalmente se usa para ver que dependencias externas se estan usando y que versiones de estas pero para este caso no sirve para nada exceptopara que no se queje.
    test-generator: version compilada del programa para LINUX
Compilacion
    Para compilar el programa es necesario tener instalado GOLANG, algunas distribuciones lo tienen en sus manejadores de paquetes pero lo mas recomendable es descargarlo directamente de la pagina oficial
    https://golang.org/dl/ las instrucciones para instalarlo estan en https://golang.org/doc/install

    Una vez instalado y con GO en el path lo unico que hay que hacer es usar el comado
        go build -o test-generator main.go
Uso:
    El programa recive de 2 a 3 argumentos:
        1 argumento: path al archivo a crear
        2 argumento: numero de items en la bolsa
        3 argumento[opcional]: peso total de la bolsa
    
    Ejemplo:
        ./test-generator ../dynamic/test-cases/dp15.txt 20 50

        Esto crearia un archivo llamado dp15.txt en la caperta de casos de prueba de el programa de programacion dinamica, este tendria 20 objetos y el peso de la mochila seria de 50

    NOTAS:
        En caso de no especificar el peso de la mochila el programa lo eligira como un numero al azar entre el 2 y el 10 multiplicado por el numero de objetos
        
        Los valores de los pesos se generan de manera aleatoria en un rango de 1 a 1.5 veces el valor del peso maximo. esto con el fin de que pueda haber objetos que no quepan en la mochila pero que la mayoria puedan entrar en ella

        Los valores de la ganacia se eneran de manera aleatoria en un rango de 1 a 2.5 veces el valor del peso maximo. 