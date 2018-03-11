#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,maxi=1e6,mini=-1,mmax=1e6,mmin=-1,dmax=1e6,dmin=-1;
    scanf("%d",&n);
    getchar();
    
    string name,young="",old="";
    int year,day,month;
    
    while(n--){
    	
    	cin>>name>>day>>month>>year;
    	
    	if(year<maxi){
    		old = name;
    		maxi = year;
    		
    		mmax = month;
    		dmax = day;
    		
    	}
    	else if(year==maxi){
    		if(month<mmax){
    			mmax = month;
    			old = name;
    		}
    		else if(month==mmax){
    			if(day<dmax){
    				old = name;
    				dmax = day;
    			}
    		}
    	}

       	if(year>mini){
    		young = name;
    		mini = year;
    		
    		mmin = month;
    		dmin = day;
    	}
    	else if(year==mini){
    		if(month>mmin){
    			mmin = month;
    			young = name;
    		}
    		else if(month==mmin){
    			if(day>mmin){
    				young = name;
    				dmin = day;
    			}
    		}
    	}
    
    }
    cout<<young<<endl<<old<<endl;
   
    return 0;
}
