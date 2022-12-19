#include <stdio.h> // Input Output
#include <stdlib.h>  // Standard Library
#include <string.h>  // To perform operations on strings


/* Declaring a structure to store the address 
add -> address
fn -> flat number
buil -> building number/name
street -> street name
city -> name of the city
state -> name of the state
pin -> pin code
*/

struct add{
    char fn[10];
    char buil[10];
    char street[20];
    char city[20];
    char state[20];
    char pin[7];
};


/* Declaring structure to store the first and last name
fname -> first name
lname -> last name
*/

struct name{
    char fname[20];
    char lname[20];
};


/* 
Declaring a structure which will help to store the data of the user.
pb -> phonebook
firname -> string -> first name of the user
lasname -> string -> last name of the user
pphone -> string -> personal phone number
aphone -> string -> alternate phone number
gender -> char -> 'M'/'F' -> Gender of the user 
ffname -> string -> Father's First Name
flname -> string -> Father's Last Name
mfname -> string -> Mother's First name
mlname -> string -> Mother's Last Name
email -> string -> Email ID of the user
address -> string -> Address of the user
*/

struct pb{
    struct name uname;
    char pphone[11];
    char aphone[11];
    char gender;
    struct name faname;
    struct name moname;
    char email[50];
    struct add address;
};


/* Count the number of data entries */
int cntData(){

    // Creating the file pointer to work with the file
    FILE *fp;

    // Opening the file
    fp = fopen("pbbin.bin", "rb");

    // If file does not exist
    if ( fp == NULL ){
        return 0;
    }

    // Variable to store the last position
    long int ctr;
    
    // Seeking to the end of the file
    fseek(fp, 0, SEEK_END);


    // Getting the current position of the file
    ctr = ftell(fp);

    // Close the file
    fclose(fp);

    // Return the number of elements
    // Number of elements = total size of file / size of each data element
    return ((int) ctr)/sizeof(struct pb);
}


/* Print the headers for the all people table
prints s.no., name, phone number, and gender in the right format
 */
void printTableHeader(){

    /* Top line */ 

    printf("+");
    // Above s.no.
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Above Name
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Above Phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    // Above Gender
    for ( int i = 0; i < 6; i ++ ){
        printf("-");
    }
    printf("+\n");
    
    // The text
    printf("|S.No.\r\t|Name\r\t\t\t|Phone Number\r\t\t\t\t\t|Gender|");

    /* Bottom Line */
    printf("\n+");
    
    // Below s.no.
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    
    // Below Name
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    
    // Below Phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Below Gender
    for ( int i = 0; i < 6; i ++ ){
        printf("-");
    }
    printf("+");
}


/* Print the headers for the search result */
void printTableHeaderAll(){

    /* Top Line */
    printf("+");

    // Above s.no
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Above name
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Above phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Above gender 
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Above email address
    for ( int i = 0; i < 31; i ++ ){
        printf("-");
    }
    printf("+");

    // Above alternate phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+\n");
    
    /* The text */
    printf("|S.No.\r\t|Name\r\t\t\t|Phone Number\r\t\t\t\t\t|Gender\r\t\t\t\t\t\t|Email Address\r\t\t\t\t\t\t\t\t\t\t|Alter. Phone\r\t\t\t\t\t\t\t\t\t\t\t\t|");


    /* Bottom line */
    printf("\n+");

    // Below s.no.
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Below name
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Below phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Below gender
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Below email address
    for ( int i = 0; i < 31; i ++ ){
        printf("-");
    }
    printf("+");

    // Below alternate phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
}


/* Print the bottom line for the search result */
void printTableFooterAll(){
    
    printf("\n+");

    // Below s.no
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Below name
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Below phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");

    // Below gender
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");

    // Below email address
    for ( int i = 0; i < 31; i ++ ){
        printf("-");
    }
    printf("+");

    // Below alternate phone number
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
}


/* Clearing the output screen */
void cls(){
    #ifdef __linux__
    /* If the user's OS is linux based */
        system("clear");
    #else
    /* If the user's OS is Windows */
        system("cls");
    #endif
}


/* Convert first letter of string to capital and rest to small */
void strToCap(char ar[]){
    
    // if first letter is small, change to capital  
    if ( ar[0] >= 'a' && ar[0] <= 'z' ){
        ar[0] = ar[0] - 32;
    }

    // if rest of the letters are capital, change to small
    for ( int i = 1; ar[i] != '\0'; i++ ){
        if ( ar[i] >= 'A' && ar[i] <= 'Z') {
            ar[i] = ar[i] + 32;
        }
    }
}


/* Searches and displays all the records according to user input criteria
crit -> criteria -> first name, last name or phone number
term -> the word/number to search for
 */
void searchDisplay(char crit, char term[]){
    
    // Opening the file that contains all the data
    FILE *fp;
    fp = fopen("pbbin.bin", "rb+");

    // If there is an error in opening the file
    if ( fp == NULL ){
        printf("Error occurred!\n");
        return;
    }

    // Creating a structure variable to store the elements read from the file
    struct pb el;

    int ctr = 1; // To print the s.no.
    int flag = 0; // To print the header banner only once, if record found
    
    /* Searching on the basis of first name */
    if ( crit == 'f' ){

        // Starting a loop till the binary file ends
        while ( 1 ){
            
            // Capitalize the search term as all the data stored in capitalized
            strToCap(term);

            // Reading the next data element
            fread(&el, sizeof(struct pb), 1, fp);

            // If current data element matches the search term
            if ( strcmp(el.uname.fname, term) == 0 ){

                // If first data element found, print the headers
                if ( flag == 0 ){

                    // Printing the header for the table
                    printTableHeaderAll();

                    // To prevent printing headers after every match
                    flag++;
                }

                // Printing the data element that matches the search term
                printf("\n|%d\r\t|%s %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.fname, el.uname.lname, el.pphone, el.gender, el.email, el.aphone);
            }

            // Increment the s.no.
            ctr++;

            // Check if the file is ending, if true break the loop
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }

        // Print the bottom line if there was atleast one data is found
        if ( flag != 0 ) {
           printTableFooterAll();
        }
    }

    /* Searhing on the basis of last name */
    if ( crit == 'l' ){

        // Starting a loop till the binary file reaches the end
        while ( 1 ){
            
            // Capitalizing the search term as all the data in the binary file is capitalized
            strToCap(term);

            // Reading the next data element
            fread(&el, sizeof(struct pb), 1, fp);

            // If there is a match
            if ( strcmp(el.uname.lname, term) == 0 ){
                
                // Printing the header when match is found
                if ( flag == 0 ){
                    printTableHeaderAll();

                    // To make sure that the header is printed only once and not after every match
                    flag++;
                }

                // Printing the data
                printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.lname, el.uname.fname, el.pphone, el.gender, el.email, el.aphone);
            }

            // Increment the s.no.
            ctr++;

            // Checking if the file is reaching the end, if true end the loop
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }

        // Printing the bottom line if there was any match found
        if ( flag != 0) {
           printTableFooterAll();
        }
    }

    /* Searching on the basis of main or alternate phone number */
    if ( crit == 'p' ){

        // Starting the loop till the binary file reaches the end
        while ( 1 ){
            
            // Reading the next data element
            fread(&el, sizeof(struct pb), 1, fp);

            // Checking if match is found
            if ( strcmp(el.pphone, term) == 0 || strcmp(el.aphone, term) == 0 ){
                
                // Printing the header if match is found
                if ( flag == 0 ){
                    printTableHeaderAll();

                    // To make sure the header is printed only once, and not after every match
                    flag++;
                }

                // Printing the data
                printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.lname, el.uname.fname, el.pphone, el.gender, el.email, el.aphone);
            }

            // Incrementing the s.no. counter
            ctr++;

            // Checking if file is reaching the end, if true breaking the loop
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }

        // Printing the bottom line if there was a match
        if ( flag != 0 ){
           printTableFooterAll(); 
        }
    }

    // Informing the user if there is no data
    if ( flag == 0 ){
        printf("\nNo records found with the search criteria!\n");
    }

    // Closing the file after displaying the data
    fclose(fp);
}


