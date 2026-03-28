struct Node {
    int key,val,cnt;
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

struct List {
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

    void addfront (Node* node) {
        Node* temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
        size++;
    }

    void deletenode (Node* node) {
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        size--;
    }
};

class LFUCache {
public:
    int limit;
    int minfreq;
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqlistmap;
    LFUCache(int capacity) {
        limit=capacity;
        minfreq=0;
    }
    
    void updateListMap (Node* node) {
        keyNode.erase(node->key);
        freqlistmap[node->cnt]->deletenode(node);
        if (node->cnt==minfreq && freqlistmap[node->cnt]->size==0) {
            minfreq++;
        }
        List* nextfreqlistmap= new List();
        if (freqlistmap.find(node->cnt+1) != freqlistmap.end()) {
            nextfreqlistmap=freqlistmap[node->cnt+1];
        }
        node->cnt+=1;
        nextfreqlistmap->addfront(node);
        freqlistmap[node->cnt]=nextfreqlistmap;
        keyNode[node->key]=node;
    }

    int get(int key) {
        if (keyNode.find(key)!=keyNode.end()) {
            Node* node=keyNode[key];
            int val=node->val;
            updateListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node=keyNode[key];
            node->val=value;
            updateListMap(node);
        }
        else {
            if ((int)keyNode.size()==limit) {
                List* currlist=freqlistmap[minfreq];
                keyNode.erase(currlist->tail->prev->key);
                currlist->deletenode(currlist->tail->prev);
            }
            minfreq=1;
            Node* node=new Node(key,value);
            List* list=new List();
            if (freqlistmap.find(minfreq)!=freqlistmap.end()) {
                list=freqlistmap[minfreq];
            }
            list->addfront(node);
            keyNode[key]=node;
            freqlistmap[minfreq]=list;
        }
       
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */