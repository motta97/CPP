int factorial(int x){

    if(x==0)//zero factorial is also one
    return 1;
    else
    return x*factorial(x-1);

}
