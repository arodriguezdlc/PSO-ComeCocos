a.out: leeConfig.o inih/ini.o imprimeMapa.o
	gcc -g -W -Wall -lncurses leeConfig.o inih/ini.o imprimeMapa.o

leeConfig.o: leeConfig.c
	gcc -g -W -Wall -lncurses -c leeConfig.c

imprimeMapa.o: imprimeMapa.c
	gcc -g -W -Wall -lncurses -c imprimeMapa.c
