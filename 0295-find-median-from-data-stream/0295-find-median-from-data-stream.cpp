class MedianFinder {
public:
    priority_queue<int>left;  //it will keep all smaller element
    priority_queue<int, vector<int>, greater<int>> right;  // it will keep all larger elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //insert into correct heap
        if(left.empty() || num <= left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        //balance the heap
        //left should have at most one extra element
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }

        //if right has more element move it to left
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top() + right.top())/2.0;
        }

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */