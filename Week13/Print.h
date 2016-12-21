//#include <cstdlib>
using namespace std;

/*template <class T>
class Print{
public:
    void print(T const& t, int size);
};*/

template <class T>
void print(T t, int size){
    for(int i = 0; i < size; i++){
        cout << t[i] << " ";
    }
    cout << endl;
}
