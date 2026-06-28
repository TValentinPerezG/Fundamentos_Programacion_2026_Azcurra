//Hacer fibonacci de forma iterativa

int fibonacci(int num){
    if(num==0){
        return 0;
    }
    else{
        if(num==1){
            return 1;
        }
        else{
            return fibonacci(num-1) + fibonacci(num-2);
        }
    }
}

int fibonacci_otro(int num){
    if(num<=1){
        return num;
    }
    else{
        return fibonacci_otro(num + 1) + fibonacci_otro(num + 2);
    }
}