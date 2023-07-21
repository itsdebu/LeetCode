struct segmentTree{
    std::vector<std::pair<int,int>> tree;
    //tree[x] = {acc[x], ways[x]}
    std::vector<int> u;
    int N;
    segmentTree(std::vector<int>& v){
        N = v.size();
        tree.resize(4*N, std::pair<int,int>(0,0));
        for (int i=0; i<N; i++)
            u.push_back(v[i]);
        return;
    }
    
    void update(int x, int left, int right, int index, int acc, int ways){
        if (left==right){
            tree[x].first = acc;
            tree[x].second = ways;
            return;
        }
        int mid = (left+right)/2;
        if (index<=mid){
            update(2*x, left, mid, index, acc, ways);
        }else{
            update(2*x+1, mid+1, right, index, acc, ways);
        }
        if (tree[2*x].first>tree[2*x+1].first){
            tree[x] = tree[2*x];
        }else if (tree[2*x+1].first>tree[2*x].first){
            tree[x] = tree[2*x+1];
        }else{
            tree[x].first = tree[2*x].first;
            tree[x].second = tree[2*x].second + tree[2*x+1].second;
        }
        return;
    }
    
    std::pair<int,int> query(int x, int left, int right, int value){
        if (u[right]<value){
            return tree[x];
        }
        if (value<=u[left]){
            return std::pair<int,int>(0,0);
        }
        
        int mid = (left+right)/2;
        std::pair<int, int> temp;
        std::pair<int, int> result;
        
        if (value<=u[mid]){
            result = query(2*x, left, mid, value);
            
        }else{
            temp = query(2*x+1, mid+1, right, value);
            if (temp.first>tree[2*x].first){
                result.first = temp.first;
                result.second = temp.second;
                
            }else if (tree[2*x].first>temp.first){
                result.first = tree[2*x].first;
                result.second = tree[2*x].second;
            
            }else{
                result.first = tree[2*x].first;
                result.second = tree[2*x].second + temp.second;
            }
        }        
        return result;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int,int>> numsPair;
        std::vector<int> indexMap(n, 0);
        std::vector<int> v(n, 0);
        for (int i=0; i<n; i++){
            numsPair.push_back(std::make_pair(nums[i], i));
        }
        std::sort(numsPair.begin(), numsPair.end());
        for (int j=0; j<n; j++){
            v[j] = numsPair[j].first;
            indexMap[numsPair[j].second] = j;
        }
        
        segmentTree sgTree = segmentTree(v);
        std::pair<int, int> myPair;
        int acc, ways;
        // i=0
        sgTree.update(1, 0, n-1, indexMap[0], 1, 1);
        
        for (int i=1; i<n; i++){
            myPair = sgTree.query(1, 0, n-1, nums[i]);
            acc = myPair.first+1;
            ways = std::max(1, myPair.second);
            //std::cout<<"acc="<<acc<<", ways="<<ways<<"\n";
            sgTree.update(1, 0, n-1, indexMap[i], acc, ways);
        }
        
        //std::cout<<"("<<sgTree.tree[1].first<<", "<<sgTree.tree[1].second<<")\n";
        return sgTree.tree[1].second;
        
    }
};