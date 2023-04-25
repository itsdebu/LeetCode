class SmallestInfiniteSet {
public:
    set<int>st;
    int n=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(st.empty())return n++;
        auto n=*st.begin();
        st.erase(n);
        return n;
    }
    
    void addBack(int num) {
        if(num<n)st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */