#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"


// make tests to check if carry 
void ctests(int tno, char* result,char *expected)
{
    printf("Test %d - ",tno);
    if(!result || 0 != strcmp(result, expected)) {
		printf("FAILED.\n");
        printf("Your Answer: %s\nExpected Answer: %s\n",result,expected);
	}
    else
    {
        printf("PASS.\n");
    }
}

void itests(int tno, int result,int expected)
{
    printf("Test %d - ",tno);
    if(result != expected) {
		printf("FAILED.\n");
        printf("Your Answer: %d\nExpected Answer: %d\n",result,expected);
	}
    else
    {
        printf("PASS.\n");
    }
}





int main(int argc, char const *argv[]) {
	int n = 12;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
	char *result1;
	int index1;

    //Intal Add Tests
    printf("\n*********************\n");
	printf("intal_add\n\nBase Test\n");

    result1 = intal_add(a[0], a[1]);
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
		}
		free(result1);
	}
	printf("\nCustom Tests\n");
    result1 = intal_add("10", "12");
    ctests(1,result1,"22");

    result1 = intal_add("99", "2");
    ctests(2,result1,"101");

    result1 = intal_add("999", "1");
    ctests(3,result1,"1000");

    result1 = intal_add("1", "999");
    ctests(4,result1,"1000");

    result1 = intal_add("9000000000", "900000000000000000000");
    ctests(5,result1,"900000000009000000000");

    result1 = intal_add("0", "0");
    ctests(6,result1,"0");
    
    printf("\n*********************\n");
	printf("intal_compare\nBase Test\n");

    index1 = intal_compare(a[0], a[1]);
	if(-1 == index1) {
		printf("Test intal_compare PASSED\n");
	} else {
		printf("Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

    printf("\nCustom Tests\n");
    index1 = intal_compare("4567", "9876");
    itests(1,index1,-1);
    index1 = intal_compare("9876", "4567");
    itests(2,index1,1);
    index1 = intal_compare("99999", "9999");
    itests(3,index1,1);
    index1 = intal_compare("999", "999");
    itests(4,index1,0);


    printf("\n*********************\n");
	printf("intal_diff\nBase Test\n");
    result1 = intal_diff(a[0], a[1]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

    printf("\nCustom Tests\n");
    result1 = intal_diff("12", "10");
    ctests(1,result1,"2");

    result1 = intal_diff("99", "99");
    ctests(2,result1,"0");

    result1 = intal_diff("1000", "1");
    ctests(3,result1,"999");

    result1 = intal_diff("10", "9");
    ctests(4,result1,"1");

    result1 = intal_diff("0", "0");
    ctests(5,result1,"0");




	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}