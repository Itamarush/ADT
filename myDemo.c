// demo program by Itamar Guetta

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{

    pbook b1 = creat_book("Itamar's book", 11111);
    pbook b2 = creat_book("Guetta's book", 22222);
    PAdptArray mybooks = CreateAdptArray(copy_book, delete_book, print_book);
    SetAdptArrayAt(mybooks, 3, b1);
    SetAdptArrayAt(mybooks, 9, b2);
    printf("the size is %d\n", GetAdptArraySize(mybooks)); // should print 10
    pbook b3 = GetAdptArrayAt(mybooks, 4);                 // should return null;
    pbook b4 = GetAdptArrayAt(mybooks, 3);                 // should return null;
    assert(b3 == NULL);                                    // doesn't fail
    b3 = GetAdptArrayAt(mybooks, 9);
    printf("the book is %s\n", b3->name); // should print "Guetta book"
    printf("the book is %s\n", b4->name); // should print "itamars book"
    PrintDB(mybooks);

    pperson p1 = creat_person("Itamar", "Guetta", 934);
    pperson p2 = creat_person("Evgeny", "Neiterman", 789);
    PAdptArray personArray = CreateAdptArray(copy_person, delete_person, print_person);
    SetAdptArrayAt(personArray, 2, p1);
    SetAdptArrayAt(personArray, 30, p2);
    printf("\nthe size is %d\n", GetAdptArraySize(personArray));
    PrintDB(personArray);                                       
    DeleteAdptArray(mybooks);
    DeleteAdptArray(personArray);
    delete_book(b1);
    delete_book(b2);
    delete_book(b3);
    delete_book(b4);
    delete_person(p1);
    delete_person(p2);
    return 0;
}
