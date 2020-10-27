#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <QString>
#include <sstream>
#include <vector>
using namespace std;
class Administrador{
public:
    std::vector<std::string> dataList;
    Administrador();
    void makeList();
};

#endif // ADMINISTRADOR_H
