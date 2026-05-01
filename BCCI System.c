#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 


void IncomeTax(float monthly_salary);
void SSS(float monthly_salary); 
float pag_ibig(float monthly_salary);  
void PhilHealth(float monthly_salary);  

void inquiryproc();

void title_screen();
void transac_complete();

int main() 
{
    int screen_effect = 1, countdown = 5, percent_screen = 0;
    title_screen();
    
    //Loading Screen 
    while (countdown!=0) 
    {
        if (screen_effect) 
        {
        system("clear");
        title_screen();
        printf("\n\t\t\t\t    Loading %d%     \n", percent_screen ) ;
        } else
        {
            system("clear");
            title_screen();
            
            //5 second duration
            countdown-=1;
            percent_screen += 20;
        printf("\n\t\t\t\t    Loading %d%     \n", percent_screen ) ;
        }
        screen_effect = !screen_effect;
        sleep(1);
    }
    //Main Menu 
    system("clear");
    title_screen();
    printf("\t\t\t\t    Enter 1 to continue     \n");
    printf("\t\t\t\t  Enter any number to exit  \n");
    inquiryproc();
    return 0;
}
// Inquiry Process Function 
void inquiryproc()
{
    char name_of_employee[50], company_name[50] , inquiryPrompt;
    float monthly_salary;
    int monthlySalaryCheck, monthlySalaryFlagCheck = 0, ui_count;
    printf("\t\t               \n");
        scanf("%d", &ui_count);
        getchar();
    if (ui_count ==1)
    {
        system("clear");
    do 
        {
            system("clear");
            printf("<=======================|BCCI System|=======================>\n");
            printf("Enter you name: ");
            fgets(name_of_employee, sizeof(name_of_employee), stdin);
            name_of_employee[strcspn(name_of_employee, "\n")] = 0;
            printf("Enter the name of the Company you are working on: ");
            fgets(company_name, sizeof(company_name), stdin);
            company_name[strcspn(company_name, "\n")] = 0;
            do {
                monthlySalaryCheck = 1;
                printf("Monthly Salary: Php ");
                if (scanf("%f", &monthly_salary) != 1) 
                    {
                    printf("Error: Invalid input. Please enter a valid number.\n");
                    monthlySalaryCheck = 0; 
                    monthlySalaryFlagCheck = 1; 
                    while (getchar() != '\n'); 
                    }
                } while (!monthlySalaryCheck);
            system("clear");
            printf("<=======================|BCCI System|=======================>\n");
            printf("                       Inquiry Results                       \n");
            printf("Name of Employee:\t\t\t%s\n", name_of_employee);
            printf("Name of Company:\t\t\t%s\n", company_name);
            printf("Monthly Salary:\t\t\t\tPhp %.2f\n\n", monthly_salary);
            printf("Monthly Dues\n\n");
            IncomeTax(monthly_salary);
            SSS(monthly_salary);
            printf("Pag-ibig Contribution: \t\t\tPhp %.2f\n", pag_ibig(monthly_salary));
            PhilHealth(monthly_salary);
            printf("<====================|©Rustico Eric III|====================>\n");
            printf("\n\nAnother Inquiry? (Y/N): ");
            scanf(" %c", &inquiryPrompt);
            while (getchar() != '\n');
        }   while (inquiryPrompt == 'Y' || inquiryPrompt == 'y');
    system("clear");
    transac_complete();
    } 
    else 
    {
    system("clear");
    transac_complete();
    } 
}

