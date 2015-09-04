//
//  main.cpp
//  Tarea_02_Algoritmos
//
//  Created by Alejandro Terrazas on 02/09/15.
//  Copyright (c) 2015 Alejandro Terrazas. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

//---------Declaraciones-------//

//--------------- Declaraciones de funcones para manejar el arreglo ----------//
//Llenar arreglo desde el .txt
void llenarArreglo(int arreglo[], int N);
//Imprimir el arreglo
void imprimirArreglo(int arreglo[]);


//--------------- Declaraciones de los algoritmos de ordenamiento ----------//
//Bubble
void bubbleSort( int v[], int N);
//Cocktail
void cocktailSort(int v[], int N);
//Insertion
void insertionSort(int v[], int N);
//Bucket
void bucketSort(int v[], const int N);
//Merge
void merge(int v[], int l, int m, int n, int N);
void mergeSort(int v[], int l, int n, int N);
//BinarySort
void binarySort(int v[], int N);
//Radix
int getMax(int v[], int N);
void countSort(int v[], int N, int exp);
void radixSort(int v[], int N);
//Shell
void shellSort(int v[], int N);
//Selection
void selectionSort(int v[], int N);
//Quick
void quickSort(int v[], int primero, int ultimo);
//Counting
void findMinMax(int v[], int N, int& mi, int& max);
void countingSort( int v[], int N);
//Heap
void shift_down(int heap[],int i, int max);
void to_heap(int arr[], int N);
void heap_sort(int arr[], int N);


//--------------------------------------- MAIN --------------------------//
int main(int argc, const char * argv[]) {
    
    const int N = 100000;
    //srand((int) time(NULL));
    int arreglo[N];
    
    llenarArreglo(arreglo, N);
    auto begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arreglo, N);
    auto end = std::chrono::high_resolution_clock::now();
    auto bubble = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Bubble: "<<bubble.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    cocktailSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto cocktail = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Cocktail: "<<cocktail.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto insertion = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Insertion: "<<insertion.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    bucketSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto bucket = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Bucket: "<<bucket.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    countingSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto counting = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Counting: "<<counting.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arreglo, 0, N-1, N);
    end = std::chrono::high_resolution_clock::now();
    auto merge = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Merge: "<<merge.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    binarySort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto binary = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"BinaryTree: "<<binary.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    radixSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto radix = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Radix: "<<radix.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto shell = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Shell: "<<shell.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto selection = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Selection: "<<selection.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arreglo, 0, N-1);
    end = std::chrono::high_resolution_clock::now();
    auto quick = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Quick: "<<quick.count()<<std::endl;
    
    llenarArreglo(arreglo, N);
    begin = std::chrono::high_resolution_clock::now();
    heap_sort(arreglo, N);
    end = std::chrono::high_resolution_clock::now();
    auto heap = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Heap: "<<heap.count()<<std::endl;
    
}

//--------Implementaciones-------//

//------------------- Funciones que llenan e imprimen el arreglo --------------//
//Llenar arreglo
void llenarArreglo(int arreglo[], int N)
{
    std::ifstream file("/Users/Alex/arreglo100000.txt");
    if(file.is_open())
    {
        for(int i = 0; i < N; ++i)
        {
            file >> arreglo[i];
        }
    }
}

//Imprimir arreglo
void imprimirArreglo(int arreglo[])
{
    for (int i = 0; i < 10; ++i)
    {
        cout<< arreglo[i]<<" ";
    }
    cout << endl;
    
}



//--------------- Algorintmos de ordenamiento ------------//
//Bubble
void bubbleSort( int v[], int N)
{
    int temp;
    
    for (int i = 0; i < N; i++){
        for(int j= N-1; j>i; j--){
            if (v[j-1] > v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}

//Cocktail
void cocktailSort(int v[], int N)
{
    int lo = 0, hi = (N-1), mov = lo, temp;
    
    while (lo<hi){
        for(int i=hi; i>lo; --i){
            if(v[i-1]>v[i]){
                temp = v[i-1];
                v[i-1]=v[i];
                v[i]= temp;
                mov=i;
            }
        }
        
        lo = mov;
        
        for(int i=lo; i<hi; ++i){
            if(v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1]= temp;
                mov = i;
            }
        }
        hi=mov;
    }
}

//Insertion
void insertionSort(int v[], int N)
{
    int index;
    for (int i=1; i < N; i++)
    {
        index = v[i];
        
        int j = i-1;
        
        while (j >= 0 && v[j] > index)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = index;
    }
}

//Bucket
void bucketSort(int v[], const int N)
{
    int m = 10001;
    int buckets[m];
    
    for(int i=0; i< m; ++i)
    {
        buckets[i]=0;
    }
    
    for (int i = 0; i < N; ++i)
    {
        ++buckets[v[i]];
    }
    
    for (int i =0, j = 0; j < m; ++j)
    {
        for (int k = buckets[j]; k > 0; --k)
        {
            v[i++] = j;
        }
    }
}

//Merge
void merge(int v[], int l, int m, int n, int N)
{
    int i, j, k;
    int aux[N];
    
    for(i=m+1;i>l;--i)
        aux[i-1] = v[i-1];
    
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    
    for(k=l;k<=n;k++)
        if (!(aux[i]> aux[j]))
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}
void mergeSort(int v[], int l, int n, int N)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergeSort (v, l, m, N);
        mergeSort (v, m+1, n, N);
        merge (v, l, m, n, N);
    }
}

