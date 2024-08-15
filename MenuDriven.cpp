#include<iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array *arr){
    if (arr->length == 0)
    {
        cout<<"Empty array"<<endl;
    }
    else {
        cout<<endl;
        for (int i = 0; i < arr->length; i++)
        {
            cout<<arr->A[i]<<" ";
        }
        cout<<endl<<endl;        
    }
    
}

int Append(struct Array *arr, int element){
    if (arr->length < arr->size)
    {       
        arr->A[arr->length] = element;
        arr->length++;
        return 1;
    }else {
        return -1;
    }
}

int Insert(struct Array *arr, int element, int index){
    if (arr->length < arr->size && (index >= 0 && index <= arr->length)) 
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = element;
        arr->length++;
        return 1;
    } else {
        return -1;
    }
}

int Delete(struct Array *arr, int index){
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return 1;
    } else {
        return -1;
    }
}

int binarySearch(struct Array *arr, int key){
    int low,high,mid;
    low = 0;
    high = arr->length-1;
    while (low<=high)
    {
        mid = (low + high)/2;
        if (arr->A[mid] == key)
            return (int) mid;
        else if (arr->A[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

void leftShift(struct Array *arr, int times){
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < arr->length; j++)
        {
            arr->A[j] = arr->A[j+1];        
        }
    }
    // arr->length = arr->length - times;           note - after shifting we cannot change the size of the array, problem in displaying the array
}

void leftRotate(struct Array *arr, int times){
    int last;
    for (int i = 0; i < times; i++)
    {
        last = arr->A[0];
        for (int j = 0; j < arr->length; j++)
        {
            arr->A[j] = arr->A[j+1];
        }
        arr->A[arr->length-1] = last;
    }
}

void rightShift(struct Array *arr, int times){
    for (int i = 0; i < times; i++)
    {
        for (int j = arr->length-1; j > 0; j--)
        {
            arr->A[j] = arr->A[j-1];
        }
        arr->A[i] = 0;
    }
    // arr->length = arr->length - times;       note - after shifting we cannot change the size of the array, problem in displaying the array
}

void rightRotate(struct Array *arr, int times){
    int first;
    for (int i = 0; i < times; i++)
    {
        first = arr->A[arr->length-1];
        for (int j = arr->length-1; j > 0; j--)
        {
            arr->A[j] = arr->A[j-1];
        }
        arr->A[0] = first;
    }
}

int Get(struct Array *arr, int key){
    int low,high,mid;
    low = 0;
    high = arr->length-1;
    while (low<=high)
    {
        mid = (low + high)/2;
        if (arr->A[mid] == key)
            return (int) mid;
        else if (arr->A[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

void Set(struct Array *arr, int element, int index){
    arr->A[index] = element;
}

int Max(struct Array *arr){
    int max = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (max < arr->A[i])
            max = arr->A[i];
    }
    return max;
}

int Min(struct Array *arr){
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (min > arr->A[i])
            min = arr->A[i];
    }
    return min;
}

int Sum(struct Array *arr){
    int sum=0;
    for (int i = 0; i < arr->length; i++)
        sum += arr->A[i];
    return sum;
}

float Average(struct Array *arr){
    int sum=0;
    for (int i = 0; i < arr->length; i++)
        sum += arr->A[i];
    return (float) sum/arr->length;
}

int main()
{
    struct Array arr;
    int choice,element,index,times;
    float res;
    cout<<"Enter the size of the array : ";
    cin>>arr.size;

    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.length=0;
    

    do
    {
        cout<<"Array Menu"<<endl;
        cout<<"1. Display\n";
        cout<<"2. Append\n";
        cout<<"3. Insert\n";
        cout<<"4. Delete\n";
        cout<<"5. Search\n";
        cout<<"6. Left Shift\n";
        cout<<"7. Left Rotate\n";
        cout<<"8. Right Shift\n";
        cout<<"9. Right Rotate\n";
        cout<<"10. Get\n";
        cout<<"11. Set\n";
        cout<<"12. Max\n";
        cout<<"13. Min\n";
        cout<<"14. Sum\n";
        cout<<"15. Average\n";
        cout<<"16. Exit\n";

        cout<<endl<<"Enter choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1:     //display
                Display(&arr);
                break;
            
            case 2:        // append
                cout<<"Enter the element to append : ";
                cin>>element;
                res = (int) Append(&arr,element);
                if (res == 1)
                    cout<<"Element appended!"<<endl;
                else
                    cout<<"Array is full! Element cannot be appended !!"<<endl;
                break;
            
            case 3:             // insert
                cout<<"Enter the element and index : ";
                cin>>element>>index;
                res = (int) Insert(&arr,element,index);
                if (res == 1)
                cout<<"Element successfully inserted!"<<endl;
                else
                    cout<<"Element cannot be inserted !!"<<endl;
                break;
            
            case 4:         // delete
                cout<<"Enter the index of the element to delete : ";
                cin>>index;
                res = (int) Delete(&arr, index);
                if (res == 1)
                cout<<"Element successfully deleted !"<<endl;
                else
                    cout<<"Element cannot be deleted!! Invalid index!"<<endl;    
                break;
            
            case 5:         // binary search
                cout<<"Enter the element to search : ";
                cin>>element;
                res = binarySearch(&arr, element);
                if (res == -1)
                    cout<<"Element not found !"<<endl;
                else
                    cout<<"Element found at index "<<res<<endl;
                break;
            
            case 6:         // left shift
                cout<<"Enter the number of times to left shift : ";
                cin>>times;
                leftShift(&arr, times);
                cout<<"Array successfully left shifted !"<<endl;
                break;
            
            case 7:          // left rotate
                cout<<"Enter the number of times to left rotate : ";
                cin>>times;
                leftRotate(&arr, times);
                cout<<"Array successfully left rotated !"<<endl;
                break;
            
            case 8:             // right shift
                cout<<"Enter the number of times to right shift : ";
                cin>>times;
                rightShift(&arr, times);
                cout<<"Array successfully right shifted !"<<endl;
                break;

            case 9:             // right rotate
                cout<<"Enter the number of times to shift : ";
                cin>>times;
                rightRotate(&arr, times);
                cout<<"Array successfully left shifted !"<<endl;
                break;

            case 10:          // Get
                cout<<"Enter the element :  ";
                cin>>element;
                res = Get(&arr,element);
                if (res == -1)
                    cout<<"Element not found !"<<endl;
                else
                    cout<<"Element is at index : "<<res<<endl;
                break;
            
            case 11:        // Set
                cout<<"Enter the element and index : ";
                cin>>element>>index;
                Set(&arr,element,index);
                cout<<"Operation successfull !!";
                break;
            
            case 12:        // Max
                res = (int) Max(&arr);
                cout<<"Largest element is  : "<<res<<endl;
                break;
            
            case 13:        // Min
                res = (int) Min(&arr);
                cout<<"Smallest element is  : "<<res<<endl;
                break;

            case 14:       // sum
                res = (int) Sum(&arr);
                cout<<"Sum of the elements is : "<<res<<endl;
                break;

            case 15:        // average
                res = Average(&arr);
                cout<<"Average of the elements is : "<<res<<endl;
                break;

            case 16:    // exit
                choice=20;
                break;

            default:
                cout<<"Invalid option !";
                break;
        }

    } while (choice >= 1 && choice <=16);

    


}