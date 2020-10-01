#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<exception>
#include<iostream>
#include<fstream>

class ListException : public std::exception
{
public:
    explicit ListException(const char* message) : msg(message) {}
    explicit ListException(const std::string& message) : msg(message) {}
    virtual ~ListException() throw() {}
    virtual const char* what() const throw()
    {
        return msg.c_str();
    }

private:
    std::string msg;


};
class List
{
private:
    int data[500];
    int last;
    void exchange(int&, int&);
    void sortDataMerge(int, int);
    void quickSort(int,int);


public:
    void initialize();

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const int&);
    void deleteData(const int&);
    int getFirstPos();
    int getLastPos();
    int getPrev(const int&);
    int getNext(const int&);
    int findData(const int&);

    void sortDataMerge();
    void quickSort();

    int retrieve(const int&);

    void sortData();
    void print();

    void deleteAll();

    void writeToDisk(std::string);
    void readFromDisk(std::string);

};

#endif // LIST_H_INCLUDED
