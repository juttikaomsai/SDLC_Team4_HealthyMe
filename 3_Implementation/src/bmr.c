#include<essentials.h>

ret_code_t calcBMR(member *p, int n) 
{	
    if(p==NULL)
        return NULL_PTR;
    
	//Variables
	int g,a;
	double weight,height,bmr;
	g = (p+n)->gender;
	a = (p+n)->age;
	if((p+n)->unit == 1)
	{
		weight = (p+n)->w;
		height = (p+n)->h;
        if(weight>150 || height>250)
        {
            return INCONSISTENT_DATA;
        }
	}
	else
	{
		weight = ((p+n)->w)*0.45359237;
		height = ((p+n)->h)*30.48;
        if(weight>150 || height>250)
        {
            return INCONSISTENT_DATA;
        }
	}
	bmr = 0;

	if (g == 1) {
		bmr = (10*weight) + (6.25*height) - (5*a) - 161;
	}
	else if (g == 2) {
		bmr = (10*weight) + (6.25 * height) - (5*a) + 5;
	}
	//Print
	printf( "You have a Basal Metabolic Rate (BMR) of:%lf ",bmr);
	printf(" calories per day.\n");
	return SUCCESS;
}