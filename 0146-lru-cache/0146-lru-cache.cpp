class Node
{
   public:
   int data ; 
   Node * next ; 
   Node * prev ;
   Node(int data)
   {
      this->data = data ;
      next=NULL ;
      prev=NULL ;
   }
};
//         /\/\/\/\/\/\/\/made by sashrik /\/\/\/\/\/\/\/\/\/
class LRUCache {
private:

    //declaration of all the elements used in the class
    Node* lru;   // declaring a doubly linked list "recency"
    Node* tail;
    int capacity = 0;
    int size = 0;
    bool gate = true;
    unordered_map<int, int> map;
    unordered_map<int, Node*> address;
    pair<int , int> jugad = {-1 ,-1}; // to handel exceptional cases for capacity = 1 
   
   //private function update for 
   //updating recency linked list accordingly

void update(int key) 
{
    auto recent = address[key];
    
    // Case 1: recent is the tail
    if(tail==recent){return  ;}

    // Case 2: recent is in between somewhere
    if (recent->next != NULL && recent->prev != NULL)
    {
        recent->next->prev = recent->prev;
        recent->prev->next = recent->next;

        tail->next = recent;
        recent->prev = tail;
        tail = tail->next;
        
        // Set the next pointer of the new tail to NULL
        tail->next = NULL;
    }

    // Case 3: recent is the current lru
    if (recent->prev == NULL)
    {
        if (lru == recent)
        {
            lru = lru->next;
            if (lru != NULL) 
            {lru->prev = NULL;}
        }
        tail->next = recent;
        recent->prev = tail;
        recent->next = NULL;
        tail = recent ; 
    }
}


public:
    //intialisation of int capacity 
    LRUCache(int capacity) {
        this->capacity = capacity;
    }


int get(int key) {

        //exceptional case for capacity = 1 ;
        if(capacity==1)
        {
            if(key == jugad.first) return jugad.second ; 
            else return -1 ;
        }
    
    // 2 step process for getting an element 
    //   step 1 : update the recency list accordingly 
    //   step 2 : return the value needed
    if (map.find(key) != map.end()) {update(key);return map[key];}

    // if nothing satisfied return -1 ;
    return -1; 
}

void put(int key, int value)
{
    //exceptional case for capacity = 1 ;
    if (capacity == 1){jugad = {key, value};return;}

    // 2 step process if element exists
    // update recency list 
    // update the value of key 
    if (map.find(key) != map.end())
    {
        update(key);
        map[key] = value;
        return ;
    }
    

    //process if element does not exists
    else
    {
        // Initialization of node
        Node* newnode = new Node(key);
        // Storing address
        address[key] = newnode;

        // for cases where current size is less than capacity 
        // fill the cache and recency list till hiting capacity 

        if (size <= capacity - 1 && gate)
        {
            // Initialization of linked list
            if (size == 0){lru = newnode; tail = newnode;}

            // Doubly linking the list
            else
            {   
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;     
            }
            map[key] = value;
            if (size == capacity - 1){gate = false;}
            if (size < capacity - 1){size++;}
        }

        // for cases where current size is equal to capacity     
        // 2 step process
        // deleting the least recent used element 
        // inserting the new element 

        else if (size == capacity - 1 && !gate)
        {
            map.erase(lru->data);
            // Erasing address of lru
            address.erase(lru->data);
            auto temp = lru;
            // Updating lru
            lru = lru->next;
            if (lru != nullptr)
            {
                lru->prev = nullptr;
            }
            // Deleting the (lru) temp
            temp->next = nullptr;
            // Doubly linking the newnode
            tail->next = newnode;
            newnode->prev = tail;
            // Updating the tail node
            tail = newnode;
            map[key] = value;
        }

    }
}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */