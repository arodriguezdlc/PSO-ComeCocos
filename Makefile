#####################################################
#                                                   #
#   MAKEFILE PSO-COMECOCOS                          #
#   AUTORES:                                        #
#       ALBERTO RODRIGUEZ DE LA CRUZ                #
#       JUAN ANTONIO PIÑERO PEREZ                   #
#       AZAHARA MARIA PORRAS TEJADA                 #
#       FRANCISCO JAVIER RODRIGUEZ LOPEZ            #
#                                                   #
#####################################################

#VARIABLES MAKEFILE:
OPTIONS= -g -W -Wall -pthread 

#Enlazamos los ficheros objeto
PSO-Comecocos:  principal.o
    gcc -o PSO-Comecocos principal.o 

principal.o: principal.c
    gcc $(OPTIONS) -c principal.c 

clean: 
    rm -rf *.o
    