#include<math.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<cfloat>
double energy_compu(int s1,int s2,const int L,int** S){
	/*
	s1:=índice fila
	s2:=índice columna
	*/
	double Ei=0;
	int up,down,left,right;
	if(s1==0){up=S[L-1][s2];} else{up=S[s1-1][s2];}
	if(s1==L-1){down=S[0][s2];} else{down=S[s1+1][s2];}
	if(s2==0){left=S[s1][L-1];} else{left=S[s1][s2-1];}
	if(s2==L-1){right=S[s1][0];} else{right=S[s1][s2+1];}
	Ei=(double)2*S[s1][s2]*(up+down+right+left);
	return Ei;
}
int main(int argc,char **argv){
	//L,T,A
	if(argc!=4){
		printf("Error: los parámetros de entrada son el tamaño del sistema -L-, la temperatura -T- y el exponente de Np, -A-.\n");
		exit(0);
	}
	int L,NP;
	L=(int)atoi(argv[1]);
	int A=8;
	A=(int)atoi(argv[3]);
	NP=(long)pow(10,A);
	double T=2.27;
	T=(double)atof(argv[2]);
	FILE *fichero;
	//Definimos matriz LxL
	int **S; //Matriz sistema
	S=(int **)malloc(L*sizeof(int *));
	for(int k=0;k<L;k++){
		S[k]=(int *)malloc(L*sizeof(int));
	}
	double E1,W,u; //variables energía estado 1, 2 y factor de Boltzmann W
	int s1,s2; //
	char name[100];
	//INICIALIZAMOS EL SISTEMA///
	srand(2);
		for(int k1=0;k1<L;k1++){
			for(int k2=0;k2<L;k2++){
				u=(double)rand()/(RAND_MAX+1.0);
				if(u<=0.5){S[k1][k2]=1;}
				else{S[k1][k2]=-1;}
			}
		}
		for(long p=0;p<=NP;p++){//bucle número de pasos
			//candidato a ser volteado
			s1=rand()%(L-1+1);
			s2=rand()%(L-1+1);
			E1=energy_compu(s1,s2,L,S);
			W=exp(-(1/T)*E1);
			u=(double)rand()/(RAND_MAX+1.0);
			if((u<W)||(E1<0)){S[s1][s2]=-S[s1][s2]; }
		}//fin bucle número de pasos
		sprintf(name,"sistema_final_Np1e%i_T%0.1f_L%i",A,T,L);
		fichero=fopen(name,"wb");
		for(int k1=0;k1<L;k1++){//Columnas
			for(int k2=0;k2<L;k2++){//filas
				if(k2==L-1){fprintf(fichero," %i\n",S[k1][k2]);}
				else{fprintf(fichero," %i\t",S[k1][k2]);}
					}
			}
		fclose(fichero);
	///Liberamos memoria
	for(int k=0;k<L;k++){
		free(S[k]);
	}
	free(S);
	return 0;
}
