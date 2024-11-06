#include <iostream>
#include <string>
using namespace std;

//Function prototype
void labelFunc(string);
string strToUpper(string);

int main()
{
    // Create header with function call
    labelFunc("| Car Sales Data |");

    // Accumulating variables
    int intFullTimeTotal = 0;
    int intPartTimeTotal = 0;
    int intUsedTotal = 0;
    int intNewTotal = 0;

    // Input and substring extraction variables
    string strID = "";
    string strCarType = "";
    string strJobType = "";    
    int intTempCarsNum;
    
    // Initial input query
    cout << "Enter salesperson ID number (or -1 to end): ";
    getline(cin, strID);

    // Loop while the sentinal value hasn't been entered
    while (strID != "-1")
    {
        // Checks that the length is correct
        if (strID.length() != 5) { cout << "Invalid ID length.\n\n"; }
        
        // Checks that the first three characters are numbers
        else if (!isdigit(strID[0]) or !isdigit(strID[1]) or !isdigit(strID[2])) { cout << "Invalid ID, first three characters must be numbers.\n\n"; }

        // Checks that the 4th character is a valid selection
        else if (strToUpper(strID.substr(3,1)) != "N" && strToUpper(strID.substr(3,1)) != "U") { cout << "Invalid job type: 4th character must be either 'N' or 'U'.\n\n"; }

        // Checks that the 5th character is a valid selection
        else if (strToUpper(strID.substr(4,1)) != "F" && strToUpper(strID.substr(4,1)) != "P") { cout << "Invalid job type: 5th character must be either 'F' or 'P'.\n\n"; }
        
        else
        {
            // Assign 4th and 5th characters to their own variables, uppercase
            strCarType = strToUpper(strID.substr(3,1));
            strJobType = strToUpper(strID.substr(4,1));

            // Input for cars sold
            cout << "Enter cars sold for salesperson " + strID + ": ";
            cin >> intTempCarsNum;
            cout << endl;
            
            // Clears out the cin stream
            cin.ignore(100, '\n');

            // Logic for where to update totals based on 4th and 5th character letters
            if (strCarType == "N")
            {
                intNewTotal += intTempCarsNum;
                if (strJobType == "F") { intFullTimeTotal += intTempCarsNum; }
                else { intPartTimeTotal += intTempCarsNum; }
            }
            else
            {
                intUsedTotal += intTempCarsNum;
                if (strJobType == "F") { intFullTimeTotal += intTempCarsNum; }
                else { intPartTimeTotal += intTempCarsNum; }
            }
        }

        // Iterative question
        cout << "Enter salesperson ID number (or -1 to end): ";
        getline(cin, strID);
    } // end loop

    // Output results
    cout << endl << endl;
    labelFunc("| Results |");
    cout << "Full-Time employee car sales: " << intFullTimeTotal << endl;
    cout << "Part-Time employee car sales: " << intPartTimeTotal << endl;
    cout << "New Car sales: " << intNewTotal << endl;
    cout << "Used Car sales: " << intUsedTotal << endl;

}

// Function to convert string to uppercase
string strToUpper(string strOut)
{
   for(int i = 0; i < strOut.length(); i++){
        strOut[i] = toupper(strOut[i]);
    }
    return strOut;
}

// Function to create a visual label
void labelFunc(string strHead)
{
    string strUnderline = "";
    strUnderline.assign(strHead.length(), '-');

    cout << strUnderline << endl << strHead << endl << strUnderline << endl << endl;

}