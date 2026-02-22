double taylorSeriesIterative(float x, float n) {
    double s = 1.0;

    for (; n > 0; n--) {
        s = 1 + x * s / n;
    }

    return s;
}


int main()
{
   cout<<taylorSeriesIterative(2,20)<<endl;
   
}
