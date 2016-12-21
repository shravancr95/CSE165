using namespace std;
class Monitor{
public:
    static int count;
    
    void incident(){
        count++;
    }
    
    void print(){
        cout << count <<  " incidents" << endl;
    }
};
