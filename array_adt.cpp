#include<iostream>
using namespace std;

class myarray{
    private:
    int total_size;
    int used_size;
    int *ptr;
    public:
    myarray(){
        total_size=10;
        used_size=0;
        ptr= new int[10];
    }    
    myarray(int tsize){
        total_size=tsize;
        ptr= new int[tsize];}
    
    ~myarray(){
        delete[] ptr;
    }    
    public:
    void display(){
        for (int i=0;i<used_size;i++){
            cout<< ptr[i]<<endl;
        }}
    void Enterval(int k){
        used_size=used_size+k;
        for (int i=0;i<k;i++){
            cout<< "Enter element: ";
            cin>>ptr[i];
        }}
    void deletion(int index){//Code for Deletion
    if (used_size<=index){
        return;
    }
    for (int i = index; i < used_size-1 ; i++)
    {
        ptr[i]=ptr[i+1];
    }
    used_size--;
    }
    
    void Insert(int element,int index){
    //Code for Insert
    if (used_size=total_size || index>total_size){
        cout<<"Error";
        return;
    }
    for (int i = used_size-1; i >= index; i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=element;
    used_size++;
    return; 
}    
    void Insert(int element){
        append(element);
    }
    
    void append(int element){
        if (used_size=total_size){
        cout<<"Error";
        return;
        }
        ptr[used_size]=element;
        used_size++;}
    bool ifsorted(){
        for(int i=1;i<used_size-1;i++){
            if(ptr[i-1]>ptr[i]){
                return 0;}
        }
        return 1;
    }
    void Insorted(int element){
        for(int i=0;i<used_size;i++){
            if(element<ptr[i]){
                Insert(element,i);}
        }   
    }
    void Linear(int s)
{
	for(int i=0;i<used_size;i++){
		if(ptr[i]==s){
			cout<<"Element found."<<endl;
			return;
		}}
		cout<<"Element not found"<<endl;
	}
    int Binary(int s,int i=0,int f= NULL){
        if(f==NULL){
            f=used_size;
        }
        int n=f-i+1;
        int mid=(i+f)/2;
        if(n==1){
            if(ptr[mid]==s){
                cout<<"Element found.\n";
                return mid;
            }else{
                cout<<"Element not found.\n";
                return -1;
            }
        }
        if(ptr[mid]==s){
            cout<<"Element found.\n";
            return mid;
        }else if(ptr[mid]<s){
            Binary(s,mid+1,f);
        }else{
            Binary(s,i,mid-1);}
        }
    int Get(int index){
        if(index>=0&& index<used_size){
        return ptr[index];}
    }
    void Set(int index,int x){
        if(index>=0&& index<used_size){
        ptr[index]=x;}
    }
    int max(){
        int max1=ptr[0];
        for(int i=1;i<used_size;i++){
            if(ptr[i]>max1){
                max1=ptr[i];
            }
        }        
        return max1;
    }
    int min(){
        int max1=ptr[0];
        for(int i=1;i<used_size;i++){
            if(ptr[i]<max1){
                max1=ptr[i];
            }
        }
        return max1;
    }
    int sum(int sum1=0,int index=0){

        if(index>used_size){
        for (int i=0;i<used_size;i++){
            sum1=sum1+ptr[i];}
        }
        sum(sum1,index++);}
    void reverse(){
        for(int i=0;i<used_size/2;i++){
            int temp=ptr[i];
            ptr[i]=ptr[used_size-1-i];
            ptr[used_size-1-i]=temp;
        }
    }    
    myarray merge(myarray &a){
        int new_size=used_size + a.used_size;
        int *arr= new int[new_size];
        for(int i=0;i<used_size;i++){
            arr[i]=ptr[i];}
        for(int i=0;i<a.used_size;i++){
            arr[i+used_size]=a.ptr[i];}
    }
    int operator + (myarray &a){
        
    } 

};

int main(){
    return 0;
}
