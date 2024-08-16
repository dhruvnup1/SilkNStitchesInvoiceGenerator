#include <iostream>
#include <string.h>
#include <vector>
#include "ClientInfo.h"
using namespace std;





int main(){

    cout << "Invoice Generator for Silks n Stitches." << endl;

    vector<Client> ClientList;

    while(true){
    

    cout << "Enter in '1' to create an invoice for a new client" << endl;
    int response = 0; 

    cin >> response; 
    if(cin.fail()){
        cin.clear();
        cout << "Invalid Input. Please enter '1' to create an Invoice for a new client." << endl; 
        continue; 
    }

    if(response == 1){

        cout << "Creating a new client... " << endl; 
        Client newClient; 
        string currName;

        cout << "Enter the client name: " << endl; 
        cin.ignore(); 
        getline(cin, currName); 
        newClient.setClientName(currName);
        cout << "How many Items or services does this client need itemized? " << endl; 

        int items = 0; 
        cin >> items; 

        for(int i = 0; i < items; i++){
           
            Item newItem; 
            int quant; 
            string itemName;
            double price;  


            cout << "Enter the Item Name: " << endl; 
            cin >> itemName; 
            if(cin.fail()){
                cin.clear();
                cout << "Ivalid Input. Please enter an item name" << endl;
                continue; 
            }
            
            cout << "Enter the quantity: " << endl; 
            cin >> quant; 
            if(cin.fail()){
                cin.clear();
                cout << "Ivalid Input. Please enter a valid quantity" << endl;
                continue; 
            } 

            cout << "Enter the price: " << endl; 
            cin >> price; 
            if(cin.fail()){
                cin.clear();
                cout << "Ivalid Input. Please enter a valid price" << endl;
                continue; 
            } 

            
            newItem.setName(itemName); 
            newItem.setQuant(quant); 
            newItem.setPrice(price); 

            newClient.addItem(newItem);

        }

        ClientList.push_back(newClient); 
        
        char cont; 
        cout << "Would you like to enter another client's information to generate another invoice? (Y/N)" << endl; 
        cin >> cont; 

        if(cont == 'Y' || cont == 'y'){
            continue; 
        } else {
            break;
        }

    }
        
    }

    cout << "Displaying all clients and their items:" << endl;
    for (const auto& client : ClientList) {
        client.displayClientDetails();
        client.displayClientDetailsToFile("invoice_" + client.getClientName() + ".txt");
    }

    return 0;
}
    