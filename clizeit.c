#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "zeigzahl.h"

char ersatz = '*';

int main(){
	//setvbuf(stdout, (char*)NULL, _IONBF, 0);
	int r = 0;
	while(1){
		long int zeit = 0;
		zeit = time(NULL);
		zeit = zeit + (60*60*2);
		int stunde,minute = 0;
		//int jahr,monat,tag = 0;
		minute = zeit%3600/60;// sekunden modulo ( sekunden * minuten ) div ( sekunden )
		stunde = zeit%86400/3600;// sekunden modulo ( sekunden * minuten * stunden ) div ( sekunden * minuten )
		//tag = zeit%31536000/86400;
		//printf("%d:%d\n",stunde,minute);
		int s1,s2,m1,m2 = 0;
		s1 = stunde%10;
		s2 = stunde/10;
		m1 = minute%10;
		m2 = minute/10;
		if(r == 0){
			r = 1;
		}else{
			r = 0;
		}
		for(int i = 0; i < 9; i++){
			printf("\x1B[36m");
			zeige_zahl(s2,i,ersatz);
			zeige_zahl(s1,i,ersatz);
			if(r){
				zeige_zahl(99,i,ersatz);
			}else{
				zeige_zahl(98,i,ersatz);
			}
			zeige_zahl(m2,i,ersatz);
			zeige_zahl(m1,i,ersatz);
			printf("\n");
		}
		//printf("s1:%ds2:%dm1:%dm2:%d",s1,s2,m1,m2);
		sleep(1);
		system("clear");
	}
}