/* Displaying all the information of an element using its serial number 
sno -> the serial number to search
*/
void displayDeets(int sno){
    
    // Creating file pointer to open the file
    FILE *fp;

    // Opening the file
    fp = fopen("pbbin.bin", "rb+");

    // Checking if there was error in opening the file
    if ( fp == NULL ){
        printf("Error in opening the file");
        return;
    }

    // Creating structure variable to store the current data in the file
    struct pb ele;

    // Seeking to the required data element
    fseek(fp, (sizeof(struct pb))*(sno - 2), SEEK_CUR);

    // Reading the data
    fread(&ele, sizeof(struct pb), 1, fp );

    // Check if the file is ending, if true break the loop
    fread(&ele, sizeof(struct pb), 1, fp );
    if ( feof( fp ) ){
        fclose(fp);
        return;
    }else{
        fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
    }

    /* Displaying the data */

    // Displaying the name
    printf("Name: %s %s\n", ele.uname.fname, ele.uname.lname );

    // Displaying the phone number
    printf("Phone Number: +91 %s\n", ele.pphone);

    // Displaying the alternate phone number
    printf("Alternate phone number: %s\n", ele.aphone );

    // Displaying the email address
    printf("Email Address: %s\n", ele.email );

    // Displaying the gender
    printf("Gender: %c\n", ele.gender);

    // Displaying the fathers name
    printf("Father's name: %s %s\n", ele.faname.fname, ele.faname.lname );
    
    // Displaying the mother's name
    printf("Mother's name: %s %s\n", ele.moname.fname, ele.moname.lname );

    /* Displaying the address */
    printf("Address: %s, %s, %s, %s, %s - %s\n", ele.address.fn, ele.address.buil, ele.address.street, ele.address.city, ele.address.state, ele.address.pin);

    printf("\n\n");

    // Closing the file after displaying all the details
    fclose(fp);

    return;
}


/* Sort the data of the file */
void insertData(struct pb data){

    // Creating the file pointer to store the file
    FILE *fp;

    // Opening the file
    fp = fopen("pbbin.bin", "ab");
    fwrite(&data, sizeof(struct pb), 1, fp);
    
    // Closing the file as it is no longer needed
    fclose(fp);

    return;

}


/* Delete a record from the file by creating a new temp file and copying all the data
 except the data to delete and then renaming the temp file to the actual file after deleting it

sno -> The serial number to delete the data
*/
void deleteRec(int sno){

    // Creating the file pointer to store the file
    FILE *fp;
    FILE *fptem;

    // Opening the file
    fp = fopen("pbbin.bin", "rb");

    // Opening the temporary file
    fptem = fopen("ptem.bin", "wb");

    // Getting the number of elements from the file
    int num = cntData();

    // Creating a structure variable to store temp data
    struct pb ele;

    // Loop to copy all the records from the current file to a temporary file
    for ( int i = 0; i < num; i ++ ){

        // Reading the data
        fread(&ele, sizeof(struct pb), 1, fp);
        
        // Adding the data if it is not equal to the required sno
        if ( i != sno - 1){
            fwrite(&ele, sizeof(struct pb), 1, fptem);
        }        
    }

    // Closing the files
    fclose(fp);
    fclose(fptem);

    // Removing the binary file and renaming the temporary file to the required name
    remove("pbbin.bin");
    rename("ptem.bin", "pbbin.bin");

    return;
}


