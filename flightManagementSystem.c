#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flight
{
    int flightID;
    int from;
    int destination;
    int date;
    int time;
    int price;
    int adultCapacity;
    int childCapacity;
    int adultTicketsSold;
    int childTicketsSold;
    int totalRevenue;
};


const char *airport[] = {
    "Karachi",
    "Islamabad",
    "Lahore",
    "Dubai",
    "London",
    "New York"
};
const char *timeslot[] = {
    "Morning",
    "Evening",
    "Night"
};
const char *classList[] = {
    "Economy",
    "Business",
    "First Class"
};

void addFlight(struct flight *a){
    printf("Adding New Flight\n");
    printf("Enter Flight Number: \n");
    scanf("%d", &a->flightID);
    printf("Airport list:\n\t0:Karachi\n\t1:Islamabad\n\t2:Lahore\n\t3:Dubai\n\t4:London\n\t5:New York\n");
    printf("Enter starting point: \n");
    scanf("%d", &a->from);
    printf("Enter destination: \n");
    scanf("%d", &a->destination);
    printf("Enter date in the format yyyymmdd: ");
    scanf("%d", &a->date);
    printf("0:Morning\n1:Evening\n2:Night\n");
    printf("Choose timeslot: ");
    scanf("%d", &a->time);
    printf("Enter Base ticket price: ");
    scanf("%d", &a->price);
    printf("Enter adult capacity: ");
    scanf("%d", &a->adultCapacity);
    printf("Enter children capacity");
    scanf("%d", &a->childCapacity);
    a->adultTicketsSold=0;
    a->childTicketsSold=0;
    a->totalRevenue=0;
    printf("FLIGHT NUMBER %d HAS BEEN SUCCESSFULLY SAVED\n",a->flightID);
}
void updateFlight(struct flight *a){
    int opp;
    printf("What would you like to modify\n0:Everything\n1:Flight ID\n2:Starting Point\n3:Destination\n4:Date\n5:TimeSlot\n6:Base Price\n7:Capacity\n");
    printf("Choose Option: ");
    scanf("%d",&opp);
    switch (opp)
    {
    case 0:
        printf("Enter Flight Number: \n");
        scanf("%d", &a->flightID);
        printf("Airport list:\n\t0:Karachi\n\t1:Islamabad\n\t2:Lahore\n\t3:Dubai\n\t4:London\n\t5:New York\n");
        printf("Enter starting point: \n");
        scanf("%d", &a->from);
        printf("Enter destination: \n");
        scanf("%d", &a->destination);
        printf("Enter date in the format yyyymmdd: ");
        scanf("%d", &a->date);
        printf("0:Morning\n1:Evening\n2:Night\n");
        printf("Choose timeslot: ");
        scanf("%d", &a->time);
        printf("Enter Base ticket price: ");
        scanf("%d", &a->price);
        printf("Enter Adult capacity: ");
        scanf("%d", &a->adultCapacity);
        printf("Enter Children capacity: ");
        scanf("%d", &a->childCapacity);
        a->adultTicketsSold = 0; a->childTicketsSold = 0; a->totalRevenue = 0;        
        break;
    case 1:
        printf("Enter Flight Number: \n");
        scanf("%d", &a->flightID);
        break;
    case 2:
        printf("Airport list:\n\t0:Karachi\n\t1:Islamabad\n\t2:Lahore\n\t3:Dubai\n\t4:London\n\t5:New York\n");
        printf("Enter starting point: \n");        
        scanf("%d", &a->from);
        break;
    case 3:
        printf("Airport list:\n\t0:Karachi\n\t1:Islamabad\n\t2:Lahore\n\t3:Dubai\n\t4:London\n\t5:New York\n");
        printf("Enter destination: \n");
        scanf("%d", &a->destination);
        break;
    case 4:
        printf("Enter date in the format yyyymmdd: ");
        scanf("%d", &a->date);
        break;
    case 5:
        printf("0:Morning\n1:Evening\n2:Night\n");
        printf("Choose timeslot: ");
        scanf("%d", &a->time);
        break;
    case 6:
        printf("Enter Base ticket price: ");
        scanf("%d", &a->price);
        break;
    case 7:
        printf("Enter adult capacity: ");
        scanf("%d", &a->adultCapacity);
        printf("Enter children capacity: ");
        scanf("%d", &a->childCapacity);
        break;
    default:
        break;
    }
}
void displayFlights(struct flight a[],int count, int privileges){
    printf("DISPLAYING SCHEDULE\n");
    for(int i=0;i<count;i++){
        printf("\tFlight Index:%d\tFlight ID %d\n",i,a[i].flightID);
        printf("Starting Point: %s\nDestination: %s\nDate: %d\nTime: %s\nPrice: %d\n",airport[a[i].from],airport[a[i].destination],a[i].date,timeslot[a[i].time],a[i].price);
        if(privileges==0){
            printf("Adult Capacity: %d\nChildren Capacity %d\nAdult tickets Sold %d\nChildren tickets sold %d\nTotal Revenue %d\n",a[i].adultCapacity,a[i].childCapacity,a[i].adultTicketsSold,a[i].childTicketsSold,a[i].totalRevenue);
	    }
        printf("\n");
    }
}
void bookFlights(int flightCount, struct flight a[]){
    int start,destination,childCount,adultCount,class,choice;
    double total;
    FILE *file = fopen("Customers.txt","a");
    if (file == NULL) {
    printf("Error opening file!\n");
    }
    char email[20],name[20];
    printf("Enter Name: ");
    scanf("%s",name);
    printf("Enter Email Address: ");
    scanf("%s",email);
    printf("Airport list:\n\t0:Karachi\n\t1:Islamabad\n\t2:Lahore\n\t3:Dubai\n\t4:London\n\t5:New York\n");
    printf("Choose starting point: ");  
    scanf("%d",&start);
    printf("Choose destination: ");
    scanf("%d",&destination);
    printf("Available options\n");
    for(int i=0;i<flightCount;i++){
        if(a[i].from==start&&a[i].destination==destination){
            printf("\tFLIGHT INDEX: %d\n",i);
            printf("Flight ID: %d\nStarting Point: %s\nDestination: %s\nDate: %d \nTime: %s\nPrice: %d\n",a[i].flightID,airport[a[i].from],airport[a[i].destination],a[i].date,timeslot[a[i].time],a[i].price);
        }
    }
    printf("Enter Index of Choice: ");
    scanf("%d",&choice);
    printf("Enter number of children: ");
    scanf("%d",&childCount);
    printf("Enter number of adult: ");
    scanf("%d",&adultCount);
    printf("Choose class\n");
    printf("0:Economy Price:Rs%.2f\n",(adultCount*a[choice].price)+(childCount*a[choice].price*0.9));
    printf("1:Business Price:Rs%.2f\n",(adultCount*a[choice].price*1.1)+(childCount*a[choice].price*1));
    printf("2:First Class Price:Rs%.2f\n",(adultCount*a[choice].price*1.2)+(childCount*a[choice].price*1.1));
    printf("Enter choice: ");
    scanf("%d",&class);
    if(class==0){
        total=(adultCount*a[choice].price)+(childCount*a[choice].price*0.9);
    }
    else if(class==1){
        total=(adultCount*a[choice].price*1.1)+(childCount*a[choice].price*1);
    }
    else{
        total=(adultCount*a[choice].price*1.2)+(childCount*a[choice].price*1.1);
    }
    printf("Your information has been saved and your bill has been sent to your email address\n");
    fprintf(file, "Customer Name:%s\t Email Address:%s\t Flight ID:%d\t %d Adults and %d Children\t %s\t Total %.2f\n",name,email,a[choice].flightID,adultCount,childCount,classList[class],total);
    fclose(file);
}




int main(){
    int stoppingCondition = 0;
    int stoppingCondition2 = 0; 
    int operation;
    struct flight flights[100];
    int flightCount = 10;
    int x;
    char password[15],username[15];
    flights[0].flightID = 354;
    flights[0].from = 0;
    flights[0].destination = 3;
    flights[0].date = 20231204;
    flights[0].time = 1;
    flights[0].price = 25000;
    flights[0].adultCapacity = 90;
    flights[0].childCapacity = 40;
    flights[0].adultTicketsSold = 32;
    flights[0].childTicketsSold = 20;

    flights[1].flightID = 274;
    flights[1].from = 3;
    flights[1].destination = 1;
    flights[1].date = 20231213;
    flights[1].time = 2;
    flights[1].price = 45000;
    flights[1].adultCapacity = 95;
    flights[1].childCapacity = 55;
    flights[1].adultTicketsSold = 30;
    flights[1].childTicketsSold = 15;
    flights[1].totalRevenue = 360000;

    flights[2].flightID = 444;
    flights[2].from = 0;
    flights[2].destination = 5;
    flights[2].date = 20231203;
    flights[2].time = 1;
    flights[2].price = 35000;
    flights[2].adultCapacity = 140;
    flights[2].childCapacity = 60;
    flights[2].adultTicketsSold = 32;
    flights[2].childTicketsSold = 31;
    flights[2].totalRevenue = 500000;

    flights[3].flightID = 342;
    flights[3].from = 4;
    flights[3].destination = 1;
    flights[3].date = 20231223;
    flights[3].time = 0;
    flights[3].price = 22000;
    flights[3].adultCapacity = 200;
    flights[3].childCapacity = 60;
    flights[3].adultTicketsSold = 42;
    flights[3].childTicketsSold = 21;
    flights[3].totalRevenue = 420000;

    flights[4].flightID = 117;
    flights[4].from = 3;
    flights[4].destination = 1;
    flights[4].date = 20231207;
    flights[4].time = 0;
    flights[4].price = 51000;
    flights[4].adultCapacity = 100;
    flights[4].childCapacity = 60;
    flights[4].adultTicketsSold = 22;
    flights[4].childTicketsSold = 11;
    flights[4].totalRevenue = 330000;

    flights[5].flightID = 221;
    flights[5].from = 2;
    flights[5].destination = 4;
    flights[5].date = 20231210;
    flights[5].time = 1;
    flights[5].price = 30000;
    flights[5].adultCapacity = 120;
    flights[5].childCapacity = 50;
    flights[5].adultTicketsSold = 35;
    flights[5].childTicketsSold = 25;
    flights[5].totalRevenue = 380000;

    flights[6].flightID = 189;
    flights[6].from = 1;
    flights[6].destination = 2;
    flights[6].date = 20231215;
    flights[6].time = 0;
    flights[6].price = 40000;
    flights[6].adultCapacity = 80;
    flights[6].childCapacity = 45;
    flights[6].adultTicketsSold = 28;
    flights[6].childTicketsSold = 18;
    flights[6].totalRevenue = 290000;

    flights[7].flightID = 511;
    flights[7].from = 0;
    flights[7].destination = 3;
    flights[7].date = 20231218;
    flights[7].time = 2;
    flights[7].price = 28000;
    flights[7].adultCapacity = 150;
    flights[7].childCapacity = 70;
    flights[7].adultTicketsSold = 40;
    flights[7].childTicketsSold = 30;
    flights[7].totalRevenue = 480000;

    flights[8].flightID = 633;
    flights[8].from = 4;
    flights[8].destination = 5;
    flights[8].date = 20231209;
    flights[8].time = 1;
    flights[8].price = 37000;
    flights[8].adultCapacity = 180;
    flights[8].childCapacity = 80;
    flights[8].adultTicketsSold = 45;
    flights[8].childTicketsSold = 30;
    flights[8].totalRevenue = 550000;

    flights[9].flightID = 295;
    flights[9].from = 3;
    flights[9].destination = 2;
    flights[9].date = 20231221;
    flights[9].time = 0;
    flights[9].price = 45000;
    flights[9].adultCapacity = 95;
    flights[9].childCapacity = 55;
    flights[9].adultTicketsSold = 30;
    flights[9].childTicketsSold = 15;
    flights[9].totalRevenue = 360000;
    
    
	printf("\t FLIGHT MANAGEMENT SYSTEM\n");
    do
    {
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp("admin", username) == 0 && strcmp("password", password) == 0) {
            do
            {
                printf("Welcome Admin\n");
                printf("Choose your option\n");
                printf("0:Add flight\n1:Update existing flight\n2:Display all flights\n3:Sign Out\n");
                printf("Enter choice: ");
                scanf("%d", &operation);
                switch (operation)
                {
                case 0:
                    flightCount++;
                    addFlight(&flights[flightCount - 1]);
                    break;
                case 1:
                    printf("Enter index of flight you wish to modify: ");
                    scanf("%d",&x);
                    updateFlight(&flights[x]);
                    break;
                case 2:
                    displayFlights(flights,flightCount,0);
                    break;
                case 3:
                    stoppingCondition2=1;
                    break;
                default:
                    stoppingCondition2=1;
                    break;
                }
                if(stoppingCondition2!=1){
                printf("Press 0 to continue, 1 to signout: ");
                scanf("%d",&stoppingCondition2); 
                }
            } while (stoppingCondition2==0);
            printf("Press 0 to sign in again, 1 to terminate program: ");
            scanf("%d",&stoppingCondition);
        }
        else{
            do
            {
                printf("Welcome\n");
                printf("Choose your option\n");
                printf("0:View Flight Schedule\n1:Book flight\n2:Sign Out\n");
                printf("Enter choice: ");
                scanf("%d",&operation);
                switch (operation)
                {
                case 0:
                    displayFlights(flights,flightCount,1);
                    break;
                case 1:
                    bookFlights(flightCount,flights);
                    break;
                case 2:
                    stoppingCondition2=1;
                    break;
                default:
                    stoppingCondition2=1;
                    break;
                }
            } while (stoppingCondition2 == 0);
            printf("Press 0 to sign in again, 1 to terminate program: ");
            scanf("%d",&stoppingCondition);
        }
    } while (stoppingCondition == 0);  
    }
