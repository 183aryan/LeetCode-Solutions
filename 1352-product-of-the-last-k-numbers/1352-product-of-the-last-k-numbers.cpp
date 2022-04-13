class ProductOfNumbers {
        vector<int> v;
public:
    ProductOfNumbers() {
        vector<int> v;
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i=0;i<k;i++){
            prod *= v[v.size()-1-i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */