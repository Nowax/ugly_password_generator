#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

class PasswordGenerator
{
public:
    std::string makePassword();
private:
    void insertCharacter(char, char);
    void insertRandomCharacter();
    void generatePasswordLenght();
    void fillPasswordWithRandoms();
    void shufflePassword();
    std::string pass = {};
    std::random_device random;
    char temp;
    int passwordLength = 0;
};

#endif // PASSWORDGENERATOR_H
