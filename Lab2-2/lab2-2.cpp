#include <stdio.h> 

int main(void) {
	char name1[9], name2[9], name3[9]; 
	char tp1, tp2, tp3; 
	unsigned int amnt1, amnt2, amnt3; 
	unsigned long int wg1, wg2, wg3;
	
	printf("1. Enter: name, type, amount, weight of 1 part (g) >"); 
	scanf("%s %c %u %u", name1, &tp1, &amnt1, &wg1);
	
	printf("2. Enter: name, type, amount, weight of 1 part (g) >");
	scanf("%s %c %u %u", name2, &tp2, &amnt2, &wg2); 
	
	printf("3. Enter: name, type, amount, weight of 1 part (g) >");
	scanf("%s %c %u %u", name3, &tp3, &amnt3, &wg3);
	
	printf("--------------------------------------------------\n");
	printf("|Details information                             |\n");
	printf("|------------------------------------------------|\n");
	printf("|  Name   | Type | Amount | Weight of 1 part (g) |\n");
	printf("|---------|------|--------|----------------------|\n");
	
	printf("| %9s | %c | %u | %u |\n", name1, tp1, amnt1, wg1); 
	printf("| %9s | %c | %u | %u |\n", name2, tp2, amnt2, wg2);
	printf("| %9s | %c | %u | %u |\n", name3, tp3, amnt3, wg3);
	
	printf("|---------------------------------------------|\n"); 
	printf("| Note: the following type coding is adopted: |\n");
	printf("| O - original, P - purchased, B - borrowed   |\n"); 
	printf("-----------------------------------------------\n"); 
	
	return 0; 

} 
