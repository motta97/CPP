float Taylor_Series(int n,int times){
    static double p=1,f=1;
    double r;
    
    if(times!=0){
        r=Taylor_Series(n,times-1);
        p *=n;
        f*= times;
        return r+p/f;
        
        
    }
    else return 1;
    
    
    
    
}


int main()
{
   cout<<Taylor_Series(2,10)<<endl;
   
}
