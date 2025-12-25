#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 1. Base Class (Common Properties)
class UtilityBill {
protected:
    string billingDate;
    double usageAmount;
public:
    void setDetails(string date, double usage) {
        billingDate = date;
        usageAmount = usage;
    }
    // Virtual function to be overridden by child classes
    virtual double calculateTotal() = 0; 
};

// 2. Child Class: Electricity (Inheritance)
class ElectricityBill : public UtilityBill {
public:
    double calculateTotal() {
        // Example: ₹10 base fee + ₹0.50 per unit
        return 10.0 + (usageAmount * 0.50);
    }
};

// 2. Child Class: Water (Inheritance)
class WaterBill : public UtilityBill {
public:
    double calculateTotal() {
        // Example: ₹5 base fee + ₹0.02 per liter
        return 5.0 + (usageAmount * 0.02);
    }
};

int main() {
    // 3. Explanation of File Handling (in comments)
    // To store bills, we would use 'ofstream' to write details to 'bills.txt'.
    // To read them, we would use 'ifstream' and parse each line.
    
    ElectricityBill e;
    e.setDetails("2025-10-01", 150);
    cout << "Electricity Bill Total: ₹" << e.calculateTotal() << endl;
    
    return 0;
}
