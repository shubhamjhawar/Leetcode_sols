class NumberContainers {
    private:
    map<int,int> mp;
    public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mp[index] = number;
    }
    
    int find(int number) {
        for(auto& itr : mp){
            if(itr.second == number){
                return itr.first;
            }
        }
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */