//Nome: Mateus Henrique Gonçalves
//Turma: SI201
//Algoritmo e Estrutura de Dados II

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <string.h>
#define maxtam 100000

using namespace std;

void BubbleSort(int *vet, int tamanho, double *trocas){
	int memoria, troca, i, j;
	troca=1; 
	for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0; 
		for(i=0; i<j; i++){
			if(vet[i]>vet[i+1]){
				memoria=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=memoria;
				troca=1; 
        *trocas = *trocas+1;
			}
		}
	}
}

void ShellSort(int *vet, int size, double *trocas){
  int i, j, value;
 
  int h = 1;
  while(h < size) {
    h = 3*h+1;
  }
    
  while (h > 0) {
    for(i = h; i < size; i++) {
      value = vet[i];
      j = i;
      while (j > h-1 && value <= vet[j - h]) {
        vet[j] = vet[j - h];
        j = j - h;
        *trocas = *trocas +1;
      }
      vet[j] = value;
    }
    h = h/3;
  }
    
}

void SelectionSort(int *v, int n, double *trocas){
  int i, j, k, aux, troca;
    
  for(i = 0; i<n-1; i++){
    troca = 0;
    k = i;
    aux = v[i];
    for(j = i+1; j<n; j++){
      if(v[j] < aux){
        k = j;
        aux = v[j];
        troca = 1;
      }
    }
    if(troca){
      v[k] = v[i];
      v[i] = aux;
      *trocas = *trocas+1;
    }  
  }
}

void InsertionSort(int *arr, int n, double *trocas){
  int i, key, j;
  for (i = 1; i < n; i++){
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
      *trocas = *trocas+1;
    }
    arr[j + 1] = key;
    }
}

void QuickSort(int *a, int left, int right, double *trocas){
  int i, j, x, y;
     
  i = left;
  j = right;
  x = a[(left + right) / 2];
     
  while(i <= j) {
    while(a[i] < x && i < right) {
      i++;
    }
    while(a[j] > x && j > left) {
      j--;
    }
    if(i <= j) {
      y = a[i];
      a[i] = a[j];
      a[j] = y;
      i++;
      j--;
    }
  }
     
  if(j > left) {
    QuickSort(a, left, j, trocas);
    *trocas = *trocas+1;
  }
  if(i < right) {
    QuickSort(a, i, right, trocas);
    *trocas = *trocas+1;
  }

}

void MergeSort(int *v, int n, double *trocas);
void Merge(int *v, int *c, int i, int m, int f, double *trocas);
void Sort(int *v, int *c, int i, int f, double *trocas);


void escolherlista(int opcao){
  cout << "\n";
  cout << "\n::Instancias::\n"; 
  cout << "1 - ListaAleatoria-1000.txt\n"; 
  cout << "2 - ListaAleatoria-10000.txt\n"; 
  cout << "3 - ListaAleatoria-100000.txt\n"; 
  cout << "4 - ListaInversamenteOrdenada-1000.txt\n"; 
  cout << "5 - ListaInversamenteOrdenada-10000.txt\n"; 
  cout << "6 - ListaInversamenteOrdenada-100000.txt\n"; 
  cout << "7 - ListaOrdenada-1000.txt\n"; 
  cout << "8 - ListaOrdenada-10000.txt\n"; 
  cout << "9 - ListaOrdenada-100000.txt\n"; 
  cout << "10 - ListaQuaseOrdenada-1000.txt\n"; 
  cout << "11 - ListaQuaseOrdenada-10000.txt\n"; 
  cout << "12 - ListaQuaseOrdenada-100000.txt\n";
}

