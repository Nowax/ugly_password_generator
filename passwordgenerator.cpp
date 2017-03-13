#include "passwordgenerator.h"

std::string PasswordGenerator::makePassword()
{
    generatePasswordLenght();
    insertCharacter('a','z');
    insertCharacter('A','Z');
    insertCharacter('0','9');
    fillPasswordWithRandoms();
    shufflePassword();
    std::cout<<pass<<"\n\n\n\n\n\n";
    return pass;
}

void PasswordGenerator::insertCharacter(char begin, char end) {
    std::uniform_int_distribution<char> uid(begin, end);
    temp = uid(random);
    pass.push_back(temp);
}

void PasswordGenerator::insertRandomCharacter()
{
    char temp = '?';
    while (!isalnum(temp) || std::find(pass.begin(), pass.end(), temp) != pass.end()) {
     std::uniform_int_distribution<char> uid('0','z');
     temp = uid(random);
    }
    pass.push_back(temp);
}

void PasswordGenerator::generatePasswordLenght()
{
    std::uniform_int_distribution<int> uid4(6,20);
    this->passwordLength = uid4(random);
}

void PasswordGenerator::fillPasswordWithRandoms()
{
    for (int i = pass.length(); i < passwordLength; i++) {
       insertRandomCharacter();

    }
}

void PasswordGenerator::shufflePassword()
{
    std::shuffle(pass.begin(), pass.end(), std::default_random_engine(std::random_device()()));
}

