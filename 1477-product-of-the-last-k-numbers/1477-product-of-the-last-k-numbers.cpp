class ProductOfNumbers {
private:
    vector<int> prod;
    int size=0;
public:
    ProductOfNumbers() {
    prod = {1};
    
    }

    void add(int num) {
        if (num == 0) {
            prod = {1};
            size = 0;
            }
        else{
            size = prod.size();
            prod.push_back(prod[size-1] *  num);
        }
        size++;
    }
    
    int getProduct(int k) {
        if(k>size-1) return 0;
        cout << "sz " << size << endl;
        cout << "prod " << prod[size - 1] << endl;
        return prod[size-1]/prod[size-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */