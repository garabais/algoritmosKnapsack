Archivos
    main.c: codigo fuente del programa en c
    dynamic: version compilada del programa para LINUX
Carpetas
    test-cases:Carpeta que contiene todos los test cases para el programa
Compilacion
    Para compilar es neceario usar GNU C Compiler (gcc) en su version mas reciente, la mayoria de las distribuciones de LINUX lo tienen instaldo pero en caso de no tenerlo dependera de cada distribuicion la manera de instalarlo, aqui algunos ejemplos
        Ubuntu:
            sudo apt update
            sudo apt install build-essential
        REDHAT:
            dnf install gcc
        ARCHLINUX:
            sudo pacman -S gcc 
    El comando para compilar es:
        gcc -o dynamic main.c
    Para ejecutar el programa hay que checar que tenga permisos de execucion usando ls -l (deberia tenerlos) y en caso de que no los tenga darselo sudo chmod +x dynamic
    Hay multples maneras de executar el programa si se quiere ingresar manualmente los datos puede executarse directamente con:
        ./dynamic
    Si quieres pasarle los datos de un archivo la mejor forma de hacerlo en mi opinion es usando:
        cat test-cases/d01.txt | ./dynamic
        (sustituyedo los paths relativos si se encuentra en otra carpeta)
    Si Queremos redirigir el output del programa a un archivo podemos agregarle direcionamiento
        cat test-cases/d01.txt | ./gredynamicedy > d01.log
    Si el archivo de prueba es muy grande y no queremos guardarlo pero tampoco queremos que se imprima todo en la terminal podemos redirigirlo a /dev/null todo dato enviado se descartara
        cat test-cases/d01.txt | ./dynamic > /dev/null
    Tambien podemos agredr el comando time para ver el tiempo de ejecucion
        time cat test-cases/d01.txt | ./dynamic > /dev/null
        en este caso como son 2 comandos (cat y dynamic) nos dara el tiempo de los 2
    Asi como podemos usar el comando time para ver el tiempo de ejecucion total podemos usar el comando timeout para limitar el tiempo de ejecucion
        timeout 180 cat test-cases/d01.txt | ./dynamic > /dev/null