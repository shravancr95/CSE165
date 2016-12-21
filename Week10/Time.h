#include <math.h>
#include <stdlib.h>
using namespace std;

class Time{
    int hours, minutes, seconds;
public:
    Time(int h, int m, int s){
        seconds = s;
        minutes = m;
        hours = h;
    }
    
    int getMinutes(){
        return minutes;
    }
    int getSeconds(){
        return seconds;
    }
    int getHours(){
        return hours;
    }
    void setMinutes(int m){
        minutes = m;
    }
    void setSeconds(int s){
        seconds = s;
    }
    void setHours(int h){
        hours = h;
    }
    void add(const Time&t){
        hours += t.hours;
        minutes += t.minutes;
        seconds += t.seconds;
        if(hours > 24){
            hours -= 23;
        }
        if(minutes > 59){
            minutes -= 59;
            hours ++;
        }
        if(seconds > 59){
            seconds -= 60;
        }
    }
    
    void getAngles(float&a, float&b, float&c){
        float rad_per_interval = M_PI/6.0f;
        //seconds
        if(getSeconds() > 15 && getSeconds() < 45){
            //cout << "should be negative" << endl;
            c = -1*((getSeconds()-15.0f)/60.0f)*M_PI*2;
            //cout << -1*((getSeconds()-15.0f)/60.0f)*M_PI*2 << " degrees" << endl;
        }
        else if ((getSeconds() >= 0 && getSeconds() <= 15)||(getSeconds() >=45 && getSeconds() < 60)){
            int adj_seconds = getSeconds() + 15;
            if(adj_seconds > 59){
                adj_seconds -= 60;
            }
            //cout << "should be positive" << endl;
            c = M_PI - ((adj_seconds)/30.0f)*M_PI;
            //cout << M_PI - ((adj_seconds)/30.0f)*M_PI << endl;
        }
        
        //cout << "seconds: " << c << endl;
        
        //minutes
        
        if(getMinutes() > 15 && getMinutes() < 45){
            //cout << "should be negative" << endl;
            b = -1*((getMinutes()-15.0f)/60.0f)*M_PI*2;
            //cout << -1*((getSeconds()-15.0f)/60.0f)*M_PI*2 << " degrees" << endl;
        }
        else if ((getMinutes() >= 0 && getMinutes() <= 15)||(getMinutes() >=45 && getMinutes() < 60)){
            int adj_minutes = getMinutes() + 15;
            if(adj_minutes > 59){
                adj_minutes -= 60;
            }
            //cout << "should be positive" << endl;
            b = M_PI - ((adj_minutes)/30.0f)*M_PI;
            //cout << M_PI - ((adj_seconds)/30.0f)*M_PI << endl;
        }
        
        float adj_hours = getHours() + getMinutes()/60.0f;
        
        //cout << "adj hours = " << adj_hours << endl;
        
        if(adj_hours > 3 && adj_hours < 9){
            //cout << "should be negative" << endl;
            float scale = (adj_hours + 9);
            if(scale > 11){
                scale -= 12;
            }
            a = -1*(scale/12.0f)*2*M_PI;
            //a = -1*((getHours() - 3)/24.0f)*M_PI*2;
        }
        else if ((adj_hours >= 0 && adj_hours <= 3)||(adj_hours >=9 && adj_hours < 12)){
            //cout << "should be positive" << endl;
            float scale = (adj_hours - 3);
            //cout << "scale = " << scale << endl;
            if (scale > 11){
                scale -= 12;
            }
            if(scale == 0){
                a = 0;
            }
            else{
                a = 2*M_PI - (scale/12.0f)*2*M_PI;
            }
        }
    }
    
    void getHourCoords ( float & x, float& y ){
        float a_h = 0, a_m = 0, a_s = 0;
        getAngles(a_h, a_m, a_s);
        x = cos(a_h);
        y = sin(a_h);
    }
    
    void getMinuteCoords ( float& x, float& y ){
        float a_h = 0, a_m = 0, a_s = 0;
        getAngles(a_h, a_m, a_s);
        x = cos(a_m);
        y = sin(a_m);
    }
    
    void getSecondsCoords ( float& x, float& y ){
        float a_h = 0, a_m = 0, a_s = 0;
        getAngles(a_h, a_m, a_s);
        x = cos(a_s);
        y = sin(a_s);
    }
    

    
};