//BinaryTree
struct Node
{
    int val;
    Node* left;
    Node* right;
    
    Node(int n) {
        val = n;
        left = right = nullptr;
    }
    
    static void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};
void insert(Node*& node, int val)
{
    if (!node)
        node = new Node(val);
    else if (val < node->val)
        insert(node->left, val);
    else
        insert(node->right, val);
}
void inOrder(Node* node, vector<int>& a)
{
    if (node)
    {
        inOrder(node->left, a);
        a.push_back(node->val);
        inOrder(node->right, a);
    }
}
void binarySort(int v[], int N)
{
    Node* root = nullptr;
    for (int i = 0; i < N; ++i)
        insert(root, v[i]);
    
    vector<int> aux;
    inOrder(root, aux);
    
    Node::destroy(root);
    
    for (int i = 0; i < aux.size(); ++i)
        v[i] = aux[i];
}

//Radix
int getMax(int v[], int N)
{
    int max = v[0];
    for(int i=1; i<N; i++)
    {
        if(v[i]>max)
        {
            max = v[i];
        }
    }
    
    return max;
}
void countSort(int v[], int N, int exp)
{
    int output[N];
    int count[10] = {0};
    
    
    for(int i=0; i<N; i++)
    {
        count[(v[i]/exp)%10]++;
    }
    
    for(int i=1; i<10;i++)
    {
        count[i]+=count[i-1];
    }
    
    for (int i = N-1; i>=0; i--)
    {
        
        output[count[( v[i]/exp ) %10 ] -1] = v[i];
        count[(v[i]/exp)%10]--;
    }
    
    for(int i=0;i<N; i++)
    {
        v[i]=output[i];
    }
}
void radixSort(int v[], int N)
{
    int m = getMax(v, N);
    for(int exp = 1; m/exp>0; exp*=10){
        countSort(v, N, exp);
    }
}

//Shell
void shellSort(int v[], int N)
{
    int temp;
    
    for(int gap= N/2; gap>0; gap/=2){
        for(int i=gap; i<N; i++){
            for(int j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j]= v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

//Selection
void selectionSort(int v[], int N)
{
    int minimo = 0;
    int temp;
    
    for(int i = 0; i < N-1; i++){
        minimo = i;
        for(int j = i + 1; j < N; j++){
            if (v[minimo] > v[j])
                minimo = j;
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

//Quick
void quickSort(int v[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    
    //Se selecciona pivote
    int pivote = v[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && !(v[izquierdo] > pivote)) izquierdo++; // <=
            while (v[derecho]> pivote ) derecho--; // >
            
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = v[derecho];
                v[derecho] = v[izquierdo];
                v[izquierdo] = temp;
            }
        }
        
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = v[derecho];
        v[derecho] = v[primero];
        v[primero] = temp;
        
        // Paso recursivo
        quickSort ( v, primero, derecho-1);
        quickSort ( v, izquierdo, ultimo);
    }
}

//Counting
void findMinMax(int v[], int N, int& mi, int& max)
{
    mi = 100;
    max = 0;
    
    for( int i = 0; i < N; i++ ){
        if( v[i] > max ) max = v[i];
        if( v[i] < mi ) mi = v[i];
    }
    
}
void countingSort( int v[], int N)
{
    int mi, max;
    int z=0;
    findMinMax(v, N, mi, max);
    int nlen = (max-mi)+1;
    int* temp = new int[nlen];
    memset(temp, 0, nlen * sizeof( int ));
    
    for( int i = 0; i < N; i++ ){
        temp[v[i] - mi]++;
    }
    
    for( int i = mi; i <= max; i++ ){
        while( temp[i - mi] )
        {
            v[z++] = i;
            temp[i - mi]--;
        }
    }
    
    
    delete [] temp;
}

//Heap
void shift_down(int heap[],int i, int max)
{
    int i_big, c1, c2;
    while(i < max) {
        i_big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( c1<max && heap[c1]>heap[i_big] )
            i_big = c1;
        if( c2<max && heap[c2]>heap[i_big] )
            i_big = c2;
        if(i_big == i) return;
        swap(heap[i],heap[i_big]);
        i = i_big;
    }
}
void to_heap(int arr[], int N)
{
    int i = (N/2) - 1;
    while(i >= 0) {
        shift_down(arr, i, N);
        --i;
    }
}
void heap_sort(int arr[], int N)
{
    to_heap(arr, N);
    int end = N - 1;
    while (end > 0) {
        swap(arr[0], arr[end]);
        shift_down(arr, 0, end);
        --end;
    }
}








