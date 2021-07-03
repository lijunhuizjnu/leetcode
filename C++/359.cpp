class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> m;
    Logger() {
        //unordered_map<string, int> m;
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.count(message)>0 &&timestamp - m[message]<10)
            return false;
        else{
            m[message]=timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
