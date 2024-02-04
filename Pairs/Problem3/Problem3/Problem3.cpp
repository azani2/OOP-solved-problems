#include <iostream>
#include <fstream>

struct Pair {
    unsigned x;
    unsigned y;
};

Pair createPair(unsigned xArg, unsigned yArg)
{
    Pair res;
    res.x = xArg;
    res.y = yArg;
    return res;
}

void initPair(Pair& toInit, unsigned xArg, unsigned yArg)
{
    toInit.x = xArg;
    toInit.y = yArg;
}

Pair readPairFromFile(std::ifstream& fin) {
    Pair res;

    if (!fin.is_open())
        throw std::exception("Error reading from file!");

    unsigned xArg, yArg;
    fin >> xArg >> yArg;

    res.x = xArg;
    res.y = yArg;
    return res;
}

int main()
{
    std::ofstream fout("pairsData.txt", std::ios::app);
    if (!fout.is_open())
    {
        std::cout << "Error opening file for writing!";
        return -1;
    }

    fout << 55 << " " << 77 << std::endl << 11 << " " << 22 << std::endl;
    fout.close();

    std::ifstream fin("pairsData.txt", std::ios::in);

    if (!fout.is_open())
    {
        std::cout << "Error opening file for writing!";
        return -1;
    }
}
