// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int>& st,int val){
    //Base Case
    if(st.size() == 0 || st.top() <= val){
        st.push(val);
        return;
    }
    
    //Recursive case
    int value = st.top();
    st.pop();
    insert(st,val);
    
    //Insert the val in the sorted stack as a whole
    st.push(value);
}
void recSort(stack<int>& st){
     //Base case
   if(st.size() == 1){
       return;
   }
    
   //Recursive case
   int val = st.top();
   st.pop();
   recSort(st);
   
   //Put the element back in the stack in the posn required
   insert(st,val);
}
void SortedStack :: sort()
{ 
     recSort(s);
}