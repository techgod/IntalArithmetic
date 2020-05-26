#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

int pcount,fcount;

// make tests to check if carry 
void ctests(int tno, char* result,char *expected)
{
    printf("Test %d - ",tno);
    if(!result || 0 != strcmp(result, expected)) {
		printf("FAILED.\n");
        printf("Your Answer: %s\nExpected Answer: %s\n",result,expected);
		++fcount;
	}
    else
    {
        printf("PASS.\n");
		++pcount;
    }
	free(result);
}

void itests(int tno, int result,int expected)
{
    printf("Test %d - ",tno);
    if(result != expected) {
		printf("FAILED.\n");
        printf("Your Answer: %d\nExpected Answer: %d\n",result,expected);
		++fcount;
	}
    else
    {
        printf("PASS.\n");
		++pcount;
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
	printf("intal_mod\nBase Tests\n");

	
	result1 = intal_mod(a[3], a[4]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	
	result1 = intal_mod("978", "5");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}
	


	
	result1 = intal_mod(a[0], a[5]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "9")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
		}
		free(result1);
	}
	


 	printf("\nCustom Tests\n");
    result1 = intal_mod("12", "10");
    ctests(1,result1,"2");

	result1 = intal_mod("12", "12");
    ctests(2,result1,"0");

	result1 = intal_mod("1", "12");
    ctests(2,result1,"1");

	result1 = intal_mod("13", "12");
    ctests(3,result1,"1");

	result1 = intal_mod("100000000000000000000000000", "10");
    ctests(4,result1,"0");

	result1 = intal_mod("1234567898765432", "23345676543543456");
    ctests(5,result1,"1234567898765432");


	result1 = intal_mod("5485743258475748273548732587432875758942375847235847254890723854702385784293753827584732895748325740827584676715489257425674892674875894705273485678436561874817584738758784371584310758439170584319758347584758947158974875476485740175841074328975843105748137458467843975843107510578417185748375483290758436584375846510896584375817408134798574893257684362547632578461759674863157647561095640509415674615750157647831561756413756843156138096784397584310751057841718574837548329075843658437584651089658437581740813479857489325768436254763257846175967486315764756109564050548732052089754892768297350823750843275894078328597438297510574328975448936789321573980127501937875892750832475481390759831257381927589378203", "76843625476325784617596748631576475610956405054873205208975489276829735082375084327589407832859743829751057432897544893678932157398012750193787589275083247548139075983125738192758937452375874329587432856472365743627523945432015367564327854647320564732564736573248");
	ctests(6,result1,"6745592845074042758050336179214847982127235696391047009999027698134925987445509261599801651598156933137843371719215878285029944889346142501291925415531320146024800732959059576926722380013672792040484448841650176640673892922708805408958509189858278475560819015643");

	result1 = intal_mod("0", "1");
    ctests(7,result1,"0");

	printf("\n*********************\n");
	printf("intal_pow\nBase Tests\n");

	result1 = intal_pow(a[5], 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1728")) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
		}
		free(result1);
	}

	result1 = intal_pow("10", 999);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[10])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
		}
		free(result1);
	}

	result1 = intal_pow("2", 3000);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[11])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
		}
		free(result1);
	}

	printf("\nCustom Tests\n");
    result1 = intal_pow("12",2);
    ctests(1,result1,"144");

	result1 = intal_pow("0", 0);
    ctests(2,result1,"0");

	result1 = intal_pow("13", 1);
    ctests(3,result1,"13");

	result1 = intal_pow("354678987654356781", 0);
    ctests(4,result1,"1");

	result1 = intal_pow("1", 1);
    ctests(5,result1,"1");

	result1 = intal_pow("1", 14567);
    ctests(6,result1,"1");

	result1 = intal_pow("678", 4);
    ctests(7,result1,"211309379856");
	

	printf("\n*********************\n");
	printf("intal_gcd\nBase Tests\n");

	result1 = intal_gcd(a[0], a[5]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}


	printf("\nCustom Tests\n");
    result1 = intal_gcd("10","15");
    ctests(1,result1,"5");

	result1 = intal_gcd("35", "10");
    ctests(2,result1,"5");

	result1 = intal_gcd("31", "2");
    ctests(3,result1,"1");

	result1 = intal_gcd("1", "1");
    ctests(4,result1,"1");

	result1 = intal_gcd("1", "0");
    ctests(5,result1,"1");

	result1 = intal_gcd("0", "2");
    ctests(6,result1,"2");

	result1 = intal_gcd("24325364", "45364021");
    ctests(7,result1,"1");

	//may not be defined, but just incase.
	result1 = intal_gcd("0", "0");
    ctests(8,result1,"0");

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


	printf("\n*********************\n");
	printf("intal_max\nBase Test\n");
	index1 = intal_max(a, n);
	if(10 == index1) {
		printf("Test intal_max PASSED\n");
	} else {
		printf("Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	printf("\nCustom Tests\n");
	char* t1[] = {"10","2"};
    index1 = intal_max(t1,2);
    itests(1,index1,0);

	char* t2[] = {"10","10"};
    index1 = intal_max(t2,2);
    itests(2,index1,0);

	char* t3[] = {"1"};
    index1 = intal_max(t3,1);
    itests(3,index1,0);

	char* t4[] = {"1","2","3","34","0","56","9"};
    index1 = intal_max(t4,7);
    itests(4,index1,5);


	printf("\n*********************\n");
	printf("intal_min\nBase Test\n");
	index1 = intal_min(a, n);
	if(2 == index1) {
		printf("Test intal_min PASSED\n");
	} else {
		printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
	}

	printf("\nCustom Tests\n");
    index1 = intal_min(t1,2);
    itests(1,index1,1);

    index1 = intal_min(t2,2);
    itests(2,index1,0);

    index1 = intal_min(t3,1);
    itests(3,index1,0);

    index1 = intal_min(t4,7);
    itests(4,index1,4);

	printf("\n*********************\n");
	printf("intal_search\nBase Test\n");
	index1 = intal_search(a, n, a[7]);
	if(6 == index1) {
		printf("Test intal_search PASSED\n");
	} else {
		printf("Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	printf("\nCustom Tests\n");
    index1 = intal_search(t1,2,"2");
    itests(1,index1,1);

    index1 = intal_search(t2,2,"10");
    itests(2,index1,0);

    index1 = intal_search(t3,1,"76453225364734523");
    itests(3,index1,-1);

    index1 = intal_search(t4,7,"9");
    itests(4,index1,6);

	printf("\n*********************\n");
	printf("intal_coin_row_problem\nBase Test\n");	
	result1 = coin_row_problem(a, n);
	if(!result1) {
		printf("Test coin_row_problem FAILED.\n");
	} else {
		if(0 == strcmp("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987", result1)) {
			printf("Test coin_row_problem PASSED\n");
		} else {
			printf("Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987");
		}
		free(result1);
	}

	printf("\nCustom Tests\n");
	char* coin_t1[] = {"5", "22", "26", "10", "4", "8"};
	char* coin_t2[] = {"5", "22", "26", "15", "4", "3", "11"};
	char* coin_t3[] = {"5", "22", "26"};
	char* coin_t4[] = {"5"};
	char* coin_t5[] = {"10","10"};
	char* coin_t6[] = {"12","10"};

    result1 = coin_row_problem(coin_t1,6);
    ctests(1,result1,"40");
	result1 = coin_row_problem(coin_t2,7);
    ctests(2,result1,"48");
	result1 = coin_row_problem(coin_t3,3);
    ctests(3,result1,"31");
	result1 = coin_row_problem(coin_t4,1);
    ctests(4,result1,"5");
	result1 = coin_row_problem(coin_t5,2);
    ctests(5,result1,"10");
	result1 = coin_row_problem(coin_t6,2);
    ctests(6,result1,"12");

	printf("\n*********************\n");
	printf("intal_sort\nBase Test\n");
	intal_sort(a, n);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
	printf("\n");

	printf("\nCustom Tests\n");
	
	//char* t1[] = {"10","2"};
	//char* t2[] = {"10","10"};
	//char* t3[] = {"1"};
	//char* t4[] = {"1","2","3","34","0","56","9"};

	intal_sort(t1, 2);
	intal_sort(t2, 2);
	intal_sort(t3, 1);
	intal_sort(t4, 7);
	
	for (int i = 0; i <2; i++) {
		printf("%s ", t1[i]);
	}
	printf("\n");
	for (int i = 0; i < 2; i++) {
		printf("%s ", t2[i]);
	}
	printf("\n");
	for (int i = 0; i < 1; i++) {
		printf("%s ", t3[i]);
	}
	printf("\n");
	for (int i = 0; i < 7; i++) {
		printf("%s ", t4[i]);
	}
	printf("\n");

	printf("\n*********************\n");
	printf("intal_binsearch\nBase Test\n");

	index1 = intal_binsearch(a, n, "3");
	if(1 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
	}

	printf("\nCustom Tests\n");

	index1 = intal_binsearch(t1,2,"2");
    itests(1,index1,0);

    index1 = intal_binsearch(t2,2,"10");
    itests(2,index1,0);

    index1 = intal_binsearch(t3,1,"76453225364734523");
    itests(3,index1,-1);

    index1 = intal_binsearch(t4,7,"9");
    itests(4,index1,4);

	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);

	printf("\n*********************\n");
	printf("Final Result\n");
	printf("Custom Tests\n");
	printf("%d Passed, %d Failed.\n",pcount,fcount);
	return 0;
}
