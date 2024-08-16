#include "ClientInfo.h"
#include <iostream>
#include <fstream>
using namespace std;

// Definitions for Item class
void Item::setQuant(int q) {
    quantity = q; 
}

int Item::getQuant() const {
    return quantity;
}

void Item::setPrice(int p) {
    price = p; 
}

int Item::getPrice() const {
    return price;
}

void Item::setName(string n) {
    name = n; 
}

string Item::getName() const {
    return name;
}

// Definitions for Client class
void Client::setClientName(string n) {
    clientName = n; 
}

string Client::getClientName() const {
    return clientName;
}

void Client::addItem(Item obj) {
    numItem.push_back(obj); 
}

vector<Item> Client::getItem() const {
    return numItem;
}

void Client::displayClientDetails() const {
    cout << "Client Name: " << clientName << endl;
    for (const auto& item : numItem) {
        cout << "Item: " << item.getName() << ", Quantity: " << item.getQuant() << ", Price: " << item.getPrice() << endl;
    }
}

void Client::displayClientDetailsToFile(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Client Name: " << clientName << endl;
        outFile << "----------------------------------------" << endl;
        outFile << "| Item Name | Quantity | Price |" << endl;
        outFile << "----------------------------------------" << endl;
        for (const auto& item : numItem) {
            outFile << "|    " << item.getName() << " |  " << item.getQuant() << " |     " << item.getPrice() << " |" << endl;
        }
        outFile << "----------------------------------------" << endl;
        outFile.close();
        cout << "Invoice saved to " << filename << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}