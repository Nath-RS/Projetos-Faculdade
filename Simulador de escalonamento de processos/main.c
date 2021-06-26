#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define PIDE 		0
#define MEMO 		1
#define STAT 		2
#define PRIO 		3
#define COL 		5
#define ROW 		10

void sysProcess(int *p_PI,int *p_M,int *p_S,int *p_PR, int *p_T){
	int i;		
	srand(time(NULL));
	
	*(p_PI+0) = 5587;
	*(p_PI+1) = 4877;
	*(p_PI+2) = 9951;
	*(p_PI+3) = 5583;
	*(p_PI+4) = 1287;
	*(p_PI+5) = 5229;
	*(p_PI+6) = 1927;
	*(p_PI+7) = 1723;

	*(p_M+0) = 2;
	*(p_M+1) = 4;
	*(p_M+2) = 8;
	*(p_M+3) = 32;
	*(p_M+4) = 64;
	*(p_M+5) = 128;
	*(p_M+6) = 256;
	*(p_M+7) = 512;

	*(p_S+0) = 1;
	*(p_S+1) = 0;
	*(p_S+2) = 2;
	*(p_S+3) = 1;
	*(p_S+4) = 2;
	*(p_S+5) = 0;
	*(p_S+6) = 0;
	*(p_S+7) = 1;

	
	*(p_PR+0) = 37;
	*(p_PR+1) = 16;
	*(p_PR+2) = 13;
	*(p_PR+3) = 50;
	*(p_PR+4) = 6;
	*(p_PR+5) = 10;
	*(p_PR+6) = 12;
	*(p_PR+7) = 22;
		
	for(i=0;i<ROW;i++){
		*(p_T+i)= rand()%100;
	}
		
}

int process(int *p_PI,int *p_M,int *p_S,int *p_PR){
	int i;
	
	for(i=8;i<ROW;i++){
		printf("Type PID Value: ");
		scanf("%d",(p_PI+i));
		
		printf("Type Memory Weight: ");
		scanf("%d",(p_M+i));
		
		printf("Type Status Number: ");
		scanf("%d",(p_S+i));
		
		printf("Type Priority Number: ");
		scanf("%d",(p_PR+i));
		printf("\n");
	}
	
}

void BCP(int (*bcp_Table)[COL],int *p_PI,int *p_M,int *p_S,int *p_PR,int *p_T){
	int i,z;
	for(i=0;i<=ROW;i++){
		for(z=0;z<COL;z++){
			*(*(bcp_Table+i)+0) = *(p_PI+i);
			*(*(bcp_Table+i)+1) = *(p_M+i);
			*(*(bcp_Table+i)+2) = *(p_S+i);
			*(*(bcp_Table+i)+3) = *(p_PR+i);
			*(*(bcp_Table+i)+4) = *(p_T+i);
		}
		printf("\n");
	}
} 


void scheduler(int *p_PI,int *p_M,int *p_S,int *p_PR,int *p_T, int opt){
	int i,X,Z,change;
	
	void changeValues(){
		change = p_PI[X];
		p_PI[X] = p_PI[Z];
		p_PI[Z] = change;
		
		change = p_M[X];
		p_M[X] = p_M[Z];
		p_M[Z] = change;
		
		change = p_S[X];
		p_S[X] = p_S[Z];
		p_S[Z] = change;
		
		change = p_PR[X];
		p_PR[X] = p_PR[Z];
		p_PR[Z] = change;
		
		change = p_T[X];
		p_T[X] = p_T[Z];
		p_T[Z] = change;
	}

	for(X=0;X<ROW;X++){
		for(Z=X;Z<ROW;Z++){
			if(opt == 1){
				if(p_PR[X] > p_PR[Z]){
					changeValues();		
				}
			}
			else if(opt == 2){
				if(p_M[X] > p_M[Z]){
					changeValues();		
				}
			}
			else if(opt == 3){
				if(p_M[X] < p_M[Z]){
					changeValues();		
				}
			}
			else if(opt == 4){
				if(p_T[X] < p_T[Z]){
					changeValues();		
				}
			}
		}
	}
	
}
void loadBar(int *p_PI, int *p_M){
	int i,Z;
	
	for(i=0;i<ROW;i++){
		printf("Process: %d",*(p_PI+i));
		printf("\n");
		
		for(Z=0;Z<40;Z++){ 
			Sleep(*(p_M+i));
			printf("%c",219);
		}
		
		printf("\n\n");	
	}
		
}

int printBCP(int (*bcp_Table)[COL]){
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){

			if(j == 0){
				printf("PID[%d][%d] = %d",i,j, *(*(bcp_Table+i)+j));
			}			
			
			else if(j == 1){
				printf("Memory[%d][%d] = %d",i,j, *(*(bcp_Table+i)+j));
			}	
			
			else if(j == 2){
				printf("Status[%d][%d] = %d",i,j, *(*(bcp_Table+i)+j));
			}	
			
			else if(j == 3){
				printf("Priority[%d][%d] = %d",i,j, *(*(bcp_Table+i)+j));
			}
			else if(j == 4){
				printf("Ticket[%d][%d] = %d",i,j, *(*(bcp_Table+i)+j));
			}	
			printf("; ");
		}
		printf("\n");
	}
}

int main(){

	int i,j,opt,optn,bcp_Table[ROW][COL];
	int p_PID[ROW],p_MEM[ROW], p_STA[ROW], p_PRI[ROW], p_TIC[ROW];
	char cls[1];
	
	//Call function to create and to allocate System's processes.
	sysProcess(p_PID,p_MEM,p_STA,p_PRI,p_TIC);
	
	//Call function to create and to allocate User's processes.
	process(p_PID,p_MEM,p_STA,p_PRI);
	
	//Call function to crate/allocate the BCP Table 2D Array.
	BCP(bcp_Table, p_PID,p_MEM,p_STA,p_PRI,p_TIC);
	
	//Print BCP table in the order that the proceses are created.
	printf("\n_______________________________BEGIN BCP Table without any method_______________________________\n");
	printBCP(bcp_Table);
	printf("\n_______________________________END BCP Table without any method_______________________________\n");
	
	//Scheduler's options
	printf("\nEscolha um dos tipos de escalonamento\n\n");	
	printf("\n1 - Priority\n2 - FIFO\n3 - LIFO\n4 - Ticket\n\nInsert the value... ");
	scanf("%d", &opt);

	scheduler(p_PID,p_MEM,p_STA,p_PRI,p_TIC, opt);
	optn = opt ;
	BCP(bcp_Table, p_PID,p_MEM,p_STA,p_PRI,p_TIC);
	
	printf("\n_______________________________BEGIN BCP Selected _______________________________\n");	
	printBCP(bcp_Table);
	printf("\n_______________________________END BCP Selected_______________________________\n");
	
	system("Pause");
	
	//call func load Bar
	loadBar(p_PID, p_MEM);

    system("Pause");
    return(0);
}
