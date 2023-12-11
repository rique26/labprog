#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pgm{
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *mat_original, *mat_suavizada, *mat_scm;
    
};

void readPGMImage(struct pgm *, char *);
void writePGMImage(struct pgm *pio, char *filename);
void filtro(struct pgm *pio, int tamJanela);
void viewPGMImage(struct pgm *pio);
void matrizSCM(struct pgm *pio, char *filename);
void quantizacao(struct pgm *pio);


int nivel = 256;

int main(){
    time_t start_time = time(NULL);

    char nome[] = "img01_ORIGINAL.pgm";
    char nome2[] = "img01_SUAVIZADA.pgm";
    char nome3[] = "img01_scm.txt";

	struct pgm img;
    int tamJanela = 3;
    
    
    readPGMImage(&img, nome);
    filtro(&img, tamJanela);
    writePGMImage(&img,nome2);
    printf("\n\n\nmatorig: %hhu\nmatsuav: %hhu\n\n\n",img.mat_original[0], img.mat_suavizada[0]);
    quantizacao(&img);
    matrizSCM(&img, nome3);
   
    printf("\n\n\nokokokok\n\n\n");
    printf("matorig: %hhu\nmatsuav: %hhu\nmatscm: %hhu",img.mat_original[0], img.mat_suavizada[0],img.mat_scm[0]);
    
    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    printf("\n\nTempo decorrido: %.2f segundos\n", elapsed_time);
}       


void readPGMImage(struct pgm *pio, char *filename){

	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"r"))){
		perror("Erro.");
		exit(1);
	}

	if ( (ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

	while((ch=getc(fp))=='#'){
		while( (ch=getc(fp))!='\n');
	}

	fseek(fp,-2, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);
	if (ferror(fp)){ 
		perror(NULL);
		exit(3);
	}	
	
	fscanf(fp, "%d",&pio->mv);
	fseek(fp,1, SEEK_CUR);

	pio->mat_original = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));
    
	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->mat_original+k);
			}
            printf("\nok\n");
		break;	
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->mat_original,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);
    
}

void writePGMImage(struct pgm *pio, char *filename){
    FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

	fwrite(pio->mat_suavizada, sizeof(unsigned char),pio->c * pio->r, fp);

	fclose(fp);

}

void filtro(struct pgm *pio, int tamJanela){

    int **result, **matCopia, soma=0, zerosAdic, acresc;
    
    switch (tamJanela)
    {
    case 3:
        zerosAdic = 2;
        acresc = 0;
        break;
    case 5:
        zerosAdic = 4;
        acresc = 1;
        break;
    case 7: 
        zerosAdic = 6;
        acresc = 2;
        break;
    case 9:
        zerosAdic = 8;
        acresc = 3;
        break;
    }

    //alocacao das matrizes
    matCopia = calloc(pio->r+zerosAdic, sizeof(int*));     
    for(int i=0; i<pio->r+zerosAdic; i++) matCopia[i] = calloc(pio->c+zerosAdic, sizeof(int));

    pio->mat_suavizada = (unsigned char*) calloc(pio->r * pio->c, sizeof(unsigned char));

    //soma matCopia + MatOrig
    int j=0;
    for(int i=1;i<=pio->r; i++)
        for(int k=1; k<=pio->c; k++){
            *(*(matCopia+i+acresc)+k+acresc) += *(pio->mat_original+j);
            j++; 
        }


    //filtro
    int a=0;
    for(int i=1; i<=pio->r; i++){
        for(int k=1; k<=pio->c; k++){
            soma = 0;
            for(int x=-1; x<=tamJanela-2; x++){
                for(int y=-1; y<=tamJanela-2; y++)
                    soma += *(*(matCopia+i+x)+k+y);
            }
            *(pio->mat_suavizada+a++) = soma/(tamJanela*tamJanela);
        }
    } 
    for (int i = 0; i < pio->r + zerosAdic; i++) free(matCopia[i]);
    free(matCopia);
}

void viewPGMImage(struct pgm *pio){
	printf("Tipo: %d\n",pio->tipo);
	printf("Dimensões: [%d %d]\n",pio->c, pio->r);
	printf("Max: %d\n",pio->mv);

	for (int k=0; k < (pio->r * pio->c); k++){
		if (!( k % pio->c)) printf("\n");
		printf("%2hhu ",*(pio->mat_original+k));
	}	
	printf("\n");
}

void matrizSCM(struct pgm *pio, char *filename){
    
    int cont, a=0, b=0;
    int c=0;//==j
    
    pio-> mat_scm = (unsigned char*) calloc(nivel * nivel, sizeof(unsigned char));
    
    for(int i=0; i<nivel; i++){
        while(c!=nivel){
            cont=1;
            for (int k=0; k < (pio->r * pio->c); k++){
                if((*(pio->mat_original+k) == a) && (*(pio->mat_suavizada+k) == c))
                    *(pio->mat_scm+b) = cont++;
            }
            b+=1;
            c+=1;;
        }
        a+=1; 
        c=0;
    }

    FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"w"))){
		perror("Erro.");
		exit(1);
	}
    
    for (int i = 0; i < 8 * 8; i++) 
        fprintf(fp, "%d, ", pio->mat_scm[i]);
    
	fclose(fp);

}

void quantizacao(struct pgm *pio){
    int intervalo = 256/nivel;
    int subintervalo, intensidade;
    int valorQuantizado;

    for (int k=0; k < (pio->r * pio->c); k++){
        intensidade = *(pio->mat_original+k);
        subintervalo = intensidade/intervalo;
        valorQuantizado = (subintervalo * intervalo) + intervalo / 2;
        *(pio->mat_original+k)  = valorQuantizado;

    }

    for (int k=0; k < (pio->r * pio->c); k++){
        intensidade = *(pio->mat_suavizada+k);
        subintervalo = intensidade/intervalo;
        valorQuantizado = (subintervalo * intervalo) + intervalo / 2;
        *(pio->mat_suavizada+k) = valorQuantizado;  
    }
}
