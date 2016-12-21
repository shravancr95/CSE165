class Fib{
public:
    static int last;
    static int secondLast;
    
    int next(){
        int term = last + secondLast;
        secondLast = last;
        last = term;
        return term;
    }
    
    int next(bool condition){
        int term;
        if(condition == true){
            secondLast = 1;
            last = 1;
            return last;
        }
        else{
            term = last + secondLast;
            secondLast = last;
            last = term;
            return term;
        }
    }

};
