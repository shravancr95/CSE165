#include <iostream>
#include <iomanip>
#include <math.h>
#include "Time.h"

using namespace std;

int main(int argc, const char * argv[])
{
    float h = 0;
    float m = 0;
    float s = 0;
    
    Time theTime = Time(9, 30, 0);
    theTime.getAngles(h, m, s);
    /*Time theTime2 = Time(9, 30, 0);
    Time theTime3 = Time(9, 30, 30);
    cout << "45" << endl;
    theTime.getAngles(h, m, s);
    cout << "0" << endl;
    theTime2.getAngles(h, m, s);
    cout << "30" << endl;
    theTime3.getAngles(h, m, s);*/
    cout << fixed << showpoint  << setprecision (6) << h << " : " << m << " : " << s << endl;
    
    return 0;
}

