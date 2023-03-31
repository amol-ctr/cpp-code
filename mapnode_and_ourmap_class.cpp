#include<iostream>
#include<string>
using namespace std;

template<typename T>
class MapNode{
    public:
    string key;
    T value;
    MapNode<T>* next;       // HEAD OF THE LINKED LIST CONTAINING KEY VALUE PAIR IN MAPS

    MapNode(string key,T value){
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template<typename T>
class ourmap{
    MapNode<T>* buckets;   // BUCKET ARRAY
    int count;             // TOTAL KEY-VALUE PAIRS IN BUCKET ARRAY
    int numBuckets;        // TOTAL SIZE ASSIGNED TO BUCKET ARRAY

    public:
    ourmap(){
        count=0;
        numBuckets=5;                           // TOTAL 5 SIZE IS ASSIGNED TO BUCKET ARRAY
        buckets= new MapNode<T>*[numBuckets]; 

        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }

    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size(){
        return count;
    }

    private:
    int getBucketIndex(key){         // HERE 'p' IS TAKEN AS 37(PRIME NUMBER)
        int coeff=1;
        int hashcode=0;
        for(int i=key.length()-1;i>=0;i--){
            hashcode+=key[i]*coeff;
            hashcode=hashcode%numBuckets;
            coeff *=37;
            coeff=coeff%numBuckets;
        }
        return hashcode%numBuckets;        // COMPRESSION IN HASH FUNCTION
    }
    private:
    void rehash(){
        MapNode<T>** temp=buckets;
        buckets=new MapNode<T>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldBucketNumber=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldBucketNumber;i++){
            MapNode<T>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                T value=head->value;
                insert(key,value);
                head=head->next;
            }
        }

        for(int i=0;i<oldBucketNumber;i++){
            delete temp[i];
        }
        delete[] temp;
    }

    public:
    void insert(string key,T value){
        int bucketIndex=getBucketIndex(key);
        MapNode<T>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key=key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<T>* node=new MapNode<T>(key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadfactor=((1.0)*count)/numBuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }

    T remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<T>* head=buckets[bucketIndex];
        MapNode<T>* prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    prev=head->next;
                }
                else{
                    prev->next=head->next;
                }
                head->next=NULL;
                T value=head->value;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return NULL;
    }

    T getValue(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<T>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return NULL;
    }

};

int main(){

    ourmap<int> map;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c; 
        int value=i+1;
        map.insert(key,value);
    }
    return 0;
}