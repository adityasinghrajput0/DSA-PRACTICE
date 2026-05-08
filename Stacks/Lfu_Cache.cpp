struct Node {
    int key,val,cnt;  //cnt variable is used here to track use counter of each cache.
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
        cnt=1;
    }
};

struct List { //a doubly linked list is created to maintain cache with same used counter.
    int size;
    Node* head;
    Node* tail;
    List () {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addfront (Node* node) { //add front function, whenever you add a new node the size of list will increase.
        Node* temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
        size++;
    }

    void deletenode (Node* node) { //deletenode function, whenever you delete a node the size of list will decrease.
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        size--;
    }
};

class LFUCache {
public:
    int limit; //store capacity of cache 
    int minfreq; //it records the minimum use counter value.
    unordered_map<int,Node*> keyNode; //stores key and corresponding node.
    unordered_map<int,List*> freqlistmap; //stores use counter as key and a doubly linked list to maintain nodes with
    // same use counter value
    LFUCache(int capacity) {
        limit=capacity;
        minfreq=0;
    }
    
    void updateListMap (Node* node) { //whenever we access a node , we have to perform this function
        keyNode.erase(node->key); //as we are changing structure of list, just to be on safe side we are removing
        //key node pair from map and then again insert it to map after performing all the operations;
        freqlistmap[node->cnt]->deletenode(node); //delete accessed node from current list;
        if (node->cnt==minfreq && freqlistmap[node->cnt]->size==0) { //if the deleted node was the last node present in 
            // minfreq list then increase the minfreq value;
            minfreq++;
        }
        List* nextfreqlistmap= new List(); //creating a new list to add current accessed node as its use counter has been
        // increased;
        if (freqlistmap.find(node->cnt+1) != freqlistmap.end()) { //if there exists a list which has same value as node's
            // use counter update nexfreqlist to existing one.
            nextfreqlistmap=freqlistmap[node->cnt+1];
        }
        node->cnt+=1; //increase the node's use counter
        nextfreqlistmap->addfront(node); //add current node to nextfreqlist;
        freqlistmap[node->cnt]=nextfreqlistmap; //insert the list in freqlistmap;
        keyNode[node->key]=node; //insert the removed node key node map
    }

    int get(int key) {
        if (keyNode.find(key)!=keyNode.end()) { //if the key exists return its value, but before returning
            // update the list map as key is accessed so its use counter has been increased;
            Node* node=keyNode[key];
            int val=node->val;
            updateListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keyNode.find(key) != keyNode.end()) { //if key exists already just update its value and update the list;
            Node* node=keyNode[key];
            node->val=value;
            updateListMap(node);
        }
        else {
            if ((int)keyNode.size()==limit) { //if limit has reached remove lfu from minfreq list
                List* currlist=freqlistmap[minfreq];
                keyNode.erase(currlist->tail->prev->key);
                currlist->deletenode(currlist->tail->prev);
            }
            minfreq=1; // reset minfreq to 1 before inserting new node;
            Node* node=new Node(key,value);
            List* list=new List();
            if (freqlistmap.find(minfreq)!=freqlistmap.end()) { //if the list with minfreq already exists update list to the
                //existing list;
                list=freqlistmap[minfreq];
            }
            list->addfront(node); //add node in front of list;
            keyNode[key]=node; // insert the current node to keynode map;
            freqlistmap[minfreq]=list; // insert or update the list in freqlist map;
        }
       
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */