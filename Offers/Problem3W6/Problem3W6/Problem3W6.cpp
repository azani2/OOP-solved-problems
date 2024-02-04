#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

struct Example {
    int data;
    char buff[8];

    Example() : data(0), buff{ "" } {};

    Example(int _data, const char* _buff) : data(_data), buff{ "" } {
        if (strlen(_buff) < 8)
            strcpy(buff, _buff);
    }

    void print() const {
        std::cout << "data: " << data << std::endl << buff << std::endl;
    }
};

size_t getFileSize(const char* fileName) {
    size_t size = 0;
    std::ifstream fin(fileName, std::ios::binary | std::ios::ate);
    size = fin.tellg();
    return size;
}

unsigned structsInFile(const char* fileName) {
    size_t fileSize = getFileSize(fileName);
    unsigned structsCount = fileSize / sizeof(Example);
    return structsCount;
}

//////////////////////////////////////////////////////////////////////////////////

struct ProjectOffer {
    char name[25];
    unsigned programmersCount;
    unsigned paidLeaveDaysCount;
    double reward;

    ProjectOffer() : name(""), programmersCount(0), paidLeaveDaysCount(0), reward(0) {};

    ProjectOffer(const char* _name, const unsigned _programmersCount, const unsigned _paidLeaveDaysCount, const double _reward) : name(""), programmersCount(_programmersCount), paidLeaveDaysCount(_paidLeaveDaysCount), reward(_reward) {
        if (strlen(_name) < 25)
            strcpy(name, _name);
    }

    void print() const {
        std::cout << name << " | " << programmersCount << " programmers in team | " << paidLeaveDaysCount << " days of paid leave | reward: " << reward << std::endl;
    }
};

ProjectOffer* readOffers(const size_t n) {
    ProjectOffer* offers = new ProjectOffer[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Offer name : ";
        std::cin >> offers[i].name;
        std::cout << "Number of programmers : ";
        std::cin >> offers[i].programmersCount; 
        std::cout << "Number of paid leave days : ";
        std::cin >> offers[i].paidLeaveDaysCount;
        std::cout << "Reward : ";
        std::cin >> offers[i].reward;
    }

    return offers;
}

unsigned offersInFile(const char* fileName) {
    size_t fileSize = getFileSize(fileName);
    unsigned structsCount = fileSize / sizeof(ProjectOffer);
    return structsCount;
}

bool readOffersFromFile(const char* fileName, size_t& offersCount, ProjectOffer*& offersRead) {
    size_t fileSize = getFileSize(fileName);
    offersCount = fileSize / sizeof(ProjectOffer);
    offersRead = new ProjectOffer[offersCount];
    std::ifstream fin(fileName, std::ios::binary | std::ios::in);
    if (!fin.is_open())
    {
        std::cout << "Error opening file for reading!\n";
        return 0;
    }
    fin.read((char*)offersRead, fileSize);
    return fin.good();
}

bool filterOffer(const char* filePath, size_t minSalary) {
    ProjectOffer* offersRead;
    size_t offersCount = 0;
    if (!readOffersFromFile(filePath, offersCount, offersRead))
    {
        std::cout << "Error reading offers from file!\n";
        return 0;
    }

    for (size_t i = 0; i < offersCount; i++)
    {
        if (offersRead[i].reward >= minSalary)
            offersRead[i].print();
    }

    delete[] offersRead;
    return 1;
}

bool findOffer(const char* filePath, const char* name) {
    ProjectOffer* offersRead;
    size_t offersCount = 0;
    if (!readOffersFromFile(filePath, offersCount, offersRead))
    {
        std::cout << "Error reading offers from file!\n";
        return 0;
    }

    bool offersFound = 0;
    for (size_t i = 0; i < offersCount; i++)
    {
        if (strcmp(offersRead[i].name, name) == 0)
        {
            offersRead[i].print();
            offersFound = 1;
        }
        
    }
    if (offersFound)
    {
        delete[] offersRead;
        return 1;
    }
    else
    {
        std::cout << "No offers from firm " << name << " were found.\n";
        delete[] offersRead;
        return 0;
    }
}

int main()
{
    {
        Example exArr[8]{ {0, ""}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"} };

        std::ofstream file("structsData.dat", std::ios::app | std::ios::binary | std::ios::_Nocreate);
        if (!file.is_open())
        {
            std::cout << "Error opening file for writing!\n";
            return -1;
        }

        file.write((const char*)&exArr, sizeof(exArr));
        std::cout << "File good: " << file.good() << std::endl;

        file.close();

        std::cout << structsInFile("structsData.dat") << " structures in file\n------------\n";
        //works//////////////////////////////////////////////////////////////////////////////////////////////////////
    }

    char testName[11] = "talkingCat";
    ProjectOffer test(testName, 3, 14, 1000);
    test.print();

    size_t n = 2;//!!!!

    ProjectOffer* offers = readOffers(n);

    for (size_t i = 0; i < n; i++)
        offers[i].print();

    std::ofstream fout("offersData.dat", std::ios::app | std::ios::binary);
    if (!fout.is_open())
    {
        std::cout << "Error opening file for writing!\n";
        return -1;
    }

    fout.write((const char*)offers, n * sizeof(ProjectOffer));

    std::cout << "good: " << fout.good() << std::endl;
    fout.close();
    std::cout << offersInFile("offersData.dat") << " offers in file" << std::endl;

    //k

    std::ifstream fin("offersData.dat", std::ios::binary | std::ios::in);
    if (!fin.is_open())
    {
        std::cout << "Error opening file for reading!\n";
        return -1;
    }

    ProjectOffer* offersRead;
    size_t offersCount = 0;

    std::cout << readOffersFromFile("offersData.dat", offersCount, offersRead) << std::endl;

    std::cout << "All offers read from file:\n";
    for (size_t i = 0; i < offersCount; i++)
        offersRead[i].print();

    size_t minReward = 1000;
    std::cout << "\nFiltered offers with reward above " << minReward << ":" << std::endl;
    filterOffer("offersData.dat", minReward);

    std::cout << "\nOffers from firm \"bleh\":\n";
    findOffer("offersData.dat", "bleh");

    delete[] offers;
    delete[] offersRead;
}
