#include<bits/stdc++.h>//includes all the standard librareies of c++
#include<iostream>
using namespace std;

/*
4types of in STL:

i) Algorithms
ii) Containers 
iii) Iterators 
iv) Function
*/
int main(){

/* --------------- PAIRS ---------*/

    pair<int,int> p = {1,2}; //stores 2 values each of any type
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, float> q = {1,2.9};
    cout<<q.first<<" "<<q.second<<endl;

    pair<int , pair<int,int>> r = {1,{2,3}};
    cout<<r.first<<" "<<r.second.first<<" "<<r.second.second<<endl;

    pair<int, int> arr[] = {{1,2}, {3,4},{5,6}}; 
    // array's pair starts from 0 like a normal array.
    cout<<arr[0].first<<" "<<arr[0].second<<" "<<arr[1].first<<endl;


/*    ------------------CONTAINERS ----------------*/

/* ---------------(a)---- Vectors ----------------*/

    vector<int> v; // creating an blank vector -> dynamic array (kinda)
    v.push_back(1); //pushes the value into the vector
    v.emplace_back(2); //oes the samething as push_back but is little faster

    // can we create a vector of type pair
    vector<pair<int,int>> vec;
    vec.push_back({1,2}); // need to push as a pair
    vec.emplace_back(1,2);  // unlike push_back no need to push as pair -> detects automatically

    vector<int> v3(5,10); // 5 instances of 100
    vector<int> v1(5); // vector of size 5 with 0 or garbage values
    vector<int> v2(v1); //creates a copy of vector v1.

    // ----  iteratrion -------//

    cout<<v[0]<<endl;// an element can be accessed as we do in an array using index
    // "v.at[0]"  can also be used

    // ---- defining an iterator---- //
    
    //datatype::iterator var_name = var_data.begin();
    // vector<int>::iterator it = v.begin();
    //cout<<*(v.begin());
    // cout<<*it; //
    // it++;


    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }

    //or

    for(auto it = v.begin();it!=v.end();it++){ // auto automatically identifies the datatype of the iterator
    //auto can be used in any for loop like
    //for(auto i=0;i<n;i++){} --> automatically knows the datatype of i
        cout<<*(it)<<" ";
    }

    //for each looop
    for(auto it : v){ //this is not an iterator it is a int type. 
        cout<<it<<" ";
    }

    // remove an element
    v.erase(v.begin()+1); // takes an address as the parameter
    //removing a range of elements
    v.erase(v.begin()+1, v.begin()+4); //[srart(inclusive) , end(exclusive)}

    //inserting an element
    v.insert(v.begin()+1,10); //(position, element to be inserted)
    v.insert(v.begin()+1,2,10); //(pos , no of instances, element) --> (100, 10 ,10, 200);
    return 0;
}
