#include <iostream>
#include <cstring>
using namespace std;

int cost[6] = {1000, 1000, 200, 500, 200, 500};
bool finalStates[6][13];

class VendingMachine
{
private:
    bool states[15], aborted = false;
    int stateNumber;
    int totalAmount;

public:
    VendingMachine()
    {
        memset(states, false, sizeof(states));
        stateNumber = 0;
        totalAmount = 0;
    }

    void Run()
    {
        int temp;

        memset(finalStates, false, sizeof(finalStates));

        states[stateNumber] = true;
        cout << "Current State: Q 0\n";

        while (stateNumber < 15)
        {
            int op = 3, temp = 0, remAmount = 0;
            char item;
            cout << "\n1. Enter money\n2. Enter Item\n3. Quit\n";
            cout << "Enter Option: ";
            cin >> op;
            if (op == 1)
            {
                cout << "\n-------------------------------------------------------------------";
                cout << "\nEnter money: ";
                cin >> temp;
                if (((temp == 100) || (temp == 200) || (temp == 500) || (temp == 1000)) && ((stateNumber + (temp / 100)) <= 14))
                {
                    temp /= 100;
                    stateNumber += temp;
                    states[stateNumber] = true;
                    cout << "Current State: Q " << stateNumber << endl;
                }
                else if (((temp == 100) || (temp == 200) || (temp == 500) || (temp == 1000)) && ((stateNumber + (temp / 100)) >= 14))
                {
                    cout << "Exceeded Machine Storage Limit\n";
                }
                else
                {
                    cout << "Enter valid amount\n";
                }
                
                cout << "-------------------------------------------------------------------\n";
            }
            else if (op == 2)
            {
                cout << "\n-------------------------------------------------------------------";
                cout << "\nEnter Item: ";
                cin >> item;
                if ((item >= 65) && (item <= 70))
                {
                    if (item == 65)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient Amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                    if (item == 66)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                    if (item == 67)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient Amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                    if (item == 68)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient Amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                    if (item == 69)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient Amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                    if (item == 70)
                    {
                        if (((stateNumber * 100) - cost[item - 65]) < 0)
                        {
                            cout << "Insufficient Amount to buy item " << item << endl;
                        }
                        else
                        {
                            remAmount = (stateNumber * 100) - cost[item - 65];
                            stateNumber -= (cost[item - 65] / 100);
                            finalStates[item - 65][stateNumber] = true;
                            cout << "\n-------------------------------------------------------------------\n";
                            cout << "|   Item Dispensed: " << item << "  Amount Dispensed: " << remAmount << "  Final State: Q " << item << " " << stateNumber << "  |" << endl;
                            cout << "-------------------------------------------------------------------\n";
                            return;
                        }
                    }
                }
                else
                {
                    cout << "Invalid Item\n";
                }
                cout << "-------------------------------------------------------------------\n";
            }
            else if (op == 3)
            {
                aborted = true;
                cout << "\n-------------------------------------------------------------------\n";
                cout << "|                     Amount Dispensed: " << stateNumber * 100 << "                      |";
                cout << "\n-------------------------------------------------------------------\n";
                stateNumber = 0;
                return;
            }
            else
            {
                cout << "Invalid Option\n";
            }
        }
    }

    void Print()
    {
        if (aborted)
        {
            cout << "\n NO FINAL STATE REACHED\n";
            return;
        }

        cout << "\n States Traversed:\n\n";

        for (int i = 0; i <= 14; i++)
        {
            if (states[i] && !aborted)
                cout << "Q " << i << " --> ";
        }

        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 13; j++)
                if (finalStates[i][j])
                    cout << "Q " << static_cast<char>(i + 65) << " " << j << endl;
    }
};

int main()
{
    VendingMachine v;
    v.Run();
    v.Print();

    return 0;
}