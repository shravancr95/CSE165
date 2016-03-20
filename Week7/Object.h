class Object{
public:
    static int count;
    Object(){
        count++;
    }
    Object(const Object&o){
        count++;
    }
    
};
