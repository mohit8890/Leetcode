class SeatManager {
public:
    int seats;
    int last_reserved = 0;
    set<int> unreserved;
    SeatManager(int n) {
        this->seats = n;
    }
    
    int reserve(){
        if(!unreserved.empty()){
            int val = *unreserved.begin();
            unreserved.erase(val); //erase the beginning val of the set because it's now being reserved again
            return val;
        } 
        last_reserved += 1;
        return last_reserved;
    }
    
    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber); //add the newly unreserved val because it can be reserved again
    }
};