/* The main function */
void main(){

    // Clearing the screen before starting the program
    cls();

    /* Printing the welcome banner */
    for ( int i = 0; i < 24; i ++ ){
        printf("=");
    }
    
    printf("\n");
    printf("WELCOME TO THE PHONEBOOK\n");
    
    for ( int i = 0; i < 24; i ++ ){
        printf("=");
    }

    printf("\n\n");

    // To make sure the welcome screen is not cleared in the first interation
    int n = 0;

    /* Printing the menu in a loop */
    while ( 1 ){
        
        // Creating variable to store the user's selection
        int opt;

        // To seperate the new menu from the previous results
        for ( int i = 0; i < 20; i ++ ){
            printf("-");
        }
        printf("\n");

        // Printing the menu to show all the available options
        printf("Enter the option:\n0. Exit\n1. Enter record\n2. Show all records\n3. Search\n4. Show Complete info\n5. Delete record\n: ");
        
        // Getting the users options
        scanf("%d", &opt);

        // Clearing the input steam
        fflush(stdin);
        
        /* If the user wants to exit the program */
        if ( opt == 0 ){
            
            /* Printing the goodbye banner */

            printf("\n\n");
            for ( int i = 0; i < 26; i ++ ){
                printf("=");
            }
            
            printf("\n");
            printf("Bye! Hope to see you soon!\n");
            
            for ( int i = 0; i < 26; i ++ ){
                printf("=");
            }

            printf("\n\n");
            
            // Exiting the program after printing the goodbye banner
            exit(1);
        }

        /* User does not want to exit */

        // Creating the file pointer to make changes to the required file
        FILE *fp;
        
        switch ( opt ){
            case 1:

            /* Entering new record */

                // Clearing the screen
                cls();

                // Creating new phonebook element
                struct pb ele;
                printf("\n");

                // Asking for the first name and Inputting it in the structure     
                printf("Enter first name: ");
                fflush(stdin);  // Clearing the input stream
                scanf(" %s", ele.uname.fname);
                // Capitalizing the input
                strToCap(ele.uname.fname);

                // Asking for the surname and Inputting it in the structure
                printf("Enter surname: ");
                scanf(" %s", ele.uname.lname);
                // Capitalizing the input
                strToCap(ele.uname.lname);

                // Asking for the main phone number and Inputting it in the structure
                printf("Enter phone number: +91 ");
                scanf(" %s", ele.pphone);

                // Asking for the alternate phone number and Inputting it in the structure
                printf("Enter alternate phone number: ");
                scanf(" %s", ele.aphone);

                // Asking for the gender and Inputting it in the structure
                printf("Enter gender (M/F/T): ");
                scanf(" %c", &ele.gender);

                /* Converting the gender to upper case if it is in lower case for consistency */
                if ( ele.gender >= 'a' && ele.gender <= 'z'){
                    ele.gender = ele.gender - 32;
                }

                /* Asking father's name */
                printf("Enter Father's name:\n");

                // Father's first name
                printf("  First name: ");

                // Creating a temp variable to input the data as the new line character
                // was autmatically being input
                char tem[1];
                scanf("%s", tem);
                
                scanf(" %s", ele.faname.fname);
                // Capitalizing the input
                strToCap(ele.faname.fname);

                // Father's Last name
                printf("  Last Name: ");
                scanf(" %s", ele.faname.lname);
                // Capitalizing the input
                strToCap(ele.faname.lname);

                /* Asking Mother's name */
                printf("Enter Mother's name:\n");

                // Mother's first name
                printf("  First name: ");
                scanf(" %s", ele.moname.fname);
                // Capitalizing the input
                strToCap(ele.moname.fname);

                // Mother's Last name
                printf("  Last Name: ");
                scanf(" %s", ele.moname.lname);
                // Capitalizing the input
                strToCap(ele.moname.lname);

                // TODO: Add regex
                // Asking for the email id
                printf("Enter you email id: ");
                scanf(" %s", ele.email);


                /* Asking for address */
                printf("Enter you address: \n");

                // Flat number
                printf("  Flat number: ");
                scanf(" %s", ele.address.fn);

                // garbage variable to store the new line character automatically inputted
                char gv[20];
                gets(gv);

                // Building number
                printf("  Building number: ");
                gets(ele.address.buil);

                // Sreet Name
                printf("  Street name: ");
                gets(ele.address.street);
                // Capitalizing the input
                strToCap(ele.address.street);

                // City name
                printf("  City: ");
                gets(ele.address.city);
                // Capitalizing the input
                strToCap(ele.address.city);

                // State
                printf("  State: ");
                gets( ele.address.state);
                // Capitalizing the input
                strToCap(ele.address.state);

                // Pincode
                printf("  Pincode: ");
                scanf(" %s", ele.address.pin);

                // Inserting the data to the file
                insertData(ele);
                printf("\n");
                
                // Printing the success message
                printf("Record saved.\n\n");
                
                break;

            case 2:

            /* Displaying the basic details of all the entries */
                
                // Clearing the screen
                cls();

                // number of data elements
                int num = cntData();

                // If there is no data then print the message and exit the loop
                if (num == 0){
                    printf("No record found\n\n");
                    break;
                }
                
                // Opening the file, using the pointer created earlier
                fp = fopen("pbbin.bin", "rb+");
                printf("\n");

                // If there is an error in opening the file / if there is no record found
                if ( fp == NULL ){
                    printf("No records found!\n\n");
                    break;
                }

                // Variable to check the header and s.no.
                int ctr = 0;

                // Looping untill the end of file is reached
                while( 1 ){

                    // Creating a structure variable to store the data from the file
                    struct pb ele;

                    // Reading the data from file and storing in the structure variable
                    fread(&ele, sizeof(struct pb), 1, fp);
                    
                    // If end of file is reached
                    if ( feof(fp) ){
                        fclose(fp);
                        break;
                    }

                    // Printing the headers only in the first iteration
                    if ( ctr == 0 ){
                        printTableHeader();
                    }

                    // Incrementing the counter to increment the serial number and make sure that the header is not printed again
                    ctr++;

                    // Printing the data
                    printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c     |", ctr, ele.uname.lname, ele.uname.fname, ele.pphone, ele.gender);
                }

                // Printing the bottom line
                printf("\n+");

                // Below s.no.
                for ( int i = 0; i < 7; i ++ ){
                    printf("-");
                }
                printf("+");

                // Below Name
                for ( int i = 0; i < 15; i ++ ){
                    printf("-");
                }
                printf("+");

                // Below phone number
                for ( int i = 0; i < 15; i ++ ){
                    printf("-");
                }
                printf("+");

                // Below gender
                for ( int i = 0; i < 6; i ++ ){
                    printf("-");
                }
                printf("+");
                printf("\n\n");
                
                break;

            case 3:
            
            /* Search for people based on first name, last name or phone number */
                // Clearing the screen 
                cls();

                // Printing the menu to ask the user for the basis of search
                printf("Select search criteria: \n  1. First Name\n  2. Last Name\n  3. Phone Number\n  4. Previous Menu\n:");
                
                // Varialbe to store the user choice
                int opt;

                // Inputting the user choice
                scanf("%d", &opt);

                // Action based on the user choice
                switch ( opt ){

                    case 1:
                    /* Search based on the first name */
                        // Variable to store the name to search for
                        char fname[20];

                        // Asking the name to search for
                        printf("Enter the first name you want to search: ");
                        
                        // Inputting the search name
                        scanf(" %s", fname);

                        // Searching and displaying the elements
                        searchDisplay('f', fname);

                        break;
                    
                    case 2:
                    /* Search based on the last name */
                        // Variable to store the last name to search for
                        char lname[20];

                        // Asking the last name to search for
                        printf("Enter the last name you want to search: ");
                        
                        // Inputting the search term
                        scanf(" %s", lname);

                        // Searching and displaying the elements
                        searchDisplay('l', lname);

                        break;
                    
                    case 3:
                    /* Search based on the phone number */
                        // Variable to store the phone number to search for
                        char ph[11];

                        // Asknig the phone number to search for
                        printf("Enter the phone number you want to search: ");
                        
                        // Inputting the phone number to search for
                        scanf(" %s", ph);

                        // Searching and displaying the elements
                        searchDisplay('p', ph);

                        break;

                    case 4:
                    /* Exit the operation */
                        break;
                }

                printf("\n\n");
                
                break;
            
            case 4:
            /* Display all the details for a entry by S.No. */

                // Clearing the screen
                cls();

                // Asking the user for the s.no. to search for
                printf("\nEnter the serial number or zero (0) for previous menu\n:");
                
                // Variable to store the s.no. to search for
                int sno4;

                // Inputting the s.no.
                scanf("%d", &sno4);
                
                // If the user wants to go back
                if ( sno4 == 0 ){
                    break;
                }

                printf("\n");

                // Displaying all the detail based on the user input
                displayDeets(sno4);
                
                printf("\n");
                break;
            
            case 5:
            /* Delete a particular record using the serial number */
                // Clearing the screen
                cls();

                // Asking for the serial number
                printf("\nEnter the serial number or zero (0) for previous menu\n:");
                
                // Variable to store the s.no. to search for
                int sno5;

                // Inputting the s.no.
                scanf("%d", &sno5);
                
                // If the user wants to go back
                if ( sno5 == 0 ){
                    break;
                }

                printf("\n");

                // Deleting the entry
                deleteRec(sno5);

                // Printing the success message
                printf("Record deleted!\n");
                break;
        }
    }
}