struct producer_consumer
{
    int data;
    void send(int next_producer,int in, int out, int buffer_size, int buffer[]){
    while((in+1)%buffer_size==out);
    buffer[in]=next_producer;
    in=(in+1)%buffer_size;
}
void receive(int next_consumer,int in, int out, int buffer_size, int buffer[]){
    while(in==out);
    next_consumer=buffer[out];
    out=(out+1)%buffer_size;
}
};