//Income Tax Function 
void IncomeTax(float monthly_salary) 
{
    float monthlyIncomeTax, annualSalary;
    annualSalary = monthly_salary * 12;
    
    //Annual Salary Range
    if (annualSalary < 250000) 
        printf("No expected Tax due.\n");
    else if (annualSalary >= 250000 && annualSalary < 400000) 
        {
        monthlyIncomeTax = ((annualSalary - 250000) * 0.20)/12;
        printf("Expected Tax Due: \t\t\tPhp %.2f\n", monthlyIncomeTax);
        } 
    else if (annualSalary >= 400000 && annualSalary < 800000) 
        {
        monthlyIncomeTax = ((annualSalary - 400000) * 0.25 + 30000)/12;
        printf("Expected Tax Due: \t\t\tPhp %.2f\n", monthlyIncomeTax);
        } 
    else if (annualSalary >= 800000 && annualSalary < 2000000) 
        {
        monthlyIncomeTax = ((annualSalary - 800000) * 0.30 + 130000)/12;
        printf("Expected Tax Due: \t\t\tPhp %.2f\n", monthlyIncomeTax);
        } 
    else if (annualSalary >= 2000000 && annualSalary < 8000000) 
        {
        monthlyIncomeTax = ((annualSalary - 2000000) * 0.32 + 490000)/12;
        printf("Expected Tax Due: \t\t\tPhp %.2f\n", monthlyIncomeTax);
        } 
    else if (annualSalary >= 8000000) 
        {
        monthlyIncomeTax = ((annualSalary - 8000000) * 0.35 + 2410000)/12;
        printf("Expected Tax Due: \t\t\tPhp %.2f\n", monthlyIncomeTax);
        }
}

//SSS Function 
void SSS(float monthly_salary) 
{
    float sssMinimumSalaryRange = 2250.00, sssMaximumSalaryRange = 2749.00, sssAddContribution = 80.00;
        while (monthly_salary > sssMaximumSalaryRange && sssMinimumSalaryRange != 19750.00) 
        {
            sssMinimumSalaryRange += 500;
            sssMaximumSalaryRange += 500;
            sssAddContribution += 20;
        }
        if (sssMinimumSalaryRange = 19750)
            sssAddContribution += 20.00;
        printf("SSS Contribution: \t\t\tPhp %.2f\n", ee);
}

//Pag-Ibig Function 
float pag_ibig(float monthly_salary) 
{
    return monthly_salary < 1500 ? monthly_salary * 0.01 : monthly_salary * 0.02;
}

//PhilHealth Function 
void PhilHealth(float monthly_salary) 
{
    float philHealthMinimumSalaryRange = 8999.99, philHealthMaximumSalaryRange = 9000.00, philHealthAddContribution = 100.00;
    while (philHealthMinimumSalaryRange < monthly_salary && philHealthMaximumSalaryRange != 35000) 
        {
            philHealthAddContribution += 12.50;
            philHealthMinimumSalaryRange += 1000.00;
            philHealthMaximumSalaryRange += 1000.00;
        }
        if (philHealthMaximumSalaryRange = 35000)
            philHealthAddContribution += 12.50;
            
        printf("PhilHealth Contribution: \t\tPhp %.2f\n", es);
}

void title_screen()
{
    printf("\t\t\t  ________   ________    ________    __  \n");
    printf("\t\t\t |    _   | |        |  |        |  |  |\n");
    printf("\t\t\t |   |_|  | |   |____|  |   |____|  |  |\n");
    printf("\t\t\t |    _  -  |    ____   |    ____   |  |\n");
    printf("\t\t\t |   |_|  | |   |    |  |   |    |  |  |\n");
    printf("\t\t\t |________| |________|  |________|  |__|\n");
    printf("\n");
    printf("\t\t\t   他人に奉仕する || 共通の利益のために\n");
    printf("\t\t\t  ____         ____  _____  ____   __ __   \n");
    printf("\t\t\t |____  |___| |____    |   |___   |  |  |\n");
    printf("\t\t\t  ____|     |  ____|   |   |____  |     |\n ");
    printf("                                          \n");
    printf("\t\t(づ ᴗ _ᴗ)づ♡| Rustico Eric E. Talaugon III - BSCPE-1|(˶˃ ᵕ ˂˶)\n");
    printf("                                           \n");
}


void transac_complete()
{
    printf("<========================|BCCI System|=========================>\n");
    printf("\n(づ ᴗ _ᴗ)づ♡|Transaction Completed. Please come again.|(˶˃ ᵕ ˂˶)\n");
    printf("\n<====================|©Rustico Eric III|=======================>\n");
}












