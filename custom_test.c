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
	free(result);
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

	result1 = intal_diff("1", "1000");
    ctests(6,result1,"999");

	result1 = intal_diff("0", "1234567890123456789012345678901234567890");
    ctests(7,result1,"1234567890123456789012345678901234567890");


	printf("\n*********************\n");
	printf("intal_multiply\nBase Test\n");
    result1 = intal_multiply(a[8], a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "65185851858518585185851852")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\n.Your answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
		}
		free(result1);
	}

    printf("\nCustom Tests\n");
    result1 = intal_multiply("12", "10");
    ctests(1,result1,"120");

    result1 = intal_multiply("0", "0");
    ctests(2,result1,"0");

    result1 = intal_multiply("0", "4567865478654787654789654367897654367897654367689876543678765");
    ctests(3,result1,"0");

    result1 = intal_multiply("12345", "45");
    ctests(4,result1,"555525");

    result1 = intal_multiply("731", "23");
    ctests(5,result1,"16813");

	result1 = intal_multiply("1", "9");
    ctests(6,result1,"9");

	result1 = intal_multiply("1001", "99");
    ctests(7,result1,"99099");


	printf("\n*********************\n");
	printf("intal_fibonacci\nBase Tests\n");
	result1 = intal_fibonacci(3);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1000);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
		}
		free(result1);
	}

	printf("\nCustom Tests\n");
    result1 = intal_fibonacci(0);
    ctests(1,result1,"0");

    result1 = intal_fibonacci(1);
    ctests(2,result1,"1");

	result1 = intal_fibonacci(2);
    ctests(3,result1,"1");

	result1 = intal_fibonacci(250);
    ctests(4,result1,"7896325826131730509282738943634332893686268675876375");

	result1 = intal_fibonacci(43);
    ctests(5,result1,"433494437");


	printf("\n*********************\n");
	printf("intal_factorial\nBase Tests\n");

	result1 = intal_factorial(30);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[6])) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(100);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}

	printf("\nCustom Tests\n");
    result1 = intal_factorial(0);
    ctests(1,result1,"1");

    result1 = intal_factorial(1);
    ctests(2,result1,"1");

	result1 = intal_factorial(2);
    ctests(3,result1,"2");

	result1 = intal_factorial(12);
    ctests(4,result1,"479001600");



	printf("\n*********************\n");
	printf("intal_bincoeff\nBase Tests\n");
	result1 = intal_bincoeff(10, 8);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "45")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "45");
		}
		free(result1);
	}

	result1 = intal_bincoeff(1000, 900);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890");
		}
		free(result1);
	}


	printf("\nCustom Tests\n");
    result1 = intal_bincoeff(1000,1000);
    ctests(1,result1,"1");

    result1 = intal_bincoeff(1000,0);
    ctests(2,result1,"1");

	result1 = intal_bincoeff(0,0);
    ctests(3,result1,"1");

	result1 = intal_bincoeff(1,0);
    ctests(4,result1,"1");

	result1 = intal_bincoeff(10,1);
    ctests(5,result1,"10");

	result1 = intal_bincoeff(50,6);
    ctests(6,result1,"15890700");


	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}
