/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Droid
*/

#include <string>
#include <iostream>

class Droid
{
    public:
    //Constructor
    Droid(std::string id = "");
    Droid(Droid const &droid);
    //Destructor
    ~Droid();
    //Get info
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    //Set info
    void setId(std::string id);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
    //Operator
    Droid &operator<<(size_t &energy);
    bool operator==(Droid const &droid) const;
    bool operator!=(Droid const &droid) const;
    Droid &operator=(Droid const &droid);
    // private info
    private:
    std::string _id;
    size_t _energy = 50;
    const size_t _attack = 25;
    const size_t _toughness = 15;
    std::string *status;
};

//Ostream for <<
std::ostream &operator<<(std::ostream &s, Droid &droid);
