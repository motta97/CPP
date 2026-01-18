int gcd(int x, int y){
    if(x%y==0)return y;
    return (gcd(y,x%y));
}
