#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;
int const LOCATION_DIM_SZ = 2;
int const TIME_DIM_SZ= 2;
int const PRODUCT_DIM_SIZE= 3;

string Location[]  = {"FL", "TX"};
string Period[]= {"Jan", "FEB"};
string Product[]= {"iPhone","iPad","MacBookPro"};


// 1
void printSalesDetails(double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]){
    
    int i(0),j(0),k(0); int sum = 0;
    
    cout << "Sales Details per Location per Period per Product" << endl;
    cout << "=================================================" << endl;
    
    for(i = 0; i < LOCATION_DIM_SZ; i++){
        for(j = 0; j < TIME_DIM_SZ; j++){
            for(k = 0; k < PRODUCT_DIM_SIZE; k++){
                cout << "Sales for location" << "\t"
                     << Location[i] << "/"
                     << Period[j] << "/"
                     << left << setw(12) << Product[k]
                     << "= $"
                     << right << setw(5) << fixed << setprecision(2) << sales[i][j][k]
                     << " millions" << endl;
                sum += sales[i][j][k];
                }
            }
    }
    cout << "Sum of sales for all Apple = $" << sum << " millions\n";
    cout << "===================================================" << endl;
}

// 4
void printSalesByPeriod(double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]){
    
    int i(0),j(0),k(0);
    double salesPerPeriod=0;
    
    cout << "Sales per Period" << endl;
    cout << "=================" << endl;
    for (i = 0; i < TIME_DIM_SZ; i++){
        for(j = 0; j < LOCATION_DIM_SZ; j++){
            for(k = 0; k < PRODUCT_DIM_SIZE; k++){
                salesPerPeriod += sales[j][i][k];
            }
        }
        cout << "Total Sales for "
             << Period[i]
             << " = $"
             << fixed << setprecision(2) <<salesPerPeriod
             << " millions\n";
        salesPerPeriod = 0;
    }
    cout << "===================================================" << endl;
    
}

// 5
void printSalesPerProductPerLocation(double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]){
    
    int i(0),j(0),k(0);
    double salesPerProductPerLocation=0;
    
    cout << "Total Sales per Product per Location" << endl;
    cout << "====================================" << endl;
    for(i = 0; i < PRODUCT_DIM_SIZE; i++){
        for(j = 0; j < LOCATION_DIM_SZ; j++){
            for(k = 0; k < TIME_DIM_SZ; k++){
                salesPerProductPerLocation += sales[j][k][i];
            }
            cout << "Total Sales for "
                 << left << setw(11) << Product[i]
                 << "in "
                 << Location[j]
                 << " = $"
                 << right << setw(6) << fixed << setprecision(2) <<salesPerProductPerLocation
                 << " millions\n";
            salesPerProductPerLocation = 0;
        }
    }
    cout << "===================================================" << endl;
}


// 6
void printSalesPerProductPerPeriod(double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]){
    
    int i(0),j(0),k(0);
    double salesPerProductPerPeriod=0;
    
    
    cout<<"Total Sales per Product per Period" <<endl;
    cout<<"===================================="<<endl;
    
    for(i = 0; i < PRODUCT_DIM_SIZE; i++){
        for(j = 0; j < TIME_DIM_SZ; j++){
            for(k = 0; k < LOCATION_DIM_SZ; k++){
                salesPerProductPerPeriod += sales[k][j][i];
            }
            cout << "Total Sales for "
            << left << setw(11) << Product[i]
            << "in "
            << Period[j]
            << " = $"
            << right << setw(6) << fixed << setprecision(2) <<salesPerProductPerPeriod
            << " millions\n";
            salesPerProductPerPeriod = 0;
        }
    }
    cout<<"==================================================="<<endl;
}


// 7
void printSalesPerLocationPerPeriod(double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]){
    
    int i(0),j(0),k(0);
    double salesPerLocationPerPeriod=0;
    
    cout<<"Total Sales per Location per Period" <<endl;
    cout<<"===================================="<<endl;
    for(i = 0; i < LOCATION_DIM_SZ ; i++){
        for(j = 0; j < TIME_DIM_SZ; j++){
            for(k = 0; k < PRODUCT_DIM_SIZE; k++){
                salesPerLocationPerPeriod += sales[i][j][k];
            }
            cout << "Total Sales for "
            << left << setw(11) << Location[i]
            << "in "
            << Period[j]
            << " = $"
            << right << setw(6) << fixed << setprecision(2) <<salesPerLocationPerPeriod
            << " millions\n";
            salesPerLocationPerPeriod = 0;
        }
    }
    cout<<"==================================================="<<endl;
}

int main() {
    
    double sales[LOCATION_DIM_SZ][TIME_DIM_SZ][PRODUCT_DIM_SIZE]={0};
    
    
    sales[0][0][0]=45;
    sales[0][0][1]=8;
    sales[0][0][2]=4;
    sales[0][1][0]=35;
    sales[0][1][1]=10;
    sales[0][1][2]=5;
    sales[1][0][0]=75;
    sales[1][0][1]=15;
    sales[1][0][2]=13;
    sales[1][1][0]=45;
    sales[1][1][1]=17;
    sales[1][1][2]=23.1;
    
    
    printSalesDetails(sales);/* 1 */
    printSalesByPeriod(sales);/* 4 */
    printSalesPerProductPerLocation(sales);/* 5 */
    printSalesPerProductPerPeriod(sales);/* 6 */
    printSalesPerLocationPerPeriod(sales);/* 7 */
    
    return 0;
}
