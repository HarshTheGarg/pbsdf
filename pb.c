#include <stdio.h>
#include <stdlib.h>

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
        printf("Enter the option:\n0. Exit\n1. Enter record\n2. Show all records\n: ");
        scanf("%d", &opt);
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
        FILE *fp;
        
        switch ( opt ){
            case 1:
                /* Entering new record */
                // Creating new phonebook element
                struct pb ele;

                // Asking for the first name       
                printf("Enter first name: ");
                fflush(stdin);
                gets(ele.uname.fname);
                printf("\n");

                // Asking for the surname
                printf("Enter surname: ");
                fflush(stdin);
                gets(ele.uname.lname);
                printf("\n");

                // Asking for the personal phone number
                printf("Enter phone number: +91 ");
                fflush(stdin);
                gets(ele.pphone);
                printf("\n");

                // Asking for the alternate phone number
                printf("Enter alternate phone number: ");
                fflush(stdin);
                gets(ele.aphone);
                printf("\n");

                // Asking for the gender
                printf("Enter gender (M/F/T): ");
                char gen;
                fflush(stdin);
                scanf("%c", &gen);

                /* Converting the gender to upper case if it is in lower case for consistency */
                if ( gen > 'a' && gen < 'z'){
                    ele.gender = gen + 32;
                }else{
                    ele.gender = gen;
                }

                /* Asking father's name */
                printf("Enter Father's name:\n");

                // Father's first name
                printf("  First name: ");
                fflush(stdin);
                gets(ele.faname.fname);
                printf("\n");

                // Father's Last name
                printf("  Last Name: ");
                fflush(stdin);
                gets(ele.faname.lname);
                printf("\n");

                /* Asking Mother's name */
                printf("Enter Mother's name:\n");

                // Mother's first name
                printf("  First name: ");
                fflush(stdin);
                gets(ele.moname.fname);
                printf("\n");

                // Mother's Last name
                printf("  Last Name: ");
                fflush(stdin);
                gets(ele.moname.lname);
                printf("\n");

                // TODO: Add regex
                // Asking for the email id
                printf("Enter you email id: ");
                fflush(stdin);
                gets(ele.email);
                printf("\n");


                /* Asking for address */
                printf("Enter you address: \n");

                // Flat number
                printf("  Flat number: ");
                fflush(stdin);
                gets(ele.address.fn);
                printf("\n");

                // Building number
                printf("  Building number: ");
                fflush(stdin);
                gets(ele.address.buil);
                printf("\n");

                // Sreet Name
                printf("  Street name: ");
                fflush(stdin);
                gets(ele.address.street);
                printf("\n");

                // City name
                printf("  City: ");
                fflush(stdin);
                gets(ele.address.city);
                printf("\n");

                // State
                printf("  State: ");
                fflush(stdin);
                gets(ele.address.state);
                printf("\n");

                // Pincode
                printf("  Pincode: ");
                fflush(stdin);
                gets(ele.address.pin);
                printf("\n");


                // Storing the data in a binary file
                
                fp = fopen("pbbin.bin", "ab+");
                
                // If there is an error in opening the file
                if ( fp = NULL ){
                    printf("Some Error Occurred");
                    exit(1);
                }
                fwrite(&ele, sizeof(struct pb), 1, fp);
                fclose(fp);
                
                // Printing the success message
                printf("Record saved.");
                break;

            case 2:
                /* Displaying the basic details of all the entries */
                printf("Jere");
                fp = fopen("ppbin.bin", "rb");
                printf("\nHere");
                // If there is an error in opening the file
                if ( fp = NULL ){
                    printf("Some Error Occurred");
                    exit(1);
                }
                int ctr = 0;
                while( 1 ){
                    struct pb ele;
                    fread(&ele, sizeof(struct pb), 1, fp);
                    
                    // If file is empty
                    if ( feof(fp) ){
                        printf("No records found!\n");
                        break;
                    }

                    // Printing the headers
                    if ( ctr == 0 ){
                        printf("S.No.\r\tName\r\t\t\tPhone Number\r\t\t\t\t\tGender");
                        ctr++;
                    }

                    printf("%d\r\t%s, %s\r\t\t\t%s\r\t\t\t\t\t%c", ctr, ele.uname.lname, ele.uname.fname, ele.pphone, ele.gender);
                    printf("\n");
                }
        }
    }
}