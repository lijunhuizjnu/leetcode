class MedianFinder {
public:
    /** initialize your data structure here. */
    struct cmp1{
        bool operator ()(int a,int b){
            return a<b;//升序，大根堆
        }
    };
    struct cmp2{
        bool operator ()(int a,int b){
            return a>b;//降序，小根堆
        }
    };
    priority_queue< int, vector<int>,cmp1> q1;//大根堆，存放较小的一半数
    priority_queue< int, vector<int>,cmp2> q2;//小根堆，存放较大的一半数
    MedianFinder() {
        q1={};
        q2={};
    }
    
    void addNum(int num) {
        int L1=q1.size(), L2=q2.size();
        int t1,t2;
        //时刻保持L2-L1等于0或1，且q1的最小值大于q2的最大值
        if(L1==L2){
            if(L2==0||q1.top()<=num){
                q2.push(num);
            }
            else{
                t1=q1.top();
                q1.pop();
                q1.push(num);
                q2.push(t1);
            }
        }
        else {
            if(q2.top()>=num){
                q1.push(num);
            }
            else{
                t2=q2.top();
                q2.pop();
                q2.push(num);
                q1.push(t2);
            }
        }
//        printf("L1=%d L2=%d\n",q1.size(),q2.size());
//        t1=q1.empty()?-1:q1.top();
//        t2=q2.empty()?-1:q2.top();
//        printf("t1=%d t2=%d\n",t1,t2);
    }
    
    double findMedian() {
        int L1=q1.size();
        int L2=q2.size();
        if(L1<L2)return double(q2.top());
        else return (1.0*q1.top()+1.0*q2.top())/2;;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
