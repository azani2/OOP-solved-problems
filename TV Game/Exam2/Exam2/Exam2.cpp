#include "Person.h"
#include "TVGame.h"
#include "CoupleGame.h"
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)

int main()
{
    char* name1 = new char[5];
    strcpy(name1, "lala\0");
    char* name2 = new char[5];
    strcpy(name2, "bobo\0");
    char* name3 = new char[5];
    strcpy(name3, "sisi\0");
    char* name4 = new char[5];
    strcpy(name4, "lolo\0");
    char* name5 = new char[5];
    strcpy(name5, "pipi\0");
    char* name6 = new char[5];
    strcpy(name6, "jojo\0");
    char* name7 = new char[6];
    strcpy(name7, "ivan\0");

    Person w1(name1, 25, "some stuff\0", 3);
    Person m1(name2, 25, "some more stuff\0", 2);
    Person w2(name3, 25, "some other stuff\0", 1);
    Person m2(name4, 25, "some better stuff\0", 7);
    Person w3(name5, 25, "some different stuff\0", 5);
    Person m3(name6, 25, "some boring stuff\0", 4);
    Person host(name7, 30, "host of TV Shows\0", 3);

    std::vector<Person> people;
    people.push_back(w1);
    people.push_back(m1);
    people.push_back(w2);
    people.push_back(m2);
    people.push_back(w3);
    people.push_back(m3);

    CoupleGame game1(people, &host, nullptr);
    
    game1.printFormatInformation();
    game1.doEvent();
    game1.showEvents(5);
    game1.doEvent();
    game1.showEvents(5);
    game1.doEvent();
    game1.showEvents(5);

}