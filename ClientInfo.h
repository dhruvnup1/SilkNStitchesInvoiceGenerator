#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <string>
#include <vector>
using namespace std;

class Item {
    private: 
        int quantity;
        int price; 
        string name; 
    public:
        void setQuant(int q);
        int getQuant() const; // Mark as const
        void setPrice(int p);
        int getPrice() const; // Mark as const
        void setName(string n);
        string getName() const; // Mark as const
};

class Client {
    private: 
        string clientName; 
        vector<Item> numItem; 
    public: 
        void setClientName(string n);
        string getClientName() const; // Mark as const
        void addItem(Item obj);
        vector<Item> getItem() const; // Mark as const
        void displayClientDetails() const; // Mark as const
        void displayClientDetailsToFile(const string& filename) const; // New function
};

#endif
