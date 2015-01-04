struct moving{
	char movin;
	pthread_t th1;
	pthread_attr_t attr;
};

void * caracter(void * car);

void creaHilosKb(struct moving * a);
