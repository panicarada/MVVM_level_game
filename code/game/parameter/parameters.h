#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>


class Parameters
{
public:
    Parameters();
};



class PathParameters : public Parameters
{
public:
    PathParameters(std::string path)
        : path(path){}

    std::string get_path()
    {
        return path;
    }
private:
    std::string path;
};

#endif // PARAMETERS_H
