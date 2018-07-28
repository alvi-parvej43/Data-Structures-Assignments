/*
Name: Alvi Parvej
ID: 1702043
level-2 , Semester-I
*/
#include<stdio.h>
#include<string.h>

#define mxn 1000000

int i, j, choice, n = 0;

void menu()
{
    printf("0....Exit\n");
    printf("1....View all elements\n");
    printf("2....Insert new element\n");
    printf("3....Search an element\n");
    printf("4....Delete an element\n");
    printf("5....Sort elements in ascending order\n");
    printf("6....Sort elements in descending order\n");
    printf("7....Find memory location of an element\n");
}

void View(int* ar){
    printf("Current elements are: ");
    for(i=1; i<=n; i++) printf("%d ", ar[i]);
    printf("\n");
}

void Insert(int* ar){
    printf("Please, enter a integer type data to be inserted: ");
    int x;
    scanf("%d", &x);
    ar[++n] = x;
    printf("%d is inserted successfully!\n", ar[n]);
}

void Search(int* ar){
    printf("Enter a data to be searched: ");
    int x;
    scanf("%d", &x);
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            printf("%d is found.\n", x);
            return;
        }
    }
    printf("%d is not found!\n", x);
}

void Delete(int* ar){
    printf("Enter a data to be deleted: ");
    int x, idx = 0;
    scanf("%d", &x);
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
        printf("%d is deleted successfully!\n", x);
    }
    else printf("%d is not found!\n", x);
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
    printf("After sorting in ascending order :\n");
    for(i=1; i<=n; i++)
        printf("%d\n",ar[i]);

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
    printf("After sorting in descending order:\n");
    for(i=1; i<=n; i++)
        printf("%d\n",ar[i]);
}

void MemLoc(int* ar){
    printf("Enter the index for what you want to know memory location: ");
    int x;
    scanf("%d", &x);
    if(x<1 || x>n) printf("Sorry! No such index is present!\n");
    else printf("Desired memory location is = %d\n", ar+x+1);
}

void perform(int* ar){
    printf("\n");
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
        printf("Sorry! You entered an invalid keyword!\n");
        break;
    }
}
void clear_screen(){
    char ch = getchar();
    printf("Press any key to clear screen: ");
    char chh = getchar();
    system("CLS");
}

int main()
{
    int *arr = malloc(mxn * sizeof(int)); //dynamic memory allocation of 10^6 elements

    while(1){
        menu();

        printf("Please, enter a valid keyword from the given list: ");
        scanf("%d", &choice);

        if(choice == 0) break;

        perform(arr);
        clear_screen();
    }

    printf("\nThank you for using this system!\n");

    return 0;
}
