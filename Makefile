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
OPTIONS= -g -W -Wall -pthread -lncurses

#Enlazamos los ficheros objeto
PSO-Comecocos.out: principal.o
	gcc -o PSO-Comecocos.out principal.o 

principal.o: principal.c
	gcc $(OPTIONS) -c principal.c -o principal.o

clean: 
	cd bin
	rm -rf *.o && rm -rf *.out
	cd ..
	