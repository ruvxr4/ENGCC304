#include <stdio.h> 

double getBaseSalary(int position); 
double calculateExperienceBonus(double baseSalary, int years); 
double calculateSpecialBonus(double baseSalary, int projects); 
void displayResults(double baseSalary, double expBonus, double specialBonus); 

int main() { 
    int positionChoice; 
    int yearsOfExperience; 
    int completedProjects; 

    printf("Enter your position:\n"); 
    printf("  1: Junior Programmer\n");
    printf("  2: Mid-Level Programmer\n"); 
    printf("  3: Senior Programmer\n"); 
    printf("Your choice: "); 
    scanf("%d", &positionChoice); 

    printf("Enter years of experience: "); 
    scanf("%d", &yearsOfExperience); 

    printf("Enter number of completed projects this year: ");
    scanf("%d", &completedProjects); 

    double baseSalary = getBaseSalary(positionChoice); 
    double experienceBonus = calculateExperienceBonus(baseSalary, yearsOfExperience); 
    double specialBonus = calculateSpecialBonus(baseSalary, completedProjects); 

    displayResults(baseSalary, experienceBonus, specialBonus); 

    return 0; 
} // end main


double getBaseSalary(int position) { 
    double salary = 0.0; 
    switch (position) {
        case 1: 
            salary = 20000.0; 
            break; 
        case 2: 
            salary = 35000.0; 
            break; 
        case 3: 
            salary = 50000.0; 
            break; 
        default: 
            printf("Invalid position choice. Setting base salary to 0.\n"); 
            salary = 0.0; 
            break; 
    } 
    return salary;
} // end getBaseSalary fuction

double calculateExperienceBonus(double baseSalary, int years) { 
    double bonusPercentage = 0.0; 
    if (years > 5) { 
        bonusPercentage = 0.20; 
    } else if (years >= 4) { 
        bonusPercentage = 0.15; 
    } else if (years >= 1) { 
        bonusPercentage = 0.10; 
    } //end if-else
    return baseSalary * bonusPercentage; 
} // end calculateExperienceBonus fuction

double calculateSpecialBonus(double baseSalary, int projects) { 
    if (projects > 5) { 
        return baseSalary * 0.05; 
    } // end if
    return 0.0; 
} // end calculateSpecialBonus fuction

void displayResults(double baseSalary, double expBonus, double specialBonus) { 
    double netSalary = baseSalary + expBonus + specialBonus; 

    printf("----------- Calculation Result -----------\n"); 
    printf("Base Salary:        %.2f THB\n", baseSalary); 
    printf("Experience Bonus:   %.2f THB\n", expBonus); 
    printf("Special Bonus:      %.2f THB\n", specialBonus); 
    printf("----------------------------------------\n"); 
    printf("Net Salary:         %.2f THB\n", netSalary); 
    printf("----------------------------------------\n"); 
} // end displayResults fuction