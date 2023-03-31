#include<iostream>
#include<list>
using namespace std;

void display(list<int> &l){
    list<int>:: iterator i1=l.begin();
    for(i1=l.begin();i1 !=l.end();i1++){
        cout<<*i1<<" ";
    } 
    cout<<endl;
} 

int main(){

    list<int> l1;
    int size,element;
    cout<<"enter the size of list: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the element you want to insert: ";
        cin>>element;
        l1.push_back(element);
        
        // For inserting an element from the front
        // l1.push_front(element);
    }
    display(l1);

    // Deleting an element from the back
    // l1.pop_back();
    // Deleting an element from the front
    // l1.pop_front();
    // removing an element required
    l1.remove(4);
    display(l1);

    // Inserting elements in the list using iterator
    list<int> l2(3);
    list<int> :: iterator it=l2.begin();
    *it=45;
    it++;
    *it=4;
    it++;
    *it=6;
    it++;
    display(l2);
    // Merging two lists
    l1.merge(l2);
    cout<<"list 1 after merging: ";
    display(l1);

    return 0;
}