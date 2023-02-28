// C program on tourism management

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// using structure for entering passenger details
typedef struct passenger_details
{
    char name[20];
    char gen[6];
    char pho[11];
    int age;
    struct passenger_details* link;
} passenger;
passenger* start = NULL;

// Declaring Function Used in this program
void types();
void heading();
void details();
void inter();
void india();
void receipt();
void payment();

 
// Global variables
int k, amount;                                 //k=no of persons going on trip
char type[60], place[30], date[20];


void types()
{
    int a;
    system("cls");
    heading();
    printf("\t\t\t\t1. International Tour Packages\n");     //allowing user to choose 
    printf("\t\t\t\t2. India Tour Packages\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    switch (a)
   {
    case 1:
        inter();
        break;
    case 2:
        india();
        break;
    default:
        printf("Enter Right Choice...");
        break;
    }
}

// Choice under  Indian category
void india()
{
    int a;
    system("cls");                   //function used for clearing the screen
    heading();
    strcpy(type, "India Tour Package");
    printf("\t\t\t\t1. Simla Tour Packages           5 Days 6 Nights-   (75000/-)\n");
    printf("\t\t\t\t2. Goa Tour Packages-            5 Days 4 Nights-   (55500/-)\n");
    printf("\t\t\t\t3. Kolkata Tour Packages-        11 Days 10 Nights- (75000/-)\n");
    printf("\t\t\t\t4. Tamil Nadu Tour Packages-     5 Days 6 Nights-   (60000/-)\n");
    printf("\t\t\t\t5. Varnasi Tour Packages-        5 Days 4 Nights-   (55500/-)\n");
    printf("\t\t\t\t6. Jaisalmer Tour Packages-      11 Days 10 Nights- (65000/-)\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    if (a == 1) 
	{
        strcpy(place, "Simla Tour");
        amount = 75000;
    }
    else if (a == 2) 
	{
        strcpy(place, "Kashmir Tour");
        amount = 55500;
    }
    else if (a == 3) 
	{
        strcpy(place, "Kolkata Tour");
        amount = 75000;
    }
    else if (a == 4) 
	{
        strcpy(place, "Tamil Nadu Tour");
        amount = 60000;
    }
    else if (a == 5) 
	{
        strcpy(place, " Varnasi Tour");
        amount = 55500;
    }
    else if (a == 6) 
	{
        strcpy(place, "Jaisalmer Tour");
        amount = 65000;
    }
    else
        printf("Enter Correct Choice...");
}
 
// Function To Take Package ChoiceO
// From International
void inter()
{
    int a;
    system("cls");
    heading();
    strcpy(type, "International Tour Package");
    printf("\t\t\t\t1. Venice Tour Packages-        6 Days 7 Nights    (90000/-)\n");
    printf("\t\t\t\t2. South Korea Tour Packages-   8 Days 9 Nights    (69000/-)\n");
    printf("\t\t\t\t3. New York Tour Packages-      11 Days 10 Nights  (87000/-)\n");
    printf("\t\t\t\t4. Dubai Tour Packages-         6 Days 7 Nights    (85000/-)\n");
    printf("\t\t\t\t5. Sydney Tour Packages-        5 Days 4 Nights    (80000/-)\n");
    printf("\t\t\t\t6. Cape Town Tour Packages-     11 Days 10 Nights  (77000/-)\n");
    printf("\t\t\t\tEnter Choice: ");
    scanf("%d", &a);
    if (a == 1) 
	{
        strcpy(place, "Venice Tour");
        amount = 90000;
    }
    else if (a == 2) 
	{
        strcpy(place, "South Korea Tour");
        amount = 69000;
    }
    else if (a == 3) 
	{
        strcpy(place, "New York Tour");
        amount = 87000;
    }
    else if (a == 4) 
	{
        strcpy(place, "Dubai Tour");
        amount = 85000;
    }
    else if (a == 5) 
	{
        strcpy(place, "Sydney Tour");
        amount = 80000;
    }
    else if (a == 6) 
	{
        strcpy(place, "Cape Town Tour");
        amount = 77000;
    }
    else
        printf("Enter Correct Choice...");
}
 
//function to add the passenger details 
 

void add_node(char lol[20], char der[6], int b, char ne[11])               //here,lol=name,der=gender,b=age
{
    passenger *newptr = NULL, *ptr;
    newptr = (passenger*)malloc(sizeof(passenger));
    strcpy(newptr->name, lol);
    strcpy(newptr->gen, der);
    strcpy(newptr->pho,ne);
    newptr->age = b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else 
	{
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}
 
// Function used for Printing Receipt
void receipt()
{
    int i, b;
    passenger* ptr = start;
    system("cls");
    heading();
    printf("\n\t\t\t\t***TAKE SCREENSHOTS FOR FURTHER USE***\n\n");
    printf("\t\t\tPhone number: ");
    puts(ptr->pho);
    for (i = 1; i <= k; i++)
    {
        printf("\t\t\t\t%d. Passenger Name: ", i);
        puts(ptr->name);
        printf("\t\t\t\t%d. Passenger Gender: ", i);
        puts(ptr->gen);
        printf("\t\t\t\t%d. Passenger Age: %d\n\n", i, ptr->age);
        ptr = ptr->link;
    }
    printf("\t\t\t\tSelected Type: ");
    puts(type);
    printf("\t\t\t\tPackage: ");
    puts(place);
    printf("\t\t\t\tDate: ");
    puts(date);
    b = amount * k;                                         //K=NO OF PASSENGERS GOING ON TRIP
    printf("\t\t\t\tTotal Amount: %d", b);
    printf("\n\t\t\t\t**YOUR TRIP IS SUCCESSFULLY REGISTERED**");
    printf("\n\t\tYour trip is provided with a free tourist guide\n");
    printf("\t\t*Do not want a guide,send a message to number-(9986534235),along with the screen-shot of your receipt *\n");
    printf("\n\t\t\t\t=====ANY QUERIES-CALL-7946458304======");
    printf("\nexiting.....\n\n\n");
}

// Function To Take Passenger Details
void details()
{
    int i, a;
	char pho[11];                                             //here pho is phone number
    char val[20], gen[6];                                             //add is address of anyone person
    system("cls");
    heading();
    printf("\t\t\t\tEnter Number Of Passengers: ");
    scanf("%d", &k);
    printf("\t\t\t\tEnter Date of going on trip (DD/MM/YY): ");
    fflush(stdin);
    gets(date);
    printf("\t\t\t\tEnter your phone number: ");
    fflush(stdin);
    gets(pho);
    for (i = 1; i <= k; i++)
	{
        system("cls");
        heading();
        printf("\t\t\t\tEnter The %d Passenger Name: ", i);
        fflush(stdin);
        gets(val);
        printf("\t\t\t\tEnter The %d Passenger Gender: ",i);
        fflush(stdin);
        gets(gen);
        printf("\t\t\t\tEnter The %d Passenger Age: ", i);
        fflush(stdin);
        scanf("%d", &a);
       add_node(val, gen, a, pho);                         //here  val meanes name,gen-gemder,a-age
    }
}

void payment()
{
	system("cls");
	heading();
    int  id, upi, bank, login, bill, payment, n;
    char holder;
    printf("\nSELECT ONE OF THE PAYMENT OPTIONS\n");
    printf("1)UPI\n2)NET BANKING: ");
    scanf("%d", &n);
    if(n==1)
    {
        printf("\nENTER UPI ID:");
        scanf("%d", &id);
        printf("\nOPEN THE UPI MOBILE APP AND APPROVE THE PAYMENT\n\n\n");
    }
    else
    {
        printf("\nSELECT ONE OF THE BANK");
        printf("\n1)AXIS BANK\n2)HDFC BANK\n3)ICIC BANK\n4)SBI BANK\n5)KOTAK BANK: ");
        scanf("%d", &bank);
        printf("\nENTER THE LOGIN ID: ");
        scanf("%d", &login);
        printf("PAY THE BILL\n\n\n\n");
    }
}


int cancel()
{
	int i,b,k;
	system("cls");
	heading();
    printf("YOUR TRIP IS CANCELLED\n");
    printf("YOUR AMOUNT  WILL BE REFUNDED BACK WITHIN 2 WEEKS\n\n\n\n\n\n\n\n");
    return 0;  
}

// Function For Printing Heading
// Of Portal
void heading()
{
    printf("\t\t\t\t***TOURISM MANAGEMENT SYSTEM***\n");
    printf("\t\t\t***VACINATION CERTIFICATE IS NESSESARY***\n\n");
    printf("\t\t\t**COVID TEST REPORTS TAKEN 15 DAYS BEFORE TRIP IS COMPULSORY**\n");
}


int main()
{
	heading();
	int ch;
	do
	{
		printf("BROCHURE\n1.TYPE OF TOUR\n2.DETAILS\n3.PAYMENT PROCESS\n4.RECEIPT\n5.CANCELATION OF TOUR\n ENTER YOUR CHOICE:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		types();
	    		break;
	    	case 2:
			    details();
				break;
			case 3:
			   payment();
				break;
			case 4:
			    receipt();
			    break;	
			case 5:
			    cancel();
			    break;			
		}
	}while(1);
}



