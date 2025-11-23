#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Subscriber
{
    string Name;
    string Number;
    Subscriber(string name, string number) : // список инициализации 
        Name(name), Number(number) {};
};

struct cell
{
    string Name;
    list<Subscriber> subscriber;
};

class Dictionary
{
private:
    static const int size = 1000;
    cell table[size];
    int hash_function(string key)
    {
        int hash = 0;
        for (char c : key)
            hash = (hash + c) % size;
        return hash;
    }
public:
    void add(string name, string number)
    {
        int index = hash_function(name);
        if (table[index].Name == name)
        {
            for (auto& a : table[index].subscriber)
                if (a.Number == number)
                {
                    cout << "The subscriber has already been added" << endl;
                    return;
                }
            table[index].subscriber.push_back(Subscriber(name, number));
            cout << "The subscriber added successfully" << endl;
            return;
        }
        table[index].Name = name;
        table[index].subscriber.push_back(Subscriber(name, number));
        cout << "The subscriber added successfully" << endl;
    }

    void find(string name)
    {
        int index = hash_function(name);
        if (table[index].Name == name)
        {
            for (auto& a : table[index].subscriber)
                cout << "Name: " << a.Name << "  "
                << "Number: " << a.Number << endl;
            return;
        }
        cout << "Couldn't find a subscriber" << endl;
    }

    void remove(string name)
    {
        int index = hash_function(name);
        if (table[index].Name == name)
        {
            table[index].Name = nullptr;
            table[index].subscriber.clear();
            cout << "Element removed successfully" << endl;
            return;
        }
        cout << "Element not found" << endl;
    }


    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            for (auto& a : table[i].subscriber)
            {
                cout << "Name: " << a.Name << "  "
                    << "Number: " << a.Number << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;
    dict.add("Marry","0987654321");
    dict.add("Lisa", "1947245431");
    dict.add("Dima", "8487246431");
    dict.add("Ryan", "5555555555");
    dict.add("Ivan", "0983265431");
    dict.add("Ivan", "0983265431");
    dict.add("Ryan", "1234567890");
    cout << endl;
    dict.find("Ivan");
    dict.find("Ryan");
    cout << endl;
    dict.print();
    return 0;
}