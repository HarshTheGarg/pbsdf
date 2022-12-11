#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printTableHeader(){
    printf("+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 6; i ++ ){
        printf("-");
    }
    printf("+\n");
    
    printf("|S.No.\r\t|Name\r\t\t\t|Phone Number\r\t\t\t\t\t|Gender|");

    printf("\n+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 6; i ++ ){
        printf("-");
    }
    printf("+");
}

void printTableHeaderAll(){
    printf("+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 31; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+\n");
    
    printf("|S.No.\r\t|Name\r\t\t\t|Phone Number\r\t\t\t\t\t|Gender\r\t\t\t\t\t\t|Email Address\r\t\t\t\t\t\t\t\t\t\t|Alter. Phone\r\t\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 7; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 31; i ++ ){
        printf("-");
    }
    printf("+");
    for ( int i = 0; i < 15; i ++ ){
        printf("-");
    }
    printf("+");
}

void printTableFooterAll(){
    printf("\n+");
            for ( int i = 0; i < 7; i ++ ){
                printf("-");
            }
            printf("+");
            for ( int i = 0; i < 15; i ++ ){
                printf("-");
            }
            printf("+");
            for ( int i = 0; i < 15; i ++ ){
                printf("-");
            }
            printf("+");
            for ( int i = 0; i < 7; i ++ ){
                printf("-");
            }
            printf("+");
            for ( int i = 0; i < 31; i ++ ){
                printf("-");
            }
            printf("+");
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

void strToCap(char ar[]){
    if ( ar[0] >= 'a' && ar[0] <= 'z' ){
        ar[0] = ar[0] - 32;
    }

    for ( int i = 1; ar[i] != '\0'; i++ ){
        if ( ar[i] >= 'A' && ar[i] <= 'Z') {
            ar[i] = ar[i] + 32;
        }
    }
}


/* Sorting the elements of the phonebook in incresasing order of their lastname, firstname */

// TODO make it work
void sortdDB(){

    
    /* Using bubble sort to sort the data */
    int ctr = -1;
    while ( ctr ){
        
        /* Opening the file */
        FILE *fp;
        FILE *fp_temp;

        fp = fopen("pbbin.bin", "wb+");
        fp_temp = fopen("pbbintem.bin", "wb+");

        /* Some error in opening the file */
        if ( fp == NULL || fp_temp == NULL ){
            printf("Some Error Occurred");
            exit(1);
        }

        ctr = 0;
        int ptr = 0;

        while ( !feof(fp) ){
            struct pb el1;
            struct pb el2;
            fseek(fp, sizeof(struct pb)*ptr, SEEK_SET);

            fread(&el1, sizeof(struct pb), 1, fp);
            fread(&el2, sizeof(struct pb), 1, fp);
            
            if ( strcmp(el1.uname.lname, el2.uname.lname) < 0 ){
                fwrite(&el2, sizeof(struct pb), 1, fp_temp);
                fwrite(&el1, sizeof(struct pb), 1, fp_temp);
                ctr++;
            }else if ( strcmp(el1.uname.lname, el2.uname.lname) == 0 ){
                if ( strcmp(el1.uname.fname, el2.uname.fname) < 0 ){
                    fwrite(&el2, sizeof(struct pb), 1, fp_temp);
                    fwrite(&el1, sizeof(struct pb), 1, fp_temp);
                    ctr++;
                }else {
                    fwrite(&el1, sizeof(struct pb), 1, fp_temp);
                    fwrite(&el2, sizeof(struct pb), 1, fp_temp);
                }
            }else {
                fwrite(&el1, sizeof(struct pb), 1, fp_temp);
                fwrite(&el2, sizeof(struct pb), 1, fp_temp);
            }
            ptr++;
        }
        
        fclose(fp);
        fclose(fp_temp);
        printf("lfdhasjkdfhlasdjf");

        remove("pbbin.bin");
        rename("pbbintem.bin", "pbbin.bins");
    }

}


/* Searches and displays all the records according to user input criteria
crit -> criteria -> first name, last name or phone number
term -> the word/number to search for
 */

void searchDisplay(char crit, char term[]){
    FILE *fp;
    fp = fopen("pbbin.bin", "rb+");
    fseek(fp, 0, SEEK_SET); 
    if ( fp == NULL ){
        printf("Error occurred!\n");
        return;
    }

    struct pb el;
    int ctr = 1; 
    int flag = 0; // To print the header banner if record found
    /* Searching on the basis of first name */
    if ( crit == 'f' ){
        while ( 1 ){
            if ( feof( fp ) ){
                break;
            }
            strToCap(term);
            fread(&el, sizeof(struct pb), 1, fp);
            if ( strcmp(el.uname.fname, term) == 0 ){
                if ( flag == 0 ){
                    printTableHeaderAll();
                    flag++;
                }

                printf("\n|%d\r\t|%s %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.fname, el.uname.lname, el.pphone, el.gender, el.email, el.aphone);
            }
            ctr++;
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }
        if ( flag != 0 ) {
           printTableFooterAll();
        }
    }
    if ( crit == 'l' ){
        while ( 1 ){
            
            strToCap(term);
            fread(&el, sizeof(struct pb), 1, fp);
            if ( strcmp(el.uname.lname, term) == 0 ){
                if ( flag == 0 ){
                    printTableHeaderAll();
                    flag++;
                }

                printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.lname, el.uname.fname, el.pphone, el.gender, el.email, el.aphone);
            }
            ctr++;
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }
        if ( flag != 0) {
           printTableFooterAll();
        }
    }
    if ( crit == 'p' ){
        while ( 1 ){

            fread(&el, sizeof(struct pb), 1, fp);
            if ( strcmp(el.pphone, term) == 0 || strcmp(el.aphone, term) == 0 ){
                if ( flag == 0 ){
                    printTableHeaderAll();
                    flag++;
                }

                printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c\r\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t|", ctr, el.uname.lname, el.uname.fname, el.pphone, el.gender, el.email, el.aphone);
            }
            ctr++;
            fread(&el, sizeof(struct pb), 1, fp );
            if ( feof( fp ) ){
                break;
            }else{
                fseek(fp, -(sizeof(struct pb)), SEEK_CUR);
            }
        }
        if ( flag != 0 ){
           printTableFooterAll(); 
        }
    }

    if ( flag == 0 ){
        printf("\nNo records found with the search criteria!\n");
    }
}

void main(){
    cls();
    /* Printing the banner */
    for ( int i = 0; i < 24; i ++ ){
        printf("=");
    }
    
    printf("\n");
    printf("WELCOME TO THE PHONEBOOK\n");
    
    for ( int i = 0; i < 24; i ++ ){
        printf("=");
    }

    printf("\n\n");

    
    /* Printing the menu in a loop */
    while ( 1 ){
        int opt;
        printf("Enter the option:\n0. Exit\n1. Enter record\n2. Show all records\n3. Search\n: ");
        scanf("%d", &opt);
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
            
            break;
        }

        /* User does not want to exit */
        FILE *fp;
        
        switch ( opt ){
            case 1:
                fflush(stdin);
                /* Entering new record */
                // Creating new phonebook element
                struct pb ele;
                printf("\n");

                // Asking for the first name       
                printf("Enter first name: ");
                fflush(stdin);
                scanf(" %s", ele.uname.fname);
                // strncat(ele.uname.fname, '\0');
                strToCap(ele.uname.fname);

                // Asking for the surname
                printf("Enter surname: ");
                scanf(" %s", ele.uname.lname);
                // strncat(ele.uname.lname, '\0');
                strToCap(ele.uname.lname);

                // Asking for the personal phone number
                printf("Enter phone number: +91 ");
                scanf(" %s", ele.pphone);
                // strncat(ele.pphone, '\0');

                // Asking for the alternate phone number
                printf("Enter alternate phone number: ");
                scanf(" %s", ele.aphone);
                // strncat(ele.aphone, '\0');

                // Asking for the gender
                printf("Enter gender (M/F/T): ");
                char gen;
                scanf(" %c", &gen);

                /* Converting the gender to upper case if it is in lower case for consistency */
                if ( gen >= 'a' && gen <= 'z'){
                    ele.gender = gen - 32;
                }else{
                    ele.gender = gen;
                }

                /* Asking father's name */
                printf("Enter Father's name:\n");

                // Father's first name
                printf("  First name: ");
                scanf(" %s", ele.faname.fname);
                // strncat(ele.faname.fname, '\0');
                strToCap(ele.faname.fname);

                // Father's Last name
                printf("  Last Name: ");
                scanf(" %s", ele.faname.lname);
                // strncat(ele.faname.lname, '\0');
                strToCap(ele.faname.lname);

                /* Asking Mother's name */
                printf("Enter Mother's name:\n");

                // Mother's first name
                printf("  First name: ");
                scanf(" %s", ele.moname.fname);
                // strncat(ele.moname.fname, '\0');
                strToCap(ele.moname.fname);

                // Mother's Last name
                printf("  Last Name: ");
                scanf(" %s", ele.moname.lname);
                // strncat(ele.moname.lname, '\0');
                strToCap(ele.moname.lname);

                // TODO: Add regex
                // Asking for the email id
                printf("Enter you email id: ");
                scanf(" %s", ele.email);
                // strncat(ele.email, '\0');


                /* Asking for address */
                printf("Enter you address: \n");

                // Flat number
                printf("  Flat number: ");
                scanf(" %s", ele.address.fn);
                // strncat(ele.address.fn, '\0');

                // Building number
                printf("  Building number: ");
                scanf(" %s", ele.address.buil);
                // strncat(ele.address.buil, '\0');

                // Sreet Name
                printf("  Street name: ");
                scanf(" %s", ele.address.street);
                // strncat(ele.address.street, '\0');
                strToCap(ele.address.street);

                // City name
                printf("  City: ");
                scanf(" %s", ele.address.city);
                // strncat(ele.address.city, '\0');
                strToCap(ele.address.city);

                // State
                printf("  State: ");
                scanf(" %s", ele.address.state);
                // strncat(ele.uname.fname, '\0');
                strToCap(ele.address.state);

                // Pincode
                printf("  Pincode: ");
                scanf(" %s", ele.address.pin);
                // strncat(ele.address.pin, '\0');


                // Storing the data in a binary file
                
                fp = fopen("pbbin.bin", "ab+");
                
                // If there is an error in opening the file
                if ( fp == NULL ){
                    printf("Some Error Occurred");
                    exit(1);
                }
                fwrite(&ele, sizeof(struct pb), 1, fp);
                fclose(fp);
                
                // Printing the success message
                printf("Record saved.\n\n");
                // TODO sortdDB();
                break;

            case 2:
                /* Displaying the basic details of all the entries */
                fp = fopen("pbbin.bin", "rb+");
                printf("\n");
                // If there is an error in opening the file
                if ( fp == NULL ){
                    printf("No records found!\n\n");
                    break;
                }
                int ctr = 0;
                while( 1 ){
                    struct pb ele;
                    fread(&ele, sizeof(struct pb), 1, fp);
                    
                    // If file is empty
                    if ( feof(fp) ){
                        break;
                    }

                    // Printing the headers
                    if ( ctr == 0 ){
                        printTableHeader();
                    }
                    ctr++;

                    printf("\n|%d\r\t|%s, %s\r\t\t\t|%s\r\t\t\t\t\t|%c     |", ctr, ele.uname.lname, ele.uname.fname, ele.pphone, ele.gender);
                }

                printf("\n+");
                for ( int i = 0; i < 7; i ++ ){
                    printf("-");
                }
                printf("+");
                for ( int i = 0; i < 15; i ++ ){
                    printf("-");
                }
                printf("+");
                for ( int i = 0; i < 15; i ++ ){
                    printf("-");
                }
                printf("+");
                for ( int i = 0; i < 6; i ++ ){
                    printf("-");
                }
                printf("+");
                printf("\n\n");
                break;
            case 3:
                printf("Select search criteria: \n  1. First Name\n  2. Last Name\n  3. Phone Number\n:");
                int opt;
                scanf("%d", &opt);

                switch ( opt ){
                    case 1:
                        char fname[20];
                        printf("Enter the first name you want to search: ");
                        scanf(" %s", fname);
                        searchDisplay('f', fname);
                        break;
                    case 2:
                        char lname[20];
                        printf("Enter the last name you want to search: ");
                        scanf(" %s", lname);
                        searchDisplay('l', lname);
                        break;
                    case 3:
                        char ph[11];
                        printf("Enter the phone number you want to search: ");
                        fflush(stdin);
                        scanf(" %s", ph);
                        ph[10] = '\0';
                        searchDisplay('p', ph);
                        break;
                }
                printf("\n\n");
                break;
        }
    }
}