int main(){
  double trocas;
  int verif=0;
  time_t t, tfim;
  int vetor[maxtam];
  int opcao, i=0, tamanho=0;
  char lista[40];
  char linha[10];
  string num;
  char nomearq[40];
  FILE *arqLista;
  char L1[40] = "ListaAleatoria-1000.txt";
  char L2[40] = "ListaAleatoria-10000.txt";
  char L3[40] = "ListaAleatoria-100000.txt";
  char L4[40] = "ListaInversamenteOrdenada-1000.txt";
  char L5[40] = "ListaInversamenteOrdenada-10000.txt";
  char L6[40] = "ListaInversamenteOrdenada-100000.txt";
  char L7[40] = "ListaOrdenada-1000.txt";
  char L8[40] = "ListaOrdenada-10000.txt";
  char L9[40] = "ListaOrdenada-100000.txt";
  char L10[40] = "ListaQuaseOrdenada-1000.txt";
  char L11[40] = "ListaQuaseOrdenada-10000.txt";
  char L12[40] = "ListaQuaseOrdenada-100000.txt";
  char metodo[20];
  char listauti[40];

  strcpy(listauti, "ListaOrdenada-1000");

  cout << "\n";
  cout << "::Algoritmos de Ordenaçao::\n";
  cout << "1 - BubbleSort\n";
  cout << "2 - ShellSort\n";
  cout << "3 - SelectionSort\n";
  cout << "4 - InsertionSort\n";
  cout << "5 - QuickSort\n";
  cout << "6 - MergeSort\n";
  cout << "Metodo que irá utilizar: ";
  scanf("%d", &opcao);

  if(opcao == 1){
    strcpy(metodo, "BubbleSort");
    cout << "\n";
    cout << "Metodo escolhido -> BubbleSort\n";
    cout << "Complexidade -> ";
    cout << "Pior caso e caso medio = O(n²) | Melhor caso = O(n)";
    cout << "\n";

    escolherlista(opcao);
    cout << "Lista que irá utilizar: ";
    cin >> lista;
    t = time(NULL);
    if((strcmp(lista, "1")==0)){
      strcpy(listauti, "ListaAleatoria-1000");
      strcpy(nomearq,L1);
      arqLista = fopen(nomearq, "r");
          
      while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
        vetor[i] = atoi(linha);
        i++;
        tamanho++;
      }
      BubbleSort(vetor, tamanho, &trocas);

      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);

        for(i=0;i<tamanho;i++){
          cout << vetor[i] << " ";        
        }
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);

      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);

        for(i=0;i<tamanho;i++){
          cout << vetor[i] << " ";       
        } 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);

        for(i=0;i<tamanho;i++){
          cout << vetor[i] << " ";       
        } 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        BubbleSort(vetor, tamanho, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }

    }else if(opcao == 2){
      strcpy(metodo, "ShellSort");
      cout << "\n";
      cout << "Metodo escolhido -> ShellSort\n";
      cout << "Complexidade -> ";
      cout << "Pior caso e melhor caso = O(n log2 n) | Caso medio = depende da sequencia";
      cout << "\n";

      escolherlista(opcao);
      cout << "Lista que irá utilizar: ";
      cin >> lista;
      t = time(NULL);
      if((strcmp(lista, "1")==0)){
        strcpy(listauti, "ListaAleatoria-1000");
        strcpy(nomearq,L1);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
  
      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        ShellSort(vetor, tamanho, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }

    }else if(opcao == 3){
      strcpy(metodo, "SelectionSort");
      cout << "\n";
      cout << "Metodo escolhido -> SelectionSort\n";
      cout << "Complexidade -> ";
      cout << "Todos os casos = O(n²)";
      cout << "\n";

      escolherlista(opcao);
      cout << "Lista que irá utilizar: ";
      cin >> lista;
      t = time(NULL);
      if((strcmp(lista, "1")==0)){
        strcpy(listauti, "ListaAleatoria-1000");
        strcpy(nomearq,L1);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
  
      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        SelectionSort(vetor, tamanho, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }
    }else if(opcao == 4){
      strcpy(metodo, "'InsertionSort");
      cout << "\n";
      cout << "Metodo escolhido -> InsertionSort\n";
      cout << "Complexidade -> ";
      cout << "Pior caso e caso medio = O(n²) | Melhor caso = O(n)";
      cout << "\n";
      t = time(NULL);
      escolherlista(opcao);
      cout << "Lista que irá utilizar: ";
      cin >> lista;

      if((strcmp(lista, "1")==0)){
        strcpy(listauti, "ListaAleatoria-1000");
        strcpy(nomearq,L1);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
  
      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        InsertionSort(vetor, tamanho, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }

    }else if(opcao == 5){
      strcpy(metodo, "QuickSort");
      cout << "\n";
      cout << "Metodo escolhido -> QuickSort\n";
      cout << "Complexidade -> ";
      cout << "Pior caso = O(n²) | Caso medio e melhor caso = O(n log n)";
      cout << "\n";
      t = time(NULL);
      escolherlista(opcao);
      cout << "Lista que irá utilizar: ";
      cin >> lista;

      if((strcmp(lista, "1")==0)){
        strcpy(listauti, "ListaAleatoria-1000");
        strcpy(nomearq,L1);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
  
      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        QuickSort(vetor, 0, tamanho-1, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }
    }else if(opcao == 6){
      strcpy(metodo, "MergeSort");
      cout << "\n";
      cout << "Metodo escolhido -> MergeSort\n";
      cout << "Complexidade -> ";
      cout << "Todos os casos = O(n log n)";
      cout << "\n";

      escolherlista(opcao);
      cout << "Lista que irá utilizar: ";
      cin >> lista;
      t = time(NULL);
      if((strcmp(lista, "1")==0)){
        strcpy(listauti, "ListaAleatoria-1000");
        strcpy(nomearq,L1);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "2")==0)){
        strcpy(listauti, "ListaAleatoria-10000");
        strcpy(nomearq,L2);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "3")==0)){
        strcpy(listauti, "ListaAleatoria-100000");
        strcpy(nomearq,L3);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "4")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-1000");
        strcpy(nomearq,L4);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "5")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-10000");
        strcpy(nomearq,L5);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "6")==0)){
        strcpy(listauti, "ListaInversamenteOrdenada-100000");
        strcpy(nomearq,L6);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "7")==0)){
        strcpy(listauti, "ListaOrdenada-1000");
        strcpy(nomearq,L7);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
  
      }else if((strcmp(lista, "8")==0)){
        strcpy(listauti, "ListaOrdenada-10000");
        strcpy(nomearq,L8);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "9")==0)){
        strcpy(listauti, "ListaOrdenada-100000");
        strcpy(nomearq,L9);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "10")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-1000");
        strcpy(nomearq,L10);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "11")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-10000");
        strcpy(nomearq,L11);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else if((strcmp(lista, "12")==0)){
        strcpy(listauti, "ListaQuaseOrdenada-100000");
        strcpy(nomearq,L12);
        arqLista = fopen(nomearq, "r");
        while((fgets(linha, sizeof(linha), arqLista))!=NULL ){
          vetor[i] = atoi(linha);
          i++;
          tamanho++;
        }
        MergeSort(vetor, tamanho, &trocas);
 
      }else{
        cout << "Lista inexistente";
        verif = 1;
      }
    }else if((opcao<1)||(opcao>6)){
      cout << "Metodo inexistente";
      verif = 1;
    }

  tfim = time(NULL);
  float tempo = (difftime(tfim, t));

  if(((opcao>0)||(opcao<7))&&(verif == 0)){
    FILE *arqSaida;
    arqSaida = fopen("Resultado.txt", "a");
    fprintf(arqSaida, "Algoritmo utilizado -> %s\n", metodo);
    fprintf(arqSaida, "Instancia utilizada -> %s\n", listauti);
    fprintf(arqSaida, "Tempo = %0.2f segundos | ", tempo);
    fprintf(arqSaida, "Trocas = %0.0lf\n", trocas);
    fprintf(arqSaida, "\n");
    fclose(arqSaida);
  }
  
}

void MergeSort(int *v, int n, double *trocas){
  int *c = (int*)calloc(n,sizeof(int));
  Sort(v, c, 0, n - 1, trocas);
  free(c);
}

void Merge(int *v, int *c, int i, int m, int f, double *trocas){
  int z, iv = i, ic = m + 1;

  for(z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m){
    v[z++] = c[iv++];
  }

  while (ic <= f){
    v[z++] = c[ic++];
  }
}

void Sort(int *v, int *c, int i, int f, double *trocas) {
  if (i >= f) return;

  int m = (i + f) / 2;

  Sort(v, c, i, m, trocas);
  Sort(v, c, m + 1, f, trocas);

  if (v[m] <= v[m + 1]) return;
  *trocas = *trocas+1;
  Merge(v, c, i, m, f, trocas);
}