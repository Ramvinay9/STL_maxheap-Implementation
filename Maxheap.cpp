#include<iostream>
#include<math.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}

class Maxheap{
   private:
       int *harr;
       int capcity;
       int heap_size;
    public:
        Maxheap(int cap)
        {
            heap_size=0;
            capcity=cap;
            harr=new int[cap];
        }
       
        int leftchild(int i)
        {
            return 2*i+1;
        }
        int rightchild(int i)
        {
            return 2*i+2;
        }
        int parent(int i)
        {
            return (i-1)/2;
        }
         void linearSearch(int val)
        {
            for(int i=0;i<heap_size;i++)
            {
                if(harr[i]==val)
                {
                    cout<<"Value Found!"<<endl;
                    return;
                }
            }
            cout<<"Value NOT Found!"<<endl;
        }

        void printArray()
        {
            for(int i=0;i<heap_size;i++)
            {
                cout<<harr[i]<<" ";
            }
            cout<<endl;
        }

        int height()
        {
            return ceil(log2(heap_size+1));
        }

        void push(int k)
        {
            if(heap_size==capcity)
            {
                cout<<"\nOverFlow : Could not insert Key\n";
                return;
            }
            //First insert the new key at the end
            heap_size++;
            int  i=heap_size-1;
            harr[i]=k;

            //Fix the max heap property if it is violated
            while(i != 0  && harr[parent(i)] < harr[i])
            {
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
        }
        void MaxHeapify(int i)
        {
           int l=leftchild(i);
           int r=rightchild(i);
           int largest=i;
           if(heap_size>l  && harr[l]>harr[i])
              {
                largest=i;
              }
            if(heap_size>r && harr[r]>harr[largest])
            {
                largest=r;
            }
            if(largest != i)
            {
                swap(harr[i],harr[largest]);
                MaxHeapify(largest);
            }
        }
        int pop()       
        {
            if(heap_size==0)
            {
                cout<<"HEAP underFlow ! "<<endl;
                return -1e9;
            }
            if(heap_size == 1)
            {
                heap_size--;
                return harr[0];
            }
            int root=harr[0];
            harr[0] = harr[heap_size-1];
            heap_size--;
            MaxHeapify(0);

            return root;
        }
        int top()
        {
            if(heap_size==0)
            {
                cout<<"Heap is empty."<<endl;
                return -1e9;
            }
            return harr[0];
        }
        void increaseKeyValue(int i,int val)
        {
            harr[i]=val;
            while( i>=0   &&   harr[parent(i)] < harr[i])
            {
                i=parent(i);
            }
            return;
        }
        int size()
        {
           return heap_size;
        }
        void isempty()
        {
            if(heap_size==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
};

int main()
{
    int size;
    cout<<"Enter size of MAX Heap : ";
    cin>>size;
    Maxheap obj(size);
    cout<<"MAX Heap Created"<<endl;

    int option, val;

    do{
        cout<<"\n****What operation do you want to perform? "
        <<"Select Option number . Enter 0 to exit."<<endl;
        cout<<"1. Push Key/Node/Value"<<endl;
        cout<<"2. Pop opeartion / Extraxt max value"<<endl;
        cout<<"3. Top of Heap / Get Max"<<endl;
        cout<<"4. Number of Element in Heap"<<endl;
        cout<<"5. Is heap empty ?"<<endl;
        cout<<"6. Height of Heap"<<endl;
        cout<<"7. Print/Traversal Heap Values"<<endl;
        cout<<"8. Search value in Heap"<<endl;
        cout<<"9. Clear Screen"<<endl;
        cout<<"0. Exit Program"<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                 break;
            case 1:
                    cout<<"Push operation -"<<endl;
                 cout<<"Enter VALUE to Push in HEAP : ";
                 cin>>val;
                 obj.push(val);
                 cout<<endl;
                 break;
            case 2:
                  cout<<"Extract Max value/ Pop operation : ";
                  cout<<obj.pop()<<endl;
                  cout<<endl;
                  break;
            case 3:
                   cout<<"Get Max value / Top of Heap: ";
                  cout<<obj.top()<<endl;
                  cout<<endl;
                  break;
            case 4:
                  cout<<"Number of Element in Heap / Size : ";
                  cout<<obj.size();
                  break;
            case 5:
                  cout<<"Is heap empty ? : ";
                 obj.isempty();
                 break;
            case 6:
                  cout<<"HEAP TREE HEIGHT : ";
                  cout<<obj.height()<<endl;
                  break;
            case 7:
                 cout<<"Print Heap Array : ";
                 obj.printArray();
                 cout<<endl;
                 break;
            case 8:
                 cout<<"Search Opeartion -"<<endl;
                  cout<<"Enter VALUE to SEARCH in HEAP : ";
                  cin>>val;
                  obj.linearSearch(val);
                  break;
            case 9:
                system("cls");
                 break;
            default:
                 cout<<"Enter Proper Option Number "<<endl;
        }
    }while(option != 0);
}