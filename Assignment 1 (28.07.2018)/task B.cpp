/*
Name: Alvi Parvej
ID: 1702043
level-2 , Semester-I
*/
#include<bits/stdc++.h>
using namespace std;
int i, j, choice, n = 0;

void menu()
{

    cout<<"0....Exit\n";
    cout<<"1....View all elements\n";
    cout<<"2....Insert new element\n";
    cout<<"3....Search an element\n";
    cout<<"4....Delete an element\n";
    cout<<"5....Sort elements in ascending order\n";
    cout<<"6....Sort elements in descending order\n";
    cout<<"7....Find memory location of an element\n";
}

void View(int* ar){
    cout<<"Current elements are: "<<endl;
    for(i=1; i<=n; i++) cout<<ar[i]<<endl;
    cout<<"\n";
}

void Insert(int* ar){
    cout<<"Please, enter a integer type data to be inserted: ";
    int x;
    cin>>x;
    ar[++n] = x;
    cout<<ar[n]<<" is inserted successfully!\n";
}

void Search(int* ar){
    cout<<"Enter a data to be searched: ";
    int x;
    cin>>x;
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            cout<<x<<" is found.\n";
            return;
        }
    }
    cout<<x<<" is not found!\n";
}

void Delete(int* ar){
    cout<<"Enter a data to be deleted: ";
    int x, idx = 0;
    cin>>x;
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            idx = i;
            n--;
            break;
        }
    }
    if(idx){
        for(i=idx; i<=n; i++){
            ar[i] = ar[i+1];
        }
        cout<<x<<" is deleted successfully!\n";
    }
    else cout<<x<<" is not found!\n";
}

void Sort_asc(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]>ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    cout<<"After sorting in ascending order :\n";
    for(i=1; i<=n; i++)
        cout<<ar[i]<<endl;

}

void Sort_des(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]<ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    cout<<"After sorting in descending order:\n";
    for(i=1; i<=n; i++)
        cout<<ar[i]<<endl;
}

void MemLoc(int* ar){
    cout<<"Enter the index for what you want to know memory location: ";
    int x;
    cin>>x;
    if(x<1 || x>n) cout<<"Sorry! No such index is present!\n";
    else cout<<"Desired memory location is = "<<ar+x+1<<endl;
}

void perform(int* ar){
    cout<<endl;
    switch(choice)
    {
    case 1:
        View(ar);
        break;
    case 2:
        Insert(ar);
        break;
    case 3:
        Search(ar);
        break;
    case 4:
        Delete(ar);
        break;
    case 5:
        Sort_asc(ar);
        break;
    case 6:
        Sort_des(ar);
        break;
    case 7:
        MemLoc(ar);
        break;
    default:
        cout<<"Sorry! You entered an invalid keyword!\n";
        break;
    }
}
void clear_screen(){
    char ch = getchar();
    cout<<"Press any key to clear screen: ";
    char chh = getchar();
    system("CLS");
}

int main()
{
    int *arr ;
    arr = new int [100000]; //dynamic memory allocation of 10^6 elements

    while(1){
        menu();

        cout<<"Please, enter a valid keyword from the given list: ";
        cin>>choice;

        if(choice == 0) break;

        perform(arr);
        clear_screen();
    }

    cout<<"\nThank you for using this system!\n";

    return 0;
}
