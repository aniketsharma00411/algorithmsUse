#include "list.h"
using namespace std;

void List::initialize() {
    last = -1;
    }

bool List::isEmpty() {
    return last==-1 ;
    }

bool List::isFull() {
    return last==499;
    }

void List::insertData(const int& p, const int& e) {
    if(p < -1 or p>last) {
        throw ListException("Position invalid to insert");

        }
    int i = last + 1;
    while(i>p) {
        data[i]=data[i-1];

        i--;
        }
    data[p + 1]= e;
    last++;
    }

void List::deleteData(const int&p) {
    if(p<0 or p>last) {
        throw ListException("Position invalid to delete");
        return;
        }
    int i=p;
    while(i<last) {
        data[i]=data[i+1];
        i++;
        }
    last--;

    }

int List::getFirstPos() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }

int List::getLastPos() {
    return last;

    }

int List::getPrev(const int&p) {
    if(isEmpty()or p<1 or p>last) {
        return -1;
        }
    return p;

    }

int List::getNext(const int&p) {
    if(isEmpty()or p<0 or p>last) {
        return -1;
        }
    return p+1;

    }

int List::findData(const int& e) { ///Lineal Search
    int i=0;
    int j=last;
    int medio;
    while (i<=j) {
        medio=(i+j)/2;

        if(data[medio]== e) {
            return medio;
            }
        if(e<data[medio]) {
            j=medio - 1;
            }
        else {
            i=medio+1;
            }
        }
    return -1;
    }

int List::retrieve(const int&p) {
    if(isEmpty()or p<0 or p>last) {
        throw ListException("Non-existent element");
        }
    return data[p];

    }
void List::exchange(int&a, int&b) {
    int aux(a);
    a=b;
    b=aux;

    }

void List::sortData() {
    int i = 1,j,menor;
    while(i<last) {
        menor = i;

        j=i+1;
        while(j<=last) {
            if(data[j]<data[menor]) {
                menor=j;
                }
            j++;
            }
        if(menor!=i) {
            exchange(data[i],data[menor]);
            }

        i++;
        }
    }

void List::print() {
    int i=0;
    while(i<=last) {
        std::cout << data[i]<<std::endl;
        i++;
        }

    }

void List::deleteAll() {
    last = -1;
    }
void List::writeToDisk(std::string fileName) {
    std::ofstream myFile;

    myFile.open(fileName,myFile.trunc); ///ios_base::trunc
    if(myFile.is_open()) {
        throw ListException("Could not open the file");
        }

    int i=0;
    while(i<=last) {
        myFile<< data[i++]<<std::endl;
        }
    myFile.clear();

    }
void List::sortDataMerge() {
sortDataMerge(0,last);
}
void List::quickSort(int leftEdge, int rightEdge)
{
    if(leftEdge<=rightEdge){
        return;
    }

    int i=leftEdge, j=rightEdge;
    while(i<j){
        while(i<j and data[i]<= data[rightEdge]){
            i++;
        }
        while(i<j and data[j]>=data[rightEdge]){
            j--;
        }
        if(i!=j){
            exchange(data[i],data[j]);
        }
    }
    if(i!=rightEdge){
        exchange(data[i],data[rightEdge]);
    }
    quickSort(leftEdge,i);
    quickSort(i+1,rightEdge);
}

void List::quickSort()
{
    quickSort(0,last);
}




void List::sortDataMerge(int leftEdge, int rightEdge) {
    if(leftEdge>=rightEdge) {
        return;
        }

    int mid=(leftEdge+rightEdge)/2;

    sortDataMerge(leftEdge,mid);
    sortDataMerge(mid+1,rightEdge);

    static int temp[500];///Tipo T, static siempre el mismo
    for(int i=leftEdge; i<=rightEdge; i++) {

        temp[i]=data[i];
        }
    int i=leftEdge, j=mid+1, x=leftEdge;

    while(i<= mid and j<=rightEdge) {
        while(i<=mid and temp[i]<=temp[j]) {
            data[x++]=temp[i++];
            }
        if(i<= mid) {
            while(j<=rightEdge and temp[j]<= temp[i]) {
                data[x++]=temp[j++];
                }
            }
        }
    while(i<=mid) {
        data[x++]=temp[i++];
        }
    while(j<=rightEdge) {
        data[x++]=temp[j++];
        }

    }

void List::readFromDisk(std::string) {

    }
